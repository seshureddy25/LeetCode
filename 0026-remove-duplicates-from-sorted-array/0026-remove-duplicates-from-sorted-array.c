int removeDuplicates(int* arr, int size) {
    if(size==0)
        return 0;
    int count=1;
    for(int i=1;i<size;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            arr[count]=arr[i];
            count++;
        }
    }
    return count;
}