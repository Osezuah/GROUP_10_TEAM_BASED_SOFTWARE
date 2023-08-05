//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
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

extern eventNode* first_event;
extern eventNode* last_event;

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

//main function for employee module that has all the major action they are able to take
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
		unsigned char Passcode2[PASSWORD_SIZE] = { 0 };  //employee verification... veryfing if employee exists in the file
		fgets(Passcode2, PASSWORD_SIZE, stdin);
		loadEvents();
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
					printf("1. Add to event inventory\n2. View event inventory\n3. Remove from event inventory\n");
					printf("Enter your option: ");
					EMPLOYEE employee;
					employee.option = InputCheck(); //employee's choice
					if (employee.option == 1) //option 1 to add an event
					{
						printf("\n***************************************\n");
						printf("You can now add to event inventory\n");
						printf("***************************************\n\n");
						unsigned char EmployeeName[ORGANIZER_SIZE] = "Employee";
						event *EmployeeEvent;
						disp_menu2();
						AddNewEvent(&EmployeeEvent, EmployeeName);
						printf("Event succesfully added!");
						saveEvents();
					}
					else if (employee.option == 2) //option to view the entire inventory.....all events
					{
						printf("***************************************\n");
						printf("You can now view event inventory\n");
						printf("***************************************\n\n");
						EmployeeView();
					}
					else if (employee.option == 3) //option 3 to remove any event given the ID
					{
						int employeeID;
						printf("***************************************\n");
						printf("You can now remove event from inventory\n");
						printf("***************************************\n\n");
						EmployeeView();
						printf("Enter event ID that you wish to remove: ");
						scanf_s("%d", &employeeID);
						EmployeeRemove(employeeID);
						printf("Event with ID %d succesfully removed!", employeeID);
						saveEvents();

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

//function to view all the events in the linked list.......
void EmployeeView() 
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
			printf("Event ID: %d\n", temp->data.eventID);
			printf("Category: %s\n", temp->data.category);
			printf("Event Name: %s\n", temp->data.eventName);
			printf("Place of the event: %s\n", temp->data.place);
			printf("Time: %d:%d\n", temp->data.times.hour, temp->data.times.minute);
			printf("Date: %d/%d/%d\n", temp->data.dates.day, temp->data.dates.month, temp->data.dates.year);
			printf("Amount of tickets avaliable: %d\n", temp->data.tickets);
			printf("Price per ticket: %lf\n", temp->data.price);
			printf("Organizer: %s\n", temp->data.organizer);
			printf("\n");
		temp = temp->next;
	}
}

//function to remove any event in the linked list by event id..
int EmployeeRemove(int eventID)
{
	eventNode* temp = first_event;

	while (temp != NULL)
	{
		if (temp->data.eventID == eventID)
		{

			if (temp->prev != NULL)
			{
				temp->prev->next = temp->next;
			}
			else
			{
				first_event = temp->next;
			}

			if (temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			else
			{
				last_event = temp->prev;
			}
			free(temp);
			return 1;
		}
		temp = temp->next;
	}
	printf("Event with ID %d not found!\n", eventID);
	return 0;
}

