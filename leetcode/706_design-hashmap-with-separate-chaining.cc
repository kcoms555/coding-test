#include "header.h"
#include <random>
template <typename T>
class DoubleLinkedList{
public:
	T key, val;
	DoubleLinkedList * left = nullptr, * right = nullptr;
	DoubleLinkedList():key(-1), val(-1), left(nullptr), right(nullptr){}
	DoubleLinkedList(T key, T val):key(key), val(val), left(nullptr), right(nullptr){}
};

template<typename T>
using dllist = DoubleLinkedList<T>;

class MyHashMap {
private:
	unsigned int size = 10;
	unsigned int len = 0;
	vector<dllist<int>> map;
public:
	int colisions = 0;
private:
	void resize(int size){
//		printf("###################resizing################\n");
		this->size = size;
		this->len = 0;
		auto tmpvec = map;
		map = vector<dllist<int>>(size, dllist<int>());
		for(auto &table : tmpvec){
			auto head = table;
			if(head.val != -1){
				this->put(head.key, head.val);
				dllist<int> * node = head.right;
				while(node){
					this->put(node->key, node->val);
					auto tmp = node;
					node = node->right;
					delete tmp;
				}
			}
		}
//		printf("###################end of resizing################\n");
	}
	dllist<int> * find_key(int key){
		//printf("finding %d... ", key);
		int index = key%size;
		if(map[index].key == -1) return nullptr;

		dllist<int> * found = nullptr;
		if(map[index].key == key){
			found = &(map[index]);
		} else{
			auto node = map[index].right;
			colisions++;
			while(node){
				colisions++;
				//printf("->%d", node->key);
				if(node->key == key) break;
				else node = node->right;
			}
			found = node;
		}
		return found;
	}
public:
	
	/** Initialize your data structure here. */
	MyHashMap() {
		map = vector<dllist<int>>(size, dllist<int>());
//		printf("size : %d, %d, %d\n", map.size(), map.front().val, map.back().val);
	}
	MyHashMap(int size):size(size) {
		map = vector<dllist<int>>(size, dllist<int>());
//		printf("size : %d, %d, %d\n", map.size(), map.front().val, map.back().val);
	}

	int getvectorsize(){
		return this->map.size();
	}
	int getsize(){
		return this->len;
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		colisions = 0;
//		printf("putting %d:%d ... ", key, value);
		auto found = find_key(key);
		if(found){
//			printf(" found! %d:%d->%d\n", key, found->val, value);
			found->val = value;
			return;
		}
		else{
//			printf("not found! added in ");
			int index = key%size;
			if(map[index].key == -1){
				map[index].key = key;
				map[index].val = value;
				auto tmp = &(map[index]);
//				printf("space[%d](%p)%p(%p) <-- added\n", index, tmp->left, tmp, tmp->right);
			}
			else{
//				printf("space[%d]%p", index, &(map[index]));
				auto nodeleft = &(map[index]);
				auto node = map[index].right;
				while(node){
//					printf("->%p", node);
					nodeleft = node;
					node = node->right;
				}
				nodeleft->right = new dllist<int>(key, value);
				nodeleft->right->left = nodeleft;
				auto tmp = nodeleft->right;
//				printf("->(%p)%p(%p) <-- added\n", tmp->left, tmp, tmp->right);
			}
			this->len++;
		}
		//if((double)len/size>0.5) resize(size*2);
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		colisions = 0;
		auto found = find_key(key);
		if(found) return found->val;
		else{
//			printf("get:(%d) not found\n", key);
			return -1;
		}
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
//		printf("removing %d ... ", key);
		auto found = find_key(key);

		if(found){
			len--;
		}
		else{
//			printf("not found\n", key);
			return;
		}

		auto node = found;
		while(node->left) node = node->left;
//		if(node == found) printf("space[%d](%p <-- this)", key%size, node);
//		else printf("space[%d]%p", key%size, node);
		node = node->right;
		while(node){
//			if(node == found) printf("->(%p <-- this)", node);
//			else printf("->%p", node);
			node = node->right;
		}

		if(found->left){
			found->left->right = found->right;
			if(found->right) found->right->left = found->left;
//			printf(", deleting (%p)%p(%p)", found->left, found, found->right);
			delete found;
		} else{
			if(found->right){
				auto tmp = found->right;
				*found = *tmp;
				found->left = nullptr;
				if(tmp->right) tmp->right->left = found;
//				printf(", deleting (%p)%p(%p), found:(%p)%p(%p)", tmp->left, tmp, tmp->right, found->left, found, found->right);
				delete tmp;
			}
			else{
				*found = dllist<int>();
			}
		}
//		printf("\n");
	}
};

int main(void){
	printf("start\n");
	MyHashMap hashMap1;
	MyHashMap hashMap2;
	MyHashMap hashMap3;
	for(int i=0; i<10; i++) hashMap1.put(i, 1);
	for(int i=0; i<10; i++) hashMap1.put(10+i, 1);
	for(int i=0; i<10; i++) hashMap1.put(20+i, 1);
	for(int i=0; i<10; i++) hashMap1.remove(i);

	for(int i=0; i<10; i++) hashMap2.put(i, 1);
	for(int i=0; i<10; i++) hashMap2.put(10+i, 1);
	for(int i=0; i<10; i++) hashMap2.put(20+i, 1);
	for(int i=0; i<10; i++) hashMap2.remove(10+i);

	for(int i=0; i<10; i++) hashMap3.put(i, 1);
	for(int i=0; i<10; i++) hashMap3.put(10+i, 1);
	for(int i=0; i<10; i++) hashMap3.put(20+i, 1);
	for(int i=0; i<10; i++) hashMap3.remove(20+i);
	/*
	int num;
	MyHashMap hashMap(100);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 10000);
	int tries = 1000;
	for(int i=0; i<100; i++){
		hashMap.put(dis(gen), 1);
		printf("loadfactor : %.2f ", (double)hashMap.getsize()/hashMap.getvectorsize());
		int colisions_sum = 0;
		for(int i=0; i<tries; i++){
			hashMap.get(dis(gen));
			colisions_sum += hashMap.colisions;
		}
		printf("average colisions : %.2f%\n", ((double)colisions_sum/tries) * 100);
	}

	*/
	printf("end\n");
	return 0;
}
