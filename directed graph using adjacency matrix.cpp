#include<iostream>
using namespace std;
int vertArr[20][20];
int verArr2[20][20];
int indegree1[20];
int outdegree1[20];
int count = 0;
int count2 = 0;
int max=0;
void displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}
void displayMatrix2(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << verArr2[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) {
   vertArr[u][v] = 1;

}
void outdegree(int v){

    for(int j=0;j<v;j++){
    int count2=0;
    for(int i=0;i<v;i++){
            if(vertArr[j][i]==1){
                    count2++;
                    outdegree1[j]=count2;

            }
    }
    if(count2%2!=0) cout<<"Odd out degree of "<<j+1<<":"<<  count2<< "\n";
 }
}
void indegree(int v){
    int maxi=0;
    for(int i=0;i<v;i++){

    int count2=0;
    for(int j=0;j<v;j++){
            if(vertArr[j][i]==1){
                    count2++;
                    indegree1[j]=count2;

            }
    }
    if(count2>maxi) maxi=count2;

 }
 cout<<"Maximum node with number of indegree"<<":"<<  maxi<< "\n";

}
void changeDir(int v){
    int i, j;
    cout<<"After Changing direction: \n" ;

   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         verArr2[j][i]=vertArr[i][j];
      }
   }
}

 void compare(int v){
    for(int i=0;i<v;i++){
        if(indegree1[i]==outdegree1[i]){
            cout<<i<< " vartix has same indegree and outdegree \n" ;
        }
    }
 }
 void isolatedVartix(int vartix, int z){
    for(int i=0;i<z;i++){
        if(vertArr[vartix][i]==1){
            vertArr[vartix][i]=0;
        }
        if(vertArr[i][vartix]==1){
            vertArr[i][vartix]=0;
        }
    }
 }
int main(int argc, char* argv[]) {
   int v = 6;
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);
   displayMatrix(v);
   outdegree(v);
   indegree(v);
   changeDir(v);
   displayMatrix2(v);
   compare(v);
   isolatedVartix(5,v);
   displayMatrix(v);
}
