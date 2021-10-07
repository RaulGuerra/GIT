//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
	//defined in employeeOne.c or employee Two.c
	PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
	PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
	PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
	PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);

	//defined in employee Table.c
	extern Employee EmployeeTable[];
	extern const int EmployeeTableEntries;

	PtrToEmployee matchPtr; //Declaration
	matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

	//Example not found
	if (matchPtr != NULL)
		printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee ID 1045 is NOT found in the record\n");

	// Example found
	matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
	if (matchPtr != NULL)
		printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee Tony Bobcat is NOT found in the record\n");

//---------------------TESTING SALARY SEARCH-----------------------------

	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.45);
	//Example not found
	if (matchPtr != NULL)
		printf("Salary 10.45 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Salary 10.45 is NOT found in the record\n");


	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
	//Example found
	if (matchPtr != NULL)
		printf("Salary 4.50 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Salary 4.50 is NOT found in the record\n");
	
	//---------------------TESTING PHONE SEARCH-----------------------------
	// Example not found
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "111-222-3333");
	if (matchPtr != NULL)
		printf("Employee phone 111-222-3333 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee phone 111-222-3333 is NOT found in the record\n");

		// Example found
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
	if (matchPtr != NULL)
		printf("Employee phone 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
	else
		printf("Employee phone 714-555-2749 is NOT found in the record\n");


	return EXIT_SUCCESS;
}

