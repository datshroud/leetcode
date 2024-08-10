#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>
#include <vector>

using namespace std;
class Solution {
public:
    string testWord(string s, int len){
        string ans;
        for (int i = 0; i < len; i++){
            ans += s[i];
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        if (size == 0) return true;
        for (auto &element : wordDict){
            int len = element.length();
            if (element == testWord(s, len)){
                string str = s.erase(0, len);
                if (wordBreak(str, wordDict)) return true;
            }
        }
        return false;
    }
};
int main(){
    string str;
    cin >> str;
    vector<string> wordDict;
    for (int i = 0; i < 3; i++){
        string st;
        cin >> st;
        wordDict.push_back(st);
    }
    Solution s;
    cout << s.wordBreak(str, wordDict) << endl;  
    sleep(40);
    return 0;
}