#include <iostream>
#include <stack>
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#if 0
class Solution {
    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *iter1 = l1, *iter2 = l2;
            int ishead = 1;
            ListNode *resultList = NULL, *iterResult = new ListNode(-1);
            resultList = iterResult;
            bool add1 = false;
            while(iter1!=NULL || iter2!= NULL) {
                int val1 = 0, val2 = 0, sum = 0;
                if(iter1!= NULL) {
                    val1 = iter1->val;
                    iter1 = iter1->next;
                }
                if(iter2!= NULL) {
                    val2 = iter2->val;
                    iter2 = iter2->next;
                }
                int sum = val1+val2;
                if(ishead) {
                    if(add1) {
                        iterResult->val = sum+1;
                        add1 = false;
                        if(iterResult->val>=10) {
                            iterResult->val %= 10;
                            add1 = true;
                        }
                    } else {
                        iterResult->val = sum%10;
                        if(sum>=10) {
                            add1 = true;
                        }
                    }
                    ishead = 0;
                } else {
                    if(add1) {
                        iterResult->next = new ListNode(sum+1);
                        add1 = false;
                        if(iterResult->next->val>=10) {
                            iterResult->next->val %= 10;
                            add1 = true;
                        }
                    } else {
                        iterResult->next = new ListNode(sum%10);
                        if(sum>=10) {
                            add1 = true;
                        }
                    }
                    iterResult = iterResult->next;
                }
            }
            iterResult = resultList;
            if(add1) {
                while(1) {
                    if(iterResult->next == NULL) {
                        iterResult->next = new ListNode(1);
                        break;
                    }
                    iterResult = iterResult->next;
                }
            }
            return resultList;
        }
};
#else

class Solution {
    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *iter1 = l1, *iter2 = l2;
            int ishead = 1;
            ListNode *resultList = new ListNode(-1), *iterResult = resultList;
            bool add1 = false;
            while(iter1!=NULL || iter2!= NULL) {
                int sum = 0;
                if(iter1!= NULL) {
                    sum += iter1->val;
                    iter1 = iter1->next;
                }
                if(iter2!= NULL) {
                    sum += iter2->val;
                    iter2 = iter2->next;
                }

                ListNode *t = new ListNode(0);
                if(add1) {
                    t->val = sum+1;
                    add1 = false;
                    if(t->val>=10) {
                        t->val %= 10;
                        add1 = true;
                    }
                } else {
                    t->val = sum%10;
                    if(sum>=10) {
                        add1 = true;
                    }
                }
                iterResult->next = t;
                iterResult = iterResult->next;
            }
            iterResult = resultList->next;
            if(add1) {
                while(1) {
                    if(iterResult->next == NULL) {
                        iterResult->next = new ListNode(1);
                        break;
                    }
                    iterResult = iterResult->next;
                }
            }
            return resultList->next;
        }
};
#endif

int main() {
    ListNode *l1 = new ListNode(9);
    ListNode *i1 = l1;
    i1->next = new ListNode(9);
    i1 = i1->next;

    ListNode *l2 = new ListNode(9);
    ListNode *i2 = l2;
    i2->next = new ListNode(9);
    i2 = i2->next;
    ListNode *l3 = Solution::addTwoNumbers(l1, l2);
    while(l3 != NULL) {
        std::cout << l3->val << std::endl;
        l3 = l3->next;
    }
}



#if 0
            bool add1 = false;
            while((!stackl1.empty()) && (!stackl2.empty())) {
                int val1 = 0, val2 = 0;
                if(!stackl1.empty()) {
                    val1 = stackl1.top();
                    stackl1.pop();
                }
                if(!stackl2.empty()) {
                    val2 = stackl2.top();
                    stackl2.pop();
                }
                int sum = val1+val2;
                if(add1) {
                    stackResult.push(sum%10+1);
                    add1 = false;
                } else
                    stackResult.push(sum%10);
                if(sum>=10) {
                     add1 = true;
                }
            }

            ListNode *resultList = NULL, *iterResult = new ListNode(-1);
            resultList = iterResult;
            while(!stackResult.empty()) {
                static int ishead = 1;
                if(ishead) {
                    iterResult->val = stackResult.top();
                    ishead = 0;
                } else {
                    iterResult->next = new ListNode(stackResult.top());
                    iterResult = iterResult->next;
                }
                stackResult.pop();
            }
#endif
