#include <stdio.h>
#include <stdlib.h>
void quecksortHoaro(int *array,size_t startIndex, size_t size );
void quecksortLomuto(int array[], size_t startIndex, size_t endIndex);
int main() {
int test[9] = {23,5,77,68,35,46,37,2,12};
    quecksortLomuto(test,0,9);

}
void quecksortHoaro(int array[], size_t startIndex, size_t endIndex){
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
        quecksortHoaro(array,startIndex, left);
        quecksortHoaro(array,left+1,endIndex);
    }
}

void quecksortLomuto(int array[], size_t startIndex, size_t endIndex){
    if(endIndex > startIndex + 1){
        int i = startIndex + 1;
        int j = startIndex + 1;
        int index = startIndex + rand()%(endIndex - startIndex);
        int key = array[index];
        array[index] = array[startIndex];
        array[startIndex]= key;
        while(j < endIndex){
            int bufer;
            if(array[j] <= key){
                bufer = array[i];
                array[i] = array[j];
                array[j] = bufer;
                i++;
                j++;
            }
            if(array[j] > key){
                j++;
            }
        }
        array[startIndex] = array[i - 1];
        array[i -1] = key;

       quecksortLomuto(array,startIndex, i - 1);
       quecksortLomuto(array,i,endIndex);
    }
}