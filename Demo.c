#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j,c=0;
    int graph[MAX][MAX];
    int indeg[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX];


    printf("Enter number of vertices: ");
    scanf("%d", &n);


    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }


    //calculate indegree
    for(i=0 ;i<n ;i++ ){
        indeg[i]=0;
        for(j = 0;j < n;j++){
            indeg[i]+=graph[j][i];
        }

    }

    for(i=0;i<n;i++){
        if(indeg[i]==0){
            rear++;
            queue[rear]=i;
        }
    }


   while(front <= rear){
      int k = queue[front++];
      topo[c++] = k;

      for(j = 0; j < n; j++){
        if(graph[k][j] == 1){
            indeg[j]--;

            if(indeg[j] == 0){
                queue[++rear] = j;
            }
        }
      }
   }

    //topo value is c value
    if(c==n){
        printf("topological order exist:\n");
        for(i=0;i<c;i++){
            printf("%d\t",topo[i]);
        }
    }
    else{
        printf("grah has cycle topological order not possible\n");
    }
    return 0;
}
