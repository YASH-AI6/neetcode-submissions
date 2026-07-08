class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            unordered_set<int> seen;

            for(int j = i + 1; j < n; j++) {

                int complement = -nums[i] - nums[j];

                if(seen.count(complement)) {

                    ans.push_back({nums[i], complement, nums[j]});

                    while(j + 1 < n && nums[j] == nums[j + 1])
                        j++;
                }

                seen.insert(nums[j]);
            }
        }

        return ans;
    }
};