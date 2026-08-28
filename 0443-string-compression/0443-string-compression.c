int compress(char* chars, int size)
{
    int visit[size];
    for(int i = 0; i < size; i++)
        visit[i] = 0;
    int l = 0;
    for(int i = 0; i < size; i++)
    {
        if(visit[i] == 1)
            continue;
        int count = 0;
        for(int j = i; j < size; j++)
        {
            if(chars[i] == chars[j] && visit[j] == 0)
            {
                count++;
                visit[j] = 1;
            }
            else
            {
                break;
            }
        }
        chars[l++] = chars[i];
        if(count > 1)
        {
            if(count < 10)
            {
                chars[l++] = count + '0';
            }
            else
            {
                int temp = count;
                int digits = 0;
                while(temp > 0)
                {
                    digits++;
                    temp /= 10;
                }
                int start = l;
                while(count > 0)
                {
                    chars[l++] = (count % 10) + '0';
                    count /= 10;
                }
                int end = l - 1;
                while(start < end)
                {
                    char tempChar = chars[start];
                    chars[start] = chars[end];
                    chars[end] = tempChar;
                    start++;
                    end--;
                }
            }
        }
    }

    return l;
}