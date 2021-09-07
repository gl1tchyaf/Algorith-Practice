#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);

void lcs(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcs[index + 1];
  lcs[index] = '\0';
    int countt=0;
  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcs[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
      countt++;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }

  cout<< "\nLCS: " << lcs <<"\nThe length: " << countt<<"\n";
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
     }


int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X,Y,m,n);

    return 0;
}
