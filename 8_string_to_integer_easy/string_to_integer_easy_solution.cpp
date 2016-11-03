#include <iostream>
using namespace std;
class Solution {
    public:
        static int myAtoi(string str) {
            bool fuckthis = false;
            long result = 0;
            const int failed = 0;
            int negative = -1;
            int negative_count = 0, active_count = 0;
            int length = str.length();
            if(length == 0 )
                return failed;

            const char base = '0';
            for(int i = 0; i< length; i++) {
                char c = str.at(i);
                if((c == ' ' || c == 0x8) && (negative != -1) && (fuckthis == false))
                    return 0;
                if((c == ' ' || c == 0x8) && (negative != -1) && (fuckthis == true))
                    return negative?(result/10*-1):(result/10);
                if((c == ' ' || c == 0x8) && (negative == -1) /*&&(fuckthis == false)*/)
                    continue;
                if(c >'9' || c < '0') {
                    if((negative != -1 && c!='-' && c!='+') || (negative_count+active_count==1))
                        return negative?(result/10*-1):(result/10);
                    else if(negative == -1 && c == '-')
                        negative_count++;
                    else if(negative == -1 && c == '+')
                        active_count++;
                } else {
                    if(negative == -1) {
                        negative = negative_count%2;
                        if(length-i-1>11)
                            return failed;
                    }
                    result += (c-base);
                    if(i != length-1) {
                        fuckthis = true;
                        result*=10;
                    }
                }
            }
            if(negative == 0 && result> INT_MAX) return INT_MAX;
            if(negative == 1 && (result*-1)< INT_MIN) return INT_MIN;
            return negative?result*-1:result;        }
};

int main() {
    std::cout << Solution::myAtoi("   - 321");
}
/*
More Details

Input:
"   - 321"
Output:
-321
Expected:
0

符号后面有空格则返回0

Input:
"123  456"
Output:
0
Expected:
123

数字后面有空格，期望截断
*/
