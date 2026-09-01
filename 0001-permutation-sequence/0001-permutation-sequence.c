char* getPermutation(int n, int k) {
    char *result=malloc((n+1)*sizeof(char));
    int arr[9];
    int fact=1;
    int i,j;
    for(i=0;i<n;i++)
        arr[i]=i+1;
    for(i=1;i<n;i++)
        fact*=i;
    k--;
    for(i =0;i<n;i++)
    {
        int index=k/fact;
        result[i]=arr[index]+'0';
        for(j=index;j<(n-i-1);j++)
            arr[j]=arr[j+1];
        k%=fact;
        if (n - i - 1 > 0)
            fact /= (n - i - 1);

    }
    result[n]='\0';
    return result;
}