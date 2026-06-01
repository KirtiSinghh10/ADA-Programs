#include <stdio.h>

#define MAX 10

int parent[MAX];

int find(int v) {
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void unite(int u, int v) {
    parent[u] = v;
}

void kruskal(int cost[MAX][MAX], int n) {
    int mincost = 0;
    int edges = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    while (edges < n - 1) {
        int min = 999, a = -1, b = -1;

        // Find minimum edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        // Include edge if it doesn't form a cycle
        if (u != v) {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            unite(u, v);
            edges++;
        }

        // Remove edge from consideration
        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d\n", mincost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    kruskal(cost, n);

    return 0;
}
