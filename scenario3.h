/*
Name: Azmar kashif
Roll no: 22i-2716
Section: B
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Employee structure
struct Employee {
    string name;
    string employeeID;
    double salary;
    string dateOfJoining;
    string designation;
};

// Calculate average tenure
int calculateTenure(const string& dateOfJoining) { // Pass by reference to avoid copying
    time_t now = time(0); // Get the current time
    tm* ltm = localtime(&now); // Convert the current time to the local time

    int currentYear = ltm->tm_year + 1900; // Get the current year
    int year = stoi(dateOfJoining.substr(dateOfJoining.find_last_of("/") + 1));// Extract the year from the date of joining string
    int tenure = currentYear - year; // Calculate the tenure

    return tenure;
}

void calcAvgTenure(Employee* employees, int numEmployees) { // Pass by reference to avoid copying
    int totalTenure = 0;
    for (int i = 0; i < numEmployees; ++i) { // Iterate over each employee
        totalTenure += calculateTenure(employees[i].dateOfJoining); // Calculate the tenure and add it to the total
    }

    cout << "Average tenure: " << totalTenure / numEmployees << " years" << endl;
}

void calcAvgTenureForAllEmployees(Employee* employees, int numEmployees) { // Pass by reference to avoid copying
    int totalTenureSoftwareEngineer = 0;
    int totalTenureSeniorSoftwareEngineer = 0;
    int totalTenureDataScientist = 0;
    int totalTenureProjectManager = 0;
    int totalTenureSeniorDataAnalyst = 0;
    int totalTenureUXDesigner = 0;
    int totalTenureQualityAssuranceAnalyst = 0;
    int totalTenureSeniorQualityAssuranceAnalyst = 0;

    int countSoftwareEngineer = 0;
    int countSeniorSoftwareEngineer = 0;
    int countDataScientist = 0;
    int countProjectManager = 0;
    int countSeniorDataAnalyst = 0;
    int countUXDesigner = 0;
    int countQualityAssuranceAnalyst = 0;
    int countSeniorQualityAssuranceAnalyst = 0;

    for (int i = 0; i < numEmployees; ++i) { // Iterate over each employee
        int tenure = calculateTenure(employees[i].dateOfJoining); // Calculate the tenure

        if (employees[i].designation == "Software Engineer") {
            totalTenureSoftwareEngineer += tenure;
            countSoftwareEngineer++;
        } else if (employees[i].designation == "Senior Software Engineer") {
            totalTenureSeniorSoftwareEngineer += tenure;
            countSeniorSoftwareEngineer++;
        } else if (employees[i].designation == "Data Scientist") {
            totalTenureDataScientist += tenure;
            countDataScientist++;
        } else if (employees[i].designation == "Project Manager") {
            totalTenureProjectManager += tenure;
            countProjectManager++;
        } else if (employees[i].designation == "Senior Data Analyst") {
            totalTenureSeniorDataAnalyst += tenure;
            countSeniorDataAnalyst++;
        } else if (employees[i].designation == "UX Designer") {
            totalTenureUXDesigner += tenure;
            countUXDesigner++;
        } else if (employees[i].designation == "Quality Assurance Analyst") {
            totalTenureQualityAssuranceAnalyst += tenure;
            countQualityAssuranceAnalyst++;
        } else if (employees[i].designation == "Senior Quality Assurance Analyst") {
            totalTenureSeniorQualityAssuranceAnalyst += tenure;
            countSeniorQualityAssuranceAnalyst++;
        }
    }

    // Calculate and display the average tenure for each designation
    cout << "Average tenure for Software Engineer: " << totalTenureSoftwareEngineer / countSoftwareEngineer << " years" << endl;
    cout << "Average tenure for Senior Software Engineer: " << totalTenureSeniorSoftwareEngineer / countSeniorSoftwareEngineer << " years" << endl;
    cout << "Average tenure for Data Scientist: " << totalTenureDataScientist / countDataScientist << " years" << endl;
    cout << "Average tenure for Project Manager: " << totalTenureProjectManager / countProjectManager << " years" << endl;
    cout << "Average tenure for Senior Data Analyst: " << totalTenureSeniorDataAnalyst / countSeniorDataAnalyst << " years" << endl;
    cout << "Average tenure for UX Designer: " << totalTenureUXDesigner / countUXDesigner << " years" << endl;
    cout << "Average tenure for Quality Assurance Analyst: " << totalTenureQualityAssuranceAnalyst / countQualityAssuranceAnalyst << " years" << endl;
}

void calcEmployeeWithTheLongestTenure(Employee* employees, int numEmployees) {
    int longestTenure = 0;
    string employeeWithLongestTenure;
    for (int i = 0; i < numEmployees; ++i) { // Iterate over each employee
        int tenure = calculateTenure(employees[i].dateOfJoining); // Calculate the tenure
        if (tenure > longestTenure) { // Check if the current employee has the longest tenure
            longestTenure = tenure; // Update the longest tenure
            employeeWithLongestTenure = employees[i].name; // Update the name of the employee with the longest tenure
        }
    }

    cout << "Employee with the longest tenure: " << employeeWithLongestTenure << endl;
}

void calcEmployeeWithTheShortestTenure(Employee* employees, int numEmployees) { // Pass by reference to avoid copying
    int shortestTenure = 100;
    string employeeWithShortestTenure;
    for (int i = 0; i < numEmployees; ++i) { // Iterate over each employee
        int tenure = calculateTenure(employees[i].dateOfJoining); // Calculate the tenure
        if (tenure < shortestTenure) { // Check if the current employee has the shortest tenure
            shortestTenure = tenure; // Update the shortest tenure
            employeeWithShortestTenure = employees[i].name; // Update the name of the employee with the shortest tenure
        }
    }

    cout << "Employee with the shortest tenure: " << employeeWithShortestTenure << endl;
}

// Search the highest paying designation
void calcHighestPayingDesignation(Employee* employees, int numEmployees) {
    double highestSalary = 0;// Initialize the highest salary to the first employee's salary
    string highestPayingDesignation;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].salary > highestSalary) { // Check if the current employee has the highest salary
            highestSalary = employees[i].salary; // Update the highest salary
            highestPayingDesignation = employees[i].designation; // Update the name of the employee with the highest salary
        }
    }

    cout << "Highest paying designation: " << highestPayingDesignation << endl;
}