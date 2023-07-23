#pragma once

typedef struct Employee
{
	int option;
}EMPLOYEE;

int InputCheck();

void WriteToUsersCredentialsFile();
void ReadFromUsersCredentialsFile();

void WriteToOrganizerCredentialsFile();
void ReadFromOrganizerCredentialsFile();

void ReadFromEmployeeFile();


void WriteToInventory();
void Write_ReadFromBookedInventory();

void Read_WriteToFreeStadiumsInventory();

