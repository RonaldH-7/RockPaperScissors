#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_name()
{
	static char name[20];
	printf("Enter your name: ");
	scanf("%19s", name);
	return name;
}

char *get_user_choice()
{
	static char user_choice[9];
	printf("What will you throw? (rock, paper, or scissors in lowercase)\n");
	scanf("%8s", user_choice);
	return user_choice;
}

char *get_computer_choice()
{
	srand(time(NULL));
	int random_number = (rand() % 3) + 1;
	
	static char computer_choice[9];
	
	if (random_number == 1)
		strcpy(computer_choice, "rock");
	else if (random_number == 2)
		strcpy(computer_choice, "paper");
	else
		strcpy(computer_choice, "scissors");
	
	return computer_choice;
}

void get_results(char name[], char user_choice[], char computer_choice[])
{
	if (strcmp(user_choice, computer_choice) == 0)
		printf("It's a tie!");
	else if (strcmp(user_choice, "rock") == 0 && strcmp(computer_choice, "scissors") == 0)
		printf("Rock beats scissors, %s wins!", name);
	else if (strcmp(user_choice, "paper") == 0 && strcmp(computer_choice, "rock") == 0)
		printf("Paper beats rock, %s wins!", name);
	else if (strcmp(user_choice, "scissors") == 0 && strcmp(computer_choice, "paper") == 0)
		printf("Scissors beats paper, %s wins!", name);
	else if (strcmp(user_choice, "rock") == 0 && strcmp(computer_choice, "paper") == 0)
		printf("Paper beats rock, the computer wins!", name);
	else if (strcmp(user_choice, "paper") == 0 && strcmp(computer_choice, "scissors") == 0)
		printf("Scissors beats paper, the computer wins!", name);
	else if (strcmp(user_choice, "scissors") == 0 && strcmp(computer_choice, "rock") == 0)
		printf("Rock beats scissors, the computer wins!", name);
		
}

void interface()
{
	
	char *name = get_name();
	char command[2] = "Y";
	
	do {
		printf("\nStarting new game...\n");
		
		char *user_choice = get_user_choice();
		char *computer_choice = get_computer_choice();
		
		printf("\n%s chooses %s, computer chooses %s\n", name, user_choice, computer_choice);
		
		get_results(name, user_choice, computer_choice);
		

		printf("\n\nWould you like to play again? \nY/N: ");
		scanf("%1s", command);
	} while (strcmp(command, "y") == 0 || strcmp(command, "Y") == 0);
	
	printf("\nThanks for playing!");
}

int main()
{
	interface();
}

