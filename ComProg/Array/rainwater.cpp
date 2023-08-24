#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int arr[num];
    int maxheight=0;
    int maxheightindex=0;
    for(int i=0;i<num;i++){
        cin >> arr[i];
        if(arr[i]>=maxheight){
            maxheight=arr[i];
            maxheightindex=i;
        }
    }
    //cout << maxheight << endl;
    int bluecount=0;
    int leftwall=0;
    int rightwall=0;
    for(int i=1;i<num-1;i++){
        bool canhavewater=false;
        int lowestwall;
        if(i-1>=maxheightindex){
            //cout << "Yes" << endl;
            rightwall=0;
        }
        if(arr[i-1]>leftwall){
            leftwall=arr[i-1];
        }
        for(int j=0;j<num-i;j++){
            if(arr[i+j]>rightwall){
                rightwall = arr[i+j];
            }
        }
        if(arr[i]<leftwall && arr[i]<rightwall){
            canhavewater = true;
        }
        if(leftwall<rightwall){
            lowestwall = leftwall;
        }else{
            lowestwall = rightwall;
        }

        if(canhavewater==true){
            int waterheight = lowestwall-arr[i];
            bluecount+=waterheight;
            //cout << "water"<<waterheight << endl;
        }
        //cout << i+1 << "left" << leftwall << "right" << rightwall << canhavewater << endl;
        
    }
    cout << bluecount;
}