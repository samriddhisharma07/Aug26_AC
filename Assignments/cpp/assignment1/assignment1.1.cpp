#include <iostream>
using namespace std;
int statusCode(double reading){
    if(reading<0){
        return -1;
    }
    else if(reading>=0 && reading<=29){
        return 0;
    }
    else if(reading>=30 && reading<=44){
        return 1;
    }
    else if(reading>=45 && reading<=59){
        return 2;
    }
    else{
        return 3;
    }
}


int main(){

    double temp;
    cin>>temp;
    
    double f = (temp * 9 / 5) + 32;
    cout<<"Temperature :  "<<temp<<"C / "<<f<<"F"<<endl;

    int value = statusCode(temp);
    switch(value){
    case -1 : 
        cout<<"Status      : "<<" SENSOR_ERROR "<<endl;
        cout<<"Action      : "<<" Sensor fault -- check wiring "<<endl;
        break;
    case 0 : 
        cout<<"Status      : "<<" NORMAL "<<endl;
        cout<<"Action      : "<<" No action required "<<endl;
        break;
    case 1 : 
        cout<<"Status      : "<<" WARNING "<<endl;
        cout<<"Action      : "<<" Alert sent to supervisor "<<endl;
        break;
    case 2 : 
        cout<<"Status      : "<<" CRITICAL "<<endl;
        cout<<"Action      : "<<" Cooling system triggered "<<endl;
        break;
    default : 
        cout<<"Status      : "<<" SHUTDOWN "<<endl;
        cout<<"Action      : "<<" Emergency shutdown initiated "<<endl;
        break;
    }

    
    (temp>25)? cout<<"Reading     : "<<" Above Average" : cout<<"Reading     : "<<" Below Average ";
    return 0;
    



}