#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure for a Day
typedef struct {
    char *dayName;       // dynamically allocated string for day name
    int date;            // date of the day
    char *activity;      // dynamically allocated string for activity
} Day;
// Function prototypes
Day* create(int size);
void read(Day *calendar, int size);
void display(Day *calendar, int size);
void freeCalendar(Day *calendar, int size);
int main() {
    int size = 7;  // 7 days in a week
    // Create calendar
    Day *calendar = create(size);
    // Read data from user
    read(calendar, size);
    // Display weekly activities
    display(calendar, size);
    // Free allocated memory
    freeCalendar(calendar, size);
    return 0;
}
// Function to create a dynamically allocated calendar array
Day* create(int size) {
    Day *calendar = (Day*) malloc(size * sizeof(Day));
    if (calendar == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return calendar;
}
// Function to read details for each day
void read(Day *calendar, int size) {
    char temp[100];
    printf("Enter details for 7 days:\n");
    for (int i = 0; i < size; i++) {
        printf("\nDay %d:\n", i + 1);
        // Read day name
        printf("Enter day name: ");
        scanf(" %[^\n]", temp);
        calendar[i].dayName = (char*) malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(calendar[i].dayName, temp);
        // Read date
        printf("Enter date: ");
        scanf("%d", &calendar[i].date);
        // Read activity description
        printf("Enter activity: ");
        scanf(" %[^\n]", temp);
        calendar[i].activity = (char*) malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(calendar[i].activity, temp);
    }
}
// Function to display the weekly activities
void display(Day *calendar, int size) {
    printf("\n\n===== WEEKLY ACTIVITY REPORT =====\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Day: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("-----------------------------------\n");
    }
}
// Function to free dynamically allocated memory
void freeCalendar(Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
    free(calendar);
}
