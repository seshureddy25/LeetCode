int minimumDeletions(int* nums, int numsSize)
{
    int minIndex = 0;
    int maxIndex = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < nums[minIndex])
            minIndex = i;

        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }
    int left = minIndex < maxIndex ? minIndex : maxIndex;
    int right = minIndex > maxIndex ? minIndex : maxIndex;
    int fromFront = right + 1;
    int fromBack = numsSize - left;
    int fromBoth = (left + 1) + (numsSize - right);
    int answer = fromFront;

    if (fromBack < answer)
        answer = fromBack;

    if (fromBoth < answer)
        answer = fromBoth;

    return answer;
}