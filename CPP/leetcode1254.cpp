#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

typedef pair<int, int> pi;

bool flood(vector<vector<int>> &grid, int i, int j, int n, int m)
{

    if (0 > i || 0 > j || i > n || j > m)
    {
        return false;
    }
    {
        if (grid[i][j] == 2 || grid[i][j] == 1)
            return true;

        grid[i][j] = 2;
        bool right = flood(grid, i, j + 1, n, m);
        bool down = flood(grid, i + 1, j, n, m);
        bool up = flood(grid, i - 1, j, n, m);
        bool left = flood(grid, i, j - 1, n, m);

        if (right && down && up && left)
            return true;
    }
    return false;
}

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
int closedIsland(vector<vector<int>> &grid)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 0)
                if (flood(grid, i, j, n - 1, m - 1))
                    count++;
        }
    }
    return count;
}

int main()
{

    vector<vector<int>> grid = {{0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
                                {1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
                                {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
                                {0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
                                {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
                                {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
                                {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
                                {1, 1, 1, 0, 1, 1, 0, 1, 1, 0}};

    cout << closedIsland(grid);

    return 0;
}
