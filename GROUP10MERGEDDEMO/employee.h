//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
#pragma once
#include "organizer.h"

typedef struct Employee
{
	int option;
}EMPLOYEE;

int InputCheck();

void WriteToUsersCredentialsFile();
int ReadFromUsersCredentialsFile();

void WriteToOrganizerCredentialsFile();
int ReadFromOrganizerCredentialsFile();

void ReadFromEmployeeFile();


int EmployeeRemove(int);
void EmployeeView();