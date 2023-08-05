//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
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

// function to display options for user module...
void mainMenuUser()
{
	Sleep(1000);
	loadEvents();
	srand(time(NULL));
	disp_menuUser();
	int choice;
	int index;
	int the_end = 0;

	while (the_end == 0)
	{
		disp_menuUser();
		printf("Enter a number (1-4) or 0 to save bookings and exit: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printFootball();
			printf("Which football event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforFootball(index);
			break;
		case 2:
			printBasketball();
			printf("Which basketball event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforBasketball(index);
			break;
		case 3:
			printBaseball();
			printf("Which baseball event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforBaseball(index);
			break;
		case 4:
			printHockey();
			printf("Which hockey event do you want to book a ticket for? Input ID: ");
			scanf("%d", &index);
			bookforHockey(index);
			break;
		case 0:
			the_end = 1;
			saveEvents();
			exit(1);
		default:
			printf("Invalid input. Please enter a number between 1 and 4 or 0 to save bookings and exit.\n");
			Sleep(750);
			break;
		}
	}
}
	
//function to display the sport categories..
void disp_menuUser(void)
{
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


//ticket booking for game football...
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
				Sleep(1000);
				return 0;
			}
			if (temp->data.tickets <= 0)
			{
				printf("The tickets for this Event have been sold out");
				Sleep(1000);
				return 0;
			}
			x = rand() % temp->data.tickets + 1; //random allocation for seat.....from available tickets.......
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x);  //printing the seat number after random allocation....
			Sleep(1000);

			temp->data.tickets--; //decrement as one of the seat is abooked ..so it's  decremented..
			break;
		}
		temp = temp->next;   
	}
	return 1;
}
//ticket booking for game basketball...
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
			x = rand() % temp->data.tickets + 1;//random allocation for seat.....from available tickets.......
			printf("Your ticket for event: %s; is: %d\n", temp->data.eventName, x); //printing the seat number after random allocation....

			temp->data.tickets--;//decrement as one of the seat is abooked ..so it's  decremented..
			break;
		}
		temp = temp->next;
	}
	return 1;
}
//ticket booking for game baseball...
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
//ticket booking for game hockey...
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

//function to print all the inventory of baseball game.....
void printBaseball(void)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, "Baseball") == 0) //if it is baseball..print......baseball detailss...
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
//function to print all the inventory of football game.....
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
//function to print all the inventory of hockey game.....
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

//function to print all the inventory of basketball game.....
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

