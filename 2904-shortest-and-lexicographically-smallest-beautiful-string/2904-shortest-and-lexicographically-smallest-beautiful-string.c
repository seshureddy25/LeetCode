char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    int left = 0;

    int start = -1;
    int bestLen = n + 1;

    for (int right = 0; right < n; right++) 
    {

        if (s[right] == '1')
            count++;

        while (count == k) 
        {
            int len = right - left + 1;
            if (len < bestLen) 
            {
                bestLen = len;
                start = left;
            }
            else if (len == bestLen) 
            {
                if (start == -1 || strncmp(s + left, s + start, len) < 0) 
                {
                    start = left;
                }
            }
            if (s[left] == '1')
                count--;

            left++;
        }
    }
    if (start == -1)
        return "";

    char* result = malloc((bestLen + 1) * sizeof(char));
    strncpy(result, s + start, bestLen);
    result[bestLen] = '\0';

    return result;
}