#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> d;
vector<int> sales;
unordered_map<int, vector<int>> map;

int get_best(int);

bool is_found(int employee_number) {
	return min(d[employee_number][0], d[employee_number][1]) > 0;
}

bool is_leaf(int employee_number) {
    return map[employee_number].size() == 0;
}

int is_attended(int employee_number) {
	return d[employee_number][1] < d[employee_number][0];
}

int get_best_when_included(int employee_number) {
	int sum = sales[employee_number-1];
    for(int child_number : map[employee_number]) {
        if(is_leaf(child_number)) continue;
        sum += get_best(child_number);
    }
	return sum;
}

int get_best_when_excluded(int employee_number) {
    bool is_any_one_attended = false;
    for(int child_number : map[employee_number]) {
        if(is_attended(child_number)) {
            is_any_one_attended = true;
            break;
        }
    }

	int sum = 0;
    if(is_any_one_attended){
        for(int child_number : map[employee_number]) {
            if(is_leaf(child_number)) continue;
            sum += get_best(child_number);
        }
		return sum;
    }

	// no one attended. select a person to attend who has lowerst sales skill.
	int _min = 987654321;
	int person_to_attend = 0;
	for(int child_number : map[employee_number]) {
		if(d[child_number][1] - d[child_number][0] < _min) {
			_min = d[child_number][1] - d[child_number][0];
			person_to_attend = child_number;
		}
	}

	sum += d[person_to_attend][1];
	for(int child_number : map[employee_number]) {
		if(child_number == person_to_attend) continue;
		sum += d[child_number][0];
	}
	return sum;
}

int get_best(int employee_number) {
    if(is_found(employee_number)){
        return min(d[employee_number][0], d[employee_number][1]);
    }

    for(int child_number : map[employee_number]){
        if(is_leaf(child_number)){
            d[child_number][0] = 0;
            d[child_number][1] = sales[child_number-1];
        }
    }

	d[employee_number][1] = get_best_when_included(employee_number);
	d[employee_number][0] = get_best_when_excluded(employee_number);
    return min(d[employee_number][0], d[employee_number][1]);
}

void init(vector<int>& _sales, vector<vector<int>>& links) {
    sales = _sales;

    d.resize(sales.size()+1);
    for(int i=0; i<sales.size()+1; i++){
        d[i].resize(2);
        d[i][0]=0;
        d[i][1]=0;
    }

    for(const auto& link : links) {
        map[link[0]].push_back(link[1]);
    }
}

int solution(vector<int> _sales, vector<vector<int>> links) {
    init(_sales, links);
    return get_best(1);
}

int main(){
//    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
//    vector<vector<int>> links = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};
//    vector<int> sales = {10, 10, 1, 1};
//    vector<vector<int>> links = {{3,2},{4,3},{1,4}};
//    vector<int> sales = {1, 2};
//    vector<vector<int>> links = {{1,2}};
//    vector<int> sales = {5, 6, 5, 3, 4};
//    vector<vector<int>> links = {{2,3}, {1,4}, {2,5}, {1,2}};
    vector<int> sales = {5, 6, 5, 1, 4};
    vector<vector<int>> links = {{2,3}, {1,4}, {2,5}, {1,2}};
//    vector<int> sales = {2, 3, 2};
//    vector<vector<int>> links = {{1,2}, {2,3}};
    printf("result : %d\n", solution(sales, links));
    for(int i=0; i<d.size(); i++) {
        printf("d[%d][0] : %d, d[%d][1] : %d\n", i, d[i][0], i, d[i][1]);
    }
    return 0;
}
