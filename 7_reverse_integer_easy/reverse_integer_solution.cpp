#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
class CommonSolution {
    public:
        static int reverse(int x) {
            if(x == 0)
                return 0;
            bool negative = x<0?true:false;
            x = std::abs(x);
            long long result = 0;
            const int fs = 10;
            int flags[fs] = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};
            stack<int> s;
            bool pushed = false;
            for(int i = 0; i<fs; i++) {
                if(x >= flags[i]) {
                     s.push(x/flags[i]);
                     x = x%flags[i];
                     pushed = true;
                } else {
                    if(pushed)
                        s.push(0);
                }
            }
            int stacksize = s.size();
            for(int i = 0; i< stacksize; i++) {
                long long n = s.top();
                result+= n*flags[i+(fs-stacksize)];
                s.pop();
            }
            if(stacksize == 10)
            {
                //int range = pow(2,31)-1;
                //int nrange = pow(2,31);
                int range = INT_MAX;
                int nrange = INT_MIN;
                if(result > range || result < nrange)
                    return 0;
            }
            return negative?-result:result;
        }

};


class ToStringSolution {
    public:
    static int reverse(int x) {
        char str[32], rev[32];
        memset(rev,0,32);
        sprintf(str, "%d", std::abs(x));
        int length = strlen(str);
        for(int i = 0; i<length; i++) {
            rev[i] = str[length-i-1];
        }
        long result = atol(rev);
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        else
            return (x<0)?-result:result;

    }
};
int main() {
    int x = 153423646;
    std::cout << ToStringSolution::reverse(x) << std::endl;
}
