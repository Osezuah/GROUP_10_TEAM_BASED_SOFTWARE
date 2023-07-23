#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hockey.h"

#define LIMIT 40
#define MAX_SEATS 100

struct hockeyGame
{
    char stadium[LIMIT];
    char tournament[LIMIT];
    char date[LIMIT];
    char time[LIMIT]; // time in 24-hour format for no confusion
    int availableTickets;
    float ticketPrice;
};

// The software shall incorporate a random number generator
// This function would randomly generate a seat number for the user
int randomseat_hockey(int availableSeats)
{
    srand(time(NULL));
    return rand() % availableSeats + 1;
}

// This functionality is mainly for demonstration purposes
// The inventory would typically be managed by the organizer
void writeHockeyInventory()
{
    struct hockeyGame games[] = {
        {"Ice Arena 1", "League P", "August 5, 2023", "17:30", 100, 20.0},
        {"Ice Arena 2", "Cup Q", "August 20, 2023", "18:00", 150, 25.0},
        {"Ice Arena 3", "Tournament R", "September 10, 2023", "19:15", 120, 30.0},
        // Add more games here if needed
    };

    FILE* fptr;
    fptr = fopen("INVENTORYhockey.txt", "w");

    if (fptr == NULL)
    {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < sizeof(games) / sizeof(struct hockeyGame); i++)
    {
        fwrite(&games[i], sizeof(struct hockeyGame), 1, fptr);
    }

    fclose(fptr);

    printf("Hockey inventory data written to the file successfully!\n");
}

void displayHockeyInventory()
{
    FILE* fptr;
    fptr = fopen("INVENTORYhockey.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct hockeyGame game;
    int gameCount = 0;

    printf("Hockey Inventory:\n");
    printf("-----------------\n");

    while (fread(&game, sizeof(struct hockeyGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %.2f\n", game.ticketPrice);
        printf("\n");
        gameCount++;
    }

    fclose(fptr);
}

void bookHockeyGame()
{
    FILE* fptr;
    fptr = fopen("INVENTORYhockey.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    struct hockeyGame game;
    int gameCount = 0;

    printf("Select a game to book tickets:\n");

    while (fread(&game, sizeof(struct hockeyGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %.2f\n", game.ticketPrice);
        printf("\n");
        gameCount++;
    }

    fclose(fptr);

    // Prompting the user to choose a game tournament
    int gameChoice;
    printf("Enter the game number to book tickets (1-%d): ", gameCount);
    scanf_s("%d", &gameChoice);

    // Input validation to check if any such game exists or not
    if (gameChoice < 1 || gameChoice > gameCount)
    {
        printf("Invalid game selection!\n");
        return;
    }

    // Open the inventory file in read-write mode
    fptr = fopen("INVENTORYhockey.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    // Move the file pointer to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct hockeyGame), SEEK_SET);

    // Read the selected game
    fread(&game, sizeof(struct hockeyGame), 1, fptr);

    // Check if there are available tickets for the selected game
    if (game.availableTickets <= 0)
    {
        printf("No available tickets for the selected game!\n");
        fclose(fptr);
        return;
    }

    // Decrement the available tickets count by 1
    game.availableTickets--;

    // Move the file pointer back to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct hockeyGame), SEEK_SET);

    // Write the updated game back to the file
    fwrite(&game, sizeof(struct hockeyGame), 1, fptr);

    fclose(fptr);

    // Assign a random seat to the user
    int seatNumber = randomseat_hockey(MAX_SEATS);
    printf("Seat number %d booked for the game!\n", seatNumber);
}

void hockey()
{
    printf("Hockey selected!\n");
    displayHockeyInventory();
    bookHockeyGame();
}
