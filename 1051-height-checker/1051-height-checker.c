int heightChecker(int* arr, int size) {
    int arr1[size];
    for(int i=0;i<size;i++)
    {
        arr1[i]=arr[i];
    }
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                int temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
    int count=0;
    for( int i=0;i<size;i++)
    {
        if(arr1[i]!=arr[i])
        {
            count++;
        }
    }
    return count;
}