#include <iostream>
#include <vector>
#include <unordered_map>

//如果输入的nums都是正数，可以用数组代替hash表。采用c++11提供的unordered_map实现hash功能

using namespace std;
class common_solution {
    static vector<int> towSum(vector<int> &nums, int target) {
        vector<int> result;
        for(int i = 0; i<nums.size(); i++) {
            for(int j = i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

class O0_solution {
    public:
    template<class T >
        class funcHash_t {
            public:
                size_t operator()(const T &k) const{
                     std::cout << "hash:" << k << std::endl;
                    return std::abs(k);
                }
        };
    template<class T >
        class funcEqual_t {
            public:
                bool operator()(const T &left, const T &right) const{
                     std::cout << "equal:" << left << "," << right<< std::endl;
                     return left == right;
                }
        };
    static vector<int> towSum(vector<int> &nums, int target) {
        vector<int> result;
        std::unordered_map<int, int, funcHash_t<int >, funcEqual_t<int > > hashSimple;
        //or std::unordered_map<int, int > hashSimple;
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

int main() {
#if 0
    vector<int> nums = {-1,-2,-2,-3,-4,-5,-6,-7};
    vector<int> result = O0_solution::towSum(nums, -7);
    for(int&tmp : result) {
        std::cout << tmp << " ";
    }
#endif

#if 1 //test_case_unordered_map
    std::unordered_map<int, int, O0_solution::funcHash_t<int >, O0_solution::funcEqual_t<int > > hashSimple;
    hashSimple[-1] = 2;
    hashSimple[-2] = 3;
    hashSimple.find(-3);
    hashSimple.find(-4);
    hashSimple.find(-5);
    hashSimple.find(4);
    //std::cout << hashSimple[-1] << std::endl;
#endif
}
