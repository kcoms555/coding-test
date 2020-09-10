#include "header.h"
//min-heap compare operation
bool compare(tuple<int, int>& a, tuple<int, int>& b){
	return get<0>(a) > get<0>(b);
}
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	unordered_map<int, vector<tuple<int, int>>> graph;
	for(auto i : times){
		int from = i[0];
		int to = i[1];
		int consuming_time = i[2];
		graph[from].push_back(tuple<int, int>(consuming_time, to));
		printf("graph[%d] : appending(%d, %d)\n", from, consuming_time, to);
	}



	unordered_map<int, int> distance;
	vector<tuple<int, int>> q;
	q.push_back(tuple<int, int>(0, K));

	while(!q.empty()){
		pop_heap(q.begin(), q.end(), compare);
		auto p = q.back(); q.pop_back();
		int consuming_time = get<0>(p);
		int node = get<1>(p);
		printf("node : %d, consuming_time : %d\n", node, consuming_time);
		
		//if distance[node] is not defined
		if( distance.find(node) == distance.end() ){
			printf("distance[%d] not defined\n", node);
			distance[node] = consuming_time;
			for(auto& i : graph[node]){
				int time = get<0>(i) + consuming_time;
				int to = get<1>(i);
				q.push_back(tuple<int, int>(time, to)); push_heap(q.begin(), q.end(), compare);
				printf("graph[%d] : q: appending(%d, %d)\n", node, time, to);
			}
		}
	}

	for(auto i : distance){
		cout<<i.first<<" : "<<i.second<<endl;
	}

	//get max element
	if( distance.size() == N ) return max_element(distance.begin(), distance.end(), 
													[](const pair<int, int>& a, const pair<int, int>& b){ return a.second<b.second; })->second;
	else return -1;
}
int main(void){
	vector<vector<int>> times{{2,1,1},{2,3,3},{3,4,4}, {2, 4, 5}};
	cout<<networkDelayTime(times, 4, 2)<<endl;
	return 0;
}
