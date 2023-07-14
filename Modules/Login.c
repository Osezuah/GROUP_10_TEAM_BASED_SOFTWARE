#include "Login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int InputStream() //this function takes and verifys input
{
	LOGIN login;
	 login.option = 0; //initializes variable
	unsigned char Option[10] = { 0 }; //creates a string for input
	while (fgets(Option, 10, stdin)) 
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
	int option;
	LOGIN login;
	login.option = NextLoginOptions(); //collects the input from the previous login info
	switch (login.option)
	{
	case 1:
		printf("\nWhich one are you?\nEnter a number to continue: ");
		unsigned int choice = 0;
		unsigned char Choice[10] = { 0 };
		while (fgets(Choice, 10, stdin))
		{
			unsigned int choice = atoi(Choice);
			if (choice > 2 || choice < 1)
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice == choice)
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{

				switch (choice)
				{
				case 1:
					//WriteToNewUserFile(); - turn the entire code below to this function in employee.h
					printf("\nEnter your Username: ");
					unsigned char Name[50] = { 0 };
					fgets(Name, 50, stdin);
					printf("\nEnter your Password: ");
					int password[10] = { 0 };
					for (int i = 0; i < 10; i++)
					{
						scanf_s("%d", &password[i]);
					}
					break;

				case 2:
					// void ReadFromExistingUserFile()
					// {
					//		function that reads from file 
					//		(the code input below is to be passed here from employee.h)
					//		VerifyExistingUser(); - verifys what was entered from above
					// }
					printf("\nEnter your Username: ");
					unsigned char name[50] = { 0 };
					fgets(name, 50, stdin);
					printf("\nEnter your Password: ");
					int Password[10] = { 0 };
					for (int i = 0; i < 10; i++)
					{
						scanf_s("%d", &Password[i]);
					}
					break;
				}
				break;
			}
		}
		break;

	case 2:
		printf("\nWhich one are you?\nEnter a number to continue: ");
		unsigned int choice1 = 0;
		unsigned char Choice1[10] = { 0 };
		while (fgets(Choice1, 10, stdin))
		{
			unsigned int choice1 = atoi(Choice1);
			if (choice1 > 2 || choice1 < 1)
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice1 == choice1)
			{
				printf("\nERROR: Enter either 1 or 2 only\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{

				switch (choice1)
				{
				case 1:
					//WriteToNewOrganizerFile(); - turn the entire code below to this function in employee.h
					printf("\nEnter your Username: ");
					unsigned char Name1[150] = { 0 };
					fgets(Name1, 150, stdin);
					printf("\nEnter your Password: ");
					int password1[10] = { 0 };
					for (int i = 0; i < 10; i++)
					{
						scanf_s("%d", &password1[i]);
					}
					break;

				case 2:
					// void ReadFromExistingOrganizerFile()
					// {
					//		function that reads from file 
					//		(the code input below is to be passed here from employee.h)
					//		VerifyExistingOrganizer(); - verifys what was entered from above
					// }
					printf("\nEnter your Username: ");
					unsigned char name1[50] = { 0 };
					fgets(name1, 50, stdin);
					printf("\nEnter your Password: ");
					int Password1[10] = { 0 };
					for (int i = 0; i < 10; i++)
					{
						scanf_s("%d", &Password1[i]);
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
		unsigned char Choice2[10] = { 0 };
		while (fgets(Choice2, 10, stdin))
		{
			unsigned int choice2 = atoi(Choice2);
			if (choice2 > 1 || choice2 < 1)
			{
				printf("\nERROR: Enter only 1\n");
				printf("\n");
				printf("Enter option: ");
			}
			else if (Choice2 == choice2)
			{
				printf("\nERROR: Enter only 1\n");
				printf("\n");
				printf("Enter option: ");
			}
			else
			{
				switch (choice2)
				{
				case 1:
					// void ReadFromExistingEmployeeFile()
					// {
					//		function that reads from file 
					//		(the code input below is to be passed here from employee.h)
					//		VerifyExistingEmployee(); - verifys what was entered from above
					// }
					printf("\nEnter your Employee ID: ");
					unsigned char ID[20] = { 0 };
					fgets(ID, 20, stdin);
					printf("\nEnter your Passcode: ");
					int Passcode2[10] = { 0 };
					for (int i = 0; i < 10; i++)
					{
						scanf_s("%d", &Passcode2[i]);
					}
					break;
				}
				break;
			}
		}
		break;
	}
}