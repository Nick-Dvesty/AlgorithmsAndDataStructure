#include <stdio.h>

int main() {
    int test[] = {0,1,2,0,0,1,0,2,0,2,1,0,2,1,2,1,1,0,0};
    int left = 0;
    int right = 18;
    int i = 0;
    while(i < right){
        int bufer;
        if(test[i] == 0){
            bufer = test[left];
            test[left] = test[i];
            test[i] = bufer;
            if(i == left || test[i] == 1)i++;
            left++;
        }
        if(test[i] == 2){
            bufer = test[right];
            test[right] = test[i];
            test[i] = bufer;
            right--;
        }
        if(test[i] == 1)i++;

    }
    for (int j = 0; j < 19; ++j) {
        printf("%d ", test[j]);
    }
}
