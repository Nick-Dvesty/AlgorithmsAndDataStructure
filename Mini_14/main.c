#include <stdio.h>
#include <stdlib.h>
int optimalPosition(int *array, size_t size);
void golandFlag(int *array, size_t size, int keyIndex);
int quecksortHoaro(int array[], size_t startIndex, size_t endIndex, int number);

int main() {
    int test[] = {9,8,7,6,5,4,3,2,1};
    quecksortHoaro(test, 0, 9);
}

int optimalPosition(int *array, size_t size){
    int keyIndex = rand();

}


void golandFlag(int *array, size_t size, int keyIndex){
    int  key = array[keyIndex -1];
    int bufer;
    int leftIndex = 0;
    int rightIndex = size - 1;/*
    for (int i = 0; i <size;) {
        if(array[i] < key && i > keyIndex){
            bufer = array[leftIndex];
            array[leftIndex] = array[i];
            array[i] = bufer;
            leftIndex++;
        }
        else if(array[i] > key && i < keyIndex){
            bufer = array[rightIndex];
            array[rightIndex] = array[i];
            array[i] = bufer;
            rightIndex--;
        } else i++;
    }*/
    int i = 0;
        while(i < rightIndex){
            int bufer;
            if(array[i] < key){
                bufer = array[leftIndex];
                    array[leftIndex] = array[i];
                array[i] = bufer;
                if(i == leftIndex || array[i] == key)i++;
                leftIndex++;
            }
            if(array[i] > key){
                bufer = array[rightIndex];
                array[rightIndex] = array[i];
                array[i] = bufer;
                rightIndex--;
            }
            if(array[i] == key)i++;

        }

}


int quecksortHoaro(int array[], size_t startIndex, size_t endIndex, int number){
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
        }else if(array[number] > key) quecksortHoaro(array,startIndex, left, number);
        else if(array[number] < key) quecksortHoaro(array,left+1,endIndex);
    }
}