#include <stdio.h>
#include <string.h>

void rotateString(char* str, int rotations, char direction) {
    int len = strlen(str);
    int i, j;
    char temp;
    
    if (direction == 'L') {
        // Rotate string to the left
        for (i = 0; i < rotations; i++) {
            temp = str[0];
            
            for (j = 0; j < len - 1; j++) {
                str[j] = str[j + 1];
            }
            
            str[len - 1] = temp;
        }
    }
    else if (direction == 'R') {
        // Rotate string to the right
        for (i = 0; i < rotations; i++) {
            temp = str[len - 1];
            
            for (j = len - 1; j > 0; j--) {
                str[j] = str[j - 1];
            }
            
            str[0] = temp;
        }
    }
}

int main() {
    char str[100];
    int rotations;
    char direction;
    
    printf("Enter the string: ");
    scanf("%s", str);
    
    printf("Enter the number of rotations: ");
    scanf("%d", &rotations);
    
    printf("Enter the direction (L/R): ");
    scanf(" %c", &direction);
    
    rotateString(str, rotations, direction);
    
    printf("Rotated String: %s\n", str);
    
    return 0;
}
