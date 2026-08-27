/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** buildArray(int* target, int targetSize, int n, int* returnSize)
{
    char **result = malloc(2 * n * sizeof(char *));
    int k = 0;
    int j = 0;

    for(int i = 1; i <= n && j < targetSize; i++)
    {
        result[k] = malloc(6);
        strcpy(result[k], "Push");
        k++;

        if(i == target[j])
        {
            j++;
        }
        else
        {
            result[k] = malloc(5);
            strcpy(result[k], "Pop");
            k++;
        }
    }

    *returnSize = k;
    return result;
}