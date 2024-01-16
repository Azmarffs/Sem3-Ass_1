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
using namespace std;

// Structure to store employee data
struct Employee {
    string name;
    double salary;
};

// Function to read employee data from file
void empData(const string& fn, Employee emp[], int& num_emp) { // Pass by reference to avoid copying
    ifstream inputFile(fn); // Open the file
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    num_emp = 0;
    string line;
    string currentName;
    double currentSalary;

    while (getline(inputFile, line)) {
        if (line.find("Employee Name:") != string::npos) {
            // Parse employee name
            currentName = line.substr(line.find(":") + 2); // Extract the name string
        }
        else if (line.find("Salary:") != string::npos) {
            // Parse employee salary from the line
            size_t salaryPos = line.find("$");
            if (salaryPos != string::npos) { // Check if the line contains the salary
                string salaryStr = line.substr(salaryPos + 1); // Extract the salary string
                currentSalary = stod(salaryStr); // Convert the salary string to a double
                emp[num_emp].name = currentName; // Assign the name to the current employee
                emp[num_emp].salary = currentSalary; // Assign the salary to the current employee
                num_emp++;
            }
        }
    }

    inputFile.close();
}

// Function to perform Bubble Sort on emp based on salary
void bubbleSort(Employee emp[], int num_emp, int& totalComp, int& swaps) { // Pass by reference to avoid copying
    totalComp = 0;
    swaps = 0;
    bool swapped;

    for (int i = 0; i < num_emp - 1; i++) { // Iterate over each element
        swapped = false; // Reset the swapped flag

        for (int j = 0; j < num_emp - i - 1; j++) {
            totalComp++; // Increment the total number of comparisons
            if (emp[j].salary > emp[j + 1].salary) { // Check if the current element is greater than the next element
                swap(emp[j], emp[j + 1]); // Swap the current element with the next element
                swapped = true; // Set the swapped flag
                swaps++; // Increment the number of swaps
            }
        }

        if (!swapped) { // Check if no swaps were performed in the last iteration
            break; // Break out of the loop
        }
    }
}
