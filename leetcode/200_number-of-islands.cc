#include "header.h"
typedef vector<vector<char>> Grid;
class Solution{
private:
	bool is_valid(Grid& grid, int x, int y){
		if( x<0 || x>=grid.size() ) return false;
		if( y<0 || y>=grid[x].size() ) return false;
		return true;
	}
	void dfs(Grid& grid, int x, int y){
		if(!is_valid(grid, x, y)) return;
		if( grid[x][y] == '1'){
			grid[x][y] = '2';
			this->dfs(grid, x-1, y);
			this->dfs(grid, x+1, y);
			this->dfs(grid, x, y-1);
			this->dfs(grid, x, y+1);
		}
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int islands = 0;

		int xsize = grid.size();
		if(xsize == 0) return 0;
		int ysize = grid[0].size();
		if(ysize == 0) return 0;

		for(int i=0; i<xsize; i++){
			for(int j=0; j<ysize; j++){
				if( grid[i][j] == '1' ){
					this->dfs(grid, i, j);
					islands++;
				}
			}
		}
		return islands;
	}
};
int main(void){
	Grid g;
	return 0;
}
