#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

#define Left 0
#define Right 1

typedef struct{
    int val;
    int dir;}
Element;

void printPermutation(Element perm[],int n){
    for (int i=0; i<n; i++){
        printf("%s%d ",perm[i].dir==Left?"<-":"->", perm[i].val);
    }
    printf("\n");
}

void JohnsonTrotter(int n){
    Element* perm=(Element*)malloc(n*sizeof(Element));
    for (int i=0; i<n; i++){
        perm[i].val=i+1;
        perm[i].dir=Left;
    }
    printPermutation(perm, n);
    while (true){
        int mIdx=-1;
        int mval=-1;
        for (int i=0; i<n; i++){
            bool ismobile=false;
            if (perm[i].dir==Left && i>0 && perm[i].val > perm[i-1].val){
                ismobile=true;
            }
            else if (perm[i].dir==Right && i<n-1 && perm[i].val > perm[i+1].val){
                ismobile=true;
            }
            if (ismobile && perm[i].val>mval){
                mval=perm[i].val;
                mIdx=i;
            }
        }
        if (mIdx==-1){
            break;
        }
        int k=perm[mIdx].val;
        int targetIdx=(perm[mIdx].dir==Left ? mIdx-1: mIdx+1);
        Element temp=perm[mIdx];
        perm[mIdx]=perm[targetIdx];
        perm[targetIdx]=temp;

        for (int i=0; i<n; i++){
            if (perm[i].val>k){
                perm[i].dir=(perm[i].dir==Left ? Right:Left);
            }
        }
        printPermutation(perm, n);
    }
    free(perm);
}
int main(){
    int n;
    printf("Enter Value of N:");
    scanf("%d", &n);
    JohnsonTrotter(n);
    return 0;
}


