#include<stdio.h>
int main(){
    int n,a[10],num;
    printf("Enter the no of terms\n");
    scanf("%d",&n);
    printf("Enter the terms\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("The sorted array is\n");
    for(int i=0;i<n;i++){
        printf("%d ,",a[i]);
    }   

    printf("\nenter the element to search\n");
    scanf("%d",&num);

    int beg=0,end=n-1,mid,flag=0;
    while(beg<=end){
        mid=(beg+end)/2;
        if(a[mid]==num){
            flag=1;
            break;
        }
        else if(a[mid]>num){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    if(flag==1){
        printf("Element %d found at position %d\n",num,mid+1);
    }
    else{
        printf("Element not found\n");
    }

    return 0;
}