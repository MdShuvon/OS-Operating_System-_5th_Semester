#include <bits/stdc++.h>
using namespace std;

int main (){
    int n=5, c=3;
    int alloc[n][c]={
        { 0, 0, 1 }, // P0 // This is Allocation Matrix 
		{ 3, 0, 0 }, // P1 
		{ 1, 0, 1 }, // P2 
		{ 2, 3, 2 }, // P3 
		{ 0, 0, 3 }  // p4
    };
    int max[n][c]={
        { 7, 6, 3 }, // P0 // MAX Matrix 
		{ 3, 2, 2 }, // P1 
		{ 8, 0, 2 }, // P2 
		{ 2, 1, 2 }, // P3 
		{ 5, 2, 3 }  // P4 
    };
    int avail[c]={2,3,2};  

    int f[5]={0}, ans[n], idx=0;

    int need[n][c];
    for (int i=0; i<n; i++){
        for (int j=0; j<c; j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (f[j]==0){
                int flag=0;
                for (int k=0; k<c; k++){
                    if (need[j][k]>avail[k]){
                        flag = 1;
                        break;
                    }
                }
                if (flag==0){
                    ans[idx++]=j;
                    for(int k=0; k<c; k++){
                        avail[k] += alloc[j][k];
                    }
                    f[j]=1;
                }
            }
        }
    }
    cout << "The safe sequence is as follows: \n";
    for (int i=0; i<n-1; i++){
        cout << "P" << ans[i] <<"->"; 
    }
    cout << "P" << ans[n-1] << endl;

}