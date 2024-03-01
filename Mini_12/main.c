#include <stdio.h>
#include <stdlib.h>
void Quecksort(int *array,size_t startIndex, size_t size );
int main() {
    size_t size;
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; ++i) {
        scanf("%d", array[i]);
    }
    Quecksort(array,0,9);
    for (int i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
void Quecksort(int array[], size_t startIndex, size_t endIndex){
if(endIndex -startIndex > 1){
    int left = startIndex;
    int right = endIndex -1;
    int index = startIndex + rand()%(endIndex - startIndex);
    int key = array[index];
    printf("key: %d \n", key);
    int i = startIndex;
    while(i <= right){
        int bufer;
        if(array[i] < key){
            bufer = array[left];
            array[left] = array[i];
            array[i] = bufer;
            if(i == left)i++;
            left++;
        }
        if(array[i] > key){
            bufer = array[right];
            array[right] = array[i];
            array[i] = bufer;
            right--;
        }
        if(array[i] == key)i++;

    }
    printf("%d, %2d, %3d \n", startIndex,left,endIndex);
    test(array, startIndex, left);
    test(array, left, endIndex);
}
}
