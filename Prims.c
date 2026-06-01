#include <stdio.h>
#define MAX 100
int cost[MAX][MAX];
int visited[MAX];
int num;

void prims() {
    int ne = 0;
    int mincost = 0;
    int min, a = -1, b = -1;
    visited[1] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < num - 1) {
        min = 999;


        for (int i = 1; i <= num; i++) {
            if (visited[i]) {
                for (int j = 1; j <= num; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d: (%d -> %d) cost: %d\n", ne + 1, a, b, min);
            mincost += min;
            visited[b] = 1;
            cost[a][b] = cost[b][a] = 999;
            ne++;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d",&num);
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    for (int i = 1; i <= num; i++)
        visited[i] = 0;

    prims();

    return 0;
}

