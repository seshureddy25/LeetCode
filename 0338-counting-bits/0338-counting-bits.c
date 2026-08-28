/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *result;
    int size=n+1;
    result =malloc(size*sizeof(int));
    for(int i=0;i<=n;i++)
    {
        int count=0;
        for(int j=31;j>=0;j--)
        {
            if(i & (1u<<j))
            {
                count++;
            }
        }
        result[i]=count;
    }
    *returnSize=size;
    return result;
}