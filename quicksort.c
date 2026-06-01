#include<stdio.h>
void quicksort(int arr[],int l,int h);
int main(){
    printf("enter the number of terms in array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
}
void quicksort(int arr[],int l,int h){
    if(l>=h) return;
    int s=l;
    int e=h;
    int mid=l+(h-l)/2;
    int pivot=arr[mid];
    while(s<=e){
        while(arr[s]<pivot){
            s++;
        }
        while(arr[e]>pivot){
            e--;
        }
        if(s<=e){
            int temp=arr[s];
            arr[s]=arr[e];
            arr[e]=temp;

        }
    }
    quicksort(arr,l,e);
    quicksort(arr,s,h);
}
