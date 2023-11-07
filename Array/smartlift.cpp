#include<iostream>
#include<cmath>
using namespace std;
//0         1       2   3
//lift no   start   end status
int main(){
    int n;
    cin >> n;
    int liftinfo[n][4];
    //int liftstatus;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> liftinfo[i][j];
            if(j==2){
                //cout << liftinfo[i][j] << "and" << liftinfo[i][j-1]<<endl;
                if(liftinfo[i][j]==liftinfo[i][j-1]){
                    liftinfo[i][3] = 0;
                }else if(liftinfo[i][j]>liftinfo[i][j-1]){
                    liftinfo[i][3] = 1;
                }else{
                    liftinfo[i][3] = 2;
                }
                //cout << liftinfo[i][3] << endl;
            }
        }
        //cout << "ij" << i;
    }
    //check table
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<4;j++){
    //         cout << liftinfo[i][j] << " "; 
    //     }
    //     cout << endl;
    // }
    int m;
    cin >> m;
    //int task[m][2];
    for(int i=0;i<m;i++){
        int start;
        int end;
        int wantstatus;
        int task[n];
        //0=still 1=up 2=down
        cin >> start >> end;
        if(start==end){
            wantstatus=0;
        }else if(end>start){
            wantstatus=1;
        }else{
            wantstatus=2;
        }
        //cout << "wantto" << wantstatus << endl;
        for(int j=0;j<n;j++){
            //case 1 lift still
            if(liftinfo[j][3]==0){
                //cout << "Case1" << endl;
                //go to start + start to end
                task[j]=abs(liftinfo[j][2]-start)+abs(start-end);
                //cout << "j" << j << " " << task[j] << endl;
                //cout << task[j];
            }else if(liftinfo[j][3]==wantstatus &&start>=liftinfo[j][1] &&start<=liftinfo[j][2]){ //case2 lift passing
                //lift go up
                //cout << start << " " << liftinfo[j][1] << " " << j << endl;
                //cout << "case2" << endl;
                //cout << "lift up" << endl;
                if(end<=liftinfo[j][2]){
                    //end in range
                    task[j] = 0;
                }else{
                    task[j] = abs(end-liftinfo[j][2]);
                    //cout << "yes";
                }
                //cout << "j" << j << " " << task[j] << endl;
            }else if(liftinfo[j][3]==wantstatus &&start<=liftinfo[j][1] &&start>=liftinfo[j][2]){
                //cout << "lift down" << endl;
                //cout << end << " and " << liftinfo[j][2] << endl;
                if(end>=liftinfo[j][2]){
                        task[j] = 0;
                }else{
                        task[j] = abs(end-liftinfo[j][2]);
                }
                //cout << "j" << j << " " << task[j] << endl;
                //cout << "j"<<j << endl;
                //cout << task[j] << endl;
            }else{ //case3 lift go different way
                //destination to start + start to end
                //cout << "case3" << endl;
                task[j] = abs(liftinfo[j][2]-start)+abs(start-end);
                //cout << "j" << j << " " << task[j] << endl;
            }
            
        }
        //find min
        int min = task[0];
        int minlocation = 0;
        for(int i=0;i<n;i++){
            //cout << liftinfo[i][0] << " " << task[i] << endl;
            if(task[i]==min){
                if (liftinfo[i][0] < liftinfo[minlocation][0]){
                    minlocation = i;
                min=task[i];
                }
            }else if(task[i]<min){
                //cout << task[n]<<"<"<<min<<endl;
                minlocation = i;
                min=task[i];
            }
        }
        //cout << endl;
        cout << ">> " << liftinfo[minlocation][0] << endl;
    }
}