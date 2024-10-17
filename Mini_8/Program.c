#include "InversionCounter.h"
#include <stdio.h>
#include <stdbool.h>
bool isIdealPermutation(int* nums, int numsSize);
int main() {
    int globInversion = 0,locInverhion = 0;
    size_t size;
    printf("Enter size of the array: ");
    scanf("%zu", &size);
    int array[size];
    for(int i = 0; i < size; i++){
        printf("Enter %d element: ", i + 1);
        scanf("%d", &array[i]);
    }
    isIdealPermutation(array, size);
    exit(0);
    for (int i = 0; i < size - 1; ++i) {
        if (array[i + 1] > array[i]) locInverhion++;
    }
    merge_sort(&globInversion, array, 0, size);
    printf("Global inversion: %d \n Local inversion: %d", globInversion, locInverhion);
    return 0;
}

bool isIdealPermutation(int* nums, int numsSize) {
    int globInversion = 0,locInverhion = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i + 1] < nums[i]) locInverhion++;
    }
    merge_sort(&globInversion, nums, 0, numsSize);
    if (locInverhion == globInversion) return true;
    else return false;
}