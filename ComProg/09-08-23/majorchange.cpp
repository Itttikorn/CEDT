#include <iostream>
using namespace std;
int main() {
    string id1,id2;
    double gpax1,gpax2;
    bool id1status=true,id2status=true;
    char id1cp,id2cp,id1cal1,id2cal1,id1cal2,id2cal2;
    cin >> id1 >> gpax1 >> id1cp >> id1cal1 >> id1cal2;
    cin >> id2 >> gpax2 >> id2cp >> id2cal1 >> id2cal2;
    if(id1cp >'A'){
        id1status = false;
    }
    if(id2cp > 'A'){
        id2status = false;
    }
    if(id1cal1 >'C'){
        id1status = false;
    }
    if(id2cal1 > 'C'){
        id2status = false;
    }
    if(id1cal2 >'C'){
        id1status = false;
    }
    if(id2cal2 > 'C'){
        id2status = false;
    }
    
    if(gpax1 > gpax2){
        id2status = false;
    }else if(gpax2 > gpax1){
        id1status = false;
    }else if(id1cal1 < id2cal1){
        id2status = false;
    }else if(id2cal1 < id1cal1){
        id1status = false;
    }else if(id1cal2 < id2cal2){
        id2status = false;
    }else if(id2cal2 < id1cal2){
        id1status = false;
    }

    if(id1status == false && id2status == false){
        cout << "None";
    }else if(id1status == true && id2status == false){
        cout << id1;
    }else if(id1status==false && id2status==true){
        cout << id2;
    }else{
        cout << "Both";
    }
}