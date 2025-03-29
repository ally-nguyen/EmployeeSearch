#include <string.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if ((*functionPtr)(targetPtr, ptr) == 0)
        {
            return (PtrToEmployee)ptr;
        }
    }
    return NULL;
}
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return *(long *)targetPtr != tableValuePtr->number;
}
static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *)targetPtr, tableValuePtr->name);
}
static int compareEmployeePhoneNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *)targetPtr, tableValuePtr->phone);
}
static int compareEmployeeSalaray(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return *(double *)targetPtr, tableValuePtr->salary;
}
// wrappers that are used in main
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int size, char *phone)
{
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhoneNumber);
}
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary)
{
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalaray);
}
