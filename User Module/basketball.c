#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "basketball.h"

#define LIMIT 40
#define MAX_SEATS 100

struct basketballGame
{
    char stadium[LIMIT];
    char tournament[LIMIT];
    char date[LIMIT];
    char time[LIMIT];  //time in 24 hour format for no confusion..
    int availableTickets;
    float ticketPrice;
};

//The software shall incorporate a random number generator..we included this..this function would randomly generate seat number to the user.
int randomseat_Basketball(int availableSeats)
{
    srand(time(NULL));
    return rand() % availableSeats + 1;
}

//this functionality is to chcek as of now n the indiviudal part. Mainly this inventory woud. be by the organizer..
void writeBasketballInventory()
{
    struct basketballGame games[] = {
        {"XYZ Arena", "ABC Cup", "July 20, 2023", "18:00", 200, 30.0},
        
    };

    FILE* fptr;
    fptr = fopen("INVENTORYbasketball.txt", "a");

    if (fptr == NULL)
    {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < sizeof(games) / sizeof(struct basketballGame); i++)
    {
        fwrite(&games[i], sizeof(struct basketballGame), 1, fptr);
    }

    fclose(fptr);

    printf("Basketball inventory data written to the file successfully\n");
}

void displayBasketballInventory()
{
    FILE* fptr;
    fptr = fopen("INVENTORYbasketball.txt", "r"); //open the file in read mode.

    //if not able to open..
    if (fptr == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct basketballGame game;
    int gameCount = 0;

    printf("Basketball Inventory:\n");
    printf("---------------------\n");

    while (fread(&game, sizeof(struct basketballGame), 1, fptr))
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

void bookBasketballGame()
{
    FILE* fptr;
    fptr = fopen("INVENTORYbasketball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    struct basketballGame game;
    int gameCount = 0;

    printf("Select a game to book tickets:\n");

    while (fread(&game, sizeof(struct basketballGame), 1, fptr))
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

    // Prompting the user to choose a game tournament..
    int gameChoice;
    printf("Enter the game number to book tickets (1-%d): ", gameCount);
    scanf_s("%d", &gameChoice);

    // Input validation...to check if any such game exists or not..
    if (gameChoice < 1 || gameChoice > gameCount)
    {
        printf("Invalid game selection!\n");
        return;
    }

    // Open the inventory file in read,write mode
    fptr = fopen("INVENTORYbasketball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    // Move the file pointer to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct basketballGame), SEEK_SET);

    // Read the selected game
    fread(&game, sizeof(struct basketballGame), 1, fptr);

    // if condition to check if there are available tickets for the selected game
    if (game.availableTickets <= 0)
    {
        printf("No available tickets for the selected game!\n");
        fclose(fptr);
        return;
    }

    // Decrement the available tickets count by 1
    game.availableTickets--;

    // Move the file pointer back to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct basketballGame), SEEK_SET);

    // Write the updated game back to the file
    fwrite(&game, sizeof(struct basketballGame), 1, fptr);

    fclose(fptr);

    // Assign a random seat to the user
    int seatNumber = randomseat_Basketball(MAX_SEATS);
    printf("Seat number %d booked for the game!\n", seatNumber);
}

void basketball()
{
    printf("Basketball selected!\n");
    displayBasketballInventory();
    bookBasketballGame();
}
