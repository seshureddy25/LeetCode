int compare(const void *a, const void *b)
{
    return *(int*)a>*(int*)b;
}
int maxProductDifference(int* arr, int size){
    qsort(arr,size,sizeof(int),compare);
    
        return (arr[size-1]*arr[size-2])-(arr[0]*arr[1]);
   // return arr[size-1]-arr[0];
}