#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_EMAILS 10
#define NEW_TOTAL 6
#define MAX_LENGTH 50  /* 49 + 1 for '\0' */

/* Function to read emails */
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

/* Function to display emails */
void display_emails(char **emails, int count)
{
	int i;
	printf("\nEmail addresses:\n");
	for (i = 0; i < count; i++)
		printf("%d. %s\n", i + 1, emails[i]);
}

/* Function to free emails */
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

	/* Allocate memory for 10 emails */
	emails = malloc(TOTAL_EMAILS * sizeof(char *));
	if (!emails)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	for (i = 0; i < TOTAL_EMAILS; i++)
	{
		emails[i] = malloc(MAX_LENGTH * sizeof(char));
		if (!emails[i])
		{
			printf("Memory allocation failed for email %d.\n", i + 1);
			/* Free previously allocated memory */
			while (--i >= 0)
				free(emails[i]);
			free(emails);
			return 1;
		}
	}

	/* Read and display emails */
	read_emails(emails, TOTAL_EMAILS);
	display_emails(emails, TOTAL_EMAILS);

	/* Shrink array to 6 students */
	emails = realloc(emails, NEW_TOTAL * sizeof(char *));
	if (!emails)
	{
		printf("Reallocation failed.\n");
		return 1;
	}

	printf("\nAfter shrinking to %d students:\n", NEW_TOTAL);
	display_emails(emails, NEW_TOTAL);

	/* Free memory for the retained emails */
	for (i = 0; i < NEW_TOTAL; i++)
		free(emails[i]);
	free(emails);

	return 0;
}

