#include "header.h"
int numJewelsInStones(string J, string S) {
	int count = 0;
	for(const auto &c : S) if(J.find(c) != string::npos) count++;
	return count;
}
int main(void){
	numJewelsInStones("aA", "aAAbbbb");
	return 0;
}
