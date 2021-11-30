#include<bits/stdc++.h>
using namespace std;
int avg_waiting_time=0;
int avg_turnaround_time=0;
class process{
public:
int pid;
int arrival_time;
int burst_time;
int completion_time;
int waiting_time;
int turn_around_time;
process(){
     waiting_time=0;
    completion_time=0;
    turn_around_time=0;
}

 bool operator <(const process& cmp){
   return arrival_time<cmp.arrival_time;
}
};
void completionTime(process p[],int n)
{
     for(int i=0;i<n;i++)
    {
       if(i==0)
       {
           p[i].completion_time=p[i].arrival_time+p[i].burst_time;
           continue;
       }
       if(p[i-1].completion_time<p[i].arrival_time)
       {
           p[i].completion_time=p[i].arrival_time+p[i].burst_time;
       }
       else {
        p[i].completion_time=p[i-1].completion_time+p[i].burst_time;
       }
    }
}
void timeCalculation(process p[],int n){
 for(int i=0;i<n;i++)
 {
     p[i].turn_around_time=p[i].completion_time-p[i].arrival_time;
     p[i].waiting_time=p[i].turn_around_time-p[i].burst_time;
     avg_turnaround_time+=p[i].turn_around_time;
     avg_waiting_time+=p[i].waiting_time;
 }
}


int main()
{
    int n;
    cout << "Enter the number of process : ";
    cin >> n;
    process p[n];
    cout << "Enter pid  arrival_time  burst_time " << n << "th time " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> p[i].pid;
        cin >> p[i].arrival_time;
        cin >> p[i].burst_time;
    }

    sort(p,p+n);
    completionTime(p,n);
    timeCalculation(p,n);
    cout << "Pid ar_time  burst_time  comp_time  turn_time wait_time" << endl;
     for(int i=0;i<n;i++)
    {
        cout << p[i].pid << "  ";
        cout << p[i].arrival_time << "  ";
        cout << p[i].burst_time << "  ";
        cout << p[i].completion_time << "  ";
        cout << p[i].turn_around_time << "  ";
        cout << p[i].waiting_time<<  endl;
    }
    cout << "Average waiting time : " << float(avg_waiting_time)/n << endl ;
    cout << "Average turn_around time : " << float(avg_turnaround_time)/n << endl;
}
