#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INF 9999  // Infinity for unreachable vertices
#define V 6        // Number of vertices in the graph

// Function to find the shortest path using Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src, int dist[V]);

#endif
