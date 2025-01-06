#pragma once

typedef struct _employee {
	int id;
	char name[10];
}Employee;

Employee* makeEmployee(int id, char* pname);
void printEmployee(Employee* pEmployee);