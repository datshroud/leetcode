
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> combine(vector<string> a, int x, string str_lt[], int max){ 
        if (x == max - 1){ // last
            vector<string> ans;
            int len = str_lt[x].length();
            for (int i = 0; i < len; i++){
                vector<string> m = a;
                string xi(1, str_lt[x][i]);
                m.push_back(xi);
                ans.insert(ans.end(), m.begin(), m.end());
            }
            return ans;
        }
        else{
            vector<string> ans;
            int len = str_lt[x].length();
            for (int i = 0; i < len; i++){
                vector<string> m = a;
                string xi(1, str_lt[x][i]);
                m.push_back(xi);
                vector<string> combined = combine(m, x + 1, str_lt, max);
                ans.insert(ans.end(), combined.begin(), combined.end());
            }
            for (const auto &i : ans){
                cout << i;
            }
            cout << endl;
            return ans;
        }
    }
    vector<string> letterCombinations(string digits) {
        string str[10];
        str[2] = "abc";
        str[3] = "def";
        str[4] = "ghi";
        str[5] = "jkl";
        str[6] = "mno";
        str[7] = "pqrs";
        str[8] = "tuv";
        str[9] = "wxyz";
        int max = digits.length();
        string str_lt[5];
        for (int i = 0; i < max; i++){
            int num = digits[i] - '0';
            str_lt[i] = str[num];
            cout << str_lt[i] << " ";
        }
        cout << endl;
        vector<string> a;
        return combine(a, 0, str_lt, max);
    }
};

int main() {
    string digits;
    cin >> digits;
    Solution s;
    s.letterCombinations(digits);
    return 0;
}