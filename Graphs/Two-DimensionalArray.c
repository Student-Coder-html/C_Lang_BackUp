#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int two_dimension[3][4];
    srand(time(NULL));

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            two_dimension[i][j] = rand() % 500;
        }
    }

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf("%d ", two_dimension[i][j]);
        }
        printf("\n");
    }

    return 0;
}
