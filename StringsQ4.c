#include <stdio.h>
#include <stdlib.h> // for atoi function
#include <string.h> // for strtok function

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int countDays(const char* dateString) {
    char* token;
    int day, month, year;
    
    // Tokenize the date string using strtok
    token = strtok((char*)dateString, "/");
    
    // Convert the day token to integer
    day = atoi(token);
    
    // Tokenize for month
    token = strtok(NULL, "/");
    month = atoi(token);
    
    // Tokenize for year
    token = strtok(NULL, "/");
    year = atoi(token);
    
    // Define days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (isLeapYear(year))
        daysInMonth[2] = 29;
    
    // Calculate total days
    int totalDays = 0;
    
    for (int i = 1; i < month; i++)
        totalDays += daysInMonth[i];
    
    totalDays += day;
    
    return totalDays;
}

int main() {
    char dateString[11];
    
    printf("Enter the date in format DD/MM/YYYY: ");
    scanf("%s", dateString);
    
    int days = countDays(dateString);
    
    printf("Number of days elapsed: %d\n", days);
    
    return 0;
}
