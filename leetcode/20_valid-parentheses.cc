#include "header.h"
bool isValidVector(string s){
	vector<char> v;
	for(char& c : s){
		char top;
		switch(c){
			case '(': v.push_back(c); break;
			case '{': v.push_back(c); break;
			case '[': v.push_back(c); break;
			case ')': if(v.empty()) return false; top = v.back(); if(top != '(') return false; v.pop_back(); break;
			case '}': if(v.empty()) return false; top = v.back(); if(top != '{') return false; v.pop_back(); break;
			case ']': if(v.empty()) return false; top = v.back(); if(top != '[') return false; v.pop_back(); break;
		}
	}
	if(v.empty()) return true;
	else return false;
}
bool isValidStack(string s){
	stack<char> v;
	for(char& c : s){
		char top;
		switch(c){
			case '(': v.push(c); break;
			case '{': v.push(c); break;
			case '[': v.push(c); break;
			case ')': if(v.empty()) return false; top = v.top(); if(top != '(') return false; v.pop(); break;
			case '}': if(v.empty()) return false; top = v.top(); if(top != '{') return false; v.pop(); break;
			case ']': if(v.empty()) return false; top = v.top(); if(top != '[') return false; v.pop(); break;
		}
	}
	if(v.empty()) return true;
	else return false;
}
int main(void){
	cout<<isValidVector("(){}[]")<<endl;;
	cout<<isValidVector("({}[])")<<endl;;
	cout<<isValidVector("({}[)]")<<endl;;
	cout<<isValidStack("(){}[]")<<endl;;
	cout<<isValidStack("({}[])")<<endl;;
	cout<<isValidStack("({}[)]")<<endl;;
	return 0;
}
