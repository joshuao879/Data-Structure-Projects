#include <iostream>
#include "info.h" 
using namespace std; 

void Print();
int main() {
    // int age;
    // int salary;
    // string name;
    // int ID; 

    Info urmom(10);
    int age = urmom.getAge();
    cout << "Age: " << age << endl; 

    Print();

// cout << "Enter info for two teachers" << endl; 
// for (int i = 0; i < 2; i++) {
//     cin >> age >> salary >> name >> ID; 
// }

return 0; 
}

