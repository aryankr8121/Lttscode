#include <stdio.h>

int main() {
    int arr[10];
    int len, i;
    int sum = 0;
    float avg;
    
    printf("Enter the length of the array (up to 10): ");
    scanf("%d", &len);
    
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    avg = (float)sum / len;
    
    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    
    return 0;
}
