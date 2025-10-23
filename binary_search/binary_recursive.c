#include <stdio.h>

// Recursive binary search function
int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
        return binarySearchRecursive(arr, mid + 1, right, target);
    }

    return -1; // Target not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    int result;

    // Using recursive approach
    result = binarySearchRecursive(arr, 0, size - 1, target);

    if (result != -1)
    {
        printf("Recursive: Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Recursive: Element %d not found\n", target);
    }

    return 0;
}