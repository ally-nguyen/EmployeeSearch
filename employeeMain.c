#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneNumToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);


    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    if (matchPtr != NULL)
    {
        printf("Employee ID 1045 is in record ld\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
    {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");

    if (matchPtr != NULL)
    {
        printf("Employee's Phone Number 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee's Phone Number is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
  
    if (matchPtr != NULL)
    {
        printf("Employee's Salaray 8.32 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee's Salary is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}