#include <stdio.h>
#define MAX 100
#define INF 9999

void floyd (int graph[MAX][MAX], int n){
    int dist[MAX][MAX];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            dist[i][j]=graph[i][j];
        }
    }

    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (dist[i][k]+dist[k][j]<dist[i][j] && dist[i][j]!=INF){
                    dist[i][j]=dist[i][k]+dist[i][j];
                }
            }
        }
    }
    printf("\n All pair shortest matrix:\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                if (dist[i][j]==INF){
                    printf("INF  ");
                }
                else
                    printf("%d  ", dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, graph[MAX][MAX];
    printf("Enter no of vertices:");
    scanf("%d", &n);
    printf("Enter adjacency matrix(9999 for no edge):");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(graph, n);
    return 0;

    }
