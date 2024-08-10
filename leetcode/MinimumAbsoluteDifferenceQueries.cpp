#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int size = nums.size();
        int same = 0;
        int newarr[size];
        newarr[0] = 0;
        for (int i = 1; i < size; i++){
            if (i > size - same) newarr[i] = same;
            else if (nums[i] == nums[i - 1]){
                nums.erase(nums.begin() + i - same);
                same++;
            }
            newarr[i] = same;
        }
        for (auto i : queries){
            i[0] -= newarr[i[0]];
            i[1] -= newarr[i[1]];
            int count[101];
            int index = 0;
            vector<int> arr = nums;
            for (int x = 0; x <= 100; x++){
                count[x] = 0;
            }
            for (int x = i[0]; x <= i[1]; x++){
                count[arr[x - index]]++;
                if (count[arr[x - index]] >= 2){
                    arr.erase(arr.begin() + x - index);
                    index++;
                }
            }
            i[1] -= index;
            if (i[0] == i[1]) ans.push_back(-1);
            else{
                int minus = abs(arr[i[0] + 1] - arr[i[0]]); 
                if (i[1] >= i[0] + 2){
                    for (int j = i[0]; j < i[1]; j++){
                        for (int k = j + 1; k <= i[1]; k++){
                            if (minus > abs(arr[k] - arr[j])) minus = abs(arr[k] - arr[j]);
                        }
                    }
                }
                ans.push_back(minus);
            }
        }
        return ans;
    }
};   
int main() {
    int a, b;
    cin >> a;
    cin >> b;
    vector<int> nums(a);
    vector<vector<int>> queries(b, vector<int>(2));
    for (int i = 0 ; i < a; i++){ // 1 3 4 8
        int element;
        cin >> element;
        nums[i] = element;
    }
    for (int i = 0; i < b; i++){ // 01 12 23 03 
        for (int j = 0; j <= 1; j++){
            int element;
            cin >> element;
            queries[i][j] = element;
        }
    }
    Solution s;
    s.minDifference(nums, queries);
    return 0;
}