#include <iostream>
#include <vector>
using namespace std;

 void coverIsland(vector<vector<char>> &board, int m, int n, int x, int y)
    {
        if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O')
        {
            board[x][y] = 'X';
            coverIsland(board, m, n, x + 1, y);
            coverIsland(board, m, n, x, y + 1);
            coverIsland(board, m, n, x - 1, y);
            coverIsland(board, m, n, x, y - 1);
        }   
    }   

    bool IslandOnEdge(vector<vector<char>> &board,vector<vector<bool>> &visited, int m, int n, int x, int y)
    {
        if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O' && !visited[x][y])
        {
            visited[x][y] = true;
            if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                return true;

              bool right =  IslandOnEdge(board, visited, m, n, x + 1, y) ;
             bool down =    IslandOnEdge(board, visited, m, n, x, y + 1) ;
             bool left =    IslandOnEdge(board, visited, m, n, x - 1, y) ;
             bool up =    IslandOnEdge(board, visited, m, n, x, y - 1);
             if(right || down || left || up)
            return true;
        }
        return false;
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (board[i][j] == 'O' && !visited[i][j] && !IslandOnEdge(board, visited, m, n, i, j))
                    coverIsland(board, m, n, i, j);
    } 





// void coverIsland(vector<vector<char>> &board, int m, int n, int x, int y, char c)
//     {
//         if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'M')
//         {
//             board[x][y] = c;
//             coverIsland(board, m, n, x + 1, y, c);
//             coverIsland(board, m, n, x, y + 1, c);
//             coverIsland(board, m, n, x - 1, y, c);
//             coverIsland(board, m, n, x, y - 1, c);
//         }   
//     }   

//     bool IslandOnEdge(vector<vector<char>> &board, int m, int n, int x, int y)
//     {
//         if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O')
//         {
//             board[x][y] = 'M';
//             if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
//                 return true;

//             else if (IslandOnEdge(board, m, n, x + 1, y) ||
//                  IslandOnEdge(board, m, n, x, y + 1) ||
//                  IslandOnEdge(board, m, n, x - 1, y) ||
//                  IslandOnEdge(board, m, n, x, y - 1))
//                 return true;
//         }
//         return false;
//     }

//     void solve(vector<vector<char>> &board)
//     {
//         int m = board.size();
//         int n = board[0].size();
//         for (int i = 1; i < m-1; i++)
//         {
//             for (int j = 1; j < n-1; j++)
//             {
//                 if (board[i][j] == 'O')
//                 {
//                     if (!IslandOnEdge(board, m, n, i, j))
//                         coverIsland(board, m, n, i, j, 'X');
//                     else
//                         coverIsland(board, m, n, i, j, 'O');
//                 }
//             }
//         }
//     }
int main()
{
    vector<vector<char>> board{{'O', 'X', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'O', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'O'}, {'X', 'X', 'O', 'X', 'O'}};

    // board.push_back({'X', 'X', 'X', 'X'});
    // board.push_back({'X', 'O', 'O', 'X'});
    // board.push_back({'X', 'X', 'X', 'X'});
    // board.push_back({'X', 'O', 'X', 'X'});

    solve(board);

    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



