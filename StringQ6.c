#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidEmail(const char* email) {
    int i, atSymbolPos = -1, dotSymbolPos = -1;
    int usernameLength = 0, domainLength = 0, extensionLength = 0;
    
    // Find the position of the '@' symbol
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atSymbolPos = i;
            break;
        }
    }
    
    // If no '@' symbol is found or it is the first or last character, the email is invalid
    if (atSymbolPos == -1 || atSymbolPos == 0 || atSymbolPos == i - 1)
        return 0;
    
    // Validate username
    for (i = 0; i < atSymbolPos; i++) {
        if (!isalnum(email[i]) && email[i] != '.')
            return 0;
        
        if (isalpha(email[i]))
            usernameLength++;
    }
    
    // Validate domain name and extension
    for (i = atSymbolPos + 1; email[i] != '\0'; i++) {
        if (email[i] == '.') {
            dotSymbolPos = i;
            break;
        }
        
        if (!isalpha(email[i]) || isupper(email[i]))
            return 0;
        
        domainLength++;
    }
    
    if (dotSymbolPos == -1 || dotSymbolPos == i - 1)
        return 0;
    
    for (i = dotSymbolPos + 1; email[i] != '\0'; i++) {
        if (!isalpha(email[i]) || isupper(email[i]))
            return 0;
        
        extensionLength++;
    }
    
    // Check if the lengths of username, domain, and extension are within the allowed limits
    if (usernameLength > 64 || domainLength < 2 || domainLength > 255 || extensionLength < 2 || extensionLength > 4)
        return 0;
    
    return 1;
}

int main() {
    char email[100];
    
    printf("Enter the email address: ");
    scanf("%s", email);
    
    if (isValidEmail(email))
        printf("Valid email address.\n");
    else
        printf("Invalid email address.\n");
    
    return 0;
}
