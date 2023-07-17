#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include "Login.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void WriteToUsersCredentialsFile()
{
	FILE* fp;
	unsigned char* Name[USERNAME_SIZE] = { 0 };
	unsigned char* NAME[USERNAME_SIZE] = { 0 };

	fp = fopen("User Credentials.txt", "a");
	while (true)
	{
		printf("\nEnter your Username: ");
		fgets(Name, USERNAME_SIZE, stdin);
		strncpy(NAME, Name, USERNAME_SIZE - 1);
		NAME[USERNAME_SIZE - 1] = 0;

		printf("\nEnter your Password: ");
		unsigned char* password[PASSWORD_SIZE] = { 0 };
		fgets(password, PASSWORD_SIZE, stdin);

		strcat(NAME, password);
		fprintf(fp, NAME);

		if ('\n')
			break;
		
	}
	fclose(fp);
}

void WriteToOrganizerCredentialsFile()
{
	FILE* fp1;

	unsigned char* Name1[ORGANIZER_SIZE] = { 0 };
	unsigned char* NAME1[ORGANIZER_SIZE] = { 0 };

	fp1 = fopen("Organizer Credentials.txt", "a");
	while (true)
	{
		printf("\nEnter your Username: ");
		fgets(Name1, ORGANIZER_SIZE, stdin);
		strncpy(NAME1, Name1, ORGANIZER_SIZE - 1);
		NAME1[ORGANIZER_SIZE - 1] = 0;

		printf("\nEnter your Password: ");
		unsigned char* password1[PASSWORD_SIZE] = { 0 };
		fgets(password1, PASSWORD_SIZE, stdin);

		strcat(NAME1, password1);
		fprintf(fp1, NAME1);

		if ('\n')
			break;
	}
	fclose(fp1);
}

void WriteToInventory()
{
	FILE* fp2;
	unsigned char* inventory[SPORT_SIZE] = { 0 };
	unsigned char* INVENTORY[SPORT_SIZE] = { 0 };

	fp2 = fopen("Inventory.txt", "a+");
	
	fclose(fp2);

}