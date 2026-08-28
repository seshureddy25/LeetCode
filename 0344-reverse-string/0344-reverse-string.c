void reverseString(char* s, int size) {
    for(int i=0;i<size/2;i++)
    {
        char temp = s[i];
        s[i]=s[size-i-1];
        s[size-i-1]=temp;
    }
}