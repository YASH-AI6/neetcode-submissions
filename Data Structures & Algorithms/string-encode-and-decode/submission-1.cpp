class Solution {
public:
    
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string &s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

             // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract string
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // Move to next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};