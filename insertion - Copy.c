#include<stdio.h>
int main()
{
    int n, a[10],k=0;
    printf("Enter the no of terms (max 10)\n");
    scanf("%d", &n);
    printf("Enter the %d terms\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i=1;i<n;i++)
    {
        int key =a[i];
        int j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;

        }
        a[j+1]=key;
         k=+1;
    }
    printf("The sorted array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("np of swapping is %d\n",k);
    return 0;
}