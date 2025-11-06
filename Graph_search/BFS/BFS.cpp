#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

#define false 0
#define true 1

int Normal_Graph[5][5] = {
    {0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 0, 0}};

int is_visited[5];

std::queue<int> Queue;

void function_Bfs(int target)
{
    is_visited[target] = true;
    Queue.push(target);
    while (!Queue.empty())
    {
        int iniPoint = Queue.front();
        Queue.pop();
        printf("%d ", iniPoint);
        for (int count = 0; count < 5; count++)
        {
            if (is_visited[count] == false && Normal_Graph[iniPoint][count] == true)
            {
                Queue.push(count);
                is_visited[count] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    function_Bfs(0);
    return 0;
}