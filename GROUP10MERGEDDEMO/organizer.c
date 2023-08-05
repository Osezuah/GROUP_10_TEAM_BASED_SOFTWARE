//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "files.h"
#include "organizer.h"


extern eventNode* first_event;
extern eventNode* last_event;

//function to display options for organizer module...
void disp_menu1(void)
{
	system("cls");
	printf("\n\n\n\n\n\n\n");
	printf("                               *****************************************************\n");
	printf("                               *                                                   *\n");
	printf("                               *             Welcome to stadium booking            *\n");
	printf("                               *                                                   *\n");
	printf("                               *                  Select option:                   *\n");
	printf("                               *                                                   *\n");
	printf("                               *****************************************************\n");
	printf("                               *                                                   *\n");
	printf("                               *         1.  Book a stadium for an event           *\n");
	printf("                               *         2.  Change existing event details         *\n");
	printf("                               *         3.  Cancel your event                     *\n");
	printf("                               *         4.  List all events with your ID          *\n");
	printf("                               *                                                   *\n");
	printf("                               *                    0.  EXIT                       *\n");
	printf("                               *                                                   *\n");
	printf("                               *****************************************************\n");
}

//function to display the sport categories..
void disp_menu2(void)
{
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
	printf("                               *****************************************************\n");
}

//mainmenu function that holds all the other organizer functions..dipslays the organizer functionalities and then sport selection menu accordingly..
void mainMenu(const unsigned char* organizerName)
{
	Sleep(1000);
	loadEvents();
	int choice;
	event newEvent;
	int index;
	char cat[SPORT] = "";
	int end = 0;


	disp_menu1();
	while (end == 0) {
		printf("Enter a number (1-4) or 0 to save the event and exit: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			disp_menu2();
			AddNewEvent(&newEvent, organizerName);
			break;
		case 2:
			printAllEventsOfThatOrganizer(organizerName);
			printf("Choose an ID of the event do you want to update: \n");
			scanf_s("%d", &index);
			Update_an_event(index, organizerName);
			break;
		case 3:
			printAllEventsOfThatOrganizer(organizerName);
			printf("Which event do you want to cancel: \n");
			scanf_s("%d", &index);
			removeEvent(index, organizerName);
			break;
		case 4:
			printAllEventsOfThatOrganizer(organizerName);
			break;
		case 0:
			end = 1;
			saveEvents(); //save the linked list to the file..
			exit(1);
		default:
			printf("Invalid input. Please enter a number between 1 and 4 or 0 to exit.\n");
			Sleep(750);
			break;
		}
	}
}



//function to add new event to the linked list.. 

void AddNewEvent(event* newEvent, const unsigned char* organizerName)//char*
{
	eventNode* temp;
	int dd, mm, yyyy, hh, min, id;
	double price = 0.0;
	int cap = 0;
	char n[MAX_EVENT_NAME], on[MAX_ORG_NAME], place[MAX_PLACE];
	int chi;
	char c[SPORT] = "";


	printf("Enter the number of the sport category (1-4): ");
	scanf_s("%d", &chi);

	// Map the choice to the corresponding category
	switch (chi)
	{
	case 1:
		strcpy(c, "Football");
		break;
	case 2:
		strcpy(c, "Basketball");
		break;
	case 3:
		strcpy(c, "Baseball");
		break;
	case 4:
		strcpy(c, "Hockey");
		break;
	default:
		printf("Invalid category choice. Using default category.\n");
		break;
	}
	printf("Enter the event name: ");
	scanf(" %[^\n]", n);

	printf("Enter the place: ");
	scanf(" %[^\n]", place);

	printf("Enter the the hour as hh: ");
	scanf_s("%d", &hh);

	printf("Enter the the minute as mm: ");
	scanf_s("%d", &min);

	printf("Enter the the day as dd: ");
	scanf_s("%d", &dd);

	printf("Enter the month as mm: ");
	scanf_s("%d", &mm);

	printf("Enter the year as yyyy: ");
	scanf_s("%d", &yyyy);

	printf("Enter the capacity: ");
	scanf_s("%d", &cap);

	printf("Enter the price: ");
	scanf_s("%lf", &price);

	strcpy(on, organizerName);

	temp = malloc(sizeof(eventNode)); //memory allocation..
	if (first_event == NULL)
	{
		id = 1;
		first_event = temp;
		temp->prev = NULL;
	}
	else
	{
		id = last_event->data.eventID + 1;
		temp->prev = last_event;
		last_event->next = temp;
	}
	temp->next = NULL; // putting the user input details of an event inside of the linekd list..
	last_event = temp;
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
	temp->data.eventID = id;
}

//function to update the details of an event...
void Update_an_event(int eventID, const unsigned char* organizerName)
{
	eventNode* temp = first_event;
	while (temp != NULL)
	{
		if (temp->data.eventID == eventID)
		{
			if (strcmp(temp->data.organizer, organizerName) != 0)
			{
				printf("This is not your event. Please choose one of yours.\n");
				return;
			}

			char choice;
			//it asks each time for input..

			printf("Do you want to update the name? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
			//if input is Y or y then it asks for new element and overwrites into the linked list.....
			//if the input is not y ot Y it goes to the next detail....
			if (choice == 'Y' || choice == 'y')
			{
				printf("Enter the new event name: ");
				scanf(" %[^\n]", temp->data.eventName);
			}

			printf("Do you want to update the place? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				printf("Enter the new place: ");
				scanf(" %[^\n]", temp->data.place);
			}

			printf("Do you want to update the time? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				printf("Enter the new hour as hh: ");
				scanf("%d", &temp->data.times.hour);

				printf("Enter the new minute as mm: ");
				scanf("%d", &temp->data.times.minute);
			}

			printf("Do you want to update the date? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				printf("Enter the new day as dd: ");
				scanf("%d", &temp->data.dates.day);

				printf("Enter the new month as mm: ");
				scanf("%d", &temp->data.dates.month);

				printf("Enter the new year as yyyy: ");
				scanf("%d", &temp->data.dates.year);
			}

			printf("Do you want to update the price? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				printf("Enter the new price: ");
				scanf("%lf", &temp->data.price);
			}

			printf("Event with ID %d updated successfully!\n", eventID);
			return;
		}
		temp = temp->next;
	}
	printf("Event with ID %d not found!\n", eventID);
}

//function to remove an event given it's iD....
int removeEvent(int eventID, const unsigned char* organizerName)
{
	eventNode* temp = first_event;

	while (temp != NULL)
	{
		if (temp->data.eventID == eventID)
		{
			if (strcmp(temp->data.organizer, organizerName) != 0)
			{
				printf("This is not your event. Please choose one of yours.\n");
				return 0;
			}
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

//function to print all the events matching organizer ID........
void printAllEventsOfThatOrganizer(const unsigned char* organizerName)
{
	eventNode* temp = first_event;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.organizer, organizerName) == 0)
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
