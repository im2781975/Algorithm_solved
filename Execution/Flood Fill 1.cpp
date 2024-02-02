#include <bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>>& ans,int newColor,int iniColor,int n,int m,int delrow[],int delcol[]){
     
    // Marking it as the newColor
    ans[row][col] = newColor;
    for(int i=0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
          // Checking Out Of Bound Condition
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
            dfs(nrow,ncol,image,ans,newColor,iniColor,n,m,delrow,delcol);
        }
    }
     
}
// FloodFill Function
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
          // Initial Color 
        int iniColor = image[sr][sc];
          // vectors for changing of rows and column direction
          // UP LEFT DOWN RIGHT
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
          // Calling dfs function
        dfs(sr,sc,image,ans,newColor,iniColor,n,m,delrow,delcol);
        return ans;
    }
 
// Driver code
int main()
{
    vector<vector<int> > screen
        = { {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1} };
 
    int n = screen.size();
      int m = screen[0].size();
    // Co-ordinate provided by the user
    int x = 1;
    int y = 1;
    // New color that has to be filled
    int newC = 3;
    vector<vector<int>> ans = floodFill(screen, x, y, newC);
    // Printing the updated screen
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
