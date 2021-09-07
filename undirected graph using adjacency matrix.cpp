#include<iostream>
using namespace std;
int vertArr[20][20];
int count = 0;
void displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) {
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
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
 void edge(int v){
    int maxi=0;
    for(int i=0;i<v;i++){

    int count2=0;
    for(int j=0;j<v;j++){
            if(vertArr[j][i]==1){
                    count2++;
            }
            if(vertArr[i][j]==1){
                    count2++;
            }

    }
    if(count2>maxi) maxi=count2;


    }
     cout<<"Maximum number of edges"<<":"<<  maxi<< "\n";
 }
 void connectEdge(int edgee, int v){
    for(int i=0;i<v;i++){
        add_edge(edgee,i);
    }
 }

 void evenVart(int v){

    for(int j=0;j<v;j++){
    int count2=0;
    for(int i=0;i<v;i++){
            if(vertArr[j][i]==1){
                    count2++;
            }
            if(vertArr[i][j]==1){
                    count2++;
            }
    }
    if(count2%2==0) cout<<"List nodes which has even number of vertices "<<j+1<< "\n";
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
   isolatedVartix(5,v);
   edge(v);
   evenVart(v);
   connectEdge(0,v);
   displayMatrix(v);
}
