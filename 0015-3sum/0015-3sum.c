int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* arr, int size, int* returnSize, int** returncolumn)
{
    int capacity = size * size;

    int **result = malloc(capacity * sizeof(int *));
    *returncolumn = malloc(capacity * sizeof(int));

    int l = 0;

    qsort(arr, size, sizeof(int), compare);

    for(int i = 0; i < size - 2; i++)
    {
        if(i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = size - 1;

        while(j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum == 0)
            {
                result[l] = malloc(3 * sizeof(int));

                result[l][0] = arr[i];
                result[l][1] = arr[j];
                result[l][2] = arr[k];

                (*returncolumn)[l] = 3;
                l++;

                while(j < k && arr[j] == arr[j + 1])
                    j++;

                while(j < k && arr[k] == arr[k - 1])
                    k--;

                j++;
                k--;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    *returnSize = l;

    return result;
}