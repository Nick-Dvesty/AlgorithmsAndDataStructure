#include "InversionCounter.h"
#include <stdio.h>
int main() {
    int quantitInversion = 0; 
    size_t size;
    printf("Enter size of the array: ");
    scanf("%zu", &size);
    int array[size];
    for(int i = 0; i < size; i++){
        printf("Enter %d element: ", i + 1);
        scanf("%d", &array[i]);
    }
    merge_sort(&quantitInversion, array, 0, size);
    printf("Inversion: %d", quantitInversion);
    return 0;
}