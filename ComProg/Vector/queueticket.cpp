#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int queuecount=0;
    int calledcount=0;
    int resetqueue;
    int totaltime=0;
    double successqueue=0;
    map<int,int> queue;
    for(int i=0;i<n;i++){
        string order;
        cin >> order;
        if(order=="reset"){
            cin >> resetqueue;
        }else if(order=="new"){
            int time;
            cin >> time;
            int queuenumber = resetqueue+queuecount;
            queue[queuenumber] = time;
            cout << ">> ticket " << queuenumber << endl;
            queuecount++;
        }else if(order=="next"){
            cout << ">> call " << resetqueue+calledcount << endl;
            calledcount++;
        }else if(order=="order"){
            int calltime;
            cin >> calltime;
            int queuenumber = resetqueue+calledcount-1;
            int time = calltime - queue[queuenumber];
            totaltime+=time;
            successqueue++;
            cout << ">> qtime " << queuenumber << " " << time << endl;
        }else if(order=="avg_qtime"){
            double avg = totaltime/successqueue;
            cout << ">> avg_qtime " <<  round(avg*100.0)/100.0 << endl;
        }
    }
}