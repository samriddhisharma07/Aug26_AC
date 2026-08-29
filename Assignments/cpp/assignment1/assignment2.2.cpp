#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* signal, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        double val = *(signal + i);
        sum = sum + (val * val);
    }
    double avg = sum / n;
    return sqrt(avg);
}

void normalise(double* signal, int n){
    double maxVal = fabs(*signal);
    for(int i = 1; i < n; i++){
        double val = fabs(*(signal + i));
        if(val > maxVal){
            maxVal = val;
        }
    }
    for(int i = 0; i < n; i++){
        *(signal + i) = *(signal + i) / maxVal;
    }
}

int countZeroCrossings(double* signal, int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        double curr = *(signal + i);
        double next = *(signal + i + 1);
        if((curr > 0 && next < 0) || (curr < 0 && next > 0)){
            count++;
        }
    }
    return count;
}
void applyGain(double* signal, int n, double gainFactor){
    for(int i = 0; i < n; i++){
        *(signal + i) = *(signal + i) * gainFactor;
    }
}
void printArray(double* signal, int n){
    for(int i = 0; i < n; i++){
        cout << *(signal + i) << " ";
    }
    cout << endl;
}

int main(){
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n = 7;

    cout << "Original signal: ";
    printArray(signal, n);

    cout << "RMS value: " << computeRMS(signal, n) << endl;
    cout << "Zero crossings: " << countZeroCrossings(signal, n) << endl;

    normalise(signal, n);
    cout << "After normalise: ";
    printArray(signal, n);

    applyGain(signal, n, 2.0);
    cout << "After applyGain(2.0): ";
    printArray(signal, n);

    return 0;
}