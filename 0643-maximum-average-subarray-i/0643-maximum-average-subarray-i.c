double findMaxAverage(int* nums, int size, int k)
{
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    double max = sum;
    for (int i = k; i < size; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        if (sum > max)
        {
            max = sum;
        }
    }
    return max / k;
}