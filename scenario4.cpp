/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<iomanip>
#include"scenario4.h"
using namespace std;
int main() {
    const string fn = "EmployeeData.txt";
    const int maxemp = 10;
    Employee emp[maxemp];
    int num_emp;
    int totalComp, swaps;

    empData(fn, emp, num_emp);

    double start = static_cast<double>(clock()); // Start time

    bubbleSort(emp, num_emp, totalComp, swaps);

    double stop = static_cast<double>(clock()); // Stop time
    double duration = (stop - start) / CLOCKS_PER_SEC * 1000.0; // Calculate duration in milliseconds

    cout << "Sorted emp by Salary:" << endl;
    for (int i = 0; i < num_emp; i++) {
        cout << "Employee Name: " << emp[i].name << " - Salary: $" << emp[i].salary << setprecision(3) << fixed << endl;
    }

    cout << "Number of totalComp: " << totalComp << endl;
    cout << "Number of Swaps: " << swaps << endl;

    cout << "Execution Time: " << duration << " milliseconds" << endl;

    return 0;
}
