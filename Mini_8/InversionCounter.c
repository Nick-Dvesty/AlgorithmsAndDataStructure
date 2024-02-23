#include "InversionCounter.h"
void merge(int *quantitInversion,int *array, int startLeft, size_t blockLeft,int startRight, size_t blockRight){
   // if(startLeft + blockLeft < startRight + blockRight){
        int *buferArray = (int*)malloc(blockLeft + blockRight);
        size_t left = 0;
        size_t right = 0;
        for(size_t i = 0; (left < blockLeft) || (right < blockRight);i++){
            //printf("check: %d, %2d \n",array[startLeft + left],array[ startRight + right]);
            if((array[startLeft + left] <= array[ startRight + right] && left < blockLeft) || right >= blockRight){
                buferArray[i] = array[startLeft + left];
                left++;
            }
            else {
                buferArray[i] = array[startRight + right];
                right++;
                *quantitInversion += blockLeft - left;
            }
        }
        for (int i = 0; i< blockLeft+ blockRight; i++) {
            array[startLeft + i] = buferArray[i];
        }
        free(buferArray);
}
void merge_sort(int *quantitInversion, int* array,int startLeft, size_t blockLeft){
    //printf("start left: %d, size: %2zu \n", startLeft,blockLeft);
    if(blockLeft > 1){
        merge_sort(quantitInversion, array, startLeft, blockLeft/2);
        merge_sort(quantitInversion, array, startLeft + blockLeft /2, blockLeft - blockLeft/2);
        merge(quantitInversion, array, startLeft, blockLeft/2, startLeft + blockLeft /2, blockLeft - blockLeft/2);
    }
}