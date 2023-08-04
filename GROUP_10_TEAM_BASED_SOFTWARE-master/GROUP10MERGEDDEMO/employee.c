#define _CRT_SECURE_NO_WARNINGS

#include "employee.h"
#include "login.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#include "user.h"
#include "organizer.h"
#define LINE_SIZE 100
#define MAX 100

int InputCheck()
{
	EMPLOYEE employee;
	employee.option = 0; //initializes variable
	unsigned char Option[NUM_SIZE] = { 0 }; //creates a string for input
	while (fgets(Option, NUM_SIZE, stdin)) //accepts string input
	{
		employee.option = atoi(Option); //converts the input string to int
		if (employee.option > 3 || employee.option < 1) //checks if input, as an integer, is wrong 
		{
			printf("\nERROR: Enter either 1, 2 or 3 only\n");
			printf("\n");
			printf("Enter option: ");
		}
		else if (Option == employee.option) //checks if input is NOT an integer
		{
			printf("\nERROR: Enter either 1, 2 or 3 only\n");
			printf("\n");
			printf("Enter option: ");
		}
		else //if input is correct break out of loop
			break;
	}
	return employee.option;//return correct input
}

void WriteToUsersCredentialsFile()
{
	FILE* fp;
	unsigned char Name[USERNAME_SIZE] = { 0 };
	unsigned char NAME[USERNAME_SIZE] = { 0 };

	fp = fopen("User Credentials.txt", "a");

	printf("\nEnter your Username: ");
	gets_s(Name, USERNAME_SIZE);
	strncpy(NAME, Name, USERNAME_SIZE - 1);
	NAME[USERNAME_SIZE - 1] = 0;

	printf("\nEnter your Password: ");
	unsigned char password[PASSWORD_SIZE] = { 0 };
	fgets(password, PASSWORD_SIZE, stdin);

	strcat(NAME, password);
	fprintf(fp, "%s", NAME);
	printf("\nYou are saved successfully\n");
	fclose(fp);
	//////////////////////////////////////////////
	printf("WELCOME! USER MODULE\n");

	//Inventory for each sport...All this would be done by Ehi in her module.
	mainMenuUser();
}

//int ReadFromUsersCredentialsFile()
//{
//	FILE* fp;
//	fp = fopen("User Credentials.txt", "r");
//	if (fp == NULL)
//	{
//		printf("Unable to open file\n");
//		return 1;
//
//	}
//		
//
//	else
//	{
//		//TAKING INPUT FROM USER
//		printf("\nEnter your Username: ");
//		unsigned char name[USERNAME_SIZE] = { 0 };
//		gets_s(name, USERNAME_SIZE);
//
//		printf("\nEnter your Password: ");
//		unsigned char Password[PASSWORD_SIZE] = { 0 };
//		fgets(Password, PASSWORD_SIZE, stdin);
//
//		strcat(name, Password);
//		unsigned char line[LINE_SIZE] = { 0 };
//		while (fgets(line, sizeof(line), fp))
//		{
//			int equal = strcmp(line, name);
//			if (equal == 0)
//			{
//				printf("\nYou are successfully found\n");
//				return 0;
//				//break;
//			}
//
//				
//		}
//		fclose(fp);
//		
//
//
//	}
//	
//}

int ReadFromUsersCredentialsFile()
{
	FILE* fp;
	fp = fopen("User Credentials.txt", "r");
	if (fp == NULL)
	{
		printf("Unable to open file\n");
		return 0;
	}

	else
	{
		// TAKING INPUT FROM USER
		printf("\nEnter your Username: ");
		unsigned char name[USERNAME_SIZE + PASSWORD_SIZE] = { 0 };
		gets_s(name, USERNAME_SIZE);

		printf("\nEnter your Password: ");
		unsigned char Password[PASSWORD_SIZE] = { 0 };
		fgets(Password, PASSWORD_SIZE, stdin);

		strncat(name, Password, PASSWORD_SIZE);
		unsigned char line[LINE_SIZE] = { 0 };
		while (fgets(line, sizeof(line), fp))
		{
			int equal = strcmp(line, name);
			if (equal == 0)
			{
				printf("\nYou are successfully found\n");
				return 1;
			}
		}
		printf("\nSorry! Not found\n");
		fclose(fp);
		return 0;
	}
}


void WriteToOrganizerCredentialsFile()
{
	FILE* fp1;
	unsigned char Name1[ORGANIZER_SIZE] = { 0 };
	unsigned char password1[PASSWORD_SIZE] = { 0 };

	fp1 = fopen("Organizer Credentials.txt", "a");
	if (fp1 == NULL)
	{
		printf("Error opening file\n");
		return;
	}

	printf("\nEnter your Username: ");
	fgets(Name1, ORGANIZER_SIZE, stdin);
	Name1[strcspn(Name1, "\n")] = '\0'; // Remove the newline character, if present.

	printf("\nEnter your Password: ");
	fgets(password1, PASSWORD_SIZE, stdin);
	password1[strcspn(password1, "\n")] = '\0'; // Remove the newline character, if present.

	fprintf(fp1, "%s,%s\n", Name1, password1);
	fclose(fp1);

	printf("\nYou are saved successfully\n");
	printf("WELCOME TO ORGANIZER MODULE!!!");
	mainMenu(Name1);
}


