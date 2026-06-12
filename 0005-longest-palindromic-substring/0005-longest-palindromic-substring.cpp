class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};