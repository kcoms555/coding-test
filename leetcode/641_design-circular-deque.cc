#include "header.h"
template <typename T>
class DoubleLinkedList{
public:
	T val;
	DoubleLinkedList * left, * right;
	DoubleLinkedList(){}
	DoubleLinkedList(T val):val(val){}
};

template<typename T>
using dequelist = DoubleLinkedList<T>;

class MyCircularDeque {
private:
	int maxsize, len = 0;
	dequelist<int> * head = nullptr, * tail = nullptr;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
		maxsize = k;
		head = new dequelist<int>(-1);
		tail = new dequelist<int>(-1);
		head->left = nullptr;
		head->right = tail;
		tail->left = head;
		tail->right = nullptr;
    }
	~MyCircularDeque(){
		while(head){
			cout<<"~MyCircularDeque() : ";
			cout<<head->val<<endl;
			dequelist<int> * tmp = head->right;
			delete head;
			head = tmp;
		}
	}
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
		if(len >= maxsize) return false;
		dequelist<int> * node = new dequelist<int>(value);
		if(!node) return false;
		len++;
		dequelist<int> * tmp = head->right;
		node->left = head;
		node->right = tmp;
		head->right = node;
		tmp->left = node;
		return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
		if(len >= maxsize) return false;
		dequelist<int> * node = new dequelist<int>(value);
		if(!node) return false;
		len++;
		dequelist<int> * tmp = tail->left; 
		node->left = tmp;
		node->right = tail;
		tail->left = node;
		tmp->right = node;
		return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
		if(!len) return false;
		len--;
		dequelist<int> * node = head->right;
		head->right = node->right;
		node->right->left = head;
		delete node;
		return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
		if(!len) return false;
		len--;
		dequelist<int> * node = tail->left;
		tail->left = node->left;
		node->left->right = tail;
		delete node;
		return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
		return head->right->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
		return tail->left->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
		return not len;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
		return len == maxsize;
    }
};

int main(void){
	MyCircularDeque q(5);
	q.insertLast(1);
	q.insertLast(2);
	q.insertLast(3);
	cout<<q.getFront()<<endl;
	q.deleteFront();
	cout<<q.getFront()<<endl;
	q.deleteFront();
	cout<<q.getFront()<<endl;
	q.deleteFront();
	cout<<q.getFront()<<endl;
	q.deleteFront();
	q.insertFront(4);
	q.insertFront(5);
	q.insertFront(6);
	return 0;
}
