#include "employeeList.h"
#include<stdlib.h>
#include<string.h>


Employee* makeEmployee(int id, char* pname)
{
	Employee * newEmployee = (Employee*)malloc(sizeof(Employee));

	newEmployee->id = id;
	strcpy_s(newEmployee->name, sizeof(newEmployee->name), pname);

	return newEmployee;
}

void printEmployee(Employee *pEmployee)
{
	printf("id = %d name = %s\n", pEmployee->id, pEmployee->name);
}
