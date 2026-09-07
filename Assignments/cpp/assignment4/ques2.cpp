#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg,const string& owner,int year,double km) {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;
        cout << "[Vehicle Constructor] "<< registrationNo << endl;
    }
    virtual double fuelCost(double kmToTravel) const = 0;
    virtual void describe() const {
        cout << "Registration: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }
    virtual string vehicleType() const = 0;
    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] "<< registrationNo << endl;
    }
    double getKmDriven() const {
        return kmDriven;
    }
    string getRegNo() const {
        return registrationNo;
    }
    string getOwnerName() const {
        return ownerName;
    }
};
class Car : public Vehicle {
private:
    string fuelType;
    double mileageKmpl;
public:
    Car(const string& reg,const string& owner,int year,double km,const string& fuel,double mileage): Vehicle(reg, owner, year, km),fuelType(fuel),mileageKmpl(mileage) {
        cout << "[Car Constructor] "<< registrationNo << endl;
    }
    double fuelCost(double kmToTravel) const override {
        double price;
        if (fuelType == "Petrol")
            price = 106.00;
        else
            price = 93.00;
        return (kmToTravel / mileageKmpl) * price;
    }

    string vehicleType() const override {
        return "Car";
    }

    void describe() const override {
        Vehicle::describe();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }
    ~Car() {
        cout << "[Car Destructor] "<< registrationNo << endl;
    }
};
class Truck : public Vehicle {
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg,const string& owner,int year,double km,double payload,double efficiency): Vehicle(reg, owner, year, km),payloadCapacityTons(payload),fuelEfficiencyKmpl(efficiency) {
        cout << "[Truck Constructor] "<< registrationNo << endl;
    }
    double fuelCost(double kmToTravel) const override {
        double efficiency =fuelEfficiencyKmpl *(1 - 0.05 * payloadCapacityTons);
        return (kmToTravel / efficiency) * 93.00;
    }
    string vehicleType() const override {
        return "Truck";
    }
    void describe() const override {
        Vehicle::describe();
        cout << "Payload: "<< payloadCapacityTons << " tons" << endl;
        cout << "Fuel Efficiency: "<< fuelEfficiencyKmpl << " km/l" << endl;
    }
    ~Truck() {
        cout << "[Truck Destructor] "<< registrationNo << endl;
    }
};

class ElectricTruck : public Truck {
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;
    double batteryPercent;

public:
    ElectricTruck(const string& reg,const string& owner,int year,double km,double payload,double efficiency,double battery,double range,double batteryStatus): Truck(reg, owner, year, km,payload, efficiency),batteryCapacityKWh(battery),rangePerChargeKm(range),batteryPercent(batteryStatus) {
        cout << "[ElectricTruck Constructor] "<< registrationNo << endl;
    }
    double fuelCost(double kmToTravel) const override {
        return (kmToTravel / rangePerChargeKm)* batteryCapacityKWh * 9.50;
    }
    string vehicleType() const override {
        return "Electric Truck";
    }
    void describe() const override {
        Truck::describe();
        cout << "Battery Capacity: "<< batteryCapacityKWh << " kWh" << endl;
        cout << "Range: "<< rangePerChargeKm << " km" << endl;
        cout << "Battery: "<< batteryPercent << "% charged" << endl;
    }
    double getBatteryPercent() const {
        return batteryPercent;
    }
    ~ElectricTruck() {
        cout << "[ElectricTruck Destructor] "<< registrationNo << endl;
    }
};

class Van : public Vehicle {
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg,const string& owner,int year,double km,int seats,double mileage): Vehicle(reg, owner, year, km),seatingCapacity(seats),mileageKmpl(mileage) {
        cout << "[Van Constructor] "<< registrationNo << endl;
    }
    double fuelCost(double kmToTravel) const override {
        return (kmToTravel / mileageKmpl) * 106.00;
    }
    string vehicleType() const override {
        return "Van";
    }
    void describe() const override {
        Vehicle::describe();
        cout << "Seats: "<< seatingCapacity << endl;
        cout << "Mileage: "<< mileageKmpl << " km/l" << endl;
    }
    ~Van() {
        cout << "[Van Destructor] "<< registrationNo << endl;
    }
};
void printFleetReport(
    const vector<Vehicle*>& fleet,
    double tripKm) {
    cout << "\n===== FLEET REPORT =====" << endl;
    cout << left<< setw(15) << "Reg"<< setw(20) << "Type"<< setw(20) << "Owner"<< setw(15) << "KM Driven"<< endl;
    double minimumCost = 1e9;
    Vehicle* mostEfficient = nullptr;
    for (Vehicle* v : fleet) {
        double cost = v->fuelCost(tripKm);
        cout << left<< setw(15) << v->getRegNo()<< setw(20) << v->vehicleType()<< setw(20) << v->getOwnerName()<< setw(15) << v->getKmDriven()<< endl;
        if (cost < minimumCost) {
            minimumCost = cost;
            mostEfficient = v;
        }
    }
    cout << "\n===== FUEL / CHARGE COST ESTIMATE ====="<< endl;
    for (Vehicle* v : fleet) {
        cout << v->getRegNo()<< " (" << v->vehicleType()<< ") : Rs. "<< fixed << setprecision(2)<< v->fuelCost(tripKm);
        ElectricTruck* electric = dynamic_cast<ElectricTruck*>(v);
        if (electric != nullptr) {
            cout << " [Battery: "<< electric->getBatteryPercent()<< " % charged]";
        }
        cout << endl;
    }
    cout << "\nMost Efficient Vehicle: "<< mostEfficient->getRegNo()<< " (" << mostEfficient->vehicleType()<< ") - Rs. "<< fixed << setprecision(2)<< minimumCost<< " for " << tripKm<< " km" << endl;
}
int main() {
    {
        ElectricTruck et("V-ET001","Green Logistics",2024,89000,10,5,85,400,85);
        cout << "...scope ends..." << endl;
    }
    vector<Vehicle*> fleet;
    fleet.push_back(
        new Car("KA01AA001","Ramesh Kumar",2022,45200,"Petrol",18));
    fleet.push_back(
        new Truck("MH04BB002","Shyam Logistics",2020,123500,8,5));
    fleet.push_back(
        new ElectricTruck("GJ07CC003","Green Fleet Co", 2024,89000,5,4,85,400,85));
    fleet.push_back(
        new Van("DL05DD004","City Transport",2021,67000,8,15 ));
    fleet.push_back(
        new Car("MP09EE005","Amit Sharma",2023,30000,"Diesel",20));
    printFleetReport(fleet, 200);
    for (Vehicle* v : fleet){
        delete v;
    }
    return 0;
}