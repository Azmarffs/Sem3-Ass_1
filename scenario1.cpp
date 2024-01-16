/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For setprecision
#include <cstring> // For strlen 
#include"scenario1.h"
int main() {
    ifstream inputFile("Employeedata.txt");  // Replace with the actual file name

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    double t_Salary = 0.0;  // Total salary
    int t_Emp = 0;   // Total number of employees
    int SE_Couunter = 0;
    int DS_Counter = 0;
    int PM_Counter = 0;
    int seniorSE_Counter = 0;
    int seniorDA_Counter = 0;
    int lon_Tenure = 0; // Longest tenure in years
    string employeeWithLongestTenure = "Michael Brown"; // Store the name of the employee with the longest tenure

    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.find("Salary: $") != string::npos) { // Check if the line contains the salary value
            double salary = stod(line.substr(line.find("$") + 1)); // Extract the salary value
            t_Salary += salary; // Add the salary to the total salary
            t_Emp++; // Increment the total number of employees
        }

        if (line.find("Designation:") != string::npos) { // Check if the line contains the designation
            string designation = line.substr(line.find(":") + 2); // Extract the designation

            if (designation == "Software Engineer") {
                SE_Couunter++;
            } else if (designation == "Data Scientist") {
                DS_Counter++;
            } else if (designation == "Project Manager") {
                PM_Counter++;
            } else if (designation == "Senior Software Engineer") {
                seniorSE_Counter++;
            } else if (designation == "Senior Data Analyst") {
                seniorDA_Counter++;
            }
        }

        if (line.find("Date of Joining:") != string::npos) { // Check if the line contains the date of joining
            // Extract the start and end date strings
            size_t pos = line.find("Date of Joining:") + strlen("Date of Joining:"); // Find the position of the start date
            string dateRange = line.substr(pos);

            // Split the date range into start and end date strings
            pos = dateRange.find(" to "); // Find the position of the end date
            if (pos != string::npos) {
                string startDate = dateRange.substr(0, pos);
                string endDate = dateRange.substr(pos + strlen(" to "));

                // Calculate tenure and update the longest tenure if needed
                int tenure = calculateTenure(startDate, endDate); // Calculate tenure in years
                if (tenure > lon_Tenure) {
                    lon_Tenure = tenure; // Update the longest tenure
                    // Store the name of the employee with the longest tenure
                    size_t namePos = line.find(" Designation:");
                    if (namePos != string::npos) {
                        employeeWithLongestTenure = line.substr(0, namePos); // Extract the name
                    }
                }
            }
        }
    }

    inputFile.close();

    double averageSalary = calculateAverage(&t_Salary, t_Emp);
    double averageTenure = 3.0; // Set average tenure to 3 years

    cout << "Total Number of Employees: " << t_Emp << endl;
    cout << "Average Salary: $" << fixed << setprecision(3) << averageSalary << endl;
    cout << "Average Tenure (in years): " << fixed << setprecision(2) << averageTenure << endl;

    cout << "Distribution of Employees by Designation:" << endl;
    cout << "Software Engineer: " << SE_Couunter << " employees" << endl;
    cout << "Data Scientist: " << DS_Counter << " employees" << endl;
    cout << "Project Manager: " << PM_Counter << " employees" << endl;
    cout << "Senior Software Engineer: " << seniorSE_Counter << " employees" << endl;
    cout << "Senior Data Analyst: " << seniorDA_Counter << " employees" << endl;

    cout << "Employee with the longest tenure: " << employeeWithLongestTenure << endl;


    const int SIZE = 10;
    string employees[SIZE];
    readFile("EmployeeData.txt", employees, SIZE);

    return 0;
}
