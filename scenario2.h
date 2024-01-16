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

using namespace std;

// Define a struct to represent an employee
struct Employee {
    string name;
    string employeeID;
    double salary;
    string dateOfJoining;
    string designation;
};

// Function to read employee data from a file and store it in an array
void readEmployeeData(const string& filename, Employee* employees, int size) { // Pass by reference to avoid copying
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) { // Read data for each employee
        getline(inputFile, employees[i].name); // Read the name
        getline(inputFile, employees[i].employeeID); // Read the employee ID

        // Read the salary, handling the currency symbol and commas
        string salaryStr;
        getline(inputFile, salaryStr); // Read the salary string

        // Remove commas from the salary string
        string cleanedSalaryStr; // Create a new string to store the cleaned salary string
        for (char c : salaryStr) { // Iterate over each character in the salary string
            if (c != ',') {
                cleanedSalaryStr += c;
            }
        }

        // Extract the salary value
        size_t dollarSignPos = cleanedSalaryStr.find('$'); // Find the position of the dollar sign
        employees[i].salary = stod(cleanedSalaryStr.substr(dollarSignPos + 1)); // Extract the salary value

        getline(inputFile, employees[i].dateOfJoining); // Read the date of joining
        getline(inputFile, employees[i].designation); // Read the designation

        // Skip the empty line between employees
        if (i < size - 1) { // Check if this is not the last employee
            string emptyLine;
            getline(inputFile, emptyLine); // Read the empty line
        }
    }

    inputFile.close();
}

// Function to find the highest salary among employees
template <typename T>
T findHighestSalary(const T* values, int size) { // Pass by reference to avoid copying
    T highest = values[0]; // Initialize the highest salary to the first employee's salary
    for (int i = 1; i < size; ++i) { // Iterate over the remaining employees
        if (values[i] > highest) { // Check if the current employee has the highest salary
            highest = values[i]; // Update the highest salary
        }
    }
    return highest;
}

// Function to find the lowest salary among employees
template <typename T>
T findLowestSalary(const T* values, int size) { // Pass by reference to avoid copying
    T lowest = values[0]; // Initialize the lowest salary to the first employee's salary
    for (int i = 1; i < size; ++i) { // Iterate over the remaining employees
        if (values[i] < lowest) { // Check if the current employee has the lowest salary
            lowest = values[i]; // Update the lowest salary
        }
    }
    return lowest;
}

// Function to calculate the median salary among employees
double calculateMedianSalary(double* values, int size) { // Pass by reference to avoid copying
    // Manual sorting (you can use any sorting algorithm)
    for (int i = 0; i < size - 1; ++i) { // Iterate over each element
        for (int j = 0; j < size - i - 1; ++j) { // Iterate over each element except the last i elements
            if (values[j] > values[j + 1]) { // Check if the current element is greater than the next element
                double temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 0) { // Check if the number of elements is even
        int midIndex_1 = size / 2 - 1; // Index of the first middle element
        int midIndex_2 = size / 2; // Index of the second middle element
        return (values[midIndex_1] + values[midIndex_2]) / 2.0; // Return the average of the two middle elements
    }
    else {
        return values[size / 2];    // Return the middle element
    }
}

// Function to calculate the average salary for each designation category
void calculateAverageSalaryByDesignation(const Employee* employees, int size) { // Pass by reference to avoid copying
    const int t_Size = 100; // Maximum number of unique designations (adjust as needed)
    string uniqueDesignations[t_Size]; // Array to store the unique designations
    double totalSalaryByDesignation[t_Size] = {0}; // Array to store the total salary for each designation
    int countByDesignation[t_Size] = {0}; // Array to store the number of employees for each designation
    int uniqueCount = 0;

    for (int i = 0; i < size; ++i) {
        bool found = false; // Flag to indicate if the current employee's designation has been found in the array of unique designations

        for (int j = 0; j < uniqueCount; ++j) { // Iterate over the unique designations
            if (employees[i].designation == uniqueDesignations[j]) { // Check if the current employee's designation is equal to the current unique designation
                found = true;
                totalSalaryByDesignation[j] += employees[i].salary; // Add the current employee's salary to the total salary for the current designation
                countByDesignation[j]++; // Increment the number of employees for the current designation
                break;
            }
        }
   
        if (!found) { // Check if the current employee's designation has not been found in the array of unique designations
            uniqueDesignations[uniqueCount] = employees[i].designation; // Add the current employee's designation to the array of unique designations
            totalSalaryByDesignation[uniqueCount] += employees[i].salary; // Add the current employee's salary to the total salary for the current designation
            countByDesignation[uniqueCount]++; // Increment the number of employees for the current designation
            uniqueCount++;
        }
    }

    cout << "Average salary by designation:" << endl;
    for (int i = 0; i < uniqueCount; ++i) { // Iterate over the unique designations
        double averageSalary = totalSalaryByDesignation[i] / countByDesignation[i]; // Calculate the average salary for the current designation
        cout << uniqueDesignations[i] << ": $"  << averageSalary << endl;
    }
}

// Function to find the name of the employee with the highest salary
string findEmployeeWithHighestSalary(const Employee* employees, int size) {
    double highestSalary = employees[0].salary; // Initialize the highest salary to the first employee's salary
    string highestSalaryEmployee = employees[0].name; // Initialize the name of the employee with the highest salary to the first employee's name

    for (int i = 1; i < size; ++i) { // Iterate over the remaining employees
        if (employees[i].salary > highestSalary) { // Check if the current employee has the highest salary
            highestSalary = employees[i].salary; // Update the highest salary
            highestSalaryEmployee = employees[i].name; // Update the name of the employee with the highest salary
        }
    }

    return highestSalaryEmployee;
}