int ReadFromOrganizerCredentialsFile()
{
	FILE* fp;
	fp = fopen("Organizer Credentials.txt", "r");
	if (fp == NULL)
	{
		printf("Unable to open file\n");
		return 0;
	}

	else
	{
		// TAKING ORGANIZER INPUT
		printf("\nEnter your Username: ");
		unsigned char name1[USERNAME_SIZE] = { 0 };
		fgets(name1, USERNAME_SIZE, stdin);
		name1[strcspn(name1, "\n")] = '\0'; // Remove the newline character, if present.

		printf("\nEnter your Password: ");
		unsigned char Password1[PASSWORD_SIZE] = { 0 };
		fgets(Password1, PASSWORD_SIZE, stdin);
		Password1[strcspn(Password1, "\n")] = '\0'; // Remove the newline character, if present.

		unsigned char inputLine[LINE_SIZE] = { 0 };
		snprintf(inputLine, sizeof(inputLine), "%s,%s", name1, Password1);

		unsigned char line[LINE_SIZE] = { 0 };
		while (fgets(line, sizeof(line), fp))
		{
			line[strcspn(line, "\n")] = '\0'; // Remove the newline character, if present.
			int equal = strcmp(line, inputLine);
			if (equal == 0)
			{
				printf("\nYou are successfully found\n");
				printf("WELCOME TO ORGANIZER MODULE!!!");
				fclose(fp);
				mainMenu(name1);
				return 1;
			}
		}
		printf("\nSorry! Not found\n");
		fclose(fp);
		return 0;
	}
}


void ReadFromEmployeeFile()
{
	//VERIFYING THEIR EXISTENCE FROM THE FILE
	FILE* fp;
	fp = fopen("Employee File.txt", "r");
	if (fp == NULL)
		printf("Unable to open file\n");
	else
	{
		//TAKING EMPLOYEE INPUT
		printf("\nEnter your Employee ID: ");
		unsigned char ID[ID_SIZE] = { 0 };
		gets_s(ID, ID_SIZE);

		printf("\nEnter your Passcode: ");
		unsigned char Passcode2[PASSWORD_SIZE] = { 0 };
		fgets(Passcode2, PASSWORD_SIZE, stdin);

		strcat(ID, Passcode2);
		unsigned char line[LINE_SIZE] = { 0 };
		while (fgets(line, sizeof(line), fp))
		{
			int equal = strcmp(line, ID);
			if (equal == 0)
			{
				printf("\nYou are successfully found\n");
				switch (equal)
				{
				case 0:
					printf("\n***************************************\n");
					printf("Choose an option below\n");
					printf("1. Add to stadium inventory\n2. Look/Update booked stadium inventory\n");
					printf("3. Look/Update free stadium inventory\n");
					printf("Enter your option: ");
					EMPLOYEE employee;
					employee.option = InputCheck(); //employee's choice
					if (employee.option == 1)
					{
						printf("\n***************************************\n");
						printf("You can now add to stadium inventory\n");
						printf("***************************************\n\n");
						WriteToInventory();
					}
					else if (employee.option == 2)
					{
						printf("***************************************\n");
						printf("You can now look/update booked stadium inventory\n");
						printf("***************************************\n\n");
						Write_ReadFromBookedInventory();
					}
					else if (employee.option == 3)
					{
						printf("***************************************\n");
						printf("You can now look/update free stadium inventory\n");
						printf("***************************************\n\n");
						Read_WriteToFreeStadiumsInventory();
					}
					break;

				}
				break;
			}
			if (feof(fp) && equal != 0)
				printf("\nSorry! You don't exist in our company...\n");
		}
		fclose(fp);
	}
}


void WriteToInventory()
{
	FILE* fp2;
	unsigned char inventory[SPORT_SIZE] = { 0 };
	unsigned char INVENTORY[SPORT_SIZE] = { 0 };

	fp2 = fopen("Inventory.txt", "a");
	//add inventory of total stadiums owned by the company 

	fclose(fp2);
}


void Write_ReadFromBookedInventory()
{
	//the booked stadiums that would be displayed to user
	//from the organizer that booked it.
	//append then read mode
}

void Read_WriteToFreeStadiumsInventory()
{
	//display this inventory to organizers
	//in append then read mode
	//the read mode prints to screen
	//organizer chooses one.
}