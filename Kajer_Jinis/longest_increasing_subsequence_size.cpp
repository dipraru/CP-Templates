#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	int n = nums.size();
	vector<int> ans;
	ans.push_back(nums[0]);
	for (int i = 1; i < n; i++) {
		if (nums[i] > ans.back()) ans.push_back(nums[i]);
		else ans[lower_bound(ans.begin(), ans.end(),nums[i])- ans.begin()]=nums[i];
	}
	return ans.size();
}

int main()
{
	vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
	printf("Length of LIS is %d\n", lengthOfLIS(nums));
	return 0;
}
