#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "user.h"

eventNode* first_event = NULL;
eventNode* last_event = NULL;



void mainMenu()
{
	//TRZEBA DODAC SPANIE GDZIES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	srand(time(NULL));
	disp_menu2();
	int choice;
	int index;

	while (1)
	{
		disp_menu2();
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

void disp_menu2(void)
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
			printf("Time: %d:d\n", temp->data.times.hour, temp->data.times.minute);
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
			printf("Time: %d:d\n", temp->data.times.hour, temp->data.times.minute);
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
			printf("Time: %d:d\n", temp->data.times.hour, temp->data.times.minute);
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
			printf("Time: %d:d\n", temp->data.times.hour, temp->data.times.minute);
			printf("Date: %d/%d/%d\n", temp->data.dates.day, temp->data.dates.month, temp->data.dates.year);
			printf("Amount of tickets avaliable: %d\n", temp->data.tickets);
			printf("Price per ticket: %lf\n", temp->data.price);
			printf("Organizer: %s\n", temp->data.organizer);
			printf("\n");
		}
		temp = temp->next;
	}
}



void loadEvents(void)
{
	eventNode* temp;
	FILE* file;
	int id = 0;
	int No = 1;
	int dd, mm, yyyy, hh, min, cap;
	double price;
	char c[SPORT], n[MAX_EVENT_NAME], on[MAX_ORG_NAME], place[MAX_PLACE], t[5], tem;


	file = fopen("event.txt", "r");
	if (file != NULL)
	{
		while (No > 0)
		{
			No = fscanf(file, "%[^;]", c);
			fgetc(file);
			fgetc(file);
			fscanf(file, "%[^;]", n);
			fgetc(file);
			fgetc(file);
			fscanf(file, "%[^;]", place);
			fgetc(file);
			fgetc(file);
			fscanf(file, "%d:%d; %d/%d/%d; %d; %lf; %s", &hh, &min, &dd, &mm, &yyyy, &cap, &price, on);
			fgetc(file);
			if (No > 0)
			{
				temp = malloc(sizeof(eventNode));
				id++;
				temp->data.eventID = id;
				strcpy(temp->data.category, c);
				strcpy(temp->data.eventName, n);
				strcpy(temp->data.place, place);
				temp->data.times.hour = hh;
				temp->data.times.minute = min;
				temp->data.dates.day = dd;
				temp->data.dates.month = mm;
				temp->data.dates.year = yyyy;
				temp->data.tickets = cap;
				temp->data.price = price;
				strcpy(temp->data.organizer, on);
				temp->prev = last_event;
				temp->next = NULL;
				if (first_event != NULL) last_event->next = temp;
				else
				{
					first_event = temp;
					temp->prev = NULL;
				}
				last_event = temp;
			}
		}
		fclose(file);
	}
	return;
}


void saveEvents(void)
{
	FILE* file;
	eventNode* temp;

	file = fopen("event.txt", "w");
	if (file != NULL)
	{
		while (first_event != NULL)
		{
			temp = first_event;
			first_event = temp->next;
			fprintf(file, "%s; %s; %s; %d:%d; %d/%d/%d; %d; %lf; %s\n", temp->data.category, temp->data.eventName, temp->data.place, temp->data.times.hour, temp->data.times.minute, temp->data.dates.day, temp->data.dates.month, temp->data.dates.year, temp->data.tickets, temp->data.price, temp->data.organizer);
			free(temp);
		}
		fclose(file);
	}
}