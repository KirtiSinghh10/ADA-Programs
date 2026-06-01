#include <stdio.h>
void Knapsack(int n,int m,int V[n+1][m+1], int w[], int p[]) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) {
                V[i][j] = 0;
            }
            else if(w[i-1] > j) {
                V[i][j] = V[i-1][j];
            }
            else {
                int val1 = V[i-1][j - w[i-1]] + p[i-1];
                int val2 = V[i-1][j];
                V[i][j] = (val1 > val2) ? val1 : val2;
            }
        }
    }
}

int main() {
    int n,m;
    printf("Enter max capacity:\n");
    scanf("%d", &m);

    printf("Enter number of items:\n");
    scanf("%d", &n);

    int w[n], p[n];
    int V[n+1][m+1];

    printf("Enter weight and value of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &p[i]);                                                                                                                                                                                   );
    }

    Knapsack(n,m,V, w, p);

    printf("\nDP Table:\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            printf("%d\t", V[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", V[n][m]);

    return 0;
}
