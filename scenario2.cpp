/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include"scenario2.h"
int main() {
    const int numEmployees = 10;
    Employee employees[numEmployees];

    // Read employee data from the file
    readEmployeeData("Employeedata.txt", employees, numEmployees);

    // Calculate and report the highest salary
    double salaries[numEmployees];
    for (int i = 0; i < numEmployees; ++i) {
        salaries[i] = employees[i].salary;
    }

    double highestSalary = findHighestSalary(salaries, numEmployees);
    cout << "The highest salary among all employees: $"  << highestSalary << endl;

    // Calculate and report the lowest salary
    double lowestSalary = findLowestSalary(salaries, numEmployees);
    cout << "The lowest salary among all employees: $"  << lowestSalary << endl;

    // Calculate and report the median salary
    double medianSalary = calculateMedianSalary(salaries, numEmployees);
    cout << "The median salary among all employees: $"  << medianSalary << endl;

    // Calculate and report the average salary by designation
    calculateAverageSalaryByDesignation(employees, numEmployees);

    // Find and report the name of the employee with the highest salary 
    string highestSalaryEmployee = findEmployeeWithHighestSalary(employees, numEmployees);
    cout << "Employee with the highest salary: " << highestSalaryEmployee << endl;

    return 0;
}
