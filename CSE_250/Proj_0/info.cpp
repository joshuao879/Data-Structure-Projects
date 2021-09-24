#include <iostream>
#include "info.h"

void Print() {
    cout << "hello" << endl; 
}

Info::Info(int a) {
    age = a; 
}

int Info::getAge() {
    Print();
    return age;
}

int Info::getSalary() {
    return salary;
}

int Info::raiseSalary(int num) {
    return salary + num;
}

string Info::getName() {
    return name;
}

int Info::getID() {
    return ID;

}
