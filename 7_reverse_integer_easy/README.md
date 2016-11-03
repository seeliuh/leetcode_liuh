#7. Reverse Integer
##题目描述
```
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
```
##解题思路
我的题解：int的范围是-2147483648 ~~ 2147483647。最多10位，利用除法将各位的数值取出来放在stack中。再从stack取出来组合成相反的数字
或转成字符串的方式。字符串方式比计算数字的方式快很多
几点心得:
- 范围计算
int max_int = pow(2,31)
int min_int = pow(2,32)
- c++对于int的最大最小值有宏定义
INT_MAX ,INT_MIN

##discuss中的好答案
```计算数字的方式。比我的简洁很多
class Solution {
public:
    int reverse(int x) {
        long num = abs((long)x);
        long new_num = 0;
        while(num) {
            new_num = new_num*10 + num%10;
            num /= 10;
        }
        
        if (new_num > INT_MAX) {
            return 0;
        }
        return (x<0 ? -1*new_num : new_num);
    }
};

```

