#include<iostream>
using namespace std;
 
int main(){
    int num;
    cin >> num;
    int arr[num][2];
    for(int i=0;i<num;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    //cin.ignore();
    string mode;
    cin >> mode;
    int line1max=arr[0][0],line1min=arr[0][0],line2max=arr[0][1],line2min=arr[0][1];
 
        for(int i=0;i<num;i++){
            if(i%2==0){
                if(arr[i][0]>line1max){
                    line1max = arr[i][0];
                }
                if(arr[i][0]<line1min){
                    line1min = arr[i][0];
                }
                if(arr[i][1]>line2max){
                    line2max = arr[i][1];
                }
                if(arr[i][1]<line2min){
                    line2min = arr[i][1];
                }
            }else if(i%2==1){
                if(arr[i][1]>line1max){
                    line1max = arr[i][1];
                }
                if(arr[i][1]<line1min){
                    line1min = arr[i][1];
                }
                if(arr[i][0]>line2max){
                    line2max = arr[i][0];
                }
                if(arr[i][0]<line2min){
                    line2min = arr[i][0];
                }
            }
        }
        if(mode=="Zig-Zag"){
            cout << line1min << " " << line2max;
        }else if(mode=="Zag-Zig"){
            cout << line2min << " " << line1max;
    }
}