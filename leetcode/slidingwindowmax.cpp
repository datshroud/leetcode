#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        int lct = 0;
        int len = nums.size();
        vector<int> ans;
        int arr[k];
        int max;
        while (len - lct < k){
            for (int i = 0; i < k; i++){
                arr[i] = nums[i + lct];
                if (i == 0) max = arr[i];
                else if (max < arr[i]) max = arr[i];
            }
            ans.push_back(max);

            for (const auto &i : ans){
                cout << i << " ";
                cout << max;
            }
            cout << endl;

            lct ++;
        }
        return ans;
    }
};
int main(){
    int k;
    int n;
    cin >> n;
    vector<int> nums(n); //[1,3,-1,-3,5,3,6,7]
    for (int i = 0; i < n; i++){
        int element;
        cin >> element;
        nums[i] = element;
    }
    cin >> k;
    Solution s;
    s.maxSlidingWindow(nums, k);
    return 0;
}