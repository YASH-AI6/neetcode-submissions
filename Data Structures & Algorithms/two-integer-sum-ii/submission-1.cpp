class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();   // CORRECTION: size is a function -> size()
        int start = 0; 
        int end = n - 1;
        vector<int> ans;

        while (start < end) {
            if (numbers[start] + numbers[end] == target) {

                // CORRECTION: pushback -> push_back
                ans.push_back(start + 1); // LeetCode Two Sum II expects 1-based indexing
                ans.push_back(end + 1);

                return ans;
            }
            else if (numbers[start] + numbers[end] < target) {
                start++;
            }
            else if (numbers[start] + numbers[end] > target) {
                end--;
            }
        }

        // CORRECTION: function returns vector<int>, not int
        return {};
    }
};