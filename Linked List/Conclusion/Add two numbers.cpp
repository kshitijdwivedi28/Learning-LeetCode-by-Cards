Add Two Numbers

Solution
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
C++	
1
/**
2
 * Definition for singly-linked list.
3
 * struct ListNode {
4
 *     int val;
5
 *     ListNode *next;
6
 *     ListNode() : val(0), next(nullptr) {}
7
 *     ListNode(int x) : val(x), next(nullptr) {}
8
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9
 * };
10
 */
11
class Solution {
12
public:
13
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14
        
15
        int sum = l1->val + l2->val;
16
        int rem = sum%10;
17
        int carry = sum/10;
18
        
19
        l1 = l1->next;
20
        l2 = l2->next;
21
        
22
        ListNode *ans_head = new ListNode(rem);
23
        ListNode *curr = ans_head;
24
​
25
        while(l1 != NULL || l2 != NULL || carry)
26
        {
27
            int n1 = (l1 != NULL) ? l1->val : 0;
28
            int n2 = (l2 != NULL) ? l2->val : 0;
29
            
30
            sum = n1 + n2 + carry;
31
            carry = sum/10;
32
            rem = sum%10;
33
​
34
            cout << sum << " " << carry << " " << rem << endl;
35
            
36
            ListNode *temp = new ListNode(rem);
37
            
38
            curr->next = temp;
39
            
40
            curr = curr->next; 
41
​
42
            if (l1 != NULL)
43
                l1 = l1->next;
44
            
45
            if(l2 != NULL)
46
                l2 = l2->next;
47
        }
48
        
49
        return ans_head;
50
    }
51
};
