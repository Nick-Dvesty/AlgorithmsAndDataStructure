#include <iostream>
#include <vector>

template<typename T>
using vector = std::vector<T>;

class NumArray {
public:
    int *arr;
    size_t size;

    void build(int* a, int v, int tl, int tr){
        if (tl == tr) {
            arr[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm + 1, tr);

        arr[v] = arr[v*2] + arr[v*2 + 1];
    }

    NumArray(vector<int>& nums) {
        arr = new int[nums.size() * 4];
        for (int i = 0; i < nums.size() * 4; ++i) {
            arr[i] = 0;
        }
        size = nums.size();
        int arrNums[nums.size()];
        for (int i = 0; i < nums.size(); ++i) {
            arrNums[i] = nums[i];
        }
        build(arrNums, 1,0, size - 1);
    }


    void update(int index, int val) {
        update(1, 0, size - 1, index, val);
    }

    void update(int v, int tl, int tr, int index, int val) {
        if (tl == tr) {
            arr[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (index <= tm) {
                update(v * 2, tl, tm, index, val);
            } else {
                update(v * 2 + 1, tm + 1, tr, index, val);
            }
            arr[v] = arr[v * 2] + arr[v * 2 + 1];
        }
    }

    int getSum(int v, int tl, int tr, int l, int r){
        if (l == tl && r == tr)
            return arr[v];
        int tm = (tl + tr) >> 1;
        int res = 0;
        if (l <= tm) {
            res+= getSum(v*2, tl, tm, l, r < tm ? r: tm);
        }
        if (r >= tm + 1) {
            res += getSum(v*2 + 1, tm + 1, tr, l > tm + 1 ? l : tm + 1, r);
        }
        return res;
    }

    int sumRange(int left, int right) {
        return getSum(1,0, size - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    vector<int> vec = {1, 1, 1, 1, 1};
    NumArray e(vec);
    std::cout<<e.sumRange(0,4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}