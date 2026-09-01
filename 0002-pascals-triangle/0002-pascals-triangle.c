/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int rows, int* returnSize, int** returncolumn) {
    int **result=malloc(rows*sizeof(int*));
    *returncolumn=malloc(rows*sizeof(int));
    *returnSize=rows;
    for( int i=0;i<rows;i++)
    {
        result[i]=malloc((i+1)*sizeof(int));
        (*returncolumn)[i]=i+1;

        result[i][0]=1;
        result[i][i]=1;
        for(int j=1;j<i;j++)
        {
            result[i][j]=result[i-1][j-1]+result[i-1][j];
        }
    }

    return result;
}