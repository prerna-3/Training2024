#include <stdio.h>
#include <string.h>

// Define the structure to hold product sales information
struct Product {
    char product_ID[10];
    int total_sales_amount;
};

// Function to sort products in descending order by total_sales_amount
void sortProducts(struct Product products[], int n) {
    int i, j;
    struct Product temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (products[i].total_sales_amount < products[j].total_sales_amount) {
                // Swap the products
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

// Function to find the highest sales amount for each unique product ID
void getHighestSales(struct Product products[], int n, struct Product uniqueProducts[], int *uniqueCount) {
    int i, j, found;
    
    *uniqueCount = 0;
    
    for (i = 0; i < n; i++) {
        found = 0;
        // Check if the product is already in the uniqueProducts array
        for (j = 0; j < *uniqueCount; j++) {
            if (strcmp(products[i].product_ID, uniqueProducts[j].product_ID) == 0) {
                found = 1;
                // If found, update the total_sales_amount if it's higher
                if (products[i].total_sales_amount > uniqueProducts[j].total_sales_amount) {
                    uniqueProducts[j].total_sales_amount = products[i].total_sales_amount;
                }
                break;
            }
        }
        // If not found, add it to the uniqueProducts array
        if (!found) {
            uniqueProducts[*uniqueCount] = products[i];
            (*uniqueCount)++;
        }
    }
}

int main() {
    struct Product products[100], uniqueProducts[100];
    int n = 0, uniqueCount = 0;
    char input[50];

    printf("Enter product records (format: ProductID-TotalSalesAmount), enter 'done' to finish:\n");
    while (1) {
        gets(input);
        if (strcmp(input, "done") == 0) break;
        
        // Parse input to get ProductID and TotalSalesAmount
        sscanf(input, "%[^-]-%d", products[n].product_ID, &products[n].total_sales_amount);
        n++;
    }

    // Get highest sales amount for each unique product ID
    getHighestSales(products, n, uniqueProducts, &uniqueCount);

    // Sort the unique products by total_sales_amount in descending order
    sortProducts(uniqueProducts, uniqueCount);

    // Print the sorted unique products
    printf("\nProduct sales in decreasing order of total_sales_amount:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%s-%d\n", uniqueProducts[i].product_ID, uniqueProducts[i].total_sales_amount);
    }

    return 0;
}

