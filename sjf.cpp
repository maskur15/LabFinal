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

 bool operator <(const process& cmp)const{
   return arrival_time<cmp.arrival_time;
}
};
void completionTime(process p[],int n)
{
    map<int,bool> visit;
    int ct=0,index=0;
    p[0].completion_time=p[0].arrival_time+p[0].burst_time;
    ct= p[0].completion_time;
    visit[0]=true;
    while(true){
       int  max=5555;
        bool flag=true;
        bool finish=true;
        for(int i=1;i<n;i++)
        {
            if(!visit[i]&&flag&&p[i].arrival_time>ct)
            {
                p[i].completion_time= p[i].arrival_time+ p[i].burst_time;
                ct= p[i].completion_time;
                visit[i]=true;
                finish=false;
                break;
            }
            else if(!visit[i]&&p[i].arrival_time<=ct)
            {
                flag=false;
                if( p[i].burst_time<=max)
                {
                    max= p[i].burst_time;
                    index=i; finish=false;
                }
            }
        }
        if(flag==false){
            p[index].completion_time=ct+ p[index].burst_time;
            ct=p[index].completion_time;
            visit[index]=true;
        }
        if(finish)
        {
            break;
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
void displayAll(process p[],int n)
{
    cout << "Pid :            " ;
    for(int i=0;i<n;i++)
        cout << p[i].pid << " ";
    cout << endl;
     cout << "Arrival time :   " ;
    for(int i=0;i<n;i++)
        cout << p[i].arrival_time << " ";
    cout << endl;
    cout << "Burst time :     " ;
    for(int i=0;i<n;i++)
        cout << p[i].burst_time << " ";
    cout << endl;
     cout << "CompletionTime:  " ;
    for(int i=0;i<n;i++)
        cout << p[i].completion_time << " ";
    cout << endl;
     cout << "TurnAroundTime:  " ;
    for(int i=0;i<n;i++)
        cout << p[i].turn_around_time << " ";
    cout << endl;
       cout << "Waiting Time:    " ;
    for(int i=0;i<n;i++)
        cout << p[i].turn_around_time << " ";
    cout << endl;
    cout << "Average waiting time : " << float(avg_waiting_time)/n << endl ;
    cout << "Average turn_around time : " << float(avg_turnaround_time)/n << endl;
}
int main()
{
    int n;
    cout << "Enter the number of process : ";
    cin >> n;
    process p[n];
    cout << "Enter pid  arrival_time  burst_time " << n << " time's " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> p[i].pid;
        cin >> p[i].arrival_time;
        cin >> p[i].burst_time;
    }

    sort(p,p+n);
    completionTime(p,n);
    timeCalculation(p,n);

    displayAll(p,n);

}
