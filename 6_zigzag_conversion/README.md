#zigzag conversion
##题目描述
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

##解题思路
构建一个2维数组，按照zigzag的方式写入到数组中，再横向访问数组，输出结果。
看到discuss中有人通过公式计算，对此没有兴趣，所以本题也没有什么过多的心得
