#include <iostream>
using namespace std;
void readMarks(int marks[], int n);
int findTotal(int marks[], int n);
double findAverage(int marks[], int n);
int findHighest(int marks[], int n);
int findLowest(int marks[], int n);
int countPassed(int marks[], int n);
void printReport(int marks[], int n);
int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    while (n < 1 || n > 100)
    {
        cout << "Enter a number between 1 and 100: ";
        cin >> n;
    }
    int *marks = new int[n];
    readMarks(marks, n);
    printReport(marks, n);
    delete[] marks;
    return 0;
}
void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];

        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid mark! Enter between 0 and 100: ";
            cin >> marks[i];
        }
    }
}
int findTotal(int marks[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }
    return total;
}
double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);
    double average = (double)total / n;
    return average;
}
int findHighest(int marks[], int n)
{
    int highest = marks[0];
    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }
    return highest;
}

int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }
    return lowest;
}
int countPassed(int marks[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 50)
        {
            count++;
        }
    }
    return count;
}
void printReport(int marks[], int n)
{
    int passed = countPassed(marks, n);
    int failed = n - passed;
    cout << "Student REPORT\n";
    cout << "Total Students       : " << n << endl;
    cout << "Total Marks          : " << findTotal(marks, n) << endl;
    cout << "Average Marks        : " << findAverage(marks, n) << endl;
    cout << "Highest Marks        : " << findHighest(marks, n) << endl;
    cout << "Lowest Marks         : " << findLowest(marks, n) << endl;
    cout << "Students Passed      : " << passed << endl;
    cout << "Students Failed      : " << failed << endl;
     cout << "===\n";
}