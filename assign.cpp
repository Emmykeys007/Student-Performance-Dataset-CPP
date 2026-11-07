#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Structure for student information
struct Student {
  string studentID;
  string department;
  int level;
  double attendance;
  double averageScore;
};

int main() {

  // Fictional student dataset
  Student students[10] = {{"STU001", "Computer Science", 200, 95, 88},
                          {"STU002", "Cybersecurity", 300, 87, 76},
                          {"STU003", "Software Engineering", 200, 78, 69},
                          {"STU004", "Nursing", 400, 92, 85},
                          {"STU005", "Information Technology", 100, 65, 58},
                          {"STU006", "International Relations", 200, 88, 79},
                          {"STU007", "Micro biology", 300, 73, 64},
                          {"STU008", "Mass Communication", 100, 98, 91},
                          {"STU009", "Accounting", 400, 81, 72},
                          {"STU010", "Criminology", 200, 90, 83}};

  // Display student dataset
  cout << "\nSTUDENT PERFORMANCE DATASET\n";
  cout << string(85, '=') << endl;

  cout << left << setw(12) << "Student ID" << setw(25) << "Department"
       << setw(10) << "Level" << setw(18) << "Attendance (%)" << setw(20)
       << "Average Score" << endl;

  cout << string(85, '-') << endl;

  for (int i = 0; i < 10; i++) {
    cout << left << setw(12) << students[i].studentID << setw(25)
         << students[i].department << setw(10) << students[i].level << setw(18)
         << students[i].attendance << setw(20) << students[i].averageScore
         << endl;
  }

  cout << string(85, '=') << endl;

  // Create CSV file
  ofstream file("student_dataset.csv");

  if (!file.is_open()) {
    cout << "Error creating CSV file!" << endl;
    return 1;
  }

  // Write CSV headings
  file << "Student ID,Department,Level,"
       << "Attendance Percentage,Average Exam Score\n";

  // Write student records
  for (int i = 0; i < 10; i++) {
    file << students[i].studentID << "," << students[i].department << ","
         << students[i].level << "," << students[i].attendance << ","
         << students[i].averageScore << "\n";
  }

  file.close();

  cout << "\nStudent dataset created successfully!\n";
  cout << "Total Students: 10\n";
  cout << "File saved as student_dataset.csv\n";

  return 0;
}
