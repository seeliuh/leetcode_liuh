#include <iostream>
class Solution {
    public:
        bool isPalindrome(int x) {
            long revered = 0;
            if(x<0)
                return false;
            int n = x;
            while(x>0) {
                revered = revered*10+ x%10;
                x /= 10;
            }
            return revered == n;
        }
}
