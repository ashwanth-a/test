#include<stdio.h>

// Global variables
int n, a[10];

// Function prototypes
int partition(int a[], int low, int high);
void quick(int a[], int low, int high);

int main()
{
    printf("Enter the no of terms (max 10)\n");
    scanf("%d", &n);

    // Added a safety check to prevent array overflow
    if (n > 10 || n < 0)
    {
        printf("Error: Number of terms must be between 1 and 10.\n");
        return 1; // Exit with an error
    }

    printf("Enter the %d terms\n", n);
    
    // FIX 3: Loop should be i < n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initial call to quicksort
    quick(a, 0, n - 1);

    printf("The sorted array is\n");
    
    // FIX 3: Loop should be i < n
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]); // Changed comma to a space for cleaner output
    }
    printf("\n"); // Add a final newline
    
    return 0;
}

// FIX 1: Removed the "low = 0" and "high = n - 1" lines.
// This function now correctly operates on the subarray passed to it.
void quick(int a[], int low, int high)
{
    if (low < high)
    {
        // Get the pivot's final position
        int mid = partition(a, low, high);
        
        // Recursively sort the left and right subarrays
        quick(a, low, mid - 1); 
        quick(a, mid + 1, high);
    }
}

// FIX 2: Corrected the partition logic.
// The pivot swap and return now happen AFTER the loop.
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    // Loop until the pointers cross
    while (i <= j)
    {
        // Find an element on the left that is > pivot
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }
        
        // Find an element on the right that is <= pivot
        while (j >= low && a[j] > pivot)
        {
            j--;
        }

        // If pointers haven't crossed, swap the elements
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    // The loop has finished, so i > j.
    // j is now the correct final position for the pivot.
    // Swap the pivot (a[low]) with the element at j.
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    // Return the pivot's new index
    return j;
}


