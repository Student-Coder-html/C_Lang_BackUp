#include <stdio.h>

false = 0;
true = 1;

int graph_G[5][5];

int is_Visited[5]; // checks visited or nah

void function_DFS(int target)
{
    printf("%d ", target);
    is_Visited[target] = 1;
    for (int i = 0; i <= 4; i++)
    {
        if (is_Visited[i] == false && graph_G[target][i] == true)
            function_DFS(i);
    }
}

int main(int argc, char const *argv[])
{
    function_DFS(0);
}
