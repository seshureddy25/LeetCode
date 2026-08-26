int* relativeSortArray(int* arr1, int size, int* arr2, int size1, int* returnSize)
{
    int *result = malloc(size * sizeof(int));
    int l = 0;
    int count = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr2[i] == arr1[j])
            {
                result[l] = arr1[j];
                l++;
                count++;
                int temp = arr1[count - 1];
                arr1[count - 1] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
    for (int i = count; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr1[i] > arr1[j])
            {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
    for (int i = count; i < size; i++)
    {
        result[l] = arr1[i];
        l++;
    }

    *returnSize = size;
    return result;
}