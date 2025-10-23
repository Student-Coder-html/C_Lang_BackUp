#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    srand(time(NULL)); // Seed for random number generation

    int n;
    printf("Enter the fkin number: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random array
    printf("Random array: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 50;
        while (i > 0 && arr[i] <= arr[i - 1])
        {
            int a = 0;
            arr[i] = rand() % 10000;
        }
        // Random numbers 0-10000
        printf("%d ", arr[i]);
    }
    printf("\n");
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    if (result != -1)
        printf("알림: Element %d found at index %d\n", target, result);
    else
        printf("알림: Element %d not found\n", target);

    return 0;
}