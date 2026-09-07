#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>
using namespace std;
class DataProcessor{
public:
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;
    virtual void printSummary() const{
        cout << "Processor: " << processorType()<< ", Records: " << recordCount() << endl;
    }
    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor{
    vector<string> records;
public:
    void loadData(const string& source) override{
        records = {"alice,25,India","bob,30,USA","charlie,28,UK","david,35,Canada","emma,26,Australia"};
    }
    void processData() override{
        for (string& record : records){
            transform(record.begin(),record.end(),record.begin(),[](unsigned char c)
                {
                    return toupper(c);
                }
            );
        }
    }
    void exportResult(const string& destination) override{
        cout << "[CSV EXPORT -> " << destination << "]" << endl;
        for (const string& record : records){
            cout << record << endl;
        }
    }
    string processorType() const override{
        return "CSV Processor";
    }
    int recordCount() const override{
        return records.size();
    }
};

class SensorStreamProcessor : public DataProcessor{
    vector<double> readings;
    double mean = 0;
    double minimum = 0;
    double maximum = 0;
public:
    void loadData(const string& source) override{
        readings = {23.4, 21.8, 25.1, 24.6,22.9, 26.3, 23.8, 24.2};
    }
    void processData() override{
        if (readings.empty()){
            return;
        }
        mean = 0;
        for (double value : readings){
            mean += value;
        }
        mean /= readings.size();
        minimum = *min_element(readings.begin(),readings.end());
        maximum = *max_element(readings.begin(),readings.end());
    }
    void exportResult(const string& destination) override{
        cout << "[SENSOR EXPORT -> "<< destination << "]" << endl;
        cout << fixed << setprecision(2)<< "Mean: " << mean<< ", Min: " << minimum<< ", Max: " << maximum << endl;
    }
    string processorType() const override{
        return "Sensor Stream Processor";
    }
    int recordCount() const override{
        return readings.size();
    }
    void printSummary() const override{
        cout << fixed << setprecision(2)<< "Processor: " << processorType()<< ", Records: " << recordCount()<< ", Mean: " << mean<< ", Min: " << minimum<< ", Max: " << maximum << endl;
    }
    double getMean() const{
        return mean;
    }
};
template <typename T>
class DataBuffer{
    T* data;
    int capacity;
    int head;
    int tail;
    int count;
public:
    DataBuffer(int cap):capacity(cap), head(0), tail(0), count(0){
        if (capacity <= 0){
            throw invalid_argument("Invalid capacity");
        }
        data = new T[capacity];
    }
    ~DataBuffer(){
        delete[] data;
    }
    void push(const T& value){
        data[tail] = value;
        tail = (tail + 1) % capacity;
        if (count < capacity)
        {
            count++;
        }
        else
        {
            head = (head + 1) % capacity;
        }
    }
    T pop(){
        if (isEmpty())
            throw underflow_error("Buffer is empty");
        T value = data[head];
        head = (head + 1) % capacity;
        count--;
        return value;
    }
    T peek() const{
        if (isEmpty())
            throw underflow_error("Buffer is empty");

        return data[head];
    }
    bool isEmpty() const{
        return count == 0;
    }
    bool isFull() const{
        return count == capacity;
    }
    int size() const{
        return count;
    }
    template <typename U>
    friend ostream& operator<<(
        ostream& out,
        const DataBuffer<U>& buf
    );
};
template <typename U>
ostream& operator<<(ostream& out,const DataBuffer<U>& buf){
    out << "[";
    for (int i = 0; i < buf.count; i++){
        int index =(buf.head + i) % buf.capacity;
        out << buf.data[index];
        if (i < buf.count - 1){
            out << ", ";
        }
    }
    out << "]";
    return out;
}

int main(){
    vector<DataProcessor*> pipeline;
    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());
    for (auto* p : pipeline){
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout << "---" << endl;
    }
    DataBuffer<int> tickBuffer(5);
    for (int i = 1; i <= 7; i++){
        tickBuffer.push(i * 10);
    }
    cout << "Tick Buffer: "<< tickBuffer << endl;
    DataBuffer<double> tempBuffer(4);
    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);
    cout << "Before pop: "<< tempBuffer << endl;
    cout << "Popped: "<< tempBuffer.pop() << endl;
    cout << "After pop: "<< tempBuffer << endl;
    DataBuffer<string> logBuffer(3);
    logBuffer.push("INFO: Server started");
    logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout");
    logBuffer.push("INFO: Retry successful");
    cout << "Log Buffer: "<< logBuffer << endl;
    for (auto* p : pipeline){
        if (auto* csv =
            dynamic_cast<CSVProcessor*>(p)){
            cout << "Found CSV Processor with "<< csv->recordCount()<< " records." << endl;
        }
        else if (auto* sensor =
                dynamic_cast<SensorStreamProcessor*>(p)){
            cout << "Found Sensor Processor - Mean: "<< sensor->getMean()<< endl;
        }
    }
    for (auto* p : pipeline){
        delete p;
    }
    return 0;
}
