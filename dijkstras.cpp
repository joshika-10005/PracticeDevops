#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, u, v, min, src;
    int cost[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source node: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;

    printf("\nIteration\tNode\t");
    for(i = 0; i < n; i++)
        printf("D[%d]\t", i);
    printf("\n");

    for(i = 1; i < n; i++) {
        min = INF;

        // Find nearest unvisited node
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for(v = 0; v < n; v++) {
            if(!visited[v] && dist[v] > dist[u] + cost[u][v])
                dist[v] = dist[u] + cost[u][v];
        }

        printf("%d\t\t%d\t", i, u);

        for(j = 0; j < n; j++)
            printf("%d\t", dist[j]);

        printf("\n");
    }

    return 0;
}
/*
Enter number of nodes: 4

Enter cost matrix:
0 2 5 9
2 0 1 4
5 1 0 2
9 4 2 0

Enter source node: 0
Iteration       Node    D[0]    D[1]    D[2]    D[3]
------------------------------------------------------
1               1       0       2       3       6
2               2       0       2       3       5
3               3       0       2       3       5
*/
