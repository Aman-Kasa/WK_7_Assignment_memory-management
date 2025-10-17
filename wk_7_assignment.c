/**
 * Dynamic Email Management System
 * 
 * This program demonstrates dynamic memory allocation for managing
 * student email addresses. It allocates memory for 10 emails,
 * then efficiently shrinks to 6 using realloc().
 * 
 * Author: [Your Name]
 * Course: Week 7 Assignment - Memory Management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_EMAILS 10
#define NEW_TOTAL 6
#define MAX_LENGTH 50  /* 49 characters + 1 for null terminator */

/**
 * Reads email addresses from user input
 * @param emails: Array of string pointers to store emails
 * @param count: Number of emails to read
 */
void read_emails(char **emails, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("Enter email %d: ", i + 1);
		if (fgets(emails[i], MAX_LENGTH, stdin) == NULL)
		{
			printf("Input error.\n");
			exit(1);
		}
		/* Remove newline if present */
		emails[i][strcspn(emails[i], "\n")] = '\0';
	}
}

/**
 * Displays the list of email addresses
 * @param emails: Array of email strings to display
 * @param count: Number of emails to display
 */
void display_emails(char **emails, int count)
{
	int i;
	printf("\nEmail addresses:\n");
	for (i = 0; i < count; i++)
		printf("%d. %s\n", i + 1, emails[i]);
}

/**
 * Frees all dynamically allocated memory for emails
 * @param emails: Array of email pointers to free
 * @param count: Number of email strings to free
 */
void free_emails(char **emails, int count)
{
	int i;
	for (i = 0; i < count; i++)
		free(emails[i]);
	free(emails);
}

int main(void)
{
	char **emails;
	int i;

	/* Step 1: Allocate memory for array of 10 email pointers */
	emails = malloc(TOTAL_EMAILS * sizeof(char *));
	if (!emails)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	/* Step 2: Allocate memory for each individual email string */
	for (i = 0; i < TOTAL_EMAILS; i++)
	{
		emails[i] = malloc(MAX_LENGTH * sizeof(char));
		if (!emails[i])
		{
			printf("Memory allocation failed for email %d.\n", i + 1);
			/* Clean up previously allocated memory */
			while (--i >= 0)
				free(emails[i]);
			free(emails);
			return 1;
		}
	}

	/* Step 3: Read and display all 10 emails */
	read_emails(emails, TOTAL_EMAILS);
	display_emails(emails, TOTAL_EMAILS);

	/* Step 4: Free memory for emails that will be removed (emails 7-10) */
	for (i = NEW_TOTAL; i < TOTAL_EMAILS; i++)
		free(emails[i]);

	/* Step 5: Shrink array to hold only 6 students using realloc */
	char **temp = realloc(emails, NEW_TOTAL * sizeof(char *));
	if (!temp)
	{
		printf("Reallocation failed.\n");
		/* Free remaining memory before exit */
		for (i = 0; i < NEW_TOTAL; i++)
			free(emails[i]);
		free(emails);
		return 1;
	}
	emails = temp;

	printf("\nAfter shrinking to %d students:\n", NEW_TOTAL);
	display_emails(emails, NEW_TOTAL);

	/* Step 6: Clean up all remaining allocated memory */
	for (i = 0; i < NEW_TOTAL; i++)
		free(emails[i]);
	free(emails);

	return 0;
}

