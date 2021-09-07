#include <bits/stdc++.h>
using namespace std;

struct Activitiy
{
    int s, f;
};

bool compare(Activitiy a1, Activitiy a2)
{
    return (a1.f < a2.f);
}

void maxActivities(Activitiy arr[], int sizee)
{
    sort(arr, arr+sizee, compare);
    int i = 0;
    int maximum_activity=1;
    cout << " (" << arr[i].s << ", " << arr[i].f << "), ";
    cout << "\n ";
    for (int j = 1; j < sizee; j++)
    {
      if (arr[j].s >= arr[i].f)
      {
          maximum_activity++;
          cout << "("<< arr[j].s << ", " << arr[j].f << "), ";
          cout << "\n ";
          i = j;
      }
    }
    cout <<"Maximum activity can be done: " << maximum_activity;
}

int main()
{
    Activitiy a[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
    int sizee = sizeof(a)/sizeof(a[0]);
    maxActivities(a, sizee);
    return 0;
}
