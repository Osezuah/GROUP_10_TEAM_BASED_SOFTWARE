#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "files.h"
#include "organizer.h"


extern eventNode* first_event;
extern eventNode* last_event;




//stadiumNode* first_stadium = NULL;
//stadiumNode* last_stadium = NULL;

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

void mainMenu(const unsigned char* organizerName)
{
	Sleep(5000);
	loadEvents();
	int choice;
	event newEvent;
	int index;
	char cat[SPORT] = "";


	disp_menu1();
	while (1) {
		printf("Enter a number (1-4) or 0 to save the event and exit: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			disp_menu2();
			//sportselect(cat);
			//printAllStadiumsofThatSport(cat);
			AddNewEvent(&newEvent, organizerName); //char*
			saveEvents();
			//saveStadiums();
			break;
		case 2:
			system("cls");
			printAllEventsOfThatOrganizer(organizerName);
			printf("Choose an ID of the event do you want to update: \n");
			scanf_s("%d", &index);
			Update_an_event(index, organizerName);
			saveEvents();
			break;
		case 3:
			system("cls");
			printAllEventsOfThatOrganizer(organizerName);
			printf("Which event do you want to cancel: \n");
			scanf_s("%d", &index);
			removeEvent(index, organizerName);
			saveEvents();
			break;
		case 4:
			system("cls");
			printAllEventsOfThatOrganizer(organizerName);
			break;
		case 0:
			return;
		default:
			printf("Invalid input. Please enter a number between 1 and 4 or 0 to exit.\n");
			break;
		}
	}
}




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
	//printf("Enter the sport: ");
	//scanf("%s", c);
	//strcpy(c, cat);

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

	//printf("Enter the organizer's name: ");
	//scanf(" %s", on);



	temp = malloc(sizeof(eventNode));
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
	temp->next = NULL;
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
			printf("Do you want to update the name? (Y/any other char to skip): ");
			fflush(stdin);
			scanf(" %c", &choice);
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


/*
void printAllStadiumsofThatSport(char* cat)
{
	stadiumNode* temp = first_stadium;

	printf("List of Events:\n");
	while (temp != NULL)
	{
		if (strcmp(temp->data.category, cat) == 0)
		{
			printf("Event ID: %d\n", temp->data.stadiumID);
			printf("Category: %s\n", temp->data.category);
			printf("Event Name: %s\n", temp->data.place);
			printf("Event Name: %d\n", temp->data.capacity);
			printf("\n");
		}
		temp = temp->next;
	}
}
*/

/*void loadEvents(void)
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
}*/

/*void saveEvents(void)
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
}*/

/*void sportselect(char* cat)
{
	int c = 0;
	char category[4][11] = { "Football","Basketball","Baseball","Hockey" };
	disp_menu2();
	printf("What type of stadium are you looking for?");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		strcpy(cat, category[0]);
		break;
	case 2:
		strcpy(cat, category[1]);
		break;
	case 3:
		strcpy(cat, category[2]);
		break;
	case 4:
		strcpy(cat, category[3]);
		break;
	default:
		printf("Thats not a valid input");
		break;

	}
}

void loadStadiums(void)
{
	stadiumNode* temp;
	FILE* file;
	int id = 0;
	int No = 1;
	int capacity;
	char c[SPORT], p[MAX_PLACE];



	file = fopen("stadium.txt", "r");
	if (file != NULL)
	{
		while (No > 0)
		{
			No = fscanf(file, "%s", c);
			fgetc(file);
			fgetc(file);
			fscanf(file, "[^;]%s", p);
			fgetc(file);
			fgetc(file);
			fscanf(file, "%d", &capacity);
			fgetc(file);
		}
		if (No > 0)
		{
			temp = malloc(sizeof(stadiumNode));
			id++;
			temp->data.stadiumID = id;
			strcpy(temp->data.category, c);
			strcpy(temp->data.place, p);
			temp->data.capacity = capacity;
			temp->prev = last_stadium;
			temp->next = NULL;
			if (first_stadium != NULL) last_stadium->next = temp;
			else
			{
				first_stadium = temp;
				temp->prev = NULL;
			}
			last_stadium = temp;
		}
		fclose(file);
	}
	return;
}

void saveStadiums(void)
{
	FILE* file;
	stadiumNode* temp;

	file = fopen("stadium.txt", "w");
	if (file != NULL)
	{
		while (first_event != NULL)
		{
			temp = first_event;
			first_event = temp->next;
			fprintf(file, "%s; %s; %d\n", temp->data.category, temp->data.place, temp->data.capacity);
			free(temp);
		}
		fclose(file);
	}
}*/

void press_key(void)
{
	printf("\nPress any key to continue...");
	getch();
}

/*int Update_an_event(int id, char* organizerName)
{
	eventNode* temp;
	char newName[MAX_EVENT_NAME];
	char c;
	int day, year, month;
	int ok = 0;
	int found = 0;
	int d;

	temp = first_event;

	while (temp != NULL && !found)
	{
		if (temp->data.eventID == id)
		{
			if (strcmp(temp->data.organizer, organizerName) != 0)
			{
				printf("This is not your event. You cannot update it.\n");
				return 0;
			}
			found = 1;
			while (!ok)
			{
				printf("Do you want to update the date?: (Y/N)");
				scanf(" %c", &c);
				switch (c)
				{
				case 'Y':
					printf("Enter new day: \n");
					ok = 0;
					while (!ok)
					{
						scanf("%d", &day);
						if (day > 0 && day < 32) ok = 1;
						else printf("That is not a valid day! Enter again: \n");
					}
					temp->data.dates.day = day;
					printf("Enter new month: \n");
					ok = 0;
					while (!ok)
					{
						scanf("%d", &month);
						if (month > 0 && month < 13) ok = 1;
						else printf("That is not a valid month! Enter again: \n");
					}
					temp->data.dates.month = month;
					printf("Enter new year: \n");
					scanf("%d", &year);
					temp->data.dates.year = year;
					ok = 1;
					break;
				case 'N':
					ok = 1;
					break;
				default:
					printf("Please enter valid Input!: \n");
					break;
				}
				ok = 0;
				while (!ok)
				{
					printf("Do you want to update the Name (Y/N): \n");
					scanf(" %c", &c);
					switch (c)
					{
					case 'Y':
						printf("Enter new name for event %d:\n", id);
						while ((d = getchar()) != '\n' && c != EOF) {}
						fgets(newName, MAX_EVENT_NAME, stdin);
						strcpy(temp->data.eventName, newName);
						ok = 1;
						break;
					case 'N':
						ok = 1;
						break;
					default:
						printf("Please enter valid input: \n");
						break;
					}
				}
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	if (!found)
	{
		printf("No event with ID %d found!\n", id);
	}

	return found;
}*/