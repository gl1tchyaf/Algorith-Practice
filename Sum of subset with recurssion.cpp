#include <stdio.h>
bool allsets(int sets[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (sets[n - 1] > sum)
        return allsets(sets, n - 1, sum);

    return allsets(sets, n - 1, sum) || allsets(sets, n - 1, sum - sets[n - 1]);
}

int main()
{
    int sets[] = { 5, 3, 40, 7, 12, 2 };
    int sum = 10;
    int n = sizeof(sets) / sizeof(sets[0]);
    if (allsets(sets, n, sum) == true){
        printf("Given sum can be obtained by subsets");
    }
    else{
        printf("Given sum can not be obtained by subsets");
    }
    return 0;
}
