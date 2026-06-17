class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        int ans = 0; // Need a variable to store the maximum length found

        for (int i = 0; i < n; i++) {

            int current = nums[i];
            int length = 1;

            // Mistake 1:
            // while(i < n) will never help here because 'i' is not changing
            // inside the loop, leading to an infinite loop.
            //
            // Instead, you need a way to keep searching for current + 1
            // until it is not found.

            while (true) {

                bool found = false;

                // Mistake 2:
                // 'j' was never declared.
                // You need another loop to search the entire array.
                for (int j = 0; j < n; j++) {

                    if (nums[j] == current + 1) {
                        current++;
                        length++;
                        found = true;
                        break;
                    }
                }

                // Mistake 3:
                // current = nums[i+1] is incorrect.
                // We are building a sequence starting from nums[i].
                // If next element is not found, we should stop.
                if (!found) {
                    break;
                }
            }

            ans = max(ans, length);
        }

        return ans; // Mistake 4: function must return an integer
    }
};