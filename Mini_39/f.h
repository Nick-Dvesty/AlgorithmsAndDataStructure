// Translation of Python code to C++ for a mathematical decomposition problem.
#include <vector>
#include <limits>
#include <numeric>


template<typename T> using vector = std::vector<T>;

class Solution {
public:
    int decomposition_sum(vector<vector<int>>& arr, int i, int j, int end_j, int step, int k) {
        if (k == 1) {
            return (i != end_j) ? arr[i][end_j] : 0;
        }

        int result = std::numeric_limits<int>::max();
        for (int x = j; x < end_j; x += step) {
            int q = decomposition_sum(arr, x + 1, x + 1, end_j, step, k - 1);
            q += (i != x) ? arr[i][x] : 0;
            result = std::min(result, q);
        }
        return result;
    }

    int mergeStones(vector<int>& stones, int k) {
        k -= 1;
        int n = stones.size();

        if (n == 1) {
            return 0;
        }

        if ((n - 1) % k) {
            return -1;
        }

        std::vector<int> prefix_sum(n);
        prefix_sum[0] = stones[0];

        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + stones[i];
        }

        std::vector<std::vector<int>> table(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            table[i][i] = stones[i];
        }

        for (int i = 0; i < n - k; ++i) {
            table[i][i + k] = prefix_sum[i + k] - prefix_sum[i] + stones[i];
        }

        for (int l = 2 * k; l < n; l += k) {
            for (int i = 0; i < n - l; ++i) {
                int j = i + l;

                int w = prefix_sum[j] - prefix_sum[i] + stones[i];

                table[i][j] = w + decomposition_sum(table, i, i, j, k, k + 1);
            }
        }

        return (table[0][n - 1] != 0) ? table[0][n - 1] : -1;
    }
};