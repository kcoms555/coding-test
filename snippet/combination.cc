#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Combination{
private:
	std::vector<std::vector<T>> list_;
	void build_(std::vector<T> prefix, const T * start, int size, int count){
		if(count == 0){
			list_.push_back(prefix);
			return;
		}
		for(int i = 0; i<=size-count; i++){
			std::vector<T> v(prefix);
			v.push_back(start[i]);
			build_(v, start+i+1, size-1-i, count-1);
		}
	}
public:
	Combination(const std::vector<T>& input, int count){
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
