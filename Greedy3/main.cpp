#include <bits/stdc++.h>
using namespace std;

void op(int a[], int b[], int n)
{
    sort(a, a + n);
    sort(b, b + n);
    int r = 0;
    int add;

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]){
            add = a[i] - b[i];
        if(add<0){
            add=add*(-1);
        }
            r = r + add;
    }

        else if (a[i] < b[i]){
            add = a[i] - b[i];
                if(add<0){
            add=add*(-1);
        }
           r = r + add;
       }
    }
    cout<< "Minimum increment or decrement needed: "<<  r;
}

int main()
{
    int a[] = { 3, 1, 1 };
    int b[] = { 1, 2, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    op(a, b, n);
    return 0;
}
