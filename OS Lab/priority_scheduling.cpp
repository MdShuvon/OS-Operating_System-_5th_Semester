#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cout << "Enter Process number: ";
    cin >> n;
    cout << "Enter Burst time: \n";

    multimap<int, pair<int, int>> process;
    for (int i=0; i<n; i++){
        cout << "P[" << i+1 << "]: ";
        int bt;
        cin >> bt;
        cout << "PR: ";
        int pr;
        cin >> pr;
        process.insert({pr,{bt, i+1}});
    }

    vector<int>priority, pid, burst, completation, waiting; 
    int time = 0;
    double totalTAT=0.0, totalWT=0.0;

    for (auto &p: process){
        int id = p.second.second;
        int bt = p.second.first;
        time += bt;
        
        int ct = time, tat = ct, wt = tat-bt;
        priority.push_back(p.first);
        pid.push_back(id);
        burst.push_back(bt);
        completation.push_back(ct);
        waiting.push_back(wt);
        totalTAT += tat;
        totalWT += wt;
    }

    cout << "PR\tProcess\tBT\tCT\tWT\n";
    for (int i=0; i<n; i++){
        cout << priority[i] <<"\tP[" << pid[i] << "]\t" << burst[i] << '\t' << completation[i] << '\t' << waiting[i] << "\n";
    }

    totalTAT /= n;
    totalWT /= n;
    
    cout << fixed << setprecision(2);
    cout << "Average turnaround time: " << totalTAT << endl;
    cout << "Average waiting time: " << totalWT << endl; 
}