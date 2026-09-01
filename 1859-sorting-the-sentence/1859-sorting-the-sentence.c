char *sortSentence(char *s)
{
    int slen=strlen(s);
    char **word = malloc(10 * sizeof(char *));
    int count = 0;
    char *token = strtok(s, " ");
    while (token != NULL)
    {
        int len = strlen(token);
        int pos = token[len - 1] - '1';

        token[len - 1] = '\0';
        word[pos] = token;

        count++;
        token = strtok(NULL, " ");
    }
    char *result = malloc(slen + 1);
    result[0] = '\0';
    for (int i = 0; i < count; i++)
    {
        strcat(result, word[i]);
        if (i < count - 1)
            strcat(result, " ");
    }
    free(word);
    return result;
}