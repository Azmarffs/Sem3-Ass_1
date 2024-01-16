/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include"scenario5.h"
int main() {
    const string filename = "EmployeeData.txt";
    const int maxEmployees = 10;
    Employee employees[maxEmployees];
    int numEmployees;
    int comparisons, swaps;

    readEmployeeData(filename, employees, numEmployees);

    // Measure execution time without clock_t
    double startTime = static_cast<double>(clock()); // Start time

    bubbleSort(employees, numEmployees, comparisons, swaps);

    double stopTime = static_cast<double>(clock()); // Stop time
    double duration = (stopTime - startTime) / CLOCKS_PER_SEC * 1000.0; // Calculate duration in milliseconds

    cout << "Sorted Employees by Tenure (Years of Service):" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << "Employee Name: " << employees[i].name << " - Tenure: " << employees[i].tenure << " years" << endl;
    }

    cout << "Number of Comparisons: " << comparisons << endl;
    cout << "Number of Swaps: " << swaps << endl;

    cout << "Execution Time: " << fixed << setprecision(2) << duration << " milliseconds" << endl;

    return 0;
}
