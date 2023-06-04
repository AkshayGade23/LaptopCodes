#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

typedef pair<int, int> pi;
void printGird(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
int flood(vector<vector<int>> &grid, int i, int j, int n, int m)
{

    if ( 0 > i || 0 > j || i > n || j > m) {
        return -1;
    }
    {
        if (grid[i][j] == 2 || grid[i][j] == 0) return 0;

        grid[i][j] = 2;
        int right = flood(grid, i, j + 1, n, m);
        int down = flood(grid, i + 1, j, n, m);
        int up = flood(grid, i - 1, j, n, m);
        int left = flood(grid, i, j - 1, n, m);

        if (right>=0 && down>=0 && up>=0 && left>=0)
            return right + down + up + left + 1;
    }
    return -1;
}
    int numEnclaves(vector<vector<int>>& grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n - 1 ; i++)
    {
        for (int j = 1; j < m -1; j++)
        {
            if (grid[i][j] == 1)
                {
                    int curr =  flood(grid, i, j, n-1, m - 1);
                    if(curr > 0) count +=curr;
                    printGird(grid);
                    cout << count << "_---" <<endl;

                    cout<<endl<<endl;
                }
                    
        }
    }
    return count >= 0 ?count : 0;
    }
int main()
{

    vector<vector<int>> grid = {{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                                {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                                {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                                {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                                {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                                {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                                {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                                {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                                {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};

    cout << numEnclaves(grid);

    return 0;
}

