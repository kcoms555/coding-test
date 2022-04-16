#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    vector<vector<int> > courses;
    vector<bool> visit_arr;
    vector<int> in_degree;

public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        courses.resize(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++) {
            visit_arr.push_back(false);
            in_degree.push_back(0);
        }

        // 진입차수 초기화
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<courses[i].size(); j++){
                in_degree[courses[i][j]]++;
            }
        }

        bool is_all_checked;
        bool is_updated;
        while(true){
            is_all_checked = true;
            // for(int i=0; i<numCourses; i++){ visit_arr[i] = false; }
            is_updated = false;
            for(int i=0; i<numCourses; i++){
                if(!visit_arr[i] && in_degree[i]==0){
                    visit_arr[i] = true;
                    is_updated = true;
                    for(int j=0; j<courses[i].size(); j++){ // update in-degree
                        in_degree[courses[i][j]]--;
                    }
                }
            }

            if(!is_updated)
                break;

            for(int i=0; i<numCourses; i++){
                if(visit_arr[i] == false)
                    is_all_checked = false; //하나라도 방문 안했을 시 모든 노드를 방문한 경우가 아님.
            }

            if(is_all_checked)  //모든 노드를 방문했을 경우.
                break;
        }

        //판단
        for(int i=0; i<numCourses; i++){
            if(in_degree[i]!=0){
                return false;
            }
        }
        return true;
        }
};

        // while(true){
        //     int will_visit = -1;
        //     for(int i=0; i<numCourses; i++){
        //         if(!visit_arr[i] && in_degree[i]==0){
        //             will_visit = i;
        //             break;
        //         }
        //     }

        //     if (will_visit == -1){
        //         return false;
        //     }
            
        //     for(int i=0; i<courses[will_visit].size(); i++){
        //        in_degree[courses[will_visit][i]]--;
        //     }

        //     visit_arr[will_visit] = true;

        //     bool is_all_node_visit = true;
        //     for(int i=0; i<numCourses; i++){
        //         if(visit_arr[i] == false){
        //             is_all_node_visit = false;
        //             break;
        //         }
        //     }

        //     if(is_all_node_visit) {
        //         return true;
        //     }
        // }
        // 위상정렬에 해당하는 알고리즘 수행. -> 노드와 엣지가 지워진 in-degree arr를 반환받음.
        
    

        // 위상정렬에 해당하는 알고리즘 수행. -> 노드와 엣지가 지워진 in-degree arr를 반환받음.
        // while(true)
        // vector<int> update_list;
        // for(int i=0; i<numCourses; i++){
        //     if(in_degree[i]==0){
        //         for(int j=0; j<courses[i].size(); j++){ // update in-degree
        //             in_degree[courses[i][j]]--;
        //         }
        //     }
        // }





// in-degree arr로 판단. "!visit_arr[i] && in_degree[i]==0

        /*
0. 아직 방문하지 않았고, 진입차수 0인 노드부터 시작. 
0-1. 진입차수가 0인 노드가 없으면 False
0-2. 모두 방문했을 시 True
1. 출발지에서 나온 목적지에 해당하는 노드의 진입차수 1씩 감소
2. 출발지의 visit 여부 기록
3. 반복
        */


int main(){
    Solution sol;
    vector<vector<int>> arr = {{1,0},{0,1}};
    sol.canFinish(2, arr);
    return 0;
}