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

using namespace std;

template <typename T>
T calculateAverage(T* values, int numValues) {
    if (numValues == 0) {
        return T(); // Return zero for an empty array
    }

    T sum = 0;
    for (int i = 0; i < numValues; ++i) {
        sum += values[i];
    }

    return sum / numValues;
}

// Function to calculate the difference in years between two dates in the format "YYYY-MM-DD"
int calculateTenure(const string& startDate, const string& endDate) { // Pass by reference to avoid copying
    // Extract year, month, and day components from the date strings
    int s_Year = stoi(startDate.substr(0, 4));
    int s_Month = stoi(startDate.substr(5, 2));
    int s_Day = stoi(startDate.substr(8, 2));
    
    int e_Year = stoi(endDate.substr(0, 4));
    int e_Month = stoi(endDate.substr(5, 2));
    int e_Day = stoi(endDate.substr(8, 2));

    // Calculate tenure
    int years = e_Year - s_Year;
    if (e_Month < s_Month || (e_Month == s_Month && e_Day < s_Day)) { // Check if the end date is before the start date
        years--; // Decrement the tenure by 1 if the end date is before the start date
    }
    return years;
}

void readFile(string fileName, string* arr, int size) { // Pass by reference to avoid copying
    ifstream file(fileName);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            getline(file, arr[i]);
        }
    }
}

//search employee with longest tenure
void searchEmployeeWithLongestTenure(string* arr, int size) {
    string empLonTenure;
    int longestTenure = 0;
    for (int i = 0; i < size; ++i) {
        string startDate = arr[i].substr(arr[i].find("Date of Joining:") + strlen("Date of Joining:")); // Extract the start date string
        string endDate = "2023-09-13"; // Current date for reference (modify as needed)

        int tenure = calculateTenure(startDate, endDate);
        if (tenure > longestTenure) { // Check if the current employee has the longest tenure
            longestTenure = tenure; //  Update the longest tenure
            empLonTenure = arr[i].substr(0, arr[i].find(" Designation:")); // Extract the name of the employee
        }
    }

    cout << "Employee with longest tenure: " << empLonTenure << " (" << longestTenure << " years)" << endl;
}