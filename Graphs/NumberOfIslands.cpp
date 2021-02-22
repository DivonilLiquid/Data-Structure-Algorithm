/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
class Solution {
    void RemoveOnesFromGrid(vector<vector<char>> &grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        //remove above one
        RemoveOnesFromGrid(grid,i-1,j);
        //remove below one
        RemoveOnesFromGrid(grid,i+1,j);
        //remove left one
        RemoveOnesFromGrid(grid,i,j-1);
        //remove right one
        RemoveOnesFromGrid(grid,i,j+1);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // first check the size of the 2-d array
        int NumberOfIsland = 0;
        /*if( grid.size() == 0 ){
            return NumberOfIsland;
        }*/
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                // chek if grid[i][j] is 1 or not
                // do this if it's 1
                if(grid[i][j]=='1'){
                    NumberOfIsland+=1;
                    RemoveOnesFromGrid(grid,i,j);
                }
                // do this if it's 0
            }
        }
        //return your answer
        return NumberOfIsland;
        
    }
};