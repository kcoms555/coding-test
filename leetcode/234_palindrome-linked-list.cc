#include "header.h"
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
bool isPalindrome(ListNode* head) {
	ListNode * fast = head, * slow = head, * rev = nullptr, * tmp = nullptr;
	if(!head) return true;
	while(fast){
		if( ! fast->next ){
			slow = slow->next;
			break;
		}
		fast = fast->next->next;
		tmp = rev;
		rev = new ListNode(slow->val);
		rev->next = tmp;
		slow = slow->next;
	}
	bool flag = true;
	while(slow){
		if(slow->val == rev->val){
			slow = slow->next;
			rev = rev->next;
		}
		else{
			flag = false;
			break;
		}
	}
	
	while(rev){
		tmp = rev->next;
		delete rev;
		rev = tmp;
	}
	
	return flag;
}
int main(void){
	ListNode l4(1);
	ListNode l3(3, &l4);
	ListNode l2(5, &l3);
	ListNode l1(3, &l2);
	ListNode l0(1, &l1);
	cout<<isPalindrome(&l0)<<endl;
	return 0;
}
