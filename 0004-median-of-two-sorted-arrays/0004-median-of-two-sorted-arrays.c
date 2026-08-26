#include<stdio.h>
double findMedianSortedArrays(int* arr1, int size1, int* arr2, int size2) 
{
    int i,j,temp;
    int merge[size1 + size2];

    for(i = 0; i < size1; i++)
        merge[i] = arr1[i];

    for(i = 0; i < size2; i++)
        merge[size1 + i] = arr2[i];
int n = size1 + size2;

for(i = 0; i < n - 1; i++)
{
    for(j = 0; j < n - i - 1; j++)
    {
        if(merge[j] > merge[j + 1])
        {
            temp = merge[j];
            merge[j] = merge[j + 1];
            merge[j + 1] = temp;
        }
    }
}
float median=0;
int Median=0;
if(n%2==0)
{
    median=(float)((merge[n/2-1]+merge[n/2])/2.0);
    return median;
}
else
{
    Median=merge[n/2];
    return Median;
}
}