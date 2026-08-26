int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int *result;
    int size = right - left + 1;

    result = malloc(size * sizeof(int));

    int i = left, l = 0;

    while(i <= right)
    {
        int temp = 0;
        int k = i;
        int count = 0, count1 = 0, valid = 1;

        while(k > 0)
        {
            if(k % 10 == 0)
            {
                valid = 0;
                break;
            }

            temp = k % 10;
            k /= 10;
            count1++;

            if(i % temp == 0)
            {
                count++;
            }
        }

        if(valid && count == count1)
        {
            result[l] = i;
            l++;
        }

        i++;
    }

    *returnSize = l;
    return result;
}