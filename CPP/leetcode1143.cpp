#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

// recursion
int lcs(string s, string m, int i, int j)
{
    if (i == 0 || j == 0)
        return 0;

    if (s[i - 1] == m[j - 1])
        return 1 + lcs(s, m, i - 1, j - 1);
    else
        return max(lcs(s, m, i, j - 1), lcs(s, m, i - 1, j));
}

int longestCommonSubsequence(string text1, string text2)
{
    // // Top Bottom with space complexity O(m * n);

    int m = text1.size();
    int n = text2.size();

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // for (int i = 0; i < m + 1; i++)
    //     dp[i][0] = 0;
    // for (int i = 0; i < n + 1; i++)
    //     dp[0][i] = 0;

    // for (int i = 1; i < m + 1; i++)
    // {
    //     for (int j = 1; j < n + 1; j++)
    //     {
    //         if (text1[i - 1] == text2[j - 1])
    //             dp[i][j] = 1 + dp[i - 1][j - 1];

    //         else
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //     }
    // }

    // return dp[m][n];

    vector<int> prev(m + 1, 0), curr(n + 1, 0);

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];

            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return curr[n];
}

int main()
{
}