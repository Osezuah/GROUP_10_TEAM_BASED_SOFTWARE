#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "football.h"

#define LIMIT 40
#define MAX_SEATS 100

struct footballGame
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
int randomseat_football(int availableSeats)
{
    srand(time(NULL));
    return rand() % availableSeats + 1;
}

// This functionality is mainly for demonstration purposes
// The inventory would typically be managed by the organizer
void writeFootballInventory()
{
    struct footballGame games[] = {
        {"Stadium A", "League X", "July 25, 2023", "19:30", 200, 30.0}    
    };

    FILE* fptr;
    fptr = fopen("INVENTORYfootball.txt", "w");

    if (fptr == NULL)
    {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < sizeof(games) / sizeof(struct footballGame); i++)
    {
        fwrite(&games[i], sizeof(struct footballGame), 1, fptr);
    }

    fclose(fptr);

    printf("Football inventory data written to the file successfully!\n");
}

void displayFootballInventory()
{
    FILE* fptr;
    fptr = fopen("INVENTORYfootball.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct footballGame game;
    int gameCount = 0;

    printf("Football Inventory:\n");
    printf("-------------------\n");

    while (fread(&game, sizeof(struct footballGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %f\n", game.ticketPrice);
        printf("\n");
        gameCount++;
    }

    fclose(fptr);
}

void bookFootballGame()
{
    FILE* fptr;
    fptr = fopen("INVENTORYfootball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    struct footballGame game;
    int gameCount = 0;

    printf("Select a game to book tickets:\n");

    while (fread(&game, sizeof(struct footballGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %f\n", game.ticketPrice);
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
    fptr = fopen("INVENTORYfootball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    // Move the file pointer to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct footballGame), SEEK_SET);

    // Read the selected game
    fread(&game, sizeof(struct footballGame), 1, fptr);

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
    fseek(fptr, (gameChoice - 1) * sizeof(struct footballGame), SEEK_SET);

    // Write the updated game back to the file
    fwrite(&game, sizeof(struct footballGame), 1, fptr);

    fclose(fptr);

    // Assign a random seat to the user
    int seatNumber = randomseat_football(MAX_SEATS);
    printf("Seat number %d booked for the game!\n", seatNumber);
}

void football()
{
    printf("Football selected!\n");
    displayFootballInventory();
    bookFootballGame();
}
