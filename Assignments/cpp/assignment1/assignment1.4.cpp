#include <iostream>
using namespace std;

int main(int argc , char* argv[]){
    
    if(argc!=4){
        cout << "Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error   : Missing arguments." << endl;
        return 1;
    }
    int warn = stoi(argv[1]);
    int critical = stoi(argv[2]);
    int num_readings = stoi(argv[3]);

    if(warn>=critical){
        cout<<"Error : Warn threshold must be less than critical."<<endl;
        return 1;
    }
    else if(num_readings<1 || num_readings>500){
        cout<<"Error : Number of readings must be between 1 and 500."<<endl;
        return 1;
    }
    cout << "Config  : Warn=" << warn<< "C     Critical=" << critical<< "C     Readings=" << num_readings << endl;

    int ncount = 0;
    int wcount = 0;
    int ccount = 0;
    int scount = 0;

    for(int i=0 ; i<num_readings ; i++){
        int temp = rand() % 70;
        if(temp < warn) {
            ncount++;
        }
        else if(temp < critical) {
            wcount++;
        }
        else if(temp < 60) {
            ccount++;
        }
        else {
            scount++;
        }
    }
    cout<<"Results : Normal:"<<ncount<<"  Warning:"<<wcount<<"  Critical:"<<ccount<<"  Shutdown:"<<scount;
    
    return 0 ;
    


}
