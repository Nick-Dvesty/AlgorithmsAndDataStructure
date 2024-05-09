#include <stdio.h>
#include <stdlib.h>
void quecksortHoaro(int *nums, size_t startIndex, size_t size );
void quecksortLomuto(int nums[], size_t startIndex, size_t endIndex);
int main() {
int test[] = {2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
               2,2,2,2,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
               2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
               2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,};
int test2[] = {5,1,1,2,0,0};
quecksortLomuto(test2,0,6);

}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    quecksortHoaro(nums, 0, numsSize);
    *returnSize = numsSize;
    return nums;
}
void quecksortHoaro(int *nums, size_t startIndex, size_t endIndex){
    if(endIndex -startIndex > 1){
        size_t left = startIndex;
        size_t right = endIndex -1;
        size_t same = endIndex - startIndex;
        size_t index = startIndex + rand()%(endIndex - startIndex);
        int key = nums[index];
        size_t i = startIndex;
        while(i <= right){
            int bufer;
            if(nums[i] < key){
                bufer = nums[left];
                nums[left] = nums[i];
                nums[i] = bufer;
                if(i == left)i++;
                left++;
                same--;
            }
            if(nums[i] > key){
                bufer = nums[right];
                nums[right] = nums[i];
                nums[i] = bufer;
                right--;
                same--;
            }
            if(nums[i] == key){
                i++;
            }
        }
        quecksortHoaro(nums, startIndex, left);
        quecksortHoaro(nums, left + same, endIndex);
    }
}

void quecksortLomuto(int *nums, size_t startIndex, size_t endIndex){
    if(endIndex > startIndex + 1){
        size_t i = startIndex + 1;
        size_t j = startIndex + 1;
        size_t index = startIndex + rand()%(endIndex - startIndex);
        int key = nums[index];
        nums[index] = nums[startIndex];
        nums[startIndex]= key;
        while(j < endIndex){
            int bufer = 0;
            if(nums[j] <= key){
                bufer = nums[i];
                nums[i] = nums[j];
                nums[j] = bufer;
                i++;
                j++;
            } else if(nums[j] > key){
                j++;
            }
        }
        nums[startIndex] = nums[i - 1];
        nums[i - 1] = key;

       quecksortLomuto(nums, startIndex, i - 1);
       quecksortLomuto(nums, i, endIndex);
    }
}