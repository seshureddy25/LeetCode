char* reverseOnlyLetters(char* s)
{
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while(i < j)
    {
        if(!isalpha(s[i]))
        {
            i++;
        }
        else if(!isalpha(s[j]))
        {
            j--;
        }
        else
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    return s;
}