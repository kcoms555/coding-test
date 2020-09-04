#include "header.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct greater1{
	bool operator()(ListNode * a, ListNode * b) {
		return a->val>b->val;
	}
};
ListNode * mergeKLists(vector<ListNode *>& lists){
	vector<ListNode *> ns;
	for( auto &lit : lists){
		cout<<"list : ";
		ListNode * node = lit;
		while(node){
			cout<<node->val<<", ";
			ns.push_back(node);
			node = node->next;
		}
		cout<<endl;
	}
	sort(ns.begin(), ns.end(), greater1());
	for(auto &v : ns)
		cout << v << ": "<<v->val<<", ";
	cout<<endl;
	ListNode * head = nullptr;
	if(!ns.empty()){
		ListNode * node = head = ns.back(); ns.pop_back();
		while(!ns.empty()){
			node->next = ns.back(); ns.pop_back();
			node = node->next;
		}
		node->next = nullptr;
	}
	return head;
	/*
	for(auto i : heap) cout<<i->val<<", "; cout<<endl;
	make_heap(heap.begin(), heap.end(), greater1());
	for(auto i=heap.begin(); i!=heap.end(); i++) cout<<(*i)->val<<", "; cout<<endl;
	sort_heap(heap.begin(), heap.end(), greater1());
	for(auto i=heap.begin(); i!=heap.end(); i++) cout<<(*i)->val<<", "; cout<<endl;
	int num=0;
	for(int i=0; i<6; i++){
		cout<<num++<<" : ";
		for(auto i=heap.begin(); i!=heap.end(); i++) cout<<(*i)->val<<", "; cout<<endl;
		pop_heap(heap.begin(), heap.end()); heap.pop_back();
		//make_heap(heap.begin(), heap.end(), greater1());
	}
	cout<<endl;
	*/
}
int main(void){
	ListNode * a4 = new ListNode(2);
	ListNode * a3 = new ListNode(2, a4);
	ListNode * a2 = new ListNode(1, a3);
	ListNode * a1 = new ListNode(1, a2);
	ListNode * b3 = new ListNode(2);
	ListNode * b2 = new ListNode(1, b3);
	ListNode * b1 = new ListNode(1, b2);
	ListNode * c1 = new ListNode(1);
	vector<ListNode *> v{a2, b1};
	vector<ListNode *> v1;
	vector<ListNode *> v2{c1};
	ListNode * p = mergeKLists(v);
	cout<<"result : ";
	int i=0;
	while(p && i++<10){
		cout<<"["<<i<<"]"<<p<<": ";
		cout<<p->val<<", "<<endl;;
		p = p->next;
	}
	return 0;
}
