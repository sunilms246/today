#include <stdio.h>
#include <string.h>
#define MAX 256
void Table(char p[], int t[]);
int Horspool(char s[], char p[], int t[]);
int main()
{
    char text[MAX];
    char pattern[MAX];
    int shifttable[MAX];
    int found;
    printf("Enter the text string\n");
    scanf("%s",text);
    printf("Enter the pattern\n");
    scanf("%s",pattern);
    Table(pattern, shifttable);
    found = Horspool(text, pattern, shifttable);
    if (found == -1)
        printf("No pattern found in text\n");
    else
        printf("Pattern found at position %d\n", found + 1);
    return 0;
}
void Table(char p[], int t[])
{
    int m, i, j;
    m = strlen(p);
    for (i = 0; i < MAX; i++)
    {
        t[i] = m;
    }
    for (j = 0; j < m - 1; j++)
    {
        t[(unsigned char)p[j]] = m - 1 - j;
    }
}
int Horspool(char s[], char p[], int t[])
{
    int i, n, m, k;
    n = strlen(s);
    m = strlen(p);
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == s[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i = i + t[(unsigned char)s[i]];
    }
    return -1;
}