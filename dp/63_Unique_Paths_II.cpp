/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        return uniquePathsWithObstaclesRecur(obstacleGrid, rows, cols);
    }
    int uniquePathsWithObstaclesRecur(vector<vector<int>>& obstacleGrid, int row, int col) {
        if((row == 0)||(col == 0)||(obstacleGrid[row - 1][col - 1] == 1)) {
            return 0;
        }
        if((row == 1)&&(col == 1)) {
            cache[row][col] = 1;
            return cache[row][col];
        }
        if(cache[row - 1][col] == 0) {
            cache[row - 1][col] = uniquePathsWithObstaclesRecur(obstacleGrid, row - 1, col);
        }
        if(cache[row][col - 1] == 0) {
            cache[row][col - 1] = uniquePathsWithObstaclesRecur(obstacleGrid, row, col - 1);
        }
        cache[row][col] = cache[row - 1][col] + cache[row][col - 1];
        return cache[row][col];
    }
private:
    int rows;
    int cols;
    int cache[101][101];
};
