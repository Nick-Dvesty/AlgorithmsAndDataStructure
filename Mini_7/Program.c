#include "insertMergeSort.h"
#include <stdio.h>
int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++){
        printf("Enter %d element: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("->");
    mergeSort(0,size,array);
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    return 0;
}