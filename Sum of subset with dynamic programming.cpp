#include <stdio.h>
bool dp(int sets[], int n, int sum)
{
    int i,j;
    bool allsets[n + 1][sum + 1];

    for (i = 0; i <= n; i++){
        allsets[i][0] = true;
    }
    for (i = 1; i <= sum; i++){
        allsets[0][i] = false;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum; j++) {
            if (j < sets[i - 1])
                allsets[i][j] = allsets[i - 1][j];
            if (j >= sets[i - 1])
                allsets[i][j] = allsets[i - 1][j]
                               || allsets[i - 1][j - sets[i - 1]];
        }
    }

    return allsets[n][sum];
}

int main()
{
    int sets[] = { 5, 3, 40, 7, 12, 2 };
    int sum = 10;
    int n = sizeof(sets) / sizeof(sets[0]);
    if (dp(sets, n, sum) == true)
        printf("Given sum can be obtained by subsets");
    else
        printf("Given sum can not be obtained by subsets");
    return 0;
}
