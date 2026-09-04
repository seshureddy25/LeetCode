
int firstStableIndex(int* arr, int size, int k) {

    for(int j=0;j<size;j++)
    {
        int max=arr[0];
        int min=arr[j];
        for(int i=0;i<=j;i++)
        {
            if(max<arr[i])
                max=arr[i];
        }
        for(int i=j;i<size;i++)
        {
            if(min>arr[i])
            min=arr[i];
        }
        if(max-min<=k)
        return j;
    }
    return -1;
}