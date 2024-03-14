#include <stdio.h>

int main() {
    int nums[] = {0,1,2,0,0,1,0,2,0,2,1,0,2,1,2,1,1,0,0};
    int left = 0;
    int right = 18;
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
        if(nums[i] == 2){
            bufer = nums[right];
            nums[right] = nums[i];
            nums[i] = bufer;
            right--;
        }
        if(nums[i] == 1)i++;

    }
    for (int j = 0; j < 19; ++j) {
        printf("%d ", nums[j]);
    }
}
