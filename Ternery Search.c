#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
using namespace std;

#define SIZE 8000
int data[SIZE];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int data[], int l, int h)
{
    int pivot = data[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {

        if (data[j] < pivot)
        {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[h]);
    return (i + 1);
}

void quickSort(int data[], int l, int h)
{
    if (l < h)
    {

        int pi = partition(data, l, h);

        quickSort(data, l, pi - 1);
        quickSort(data, pi + 1, h);
    }
}

int ternarySearch(int l, int r, int key, int data[])
{
    if (r >= l) {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (data[mid1] == key) {
            return mid1;
        }
        if (data[mid2] == key) {
            return mid2;
        }

        if (key < data[mid1]) {

            return ternarySearch(l, mid1 - 1, key, data);
        }
        else if (key > data[mid2]) {

            return ternarySearch(mid2 + 1, r, key, data);
        }
        else {

            return ternarySearch(mid1 + 1, mid2 - 1, key, data);
        }
    }

    return -1;
}

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}



int main(){
    clock_t start, end;;
    int i, ans, key;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");

    for(i = 0; i < SIZE; i++){
        printf("%10d", data[i]);

    }

     printf("\n");
     scanf("%d",&key);


    start = clock();
    quickSort(data,0,SIZE-1);
    ans= ternarySearch(0,SIZE-1,key,data);
    end = clock();



    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\n\nQuickshort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

}
