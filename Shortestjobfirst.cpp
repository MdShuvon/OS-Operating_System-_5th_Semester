#include<bits/stdc++.h>
using namespace std;

int main (){
    int n; 
    cout << "Enter number of processes: ";
    cin >> n;

    multimap<int, int> processes;
    cout << "Enter burst time: \n";
    for (int i=0; i<n; i++){
        int bt;
        cout << "P[" << i+1 << "]: ";
        cin >> bt;
        processes.insert({bt, i+1});
    }

    vector<int> pid, burst, completation, turnaround, waiting;
    int time = 0;
    double totalTAT=0, totalWT=0;
    
    for (auto &p: processes){
        int id = p.second;
        int bt = p.first;
        time += bt;

        int  ct = time, tat = ct, wt = tat-bt;
        pid.push_back(id);
        burst.push_back(bt);
        completation.push_back(ct);
        waiting.push_back(wt);

        totalTAT += tat;
        totalWT += wt;
    }

    cout << "P_ID\tBT\tCT\tWT\n";
    for (int i=0; i<n; i++){
        cout<<"P"<<pid[i]<<'\t'<<burst[i]<<'\t'<<completation[i]<<'\t'<<waiting[i]<<'\n';
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << totalTAT/n;
    cout << "\nAverage Waiting Time: " << totalWT/n << '\n';
}