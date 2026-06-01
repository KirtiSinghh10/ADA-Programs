#include <stdio.h>

#define MAX 10
#define INF 9999

void dijkstra(int c[MAX][MAX], int n, int s, int d[MAX])
{
    int v[MAX], i, j, u, min;

    // Initialization
    for(i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        v[i] = 0;
    }

    d[s] = 0;
    v[s] = 1;

    // Main loop
    for(i = 1; i <= n; i++)
    {
        min = INF;

        // Find the unvisited vertex with minimum distance
        for(j = 1; j <= n; j++)
        {
            if(v[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;

        // Update distances
        for(j = 1; j <= n; j++)
        {
            if(v[j] == 0 && (d[u] + c[u][j] < d[j]))
            {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main()
{
    int c[MAX][MAX], d[MAX];
    int n, i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 1; i <= n; i++)
{
    for(j = 1; j <= n; j++)
    {
        scanf("%d", &c[i][j]);

        if(i != j && c[i][j] == 0)
        {
            c[i][j] = INF;
        }
    }
}

    printf("Enter source vertex: ");
    scanf("%d", &s);

    dijkstra(c, n, s, d);

    printf("\nShortest distances from vertex %d:\n", s);
    for(i = 1; i <= n; i++)
    {
        printf("To %d = %d\n", i, d[i]);
    }

    return 0;
}
