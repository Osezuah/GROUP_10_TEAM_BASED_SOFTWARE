#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "files.h"
#include "user.h"

extern eventNode* first_event;
extern eventNode* last_event;

void mainMenuUser()
{
	Sleep(1000);
	//TRZEBA DODAC SPANIE GDZIES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	loadEvents();
	srand(time(NULL));
	disp_menuUser();
	int choice;
	int index;

	while (1)
	{
		disp_menuUser();
		printf("Enter a number (1-4) or 0 to exit: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printFootball();
			printf("Which football event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforFootball(index);
			saveEvents();
			break;
		case 2:
			printBasketball();
			printf("Which basketball event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforBasketball(index);
			saveEvents();
			break;
		case 3:
			printBaseball();
			printf("Which baseball event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforBaseball(index);
			saveEvents();
			break;
		case 4:
			printHockey();
			printf("Which hockey event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforHockey(index);
			saveEvents();
			break;
		case 0:
			return;
		default:
			printf("USE GOOD INPUT SHITTER!!");
			break;
		}
	}
}

void disp_menuUser(void)
{
	//TRZEBA DODAC SPANIE GDZIES
	system("cls");
	printf("\n\n\n");
	printf("                               *****************************************************\n");
	printf("                               *                                                   *\n");
	printf("                               *                  Select category:                 *\n");
	printf("                               *                                                   *\n");
	printf("                               *****************************************************\n");
	printf("                               *                                                   *\n");
	printf("                               *                   1. Football                     *\n");
	printf("                               *                   2. Basketball                   *\n");
	printf("                               *                   3. Baseball                     *\n");
	printf("                               *                   4. Hockey                       *\n");
	printf("                               *                                                   *\n");
	printf("                               *                    0.Exit                         *\n");
	printf("                               *                                                   *\n");
	printf("                               *****************************************************\n");
}

int bookforFootball(int ID)
{
	eventNode* temp = first_event;
	int x;

	while (temp != NULL)
	{
		if (temp->data.eventID == ID)
		{
			if (strcmp(temp->data.category, "Football") != 0)
			{
				printf("The ID you chose does not match a Football event.\n");
				Sleep(5000);
				return 0;
			}
			if (temp->data.tickets <= 0)
			{
				printf("The tickets for this Event have been sold out");
				Sleep(5000);
				return 0;
			}
			x = rand() % temp->data.tickets + 1;
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x);
			Sleep(5000);

			temp->data.tickets--;
			break;
		}
		temp = temp->next;
	}
	return 1;
}

int bookforBasketball(int ID)
{
	eventNode* temp = first_event;
	int x;

	while (temp != NULL)
	{
		if (temp->data.eventID == ID)
		{
			if (strcmp(temp->data.category, "Basketball") != 0)
			{
				printf("The ID you chose does not match a basketball event.\n");
				return 0;
			}
			if (temp->data.tickets <= 0)
			{
				printf("The tickets for this Event have been sold out");
				return 0;
			}
			x = rand() % temp->data.tickets + 1;
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x);

			temp->data.tickets--;
			break;
		}
		temp = temp->next;
	}
	return 1;
}

int bookforBaseball(int ID)
{
	eventNode* temp = first_event;
	int x;

	while (temp != NULL)
	{
		if (temp->data.eventID == ID)
		{
			if (strcmp(temp->data.category, "Baseball") != 0)
			{
				printf("The ID you chose does not match baseball event.\n");
				return 0;
			}
			if (temp->data.tickets <= 0)
			{
				printf("The tickets for this Event have been sold out");
				return 0;
			}
			x = rand() % temp->data.tickets + 1;
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x);

			temp->data.tickets--;
			break;
		}
		temp = temp->next;
	}
	return 1;
}

int bookforHockey(int ID)
{
	eventNode* temp = first_event;
	int x;

	while (temp != NULL)
	{
		if (temp->data.eventID == ID)
		{
			if (strcmp(temp->data.category, "Hockey") != 0)
			{
				printf("The ID you chose does not match Football event.\n");
				return 0;
			}
			if (temp->data.tickets <= 0)
			{
				printf("The tickets for this Event have been sold out");
				return 0;
			}
			x = rand() % temp->data.tickets + 1;
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x);

			temp->data.tickets--;
			break;
		}
		temp = temp->next;
	}
	return 1;
}

void printBaseball(void)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, "Baseball") == 0)
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
		}
		temp = temp->next;
	}
}

void printFootball(void)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, "Football") == 0)
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
		}
		temp = temp->next;
	}
}

void printHockey(void)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, "Hockey") == 0)
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
		}
		temp = temp->next;
	}
}

void printBasketball(void)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, "Basketball") == 0)
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
		}
		temp = temp->next;
	}
}