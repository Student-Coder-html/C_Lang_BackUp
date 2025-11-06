#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

#define MAX_NODES 100

std::queue<int> Queue;

void function_Bfs(int target, int graph[][MAX_NODES], int is_visited[], int num_nodes)
{
    is_visited[target] = 1;
    Queue.push(target);

    while (!Queue.empty())
    {
        int iniPoint = Queue.front();
        Queue.pop();
        printf("%d ", iniPoint);

        for (int count = 0; count < num_nodes; count++)
        {
            if (is_visited[count] == 0 && graph[iniPoint][count] == 1)
            {
                Queue.push(count);
                is_visited[count] = 1;
            }
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int num_nodes, num_edges;
    int graph[MAX_NODES][MAX_NODES] = {0};
    int is_visited[MAX_NODES] = {0};

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    if (num_nodes > MAX_NODES)
    {
        printf("Number of nodes exceeds maximum limit of %d.\n", MAX_NODES);
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (format: a b):\n");
    for (int i = 1; i < num_edges; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a >= 0 && a < num_nodes && b >= 0 && b < num_nodes)
        {
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        else
        {
            printf("Invalid edge (%d, %d). Nodes must be between 0 and %d.\n", a, b, num_nodes - 1);
            i--;
        }
    }

    int start_node;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &start_node);

    if (start_node >= 0 && start_node < num_nodes)
    {
        printf("BFS Traversal starting from node %d: ", start_node);
        function_Bfs(start_node, graph, is_visited, num_nodes);
    }
    else
    {
        printf("Invalid starting node.\n");
    }

    return 0;
}