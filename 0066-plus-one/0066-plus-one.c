int* plusOne(int* str, int size, int* returnSize)
{
    int *result = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        result[i] = str[i];

    for (int i = size - 1; i >= 0; i--)
    {
        if (result[i] < 9)
        {
            result[i]++;
            *returnSize = size;
            return result;
        }

        result[i] = 0;
    }
    free(result);
    result = malloc((size + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1; i <= size; i++)
        result[i] = 0;

    *returnSize = size + 1;

    return result;
}