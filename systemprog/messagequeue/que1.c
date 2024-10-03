#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <pthread.h>

#define QUEUE_NAME "/my_queue"
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 256
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

void* producer(void* arg) {
    mqd_t mq = mq_open(QUEUE_NAME, O_WRONLY);
    if (mq == (mqd_t)-1) {
        perror("Producer: mq_open");
        return NULL;
    }

    char message[MAX_MESSAGE_SIZE];
    for (int i = 0; i < 5; i++) { // Each producer sends 5 messages
        snprintf(message, sizeof(message), "Message %d from producer %ld", i, (long)arg);
        mq_send(mq, message, strlen(message) + 1, 0);
        printf("Producer %ld sent: %s\n", (long)arg, message);
        sleep(1); // Simulate work
    }

    mq_close(mq);
    return NULL;
}

void* consumer(void* arg) {
    mqd_t mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("Consumer: mq_open");
        return NULL;
    }

    char message[MAX_MESSAGE_SIZE];
    while (1) {
        ssize_t bytes_read = mq_receive(mq, message, sizeof(message), NULL);
        if (bytes_read >= 0) {
            printf("Consumer %ld received: %s\n", (long)arg, message);
            sleep(2); // Simulate processing time
        } else {
            perror("Consumer: mq_receive");
            break;
        }
    }

    mq_close(mq);
    return NULL;
}

int main() {
    // Create the message queue
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MESSAGE_SIZE;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_EXCL | O_RDWR, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    // Create producer threads
    for (long i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producers[i], NULL, producer, (void*)i);
    }

    // Create consumer threads
    for (long i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumers[i], NULL, consumer, (void*)i);
    }

    // Wait for producer threads to finish
    for (long i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Close the message queue after producers finish
    mq_close(mq);
    mq_unlink(QUEUE_NAME); // Remove the message queue

    // Consumers will run indefinitely; you might want to handle their termination appropriately in a real application.

    return 0;
}

