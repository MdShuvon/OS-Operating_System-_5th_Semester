#include<bits/stdc++.h>
using namespace std;

int main (){
    int n, bt[50], ct[50], wt[50], tat[50];
    cout << "Enter process number: ";
    cin >> n;
    cout << "Enter burst time: \n";
    for (int i=1; i<=n; i++){
        cout << "P[" << i <<"]: ";
        cin >> bt[i];
    }
    bt[0]=0;
    for (int i=1; i<=n; i++){
        wt[i]=0;
        for (int j=1; j<=i; j++){
            wt[i] += bt[j-1];
        }
    }

    double avwt = 0, avtat = 0;
    for (int i=1; i<=n; i++){
        tat[i] = bt[i]+wt[i];
        avtat += tat[i];
        avwt += wt[i];
    }

    cout << "Total turnaround time: " << avtat << endl;
    cout << "Total waiting time: " << avwt << endl;
    avtat /= n; 
    avwt /= n;
    cout << fixed << setprecision(2);
    cout << "Average turnaround time: " << avtat << endl;
    cout << "Average waiting time: " << avwt << endl;
    
}