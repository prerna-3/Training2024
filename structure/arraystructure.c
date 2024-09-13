#include <stdio.h>

// Define the structure Book
struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book books[5];  // Array of 5 books
    int i;

    // Input details for each book
    for (i = 0; i < 5; i++) {
        printf("Enter details for Book %d:\n", i + 1);
        printf("Title: ");
        gets(books[i].title);
        printf("Author: ");
        gets(books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar();  // Consume newline character left by scanf
    }

    // Print details of all books
    printf("\nBook Details:\n");
    for (i = 0; i < 5; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n\n", books[i].price);
    }

    return 0;
}

