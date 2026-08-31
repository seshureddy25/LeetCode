int removeElement(int* arr, int size, int val) {
    int count=0;
    for( int i=0;i<size;i++)
    {
        if(arr[i]!=val)
        {
            arr[count]=arr[i];
            count++;
        }
    }
    return count;

}