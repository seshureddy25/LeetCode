/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int size, int target, int* returnSize) {
    int *result=malloc(2*sizeof(int));
    int left=0;
    int right=size-1;

    while(left<right)
    {
        int sum=0;
        sum=numbers[left]+numbers[right];
        if(sum==target)
        {
            result[0]=left+1;
            result[1]=right+1;
            *returnSize= 2;
            return result;
        }
        if(sum>target)
            right--;
        else
            left++;
    }
    return NULL;
}