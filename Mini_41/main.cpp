#include <iostream>
#include <vector>
template <typename T> using vector =std::vector<T>;
#include <climits>

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int matrix[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = i == j ? 0 : INT_MAX;
            }
        }
        for (int i = 0; i < edges.size(); ++i) {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int a = matrix[i][j];
                    int b = INT_MAX;
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX){
                        b = matrix[i][k] + matrix[k][j];
                    }
                    matrix[i][j] = a < b ? a : b;
                }
            }
        }
        int answer = 0, minCount = n;
        for (int i = 0; i < n; ++i) {
            int countCity = 0;
            for (int j = 0; j < n; ++j) {
                if(i == j) continue;
                if (matrix[i][j] <= distanceThreshold) countCity++;
            }
            if (countCity <= minCount) {
                answer = i;
                minCount = countCity;
            }
        }
        return answer;
    }
};

int main() {
    v =
    return 0;
}
