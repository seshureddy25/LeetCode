#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int size, int k)
{
    int count = 0;

    qsort(nums, size, sizeof(int), compare);

    int i = 0;
    int j = size - 1;

    while(i < j)
    {
        int sum = nums[i] + nums[j];

        if(sum == k)
        {
            count++;
            i++;
            j--;
        }
        else if(sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return count;
}