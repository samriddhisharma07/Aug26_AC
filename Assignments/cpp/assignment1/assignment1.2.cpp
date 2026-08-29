#include <iostream>
using namespace std;

void countNumber(double reading[], int size) {
    int ncount = 0;
    int wcount = 0;
    int ccount = 0;
    int scount = 0;

    for (int i = 0; i < size; i++) {
        if (reading[i] < 0) {
            continue;
        }
        if (reading[i] >= 0 && reading[i] <= 29.0) {
            ncount++;
        }
        else if (reading[i] >= 30.0 && reading[i] <= 44.0) {
            wcount++;
        }
        else if (reading[i] >= 45.0 && reading[i] <= 59.0) {
            ccount++;
        }
        else {
            scount++;
        }
    }

    cout << "Normal:" << ncount << " Warning:" << wcount<< " Critical:" << ccount << " Shutdown:" << scount << endl;
}

int main() {
    int count = 0;
    int size = 0;

    cin >> size;

    double reading[size];
    double totalEntered = size;

    for (int i = 0; i < size; i++) {
        cin >> reading[i];
        if (reading[i] < 0) {
            count++;
            continue;
        }
    }

    cout << "Readings entered   :  " << totalEntered << endl;

    cout << "Valid readings     :  ";
    for (int i = 0; i < size; i++) {
        if (reading[i] < 0) {
            continue;
        }
        cout << reading[i] << "  ";
    }
    cout << endl;

    cout << "Skipped (errors)   :  " << count << endl;
    cout << endl;

    double min = reading[0];
    double max = reading[0];
    double total = 0;
    double validCount = 0;

    for (int i = 0; i < size; i++) {
        if (reading[i] >= 0) {
            total = total + reading[i];
            validCount++;

            if (min > reading[i]) {
                min = reading[i];
            }
            if (max < reading[i]) {
                max = reading[i];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (reading[i] >= 45) {
            cout << "First CRITICAL     :  Index  " << i<< "   ->   " << reading[i] << endl;
            break;
        }
    }

    cout << endl;
    cout << "Min : " << min << "C" << "    Max : " << max << "C" << "    Avg : " << total / validCount << "C" << endl;
    cout << endl;

    countNumber(reading, size);
    cout << endl;

    return 0;
}


