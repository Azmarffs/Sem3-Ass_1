/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include"scenario3.h"
int main() {
    ifstream inputFile("Employeedata.txt");  // Replace with the actual file name

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    int numEmployees = 0;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.find("Name:") != string::npos) {
            numEmployees++;
        }
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    Employee* employees = new Employee[numEmployees];

    int index = 0;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.find("Name:") != string::npos) {
            employees[index].name = line.substr(line.find(":") + 2);
        } else if (line.find("Employee ID:") != string::npos) {
            employees[index].employeeID = line.substr(line.find(":") + 2);
        } else if (line.find("Salary: $") != string::npos) {
            employees[index].salary = stod(line.substr(line.find("$") + 1));
        } else if (line.find("Date of Joining:") != string::npos) {
            employees[index].dateOfJoining = line.substr(line.find(":") + 2);
        } else if (line.find("Designation:") != string::npos) {
            employees[index].designation = line.substr(line.find(":") + 2);
            index++;
        }
    }

    calcAvgTenure(employees, numEmployees);
    calcAvgTenureForAllEmployees(employees, numEmployees);
    calcEmployeeWithTheLongestTenure(employees, numEmployees);
    calcEmployeeWithTheShortestTenure(employees, numEmployees);
    calcHighestPayingDesignation(employees, numEmployees);
    delete[] employees;
    employees = nullptr;

    return 0;
}
