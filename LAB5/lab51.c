/*
PRATISTHA SRIVASTAVA 
1906621
Write a program to implement the Longest Common Subsequence using Dynamic Programming.


 Sample Inputs & Outputs:
 The LCS of HUMAN and CHIMPANZEE is HMAN*/

#include <stdio.h>
#include <string.h>
int max(int a, int b);

void lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    printf("Length of LCS is %d", L[m][n]);

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    printf("\n%s", lcs);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int m, n;
    printf("Enter size of first and second string\n");
    scanf("%d%d", &m, &n);
    char X[m], Y[n];
    printf("Enter X\n");
    scanf("%s", X);
    printf("Enter Y\n");
    scanf("%s", Y);
    lcs(X, Y, m, n);

    return 0;
}
