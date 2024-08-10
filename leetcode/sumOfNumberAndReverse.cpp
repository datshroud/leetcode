#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>

using namespace std;
class Solution {
public:
    int lastNum(int num){
        string str = to_string(num);
        string s;
        int len = str.length();
        s += str[len - 1];
        int ans = stoi(s);
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        string str = to_string(num);
        int len = str.length();
        int index = len - 1;
        if (num % 2 == 0 && num <= 18) return true;
        while (index != 5){
            int count = 0;
            int a = num;
            while (index - count >= count){
                if (count == 0){
                    if (lastNum(a) == 0 && a - 10 * (pow(10, index - count) + pow(10, count)) < 0) return false;
                    else if (a - lastNum(a) * (pow(10, index - count) + pow(10, count)) == 0 || a - (lastNum(a) + 10) * (pow(10, index - count - 1) + pow(10, count)) == 0) return true;
                    else if (a - lastNum(a) * (pow(10, index - count) + pow(10, count)) > 0){
                        a -= lastNum(a) * (pow(10, index - count) + pow(10, count));
                        count++;
                        if (index - count != count) a /= 10;
                        else if (a % 20 == 0) {
                            a /= 20;
                            if (a > 9) break;
                        }
                        else break;
                    }
                    else if (a - lastNum(a) * (pow(10, index - count) + pow(10, count)) < 0) return false;
                }
                else {
                    if (a * 10 - lastNum(a) * (pow(10, index - count) + pow(10, count)) > 0 && index - count != count) count++;
                    else if (a * 10 - lastNum(a) * (pow(10, index - count) + pow(10, count)) == 0 && index - count != count){
                        return true;
                    }
                    else if (a * 10 - lastNum(a) * pow(10, index - count) == 0 && index - count == count) return true;
                }                
            }
            index++;
        }
        return false;
    }
};
int main(){
    int num;
    cin >> num;
    Solution s;
    cout << s.sumOfNumberAndReverse(num) << endl;  
    sleep(40);
    return 0;
}