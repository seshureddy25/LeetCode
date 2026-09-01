char* getPermutation(int n, int k)
{
    char *ans = malloc((n + 1) * sizeof(char));
    int nums[9];
    int fact = 1;
    int i, j;
    for (i = 0; i < n; i++)
        nums[i] = i + 1;

    for (i = 1; i < n; i++)
        fact *= i;
    k--;
    for (i = 0; i < n; i++)
    {
        int index = k / fact;
        ans[i] = nums[index] + '0';
        for (j = index; j < n - i - 1; j++)
            nums[j] = nums[j + 1];
        k %= fact;
        if (n - i - 1 > 0)
            fact /= (n - i - 1);
    }
    ans[n] = '\0';
    return ans;
}