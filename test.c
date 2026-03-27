#include <stdio.h>

int main() {
    int n, i, num;
    int sum = 0; // Always initialize the sum to 0

    // Ask the user how many numbers they want to add
    printf("Enter how many numbers you want to add: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    // Loop 'n' times to get each number
    for (i = 0; i < n; ++i) {
        scanf("%d", &num);    // Read a single number from the user
        sum = sum + num;      // Add the number to the running total
    }

    // Print the final result
    printf("The sum of the numbers is: %d\n", sum);

    return 0;
}