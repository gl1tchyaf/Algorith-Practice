
#include <bits/stdc++.h>
void tracing(int W, int result, int weights[],int n,int value[]);
void knapSack(int W, int weights[], int value[], int n);
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
     }


void knapSack(int W, int weights[], int value[], int n){
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(value[i - 1] +
                    K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int result = K[n][W];
    printf("Sum of Max value: %d\nItems taken: ", result);
    tracing(W,result,weights,n,value);

}
void tracing(int W, int result, int weights[],int n,int value[]){
    int w = W;
    int K[n + 1][W + 1];
    K[n][w]=result;

    for (int i = n; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w])
            continue;
        else {
            printf("%d ", weights[i - 1]);
            result = result - value[i - 1];
            w = w - weights[i - 1];
        }
    }
}


int main()
{
    int value[] = { 60, 100, 120 };
    int weights[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(value) / sizeof(value[0]);

    knapSack(W, weights, value, n);


    return 0;
}
