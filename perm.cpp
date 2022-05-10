#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return;
        int i = sz - 2;
        // find the decreasing element
        while ((i >= 0) && (nums[i] >= nums[i + 1])) --i;
        if (i >= 0) { // if there is..
            int j = sz - 1;
            // find next larger number
            while ((j >= i) && (nums[j] <= nums[i])) {
                -- j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(begin(nums) + i + 1, end(nums));
	for(int& i:nums) cout << i << " " ;
	cout << endl;
    }
};

int main(){

	Solution s;
	vector<int> v = { 1,2,3,4 };
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
	s.nextPermutation(v);
}

