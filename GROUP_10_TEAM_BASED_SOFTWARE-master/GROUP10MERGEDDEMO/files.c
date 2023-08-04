#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "files.h"

extern eventNode* first_event;
extern eventNode* last_event;

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