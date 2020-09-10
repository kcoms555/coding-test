#include "header.h"
typedef int _node;
typedef int _price;
typedef int _stops;
//min-heap compare operation
bool compare(tuple<_price, _node, _stops>& a, tuple<_price, _node, _stops>& b){
	return get<0>(a) > get<0>(b);
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
	unordered_map<_node, vector<tuple<_price, _node>>> graph;
	for(auto i : flights){
		_node from = i[0];
		_node to = i[1];
		_price price = i[2];
		graph[from].push_back(tuple<_price, _node>(price, to));
	}

	vector<tuple<_price, _node, _stops>> q;
	q.push_back(tuple<_price, _node, _stops>(0, src, K));

	while(!q.empty()){
		pop_heap(q.begin(), q.end(), compare);
		auto p = q.back(); q.pop_back();
		int price = get<0>(p);
		int node = get<1>(p);
		int stop = get<2>(p);
		if(node == dst) return price;
		if(stop < 0) continue;
		for(auto i : graph[node]){
			int next_price = get<0>(i) + price;
			int to = get<1>(i);
			int k = stop-1;
			q.push_back(tuple<_price, _node, _stops>(next_price, to, k));
			push_heap(q.begin(), q.end(), compare);
		}
	}

	return -1;
}
int main(void){
	vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};
	cout<<findCheapestPrice(3, flights, 0, 2, 1)<<endl;
	cout<<findCheapestPrice(3, flights, 0, 2, 0)<<endl;
	return 0;
}
