#include "insertMergeSort.h"

void merge(int startLeft, int startRight, int endIndex, int* array, int endBufer){
    int left = 0;
    int right = 0;
    int buffer = 0;
    for(int i = endBufer - 1; (left < startRight - startLeft) || right < (endIndex - startRight);i--){
        buffer = array[i];
        if (((array[startRight - 1 - left] >= array[endIndex - 1 - right]) &&(left < (startRight - startLeft))) ||( right >= (endIndex - startRight))){
            array[i] = array[startRight  - 1- left];
            array[startRight - 1- left] =  buffer;
            left++;
        } 
        else{
            array[i] = array[endIndex -1- right];
            array[endIndex -1- right] =  buffer;
            right++;
        }
    }
}

void merge2(int startLeft, int endLeft, int startBufer, int startRight, int* array, int endIndex){
    if ((startLeft == startBufer ) || (startBufer ==  startRight)){
        classicSort(startLeft, array, endIndex);
    } else{
        int EndBufer = startRight - 1;
        int left = startLeft;
        int right = startRight;
        int buffer = 0;
        for(int i = startBufer; (i < endIndex) && ((left <= endLeft)||( right < endIndex));i++){
            buffer = array[i];
            if(((array[left] <= array[right]) && (left <= endLeft)) ||( right >= endIndex)){
                array[i] = array[left];
                array[left] =  buffer;
                left++;
            } 
            else{
                array[i] = array[right];
                array[right] =  buffer;
                right++;
            }
        } 
    }
}

void classicSort(int index, int* array, int endIndex){
        int a = array[index];
        int j = index;
        for (j = index; j< endIndex - 1 && a > array[j + 1]; j++) {
            array[j] = array[j + 1];
        }
        array[j] = a;

}

void mergeSort(int startIndex, int endIndex, int* array){
    int size = endIndex - startIndex;
    int partSorted = 0;
    if(size >= 2){
        mergeSort(startIndex, startIndex + (size)/4 + size%2, array);
        mergeSort(startIndex + (size)/4 + size%2, startIndex + (size)/2 + size%2, array);
        if(size> 2){
            merge(startIndex, startIndex + (size)/4 + size%2, startIndex + (size)/2 + size%2, array, startIndex+size);
        }
        partSorted = (size)/2 + size%2; 
        for(int i = 1; partSorted < size;i++){
            mergeSort(startIndex, startIndex + (size - partSorted)/ 2, array);
            merge2(startIndex,startIndex + (size - partSorted)/ 2 - 1, startIndex + (size - partSorted)/ 2 + (size - partSorted)%2, endIndex - partSorted, array,endIndex);
            if ((size - partSorted)/ 2 != 0) partSorted += (size - partSorted)/ 2;
            else partSorted++;
        }
    }
}