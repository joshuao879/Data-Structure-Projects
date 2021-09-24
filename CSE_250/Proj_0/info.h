#include <string>
using namespace std;

class Info {

public:
    Info(int a);
    int getAge();
    int getSalary();
    int raiseSalary(int num);
    string getName();
    int getID(); 

private:
    int age;
    int salary;
    string name;
    int ID; 
};