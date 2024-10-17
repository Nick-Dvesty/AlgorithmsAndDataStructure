#include <stdio.h>
#include <stdlib.h>

int findOrdinalStat(int array[], int startIndex, int endIndex, int number);

int main() {
    int size;
    printf("enter the number of oil towers: ");
    scanf("%d", &size);
    int array[size];
    for (int i; i<size; i++) {
        printf("Enter coordinate oil %d'th tower: ",i+1);
        scanf("%d", &array[i]);
    }
    if(size % 2 == 0){
        int t1 = findOrdinalStat(array, 0, size, size/2);
        int t2 = findOrdinalStat(array, 0, size, size/2 + 1);
        printf("Position oil pipeline1: %d", (t1 + t2)/2);
    }
    else {
        int t1 = findOrdinalStat(array, 0, size, size/2 + size%2 - 1);
        printf("Position oil pipeline2: %d", t1);
    }
}


int findOrdinalStat(int array[], int startIndex, int endIndex, int number){
   // int returnValue = 0;
   // printf("startIndex: %d, endIndex %2d, number%3d \n", startIndex, endIndex,number);
    if(endIndex -startIndex > 1){
        int left = startIndex;
        int right = endIndex -1;
        int index = startIndex + rand()%(endIndex - startIndex);
        int key = array[index];
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
        if(array[number] == key){
            return array[number];
        }else if(array[number] < key)
            return findOrdinalStat(array, startIndex, left, number);
        else if(array[number] > key)
            return findOrdinalStat(array,left+1,endIndex, number);
    }
    return endIndex;

}