#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int dist[MAX_VERTICES][MAX_VERTICES];
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, i, j;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use INF for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) { 
                graph[i][j] = INT_MAX;
            }
        }
    }
    floydWarshall(graph, n);

    return 0;
}
