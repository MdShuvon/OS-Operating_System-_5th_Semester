#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    multimap<int,pair<int, int>>processes;
    cout << "Enter burst time: \n";
    for(int i=0; i<n; i++){
        int bt, pr;
        cout << "P [" << i+1 << "]: ";
        cin >> bt;
        cout << "Priority: ";
        cin >> pr;
        processes.insert({pr, {bt, i+1}});
    }
    vector<int>priority, pid, burst, completation, turnaround, waiting;
    int time = 0;
    double totalTAT =0 , totalWT = 0;

    for(auto &p: processes){
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
    cout << "PR\tP_ID\tBT\tCT\tWT\n";
    for(int i=0; i<n; i++){
        cout <<priority[i] <<  "\tP" <<pid[i] << '\t' << burst[i] << '\t' << completation[i] << '\t' << waiting[i] << endl;

    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << totalTAT/n;
    cout << "\nAverage Waiting Time: " << totalWT/n << '\n';
}