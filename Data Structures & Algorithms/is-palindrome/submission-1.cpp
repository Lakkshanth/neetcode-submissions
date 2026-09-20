class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            // Skip non-alphanumeric characters on the left
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // Skip non-alphanumeric characters on the right
            while (l < r && !isalnum(s[r])) {
                r--;
            }

            // Compare characters ignoring case
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};