#include<stdio.h>
void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int b[100];
    while(i<=mid && j<=high)
    {
        if(a[i] <= a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
        while(i<=mid)
        {
            b[k++]=a[i++];
        }
        while(j<=high)
        {
            b[k++]=a[j++];
        }
        for(i=low;i<=high;i++)
        {
            a[i]=b[i];
        }

    }
}

void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int n,a[100];
    printf("enter the no of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("the sorted array is\n");    
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}