bool increasingTriplet(int* nums, int numsSize) {
    int max=INT_MAX;
    int min=INT_MAX;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<=min)
        min=nums[i];
        else if(nums[i]<=max)
        max=nums[i];
        else
        return true;

    }
    return false;
}