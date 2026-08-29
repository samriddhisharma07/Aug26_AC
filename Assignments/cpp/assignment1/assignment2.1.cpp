#include <iostream>
using namespace std;
void resetSensorPairV1(int reading1, int reading2){
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}
void resetSensorPairV2(int& reading1, int& reading2){
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;

}
void resetSensorPairV3(int* reading1, int* reading2){
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;

}
int main(){
    int reading1 = 55;
    int reading2 = 12;

    cout<<"--- V1: Call by Value ---"<<endl;
    cout<<"Before : A = "<<reading1<<"  B = "<<reading2<<endl;
    resetSensorPairV1(reading1,reading2);
    cout<<"After  : A = "<<reading1<<"  B = "<<reading2<<"     <- values unchanged"<<endl;
    cout<<endl;
   

    cout<<"--- V2: Call by Reference ---"<<endl;
    cout<<"Before : A = "<<reading1<<"  B = "<<reading2<<endl;
    resetSensorPairV2(reading1,reading2);
    cout<<"After  : A = "<<reading1<<"  B = "<<reading2<<"     <- values swapped"<<endl;
    cout<<endl;
    

    cout<<"--- V3: Call by Pointer ---"<<endl;
    cout<<"Before : A = "<<reading1<<"  B = "<<reading2<<endl;
    resetSensorPairV3(&reading1,&reading2);
    cout<<"After  : A = "<<reading1<<"  B = "<<reading2<<"     <- values swapped back"<<endl;
    cout<<endl;


     /*
     * Why V1 fails:
     * V1 uses call-by-value, so the function receives COPIES of reading1
     * and reading2, not the original variables from main(). The swap
     * happens only on these local copies inside the function. Once the
     * function returns, these copies are destroyed, and the original
     * variables in main() remain completely unaffected.
     */


    return 0;



}