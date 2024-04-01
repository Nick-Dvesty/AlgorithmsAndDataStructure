#include <stdio.h>
void sortColors(int* nums, int numsSize);

int main() {
    int test[] = {2,0,1};
    sortColors(test, 3);
    for (int j = 0; j < 3; ++j) {
        printf("%d ", test[j]);
    }
}

void sortColors(int* nums, int numsSize){
    int left = 0;
    int right = numsSize;
    int i = 0;
    while(i < right){
        int bufer;
        if(nums[i] == 0){
            bufer = nums[left];
            nums[left] = nums[i];
            nums[i] = bufer;
            if(i == left || nums[i] == 1)i++;
            left++;
        }
        else if(nums[i] == 2){
            bufer = nums[right - 1];
            nums[right - 1] = nums[i];
            nums[i] = bufer;
            right--;
        } else if(nums[i] == 1)i++;

    }
}
