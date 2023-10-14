#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
    int sortedArray[] = {1, 2, 5, 5, 6, 9}; // Sorted array

    printf("Child process:\n");
    printf("Child PID: %d\n", getpid());

    int target = 5; // Item to search
    int result = binarySearch(sortedArray, 0, sizeof(sortedArray) / sizeof(sortedArray[0]) - 1, target);

    if (result != -1)
    {
        printf("Item %d found at index %d.\n", target, result);
    }
    else
    {
        printf("Item %d not found in the array.\n", target);
    }

    return 0;
}