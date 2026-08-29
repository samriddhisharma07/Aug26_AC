#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size, int** outMin, int** outMax){
    if(size <= 0){
        return false;
    }

    const int* minElement = rawData;
    const int* maxElement = rawData;

    for(int i = 1; i < size; i++){
        if(*(rawData + i) < *minElement){
            minElement = rawData + i;
        }
        if(*(rawData + i) > *maxElement){
            maxElement = rawData + i;
        }
    }

    *outMin = (int*)minElement;
    *outMax = (int*)maxElement;

    return true;
}

int main(){
    int packet[] = {45, 12, 67, 8, 55, 31};
    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if(parsePacket(packet, 6, &minPtr, &maxPtr)){
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}