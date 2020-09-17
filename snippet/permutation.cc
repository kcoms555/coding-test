#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Permutation{
private:
	std::vector<std::vector<T>> list_;
	void build_(std::vector<T> prefix, const T * start, int size, int count){
		if(count == 0){
			list_.push_back(prefix);
			return;
		}
		for(int i = 0; i<size; i++){
			std::vector<T> v(prefix);
			v.push_back(start[i]);
			build_(v, start, size, count-1);
		}
	}
public:
	Permutation(const std::vector<T>& input, int count){
		build_({}, &input[0], input.size(), count);
	}
	std::vector<std::vector<T>> get(){
		return list_;
	}
	void print(){
		for(auto& i : list_){
			for(auto& j : i){
				std::cout<<j<<" ";
			}
			std::cout<<std::endl;
		}
	}
};
