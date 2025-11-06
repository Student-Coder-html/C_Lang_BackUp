#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define MAX_NODES 100

int **graph_G;
int *is_Visited;
int node_count;

void function_DFS(int target)
{
    printf("%d ", target);
    is_Visited[target] = true;

    for (int i = 0; i < node_count; i++)
    {
        if (is_Visited[i] == false && graph_G[target][i] == true)
            function_DFS(i);
    }
}

int main(int argc, char const *argv[])
{
    int edge_count, start_node;

    printf("Enter the number of nodes: ");
    scanf("%d", &node_count);

    if (node_count <= 0 || node_count > MAX_NODES)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edge_count);

    printf("Enter the edges (format: node_a node_b):\n");
    for (int i = 0; i < edge_count; i++)
    {
        int a, b;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &a, &b);

        if (a >= 0 && a < node_count && b >= 0 && b < node_count)
        {
            graph_G[a][b] = true;
            graph_G[b][a] = true;
        }
        else
        {
            printf("Invalid edge! Nodes must be between 0 and %d\n", node_count - 1);
            i--; // Retry this edge
        }
    }

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start_node);

    if (start_node < 0 || start_node >= node_count)
    {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("\nDFS: ");
    function_DFS(start_node);
    printf("\n");

    return 0;
}