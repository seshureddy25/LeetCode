#include <stdbool.h>
#include <limits.h>

bool uniformArray(int* nums1, int size)
{
    int minOdd = INT_MAX;

    for(int i = 0; i < size; i++)
    {
        if(nums1[i] % 2 != 0 && nums1[i] < minOdd)
        {
            minOdd = nums1[i];
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(nums1[i] % 2 == 0 && minOdd != INT_MAX && nums1[i] < minOdd)
        {
            return false;
        }
    }

    return true;
}