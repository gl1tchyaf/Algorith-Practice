#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct iteam
{
    int benifit,weight,value;
};
int main()
{
    iteam i[5];
    int weight_limit=60,j,k,l,total_profit=0;
    i[0].benifit=30;
    i[1].benifit=40;
    i[2].benifit=45;
    i[3].benifit=77;
    i[4].benifit=90;

    i[0].weight=5;
    i[1].weight=10;
    i[2].weight=15;
    i[3].weight=22;
    i[4].weight=25;



        i[0].value=i[0].benifit/i[0].weight;
        i[1].value=i[1].benifit/i[1].weight;
        i[2].value=i[2].benifit/i[2].weight;
        i[3].value=i[3].benifit/i[3].weight;
        i[4].value=i[4].benifit/i[4].weight;


        for(l=0;l<=5;l++){
                if(weight_limit==0){
                    break;
                }
                else{
        int minn=0,maxx;
        for(j=0;j<5;j++){
            if(i[j].value>minn){
                maxx=j;
                }
            }
            if(i[maxx].weight<=weight_limit){
                    weight_limit=weight_limit-i[maxx].weight;
                    total_profit=total_profit+i[maxx].benifit;
        }
        else{
                while(weight_limit!=0&& (i[maxx].benifit/i[maxx].value)<=i[maxx].weight){
            weight_limit=weight_limit-1;
            total_profit=total_profit+i[maxx].value;
            }
        }
                i[maxx].value=0;

    }
    }
    cout<< "Total Profit: "<< total_profit;


}
