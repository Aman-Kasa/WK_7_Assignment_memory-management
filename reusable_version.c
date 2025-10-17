#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50

/* Allocate memory for email array */
char **allocate_emails(int count)
{
    char **emails = malloc(count * sizeof(char *));
    if (!emails) return NULL;
    
    for (int i = 0; i < count; i++) {
        emails[i] = malloc(MAX_EMAIL_LENGTH);
        if (!emails[i]) {
            while (--i >= 0) free(emails[i]);
            free(emails);
            return NULL;
        }
    }
    return emails;
}

/* Read emails from user */
void read_emails(char **emails, int count)
{
    for (int i = 0; i < count; i++) {
        printf("Enter email %d: ", i + 1);
        if (!fgets(emails[i], MAX_EMAIL_LENGTH, stdin)) {
            printf("Input error.\n");
            exit(1);
        }
        emails[i][strcspn(emails[i], "\n")] = '\0';
    }
}

/* Display email list */
void display_emails(char **emails, int count)
{
    printf("\nEmail addresses:\n");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, emails[i]);
}

/* Resize email array */
char **resize_emails(char **emails, int old_count, int new_count)
{
    if (new_count < old_count) {
        for (int i = new_count; i < old_count; i++)
            free(emails[i]);
    }
    
    char **temp = realloc(emails, new_count * sizeof(char *));
    if (!temp && new_count > 0) {
        for (int i = 0; i < (new_count < old_count ? new_count : old_count); i++)
            free(emails[i]);
        free(emails);
        return NULL;
    }
    return temp;
}

/* Free all email memory */
void free_emails(char **emails, int count)
{
    for (int i = 0; i < count; i++)
        free(emails[i]);
    free(emails);
}

int main(void)
{
    const int INITIAL_COUNT = 10;
    const int FINAL_COUNT = 6;
    
    /* Allocate and read emails */
    char **emails = allocate_emails(INITIAL_COUNT);
    if (!emails) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    read_emails(emails, INITIAL_COUNT);
    display_emails(emails, INITIAL_COUNT);
    
    /* Resize to 6 students */
    emails = resize_emails(emails, INITIAL_COUNT, FINAL_COUNT);
    if (!emails) {
        printf("Resize failed.\n");
        return 1;
    }
    
    printf("\nAfter shrinking to %d students:\n", FINAL_COUNT);
    display_emails(emails, FINAL_COUNT);
    
    free_emails(emails, FINAL_COUNT);
    return 0;
}
