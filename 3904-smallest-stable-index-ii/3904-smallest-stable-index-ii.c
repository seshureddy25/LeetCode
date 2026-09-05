int firstStableIndex(int* nums, int numsSize, int k) 
{
    int* maxPrev = (int*)malloc(sizeof(int) * numsSize);
    int* minNext = (int*)malloc(sizeof(int) * numsSize);

    maxPrev[0] = nums[0];
    for (int i = 1; i < numsSize; i++) 
    {
        maxPrev[i] =(maxPrev[i - 1] > nums[i]) ? maxPrev[i - 1] : nums[i];
    }

    minNext[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) 
    {
        minNext[i] = (minNext[i + 1] < nums[i]) ? minNext[i + 1] : nums[i];
    }

    int answer = -1;

    for (int i = 0; i < numsSize; i++)
    {
        if (maxPrev[i] - minNext[i] <= k) 
        {
            answer = i;
            break;
        }
    }

    free(maxPrev);
    free(minNext);

    return answer;
}