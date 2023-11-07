#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int arr[num];
    int arr2[num];
    for(int i=0;i<num;i++){
        cin >> arr[i];
    }
    //print
    for(int i=0;i<num;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int currentsize = num; currentsize>1; --currentsize){
        int maxindex=0;
        for(int j=0,i=0;i<currentsize;++i){
            if(arr[i]>arr[j]){
                j=i;
            }
            maxindex=j;
        }
        //cout << maxindex << endl;
        if(maxindex!=currentsize-1){
            if(maxindex==0){
                //cout << "case1" << endl;
                //flipmax
                //copy
                for(int i=0;i<=currentsize-1;i++){
                    arr2[currentsize-1-i]=arr[i];
                }
                //paste
                for(int i=0;i<=currentsize-1;i++){
                    arr[i]=arr2[i];
                }
                //print
                for(int i=0;i<num;i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }else if(maxindex==currentsize-1){
                //cout << "case2" << endl;
                continue;
            }else{
                //cout << "case3" << endl;
                //flipmax
                //copy
                for(int i=0;i<=maxindex;i++){
                    arr2[maxindex-i]=arr[i];
                }
                //paste
                for(int i=0;i<=maxindex;i++){
                    arr[i]=arr2[i];
                }
                //print
                for(int i=0;i<num;i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                //flipall
                //copy
                for(int i=0;i<=currentsize-1;i++){
                    arr2[currentsize-1-i]=arr[i];
                }
                //paste
                for(int i=0;i<=currentsize-1;i++){
                    arr[i]=arr2[i];
                }
                //print
                for(int i=0;i<num;i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
    }
}