#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear search function
int linearSearch(int arr[], int n, int target)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element found at index i
        }
        else if (arr[i] > target)
        {
            return -1; // Element not found
        }
        printf("Count: %d\n", ++a);
    }
}

int main()
{
    srand(time(NULL)); // Seed for random number generation

    int n = 6; // Size of array
    int arr[n];

    // Generate random array
    printf("Random array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 5000;
        while (i > 0 && arr[i] <= arr[i - 1])
        {
            arr[i] = rand() % 10001;
        }
        // Random numbers 0-10000
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Search for a number
    int target;
    scanf("%d", &target);
    printf("Searching for: %d\n", target);

    int result = linearSearch(arr, n, target); //  ->  goes to search

    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}