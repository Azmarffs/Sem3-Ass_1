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

using namespace std;

// Structure to store employee data
struct Employee {
    string name;
    double salary;
    string dateOfJoining;
    int tenure; // Years of service
};

// Function to read employee data from file
void readEmployeeData(const string& filename, Employee employees[], int& numEmployees) { // Pass by reference to avoid copying
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    numEmployees = 0;
    string line;
    string currentName;
    double currentSalary;
    string currentDateOfJoining;

    while (getline(inputFile, line)) {
        if (line.find("Employee Name:") != string::npos) { // Check if the line contains the employee name
            // Parse employee name
            currentName = line.substr(line.find(":") + 2); // Extract the name string
        }
        else if (line.find("Salary:") != string::npos) { // Check if the line contains the salary
            // Parse employee salary from the line
            size_t salaryPos = line.find("$"); // Find the position of the dollar sign
            if (salaryPos != string::npos) {
                string salaryStr = line.substr(salaryPos + 1);
                currentSalary = stod(salaryStr);
            }
        }
        else if (line.find("Date of Joining:") != string::npos) { // Check if the line contains the date of joining
            // Parse date of joining
            currentDateOfJoining = line.substr(line.find(":") + 2); // Extract the date of joining string

            // Calculate tenure (years of service) for the employee
            string currentYear = currentDateOfJoining.substr(0, 4); // Extract the year from the date of joining string
            int year = stoi(currentYear); // Convert the year string to an integer
            time_t currentTime;
            time(&currentTime); // Get the current time
            tm* currentTimeStruct = localtime(&currentTime); // Convert the current time to the local time
            int currentYearNumber = currentTimeStruct->tm_year + 1900; // Get the current year

            employees[numEmployees].name = currentName; // Assign the name to the current employee
            employees[numEmployees].salary = currentSalary;
            employees[numEmployees].dateOfJoining = currentDateOfJoining;
            employees[numEmployees].tenure = currentYearNumber - year;

            numEmployees++;
            currentName.clear();
            currentDateOfJoining.clear();
        }
    }

    inputFile.close();
}

// Function to perform Bubble Sort on employees based on tenure
void bubbleSort(Employee employees[], int numEmployees, int& comparisons, int& swaps) { // Pass by reference to avoid copying
    comparisons = 0;
    swaps = 0;
    bool swapped;

    for (int i = 0; i < numEmployees - 1; i++) { // Iterate over each element
        swapped = false;

        for (int j = 0; j < numEmployees - i - 1; j++) { // Iterate over each element
            comparisons++; // Increment the total number of comparisons
            if (employees[j].tenure > employees[j + 1].tenure) { // Check if the current element is greater than the next element
                swap(employees[j], employees[j + 1]); // Swap the current element with the next element
                swapped = true; // Set the swapped flag
                swaps++; // Increment the number of swaps
            }
        }

        if (!swapped) { // Check if no swaps were made in the last iteration
            break; // Break out of the loop
        }
    }
}
