#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Merge(int low, int mid, int high, int a[]){
    int i=low;
    int j=mid+1;
    int k=low;

    int c[000];


    while (i<=mid && j <=high){
        if (a[i]<a[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=a[j];
            j++;
            k++;
        }
    }

    while (i<=mid){
            c[k]=a[i];
            i++;
            k++;
    }

    while (j<=high){
        c[k]=a[j];
        k++;
        j++;
    }

    for (int o=low; o<=high; o++){
            a[o]=c[o];}
}

void MergeSort(int low, int high, int a[]){
    if (low<high){
        int mid=(high+low)/2;
        MergeSort(low, mid, a);
        MergeSort(mid+1, high, a);
        Merge(low, mid, high, a);
    }
}

int main(){
    srand(time(NULL));

    int min = 1;
    int max = 10000;
    int n = 15000;
    int a[n];
    for (int i = 0; i < n; i++) {
        int random_num = (rand() % (max - min + 1)) + min;
        a[i]=random_num;
    }
    clock_t start=clock();
    MergeSort(0, n-1, a);
    clock_t end=clock();
    double time=((double)(end-start)/CLOCKS_PER_SEC)*1000;
    printf("\n %lf is the time taken:", time);
    return 0;
    }
