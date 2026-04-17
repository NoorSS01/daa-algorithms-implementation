#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int n;

// Topological Sort
void topoSort() {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
        count++;
    }

    if (count != n)
        printf("\nCycle detected!\n");
}

int main() {
    n = 3;

    // Initialize graph
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    // Edges: 0->1, 1->2
    graph[0][1] = 1;
    graph[1][2] = 1;

    indegree[1]++;
    indegree[2]++;

    printf("Topological Order:\n");
    topoSort();

    return 0;
}