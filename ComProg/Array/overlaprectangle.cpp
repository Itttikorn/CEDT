#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    int maxcount=0;
    int counter=0;
    int result[1000][2];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int count=0;
            
            //cout << i << j << endl;
            if(i==j){
                continue;
            }
            int lowerleftix = arr[i][0];
            int lowerleftiy = arr[i][1];
            int toprightix = arr[i][2];
            int toprightiy = arr[i][3];

            int lowerleftjx = arr[j][0];
            int lowerleftjy = arr[j][1];
            int toprightjx = arr[j][2];
            int toprightjy = arr[j][3];

            int minlowerleftx = min(arr[i][0],arr[j][0]);
            int minlowerlefty = min(arr[i][1],arr[j][1]);
            int maxtoprightx = max(arr[i][2],arr[j][2]);
            int maxtoprighty = max(arr[i][3],arr[j][3]);
            //cout << minlowerleftx << " " << minlowerlefty << endl;
            //cout << maxtoprightx << " " << maxtoprighty << endl;
            for(int y=maxtoprighty;y>=minlowerlefty;y--){
                for(int x=minlowerleftx;x<=maxtoprightx;x++){
                    //cout << x << " " << y << endl;
                    if(x>=lowerleftix && x<toprightix && x>=lowerleftjx && x<toprightjx && y>=lowerleftiy && y<toprightiy && y>=lowerleftjy && y<toprightjy){
                        //cout << "Yes";
                        count++;
                    }
                //cout << "endl" << endl;
                }
            }
            //cout << i << j << " " << count << endl;
            if(count >= maxcount){
                if(count>maxcount){
                    counter=0;
                }
                result[counter][0] = i;
                result[counter][1] = j;
                maxcount=count;
                counter++;
            }
        }
    }
    if(maxcount!=0){
        cout << "Max overlapping area = " << maxcount << endl;
        for(int i=0;i<counter;i++){
            cout << "rectangles " << result[i][0] << " and " << result[i][1] << endl;
        }
    }else{
        cout << "No overlaps";
    }
}