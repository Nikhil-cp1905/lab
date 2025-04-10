#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4  // Number of cities

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int minCost = INT_MAX;
bool visited[V];

void tsp(int pos, int count, int cost, int start) {
    if (count == V && graph[pos][start]) {
        int totalCost = cost + graph[pos][start];
        if (totalCost < minCost)
            minCost = totalCost;
        return;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true;
            tsp(i, count + 1, cost + graph[pos][i], start);
            visited[i] = false;  // backtrack
        }
    }
}

int main() {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    visited[0] = true;  // start from city 0
    tsp(0, 1, 0, 0);

    printf("Minimum cost of TSP tour: %d\n", minCost);

    return 0;
}

