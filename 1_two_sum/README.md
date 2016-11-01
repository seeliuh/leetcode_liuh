#two sum笔记
``````
题目：
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
``````

有两种解法
1. 普通遍历法. O(n****n)
普通解法不用说，即使初学者也能解出来
2. 借助hash table. O(n)。
只遍历一次，增加一个hash table，key存储已遍历数据的解，value存储已遍历数据的index，在遍历下一个元素的时候，如果此元素已经存在于hash table的key中，则找到解。
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::unordered_map<int, int > hashSimple;
        for(int i = 0; i< nums.size(); i++) {
            if(hashSimple.find(nums[i]) != hashSimple.end()) {
                 result.push_back(hashSimple[nums[i]]);
                 result.push_back(i);
                 return result;
            }
            else {
                hashSimple[target-nums[i]] = i;
            }
        }
        return result;
    }
};
```
此解法关键点在于利用hash table O(1)的查找速度，将能够与遍历过的元素组成解的元素记录在key中，非常巧妙

##c++ hash map
c++11提供了內建的hash map。 std::unordered_map。很好用，既可以简单实用，又可定制化使用
```
template<
    class Key, //key类型
    class T, //value类型
    class Hash = std::hash<Key>, //hash映射仿函数 
    class KeyEqual = std::equal_to<Key>, //等于仿函数
    class Allocator = std::allocator< std::pair<const Key, T> >
> class unordered_map 
```
参数3：要符合表达式：std::hash<Key>()(k1) == std::hash<Key>()(k2)
举例
```
    template<class T >
        class funcHash_t {
            public:
                size_t operator()(const T &k) const{
                    return std::abs(k);
                }
        };
```
参数4：判断两个key是否相等
举例
```
    template<class T >
        class funcEqual_t {
            public:
                bool operator()(const T &left, const T &right) const{
                     return left == right;
                }
        };
```
key的类型是內建类型，并且应用较为简单时，参数3和参数4使用默认的即可。参数3的hash映射函数已经內建了string int char*等常见类型。
在高级应用中，要根据数据集的特点设计hash映射函数(参数3)，hash映射函数设计的好坏，直接影响了hash table的效率。
当有数据碰撞情况存在时，参数4将发挥作用，在hash_key相同的keys集合中，利用参数4找到目标key


