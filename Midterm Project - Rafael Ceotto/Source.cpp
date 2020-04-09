//Rafael Ceotto
//04/03/2020
//Midterm project - Employees Database
//Description: A program used to display employess by specific information


#include <iostream>
#include <string>
using namespace std;

#define EMPLOYEE_NUMS 10 

//Prototypes
void input();
void printAll();
void printbyAge();
void printSexCount();


//Global Variable
int curEmployees = 0;
int choice;

//Strutct to hold Employee information

struct Employees {

	int Id;
	char Name[20];
	int Age;
	char Dob[20];
	char Position[30];
	char Gender;
};

//Using an array to hold the number of Employees
Employees list[EMPLOYEE_NUMS];

//Passing a pointer on Employees to retrieve a specifict employee from the list
Employees* getEmployee(int index)
{
	Employees* empPtr = list + index;
	return empPtr;
}

//Function to request the user to enter Employee's data
void input() {

	if (curEmployees < EMPLOYEE_NUMS)
	{
		cout << "\nPlease, enter the ID of the employee: ";
		cin >> list[curEmployees].Id;
		cout << "\nPlease, enter the first name of the employee: ";
		cin >> list[curEmployees].Name;
		cout << "\nPlease, enter the age of the employee: ";
		cin >> list[curEmployees].Age;
		cout << "\nPlease, enter the DOB (mm-dd-yyyy) of the employee: ";
		cin >> list[curEmployees].Dob;
		cout << "\nPlease, enter the position of the employee: ";
		cin >> list[curEmployees].Position;
		cout << "\nPlease, enter the gender of the employee(M/F): ";
		cin >> list[curEmployees].Gender;
		curEmployees++;
		
	}
	else
	{
		cout << "\n You can not input more than " << EMPLOYEE_NUMS << " people";
	}
}

//Function to display the all records from database
void printAll() {
	cout << "\n Displaying all records";
	cout << "\n Total number of Employees: " << curEmployees << endl;
	for (int i = 0; i < curEmployees; i++) {
		cout << "\n ID : " << list[i].Id;
		cout << "\t Name : " << list[i].Name;
		cout << "\t Age : " << list[i].Age;
		cout << "\t DOB : " << list[i].Dob;
		cout << "\t Position: " << list[i].Position;
		cout << "\t Gender : " << list[i].Gender;
		cout << endl;
	}
}

//Function to display and sort by age of employee
void printbyAge() {
	cout << "\n Displaying all records by Age";
	int empAbove40 = 0;
	int empOn30s = 0;
	int babyEmployee = 0;

	for (int i = 0; i < curEmployees; i++) {
		if (list[i].Age < 50 && list[i].Age > 40) {
			empAbove40++;
		}			
		if (list[i].Age < 40 && list[i].Age > 30) {
			empOn30s++;
		}			
		else {
			babyEmployee++;
		}
			
	}

	cout << "\n Employees more than 40: " << empAbove40 << endl;
	cout << "\n Employees more than 30: " << empOn30s << endl;
	cout << "\n Employees less than 30: " << babyEmployee << "\n";
}

//Function to display and sort by sex of employee
void printSexCount() {
	cout << "\n Displaying all records by Sex Count";
	int maleNum = 0;
	int femaleNum = 0;

	for (int i = 0; i < curEmployees; i++) {
		if (list[i].Gender == 'M')
			maleNum++;
		else if (list[i].Gender == 'F')
			femaleNum++;
	}
	cout << "\n Number of Male: " << maleNum;
	cout << "\n Number of Female: " << femaleNum << "\n\n";
}

int main() {

	while (choice != 4)  {
		cout << "\nRafa's Company Database of Employees" << "\n\n";
		cout << "1 - Input Employee Records" << endl;
		cout << "2 - Display All Employee Records" << endl;
		cout << "3 - Display by Age" << endl;
		cout << "4 - Display by Sex count" << "\n" << endl;

		cout << "Enter you choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			input();
			break;
		case 2:
			printAll();
			break;
		case 3:
			printbyAge();
			break;
		case 4:
			printSexCount();
			break;
		
		default:
			cout << "\n Wrong choice. Try again";
			break;

		}
	}
	
		
		
	system("pause");
	return 0;

}