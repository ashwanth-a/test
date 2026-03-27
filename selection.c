#include<stdio.h>
int main()
{
    int n,i,loc,min;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    int a[10];
    printf("Enter the %d terms\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i < n-1; i++)
    {
        // Assume the first element is the minimum
        min = a[i];
        loc = i;

        // Inner loop checks the rest of the array
        for(int j=i+1; j < n; j++)
        {
            if(a[j] < min)
            {
                // Found a new minimum
                min = a[j];
                loc = j;
            }
        }
        
        // BUG FIX: The swap logic is now INSIDE the outer loop.
        // After the inner loop, 'loc' holds the index of the
        // smallest element. We swap it with the 'i'th element.
        if(loc != i)
        {
            int temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
    }
    printf("the sorted arry is ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
return 0;
}