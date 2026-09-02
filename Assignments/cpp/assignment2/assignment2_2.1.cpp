#include <iostream>
#include<string>
using namespace std;
class Patient{
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;
    static int pId;
public:
    Patient() : patientId(0) , name("Unknown") , age(0) , ward("General") ,bloodGroup("O+") {
        patientId = ++pId;
        //pId++;
        cout << "[Constructor] Default patient registered." << endl;
    }
    Patient(int id , const string&name) : patientId(id), name(name), age(0), ward("General"), bloodGroup("O+"){
        this->patientId = id;
        this->name = name;
        cout << "[Constructor] Emergency: " << name << endl;
    }
    Patient(int id , const string &name , int age , const string& ward , const string &bg) : patientId(id), name(name), age(age), ward(ward), bloodGroup(bg){

        cout << "[Constructor] Full admission: " << name << endl;
    }
    ~Patient(){
        
        cout << "[Destructor] Patient " << name << " discharged." << endl; 
    
    }
    void takeRecord(){
        cout<<"enter name: "<<endl;
        getline(cin, name);
        setName(name);
        cout<<endl;
        cout<<"enter age: "<<endl;
        cin>>age;
        setAge(age);
        cout<<endl;
        cout<<"enter ward"<<endl;
        cin>>ward;
        setWard(ward);

        cin.ignore();

    }
    void displayRecord() const{
        cout<<"-----------Patient Record-------------"<<endl;
        cout<<"Id   : "<<getpatientId()<<endl;  //inside const non const are not called
        cout<<"Name : "<<getName()<<endl;
        cout<<"Age  : "<<getAge()<<endl;
        cout<<"Ward : "<<getWard()<<endl;
        cout<<"Blood Grp : "<<getbloodGroup()<<endl;

        
    }
    void setName(string const &name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setWard(string const& ward){
        this->ward = ward;
    }
    int getAge() const{
        return age;
    }
    string getbloodGroup()const{
        return bloodGroup;
    }
    string getWard() const{
        return ward;
    }
    string getName() const{
        return name;
    }
    
    int getpatientId()const{
        return patientId;
    }
    void transferWard(const string& newWard){
    cout << "Ward Transfer: " << name << " -> " << newWard << endl;
    ward = newWard;
    }

};
int Patient::pId = 00;
int main(){

   
    //cout<<p1.getpatientId()<<endl;       //Patient::getpatientId() → for static function 
                                        // p1.getpatientId() → for normal member function 
                                        // ::getpatientId() → for global function 
    Patient p3(1002, "Raj Patel");
    Patient p2(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p1;
    Patient p1b;
    Patient *p = new Patient[4];
    for(int i=0 ; i<4 ; i++){
        p[i].takeRecord();
    }
    for(int i=0 ; i<4 ; i++){
        p[i].displayRecord();
        
    }
    p2.transferWard("ICU");
    p2.displayRecord();
    delete[] p;
    return 0;

}