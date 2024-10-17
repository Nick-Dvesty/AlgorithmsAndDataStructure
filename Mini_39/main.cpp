#include <iostream>
#include <list>
#include <vector>



using string = std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        std::vector<string> qwe;
        for (char &i: p) {
            if (i == '*') qwe.back() = qwe.back() + i;
            else qwe.push_back(string("") + i);
        }
        if (qwe.size() == p.size() && qwe.size() != s.size()) return false;
        if (qwe.front().size() != 2 && qwe.front() != "." && qwe.front()[0] != s[0]) return false;
        bool flag = qwe[0][0] == s[0];

        bool table[qwe.size()][s.size()];

        for (int i = 0; i < qwe.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                table[0][0] = false;
            }
        }

        char target;
        string pattern = qwe.front();
        bool control = (pattern.size() == 2 and pattern[0] != '.' && pattern[0] != s[0]);

        for (int i = 1; i < s.size(); ++i) {
            target = s[i];
            if (pattern == ".") {
                table[0][i] = true;
            } else if (pattern.size() == 2) {
                table[0][i] = table[0][i - 1] || (target != pattern[0] && pattern[0] != '.') || control;
                control = false;
            } else {
                table[0][i] = table[0][i - 1] || flag;
                if (target == pattern[0])
                    flag = true;
            }
        }

        target = s[0];
        bool count_point = qwe[0] == ".";

        for (int i = 1; i < qwe.size(); ++i) {
            pattern = qwe[i];
            if (pattern == ".") {
                table[i][0] = table[i - 1][0] || count_point;
                count_point = true;
            } else if (pattern.size() == 2) {
                table[i][0] = table[i - 1][0];
            } else {
                table[i][0] = table[i - 1][0] || target != pattern[0] || flag;
                if (target == pattern[0])
                    flag = true;
            }
        }

        for (int i = 1; i < qwe.size(); ++i) {
            pattern = qwe[i];
            for (int j = 1; j < s.size(); ++j) {
                target = s[j];
                if (pattern == ".") {
                    table[i][j] = table[i - 1][j - 1];
                } else if (pattern.size() == 2) {
                    table[i][j] = table[i - 1][j] && (table[i][j - 1] || (pattern[0] != target and pattern[0] != '.'));
                } else {
                    table[i][j] = table[i - 1][j - 1] or (pattern[0] != target);
                }
            }
        }
        std::cout<<std::endl;
        for (int i = 0; i < qwe.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                std::cout<<table[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        return table[qwe.size() - 1][s.size() - 1] == 0;
    }
};

int main() {
    Solution tst;
    string s = "b";
    string p = "c*bb";
    tst.isMatch(s,p);
    return 0;
}