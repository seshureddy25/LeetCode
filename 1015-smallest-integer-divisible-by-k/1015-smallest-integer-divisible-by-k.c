int smallestRepunitDivByK(int k) {
    if(k%2==0 || k%5==0)
    {
        return -1;
    }
    int tem=0;
    for(int i=1;i<=k;i++)
    {
         tem=(tem*10+1)%k;
        if(tem==0)
            return i;
    }
    return -1;
}