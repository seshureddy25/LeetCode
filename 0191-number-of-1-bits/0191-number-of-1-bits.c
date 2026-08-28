int hammingWeight(int n) {
    int count=0;
    for(int i=31;i>=0;i--)
    {
        if(n&(1u<<i))
            count++;
    }
    return count;
}