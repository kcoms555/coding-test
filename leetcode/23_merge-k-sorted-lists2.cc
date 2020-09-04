#include "header.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct greater1{
	bool operator()(ListNode * a, ListNode * b){
		return a->val>b->val;
	}
};
ListNode * mergeKLists(vector<ListNode *>& lists){
	vector<ListNode *> heap;
	for( auto &lit : lists){
		cout<<"list : ";
		ListNode * node = lit;
		while(node){
			ListNode * tmp = node;
			cout<<node->val<<", ";
			heap.push_back(node);
			node = node->next;
			tmp->next = nullptr;
		}
		cout<<endl;
	}
	for(auto i : heap) cout<<i->val<<", "; cout<<endl;
	make_heap(heap.begin(), heap.end(), greater1());
	for(auto i=heap.begin(); i!=heap.end(); i++) cout<<(*i)->val<<", "; cout<<endl;
	ListNode * head = nullptr;
	ListNode * node = nullptr;
	if(!heap.empty()){
		pop_heap(heap.begin(), heap.end(), greater1());
		node = head = heap.back(); heap.pop_back();
	}
	while(!heap.empty()){
		pop_heap(heap.begin(), heap.end(), greater1());
		node->next = heap.back(); heap.pop_back();
		node = node->next;
	}
	return head;
}
int main(void){
	ListNode * a4 = new ListNode(5);
	ListNode * a3 = new ListNode(7, a4);
	ListNode * a2 = new ListNode(2, a3);
	ListNode * a1 = new ListNode(9, a2);
	ListNode * b3 = new ListNode(8);
	ListNode * b2 = new ListNode(4, b3);
	ListNode * b1 = new ListNode(3, b2);
	ListNode * c1 = new ListNode(1);
	vector<ListNode *> v{a1, b1};
	vector<ListNode *> v1;
	vector<ListNode *> v2{c1};
	ListNode * p = mergeKLists(v2);
	cout<<"result : ";
	int i=0;
	while(p && i++<10){
		cout<<"["<<i<<"]"<<p<<": ";
		cout<<p->val<<", "<<endl;;
		p = p->next;
	}
	return 0;
}
