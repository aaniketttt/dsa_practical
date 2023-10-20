#include "dijkstra.h"
#include <stdio.h>

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int src = 0;  // Source vertex

    int dist[V];  // Array to store the shortest distances

    dijkstra(graph, src, dist);

    return 0;
}
