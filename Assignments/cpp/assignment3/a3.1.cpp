#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer {
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

public:
    LogBuffer(int capacity) {
        this->capacity = capacity;
        this->buffer = new char[capacity];
        this->size = 0;

        buffer[0] = '\0';

        instanceCount++;

        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }
    LogBuffer(const LogBuffer& other) {
        capacity = other.capacity;
        size = other.size;

        buffer = new char[capacity];

        strcpy(buffer, other.buffer);

        instanceCount++;

        cout << "[LogBuffer Copied]" << endl;
    }
    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            return *this;
        }
        delete[] buffer;
        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        strcpy(buffer, other.buffer);

        return *this;
    }
    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;

        cout << "[LogBuffer Destroyed]" << endl;
    }
    void append(const char* msg) {

        int msgLength = strlen(msg);
        int available = capacity - size - 1;
        if (msgLength > available) {
            msgLength = available;
        }
        for (int i = 0; i < msgLength; i++) {
            buffer[size + i] = msg[i];
        }
        size += msgLength;
        buffer[size] = '\0';
    }
    void print() const {
        cout << buffer << endl;
    }
    void clear() {
        size = 0;
        buffer[0] = '\0';
    }
    static int getInstanceCount() {
        return instanceCount;
    }
};
int LogBuffer::instanceCount = 0;

int main() {

    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");

    log1.print();
    LogBuffer log2 = log1;
    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();
    cout << "log2 : ";
    log2.print();

    LogBuffer log3(128);
    log3 = log1;
    cout << "log3 : ";
    log3.print();
    log1 = log1;

    cout << "After self assignment:" << endl;
    log1.print();

    cout << "Live LogBuffer objects : "<< LogBuffer::getInstanceCount() << endl;
    return 0;
}