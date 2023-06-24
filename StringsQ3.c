#include <stdio.h>
#include <stdlib.h> // for strtol function
#include <string.h> // for strtok function

int computeTotalSeconds(const char* timeString) {
    char* token;
    int hours, minutes, seconds;
    
    // Tokenize the time string using strtok
    token = strtok((char*)timeString, ":");
    
    // Convert the hours token to integer
    hours = strtol(token, NULL, 10);
    
    // Tokenize for minutes
    token = strtok(NULL, ":");
    minutes = strtol(token, NULL, 10);
    
    // Tokenize for seconds
    token = strtok(NULL, ":");
    seconds = strtol(token, NULL, 10);
    
    // Calculate total seconds
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    
    return totalSeconds;
}

int main() {
    char timeString[9];
    
    printf("Enter the time in format hh:mm:ss: ");
    fgets(timeString, sizeof(timeString), stdin);
    
    // Remove the newline character from the string
    timeString[strcspn(timeString, "\n")] = '\0';
    
    int totalSeconds = computeTotalSeconds(timeString);
    
    printf("Total Seconds: %d\n", totalSeconds);
    
    return 0;
}
