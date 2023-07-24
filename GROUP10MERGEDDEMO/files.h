#pragma once

#define SPORT 11
#define MAX_ORG_NAME 150
#define MAX_EVENT_NAME 100
#define MAX_PLACE 50

typedef struct Date {
    int day;
    int month;
    int year;
}date;

typedef struct Time {
    int hour;
    int minute;
}TIME;

typedef struct Stadium
{
    int stadiumID;
    char category[SPORT];
    char place[MAX_PLACE];
    int capacity;
} stadium;

typedef struct Event {
    int eventID;
    char category[SPORT];
    char eventName[MAX_EVENT_NAME];
    char place[MAX_PLACE];
    TIME times;
    date dates;
    int tickets;
    double price;
    char organizer[MAX_ORG_NAME];
} event;

typedef struct EventNode {
    event data;
    struct EventNode* prev;
    struct EventNode* next;
} eventNode;

void loadEvents(void);
void saveEvents(void);

