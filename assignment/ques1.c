#include <stdio.h>

int main() {
    int n;

    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    int isPresent[n + 1];  

    
    for (int i = 1; i <= n; i++) {
        isPresent[i] = 0;
    }

    
    printf("Enter %d numbers between 1 and %d :\n", n, n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        
        if (arr[i] >= 1 && arr[i] <= n) {
            isPresent[arr[i]] = 1;
        }
    }

  
    int missingNumber = -1;
    for (int i = 1; i <= n; i++) {
        if (isPresent[i] == 0) {  
            missingNumber = i;
            break;  
        }
    }

   
    if (missingNumber != -1) {
        printf("Heyy, The missing number is: %d\n", missingNumber);
    } else {
        printf("Hmm... something went wrong.......!!!!\n");
    }

    return 0;
}

