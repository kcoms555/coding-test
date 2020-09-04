#include "header.h"
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ret = vector<int>();
	for(int i=0; i<nums.size()-1; i++){
		for(int j=i+1; j<nums.size(); j++){
			if(nums[i]+nums[j] == target){
				ret.push_back(i);
				ret.push_back(j);
				return ret;
			}
		}
	}
	return ret;
}
int main(void){
	vector<int> in{2, 7, 11, 13};
	vector<int> r = twoSum(in, 9);
	for(auto i = r.begin(); i != r.end(); i++)
		cout<<*i<<endl;
	return 0;
}
