#ifndef EMAIL_MANAGER_H
#define EMAIL_MANAGER_H

#define MAX_EMAIL_LENGTH 50

char **allocate_emails(int count);
void read_emails(char **emails, int count);
void display_emails(char **emails, int count);
char **resize_emails(char **emails, int old_count, int new_count);
void free_emails(char **emails, int count);

#endif
