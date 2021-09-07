#include<stdio.h>
#include<limits.h>

int i=0;
int p=0;
int max(int a, int b) {
    return (a > b)? a : b;
    }


int cutWood(int price[], int n,int sz)
{

   int r= n-price[i];
   if(i==0){
    p+= n+max(r,price[i]);
    i++;
    }
    else{
        p+= max(r,(price[i]-price[i-1]));
        i++;
    }
   if(i!=(sz-1)){
    cutWood(price,n,sz);
    i++;
   }

   return p;
}


int main()
{
    int arr[] = {3,7,14};
    int size = 15;
    int arrSize= sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d", cutWood(arr, size, arrSize));
    getchar();
    return 0;
}
