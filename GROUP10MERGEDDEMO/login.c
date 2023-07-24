#include "login.h"
#include "employee.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "organizer.h"
#include "user.h"


int InputStream() //this function takes and verifys input
{
	LOGIN login;
	login.option = 0; //initializes variable
	unsigned char Option[NUM_SIZE] = { 0 }; //creates a string for input
	while (fgets(Option, NUM_SIZE, stdin)) //accepts input string
	{
		login.option = atoi(Option); //converts the input string to int
		if (login.option > 3 || login.option < 1) //checks if input, as an integer, is wrong 
		{
			printf("\nERROR: Enter either 1, 2 or 3 only\n");
			printf("\n");
			printf("Enter option: ");
		}
		else if (Option == login.option) //checks if input is NOT an integer
		{
			printf("\nERROR: Enter either 1, 2 or 3 only\n");
			printf("\n");
			printf("Enter option: ");
		}
		else //if input is correct break out of loop
			break;
	}
	return login.option;//return correct input
}

void WelcomeMessage() //prints welcome message to screen
{
	printf("***************************************\n");
	printf("Welcome to Tournament Management System\n");
	printf("***************************************\n\n");
}

void DisplayLoginOptions() //prints login info
{
	printf("Choose an option to login to your account\n");
	printf("1. User Login\n");
	printf("2. Organizer Login\n");
	printf("3. Employee Login\n\n");
}


int NextLoginOptions()
{
	LOGIN login;
	login.option = InputStream(); //collects the input from the user
	if (login.option == 1)//if the input is 1 display the first login info
	{
		printf("\n");
		printf("1. New User - Sign In\n");
		printf("2. Existing User - Log In\n");
	}
	else if (login.option == 2)//if the input is 2 display the second login info
	{
		printf("\n");
		printf("1. New Organizer - Sign In\n");
		printf("2. Existing Organizer - Log In\n");
	}
	else if (login.option == 3)//if the input is 3 display the third login info
	{
		printf("\n");
		printf("1. Employee - Log In\n");
	}
	return login.option; //returns the input entered
}

void LoginCredentials()
{
	int out;
	int out1;
	int option;
	LOGIN login;
	login.option = NextLoginOptions(); //collects the input from the previous login info
	switch (login.option)
	{
	case 1:
		printf("\nWhich one are you?\nEnter a number to continue: ");
		unsigned int choice = 0;
		unsigned char Choice[NUM_SIZE] = { 0 };
		while (fgets(Choice, NUM_SIZE, stdin))
		{
			//HANDLING ERRORS FROM INPUT
			unsigned int choice = atoi(Choice);
			if (choice > 2 || choice < 1) //checks if input, as an integer, is wrong
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice == choice) //checks if input is NOT an integer
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{

				switch (choice) //CHECKING FOR WHICH KIND OF INPUT
				{
				case 1: //IF USER ENTERS 1; SAVE THEM TO FILE
					//WriteToNewUserFile(); - turn the entire code below to this function in employee.h
					WriteToUsersCredentialsFile();


				case 2: //IF USER ENTERS 2; VERIFY THEIR EXISTENCE IN OUR DATABASE
					out = ReadFromUsersCredentialsFile();
					if (out == 1)
					{
						printf("WELCOME! USER MODULE\n");

						//Inventory for each sport...All this would be done by Ehi in her module.
						mainMenuUser();
						break;
					}

				}
			}
			break;
		}
	case 2:
		printf("\nWhich one are you?\nEnter a number to continue: ");
		unsigned int choice1 = 0;
		unsigned char Choice1[NUM_SIZE] = { 0 };
		while (fgets(Choice1, NUM_SIZE, stdin))
		{
			//HANDLING ERRORS FROM INPUT
			unsigned int choice1 = atoi(Choice1);
			if (choice1 > 2 || choice1 < 1) //checks if input, as an integer, is wrong
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice1 == choice1) //checks if input is NOT an integer
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{

				switch (choice1) //CHECKING FOR WHICH KIND OF INPUT
				{
				case 1: //IF ORGANIZER ENTERS 1; SAVE THEM TO FILE
					//WriteToNewOrganizerFile(); - turn the entire code below to this function in employee.h
					WriteToOrganizerCredentialsFile();
					break;

				case 2: //IF ORGANIZER ENTERS 2; VERIFY THEIR EXISTENCE IN OUR DATABASE
					// void ReadFromExistingOrganizerFile()
					out1 = ReadFromOrganizerCredentialsFile();
					if (out1 == 1)
					{
						mainMenu();

					}
					
					break;
				}
				break;
			}

		}
		break;
	case 3:
		printf("\nEnter a number to continue: ");
		unsigned int choice2 = 0;
		unsigned char Choice2[NUM_SIZE] = { 0 };
		while (fgets(Choice2, NUM_SIZE, stdin))
		{
			//HANDLING ERRORS FROM INPUT
			unsigned int choice2 = atoi(Choice2);
			if (choice2 > 1 || choice2 < 1) //checks if input, as an integer, is wrong
			{
				printf("\nERROR: Enter only 1\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice2 == choice2) //checks if input is NOT an integer
			{
				printf("\nERROR: Enter only 1\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{
				switch (choice2)
				{
				case 1: //IF EMPLOYEE ENTERS 1; VERIFY THEIR EXISTENCE IN OUR DATABASE
					ReadFromEmployeeFile();
					break;
				}
				break;
			}
		}
		break;
	}
}