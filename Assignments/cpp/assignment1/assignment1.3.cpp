#include <iostream>
using namespace std;

int main(){
    double total;
    double avg;

    double temperature[3][3];
    double maxAvg = -999.0; 
    int highestAvgFloor = 0;

    for(int i=0 ; i<3 ; i++){
        total = 0;
        for(int j = 0; j < 3; j++) { 
            cin >> temperature[i][j]; 
            total = total + temperature[i][j]; 
        } 

        avg = total / 3.0;  

        if(avg > maxAvg) {
            maxAvg = avg;         
            highestAvgFloor = i;  
        }
    }   
    
    
    for(int i=0 ; i<4 ; i++){
        if(i==0){
            cout<<"              ";
            continue;
        }
        cout<<" "<<"Room"<<i<<"   ";
    }
    cout<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<"Floor  "<<i+1<<"    :  ";
        for(int j=0 ; j<3 ; j++){
            cout<<temperature[i][j]<<"     ";
        }
        cout<<endl;
    }
    
    double max = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;
    
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(max < temperature[i][j]){
                max = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }
        }
    }
    cout<<endl;
    cout<<"Hottest Room  : Floor "<<hottestFloor+1<<", Room "<<hottestRoom+1<<"  ->  "<<max<<"C"<<endl;
    cout << "Hottest Floor : Floor "<<highestAvgFloor+1<<" (avg "<<maxAvg <<"C)"<<endl;
    int warningCount=0;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(temperature[i][j]>=30){
            warningCount++;
            }
        }
    }
    cout<<"Rooms at WARNING or above : "<<warningCount<<endl;
    return 0;
        
  




}