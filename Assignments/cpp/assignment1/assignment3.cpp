#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Employee{
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;
    static int nextId;

public:

    Employee(){
        empId = nextId;
        nextId++;
        isActive = true;
        employeeCount++;
        basicSalary = 0;
        grade = '\0';
    }
    void setName(const string &n){
        if(n.empty()){
            cout<<"Error! Name cannot be empty"<<endl;
        }else{
            name = n;
            cout<<"Name: "<<n<<endl;
        }
    }
    void setDepartment(const string &dept){
        if(dept == "Engineering"){
            department = dept;
        }else if(dept == "HR"){
            department = dept;
        }else if(dept == "Finance"){
            department = dept;
        }else if(dept == "Operations"){
            department = dept;
        }else{
            cout<<"ERROR: '"<<dept<<"' is not a registered department."<<endl;
        }    
    }
    void setGrade(char g){
        switch(g){
        case 'A' :
                grade = g;
                break;
        case 'B' :
                grade = g;
                break;
        case 'C' :
                grade = g;
                break;
        case 'D' :
                grade = g;
                break;
        default : 
                cout<<"ERROR: Invalid grade '"<<g<<"'. Accepted values: A, B, C, D."<<endl;
        }
    }
    void setBasicSalary(double salary){
        if(salary>10000 && salary<500000){
            basicSalary = salary;
            cout<<"Salary: "<<salary<<endl;
        }
        else{
            cout<<"ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."<<endl;
        }
    }
    void deactivate(){
        isActive = false;
    }

    int getEmpId() const{
        return empId;
    }        
    string getName() const{
        return name;
    }
    string getDepartment() const{
        return department;
    }
    char getGrade() const{
        return grade;
    }
    double getBasicSalary() const{
        return basicSalary;
    }
    bool getIsActive() const{
        return isActive;
    }
    

    double computeAllowances() const{
        if(grade=='A'){
            double rel = (basicSalary*40)/100;
            return rel;
        }
        else if(grade == 'B'){
            double rel = (basicSalary*30)/100;
            return rel;
        }
        else if(grade == 'C'){
            double rel = (basicSalary*20)/100;
            return rel;
        }
        else if(grade == 'D'){
            double rel = (basicSalary*10)/100;
            return rel;
        }
        else{
            return 0;
        }
        
    }

    double computeGrossSalary() const{
        double grossSalary = basicSalary + computeAllowances();
        return grossSalary;
    
    }
    double computeTax() const{
        double gross = computeGrossSalary();
        double tax;
        if(gross<=50000){
            tax = 0;
            return tax;
        }
        else if(gross>=50001 && gross<=100000){
            tax = (gross - 50000) * 10.0 / 100 ;
            return tax;
        }
        else if(gross > 100000){
            tax = 5000 + (gross - 100000) * 20.0 / 100;
            return tax;
        }
        else{
            return 0;
        }
    }
    double computeNetSalary() const{
        double netSalary = computeGrossSalary() - computeTax();
        return netSalary;
    }
    void acceptDetails(){
        string n , dept;
        char g ;
        double salary;

        cout<<"Enter name: ";
        getline(cin >> ws , n);
        setName(n);

        cout << "Enter department: ";
        cin >> dept;
        setDepartment(dept);

        cout << "Enter grade: ";
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> salary;
        setBasicSalary(salary);
    }
    void printPayslip() const{
        cout<<"============================================"<<endl;
        cout<<"        EMPLOYEE PAYSLIP - AUG 2026         "<<endl;
        cout<<"============================================"<<endl;
        cout<<"Emp ID      : "<<getEmpId()<<endl;
        cout<<"Name        :  "<< getName() << endl;
        cout<<"Department  : "<< getDepartment() << endl;
        cout<<"Grade       : "<< getGrade() << endl;
        cout<<"Status      : "<< (getIsActive() ? "Active" : "Inactive")<< endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Basic Salary     : "<<"Rs. "<<getBasicSalary()<<endl;
        int pct = (grade=='A')?40:(grade=='B')?30:(grade=='C')?20:(grade=='D')?10:0;
        cout<<"Allowances ("<<pct<<"%) : "<<"Rs. "<<computeAllowances()<<endl;
        cout<<"Gross Salary     : "<<"Rs. "<<computeGrossSalary()<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Tax Deduction    : "<<"Rs. "<<computeTax()<<endl;
        cout<<"Net Salary       : "<<"Rs. "<<computeNetSalary()<<endl;
        cout<<"============================================="<<endl;
    }
    static int getEmployeeCount(){
        return employeeCount;
    }
};
int Employee::nextId = 1001;
int Employee::employeeCount=0;

struct Layout1 { char c1; int i; char c2; };
struct Layout2 { int i; char c1; char c2; };

int main(){
    cout << fixed << setprecision(2);

    Employee e1;
    Employee *e2 = new Employee();
    Employee *e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    //e1.empId = 999;               //empId is private so it cannot be accessed directly from main()
                                    //Therefore e1.empId = 999; gives a **private access error**.


    //e1.basicSalary = -1000;       //e1.basicSalary = -1000; gives the same private access error.
                                    //basicSalary is a private data member, so main() cannot access or modify it directly.
                                    //Therefore e1.basicSalary = -1000; is not allowed

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();
    if(!e3->getIsActive()){
        cout << e3->getName()<< " is no longer active. Payroll skipped." << endl;
    }

    cout<<"Total employees : "<<Employee::getEmployeeCount()<<endl;

    delete e2;
    delete e3;

    cout << "\nsizeof(Layout1) = " << sizeof(Layout1) << " bytes" << endl;
    cout << "sizeof(Layout2) = " << sizeof(Layout2) << " bytes" << endl;

        // ---- Bonus: Struct Padding ----

    cout << "\nsizeof(Layout1) = " << sizeof(Layout1) << " bytes" << endl;
    cout << "sizeof(Layout2) = " << sizeof(Layout2) << " bytes" << endl;

       /*
     * 1. Sizes differ: Layout1 = 12 bytes, Layout2 = 8 bytes — same members,
     *    different order, so different amount of padding is needed.
     *
     * 2. Padding = extra unused bytes the compiler inserts between/after
     *    members so each member starts at an address that is a multiple of
     *    its own size (alignment). E.g. an int must start at a 4-byte
     *    boundary. Compiler adds this because misaligned memory access is
     *    slower (or unsupported) on many CPUs.
     *    - Layout1 (char, int, char): 3 bytes padding after c1 (to align
     *      int at address 4), + 3 bytes padding at the end (to make total
     *      size a multiple of 4) = 12 bytes.
     *    - Layout2 (int, char, char): int already aligned, both chars fit
     *      right after with no gap, only 2 bytes padding at the end = 8 bytes.
     *
     * 3. In network packet headers / hardware register maps, the byte
     *    layout must exactly match the protocol/hardware spec — no hidden
     *    gaps allowed. Compiler-inserted padding would shift field offsets,
     *    causing wrong bytes to be read/written. So members are ordered
     *    largest-to-smallest to minimize padding, or #pragma pack(1) /
     *    __attribute__((packed)) is used to force zero padding.
     */

    return 0;

}