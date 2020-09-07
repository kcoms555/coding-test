#include "header.h"
vector<string> letterCombinations(string digits) {
	vector<string> digitmap = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	queue<string> q;
	for(char& d : digits){
		if(q.empty()){
			for(char& c : digitmap[d-'2']){
				q.push(string()+c);
			}
		} else{
			int size = q.size();
			for(int i=0; i<size; i++){
				string front = q.front();
				q.pop();
				for(char& c : digitmap[d-'2']){
					q.push(front+c);
				}
			}
		}
	}
	vector<string> ret;
	int size = q.size();
	for(int i=0; i<size; i++){
//		cout<<q.front()<<", ";
		ret.push_back(q.front());
		q.pop();
	}
//	cout<<endl;
	return ret;
}
int main(void){
	letterCombinations("23");
	return 0;
}
