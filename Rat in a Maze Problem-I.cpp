class Solution {
  public:
  void helper(vector<vector<int>> &mat, int r, int c, vector<string> &ans, string path){
      int n=mat.size();
      //base case
      
      if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || mat[r][c] == -1){
          return;
      }
      if(r==n-1 && c==n-1){
          ans.push_back(path);
          return;
      }
      
      mat[r][c]=-1;                    //VISIT
      
      helper(mat, r,c-1,ans,path + "L");//left
      helper(mat, r,c+1,ans,path + "R");//right
      helper(mat, r-1,c,ans,path + "U");//up
      helper(mat, r+1,c,ans,path + "D");//down
      
      mat[r][c]=1;                    //UNVISIT           //BACKTRACK
  }
  
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<string> ans;
        string path="";
        
        
        helper(mat, 0, 0, ans, path);
        return ans;
    }
};

//RAT IN A MAZE

// Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

// The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

// Return the final result vector in lexicographically smallest order.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists and the destination cell is blocked.
// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1


