#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int wordS = 0;
int targetS = 0;
const int mod = 1000000007;

// int solve(vector<string> &words, string target, vector<vector<int>> &dp, vector<vector<int>> &freq, int k, int index)
// {
//     if (k >= targetS)
//         return 1;

//     if (dp[index][k] != -1)
//     {
//         cout << "yesss";
//         return dp[index][k];
//     }

//     int currIndex = 0;
//     for (int j = wordS - (targetS - k - 1) - 1; j >= index; j--)
//     {
//         int frequency = freq[j][target[k] - 97];

//         if (frequency > 0)
//         {
//             int curr = (frequency * solve(words, target, dp, freq, k + 1, j + 1)) % mod;
//             currIndex = (currIndex + curr) % mod;
//             dp[j][k] = currIndex;
//         }
//         cout << index << " " << j << " " << k << " " << frequency << "->" << currIndex << endl;
//     }

//     return dp[index][k] = currIndex;
// }

int numWays(vector<string> &words, string target)
{
    targetS = target.size();
    wordS = words[0].size();
    vector<vector<int>> dp(wordS + 1, vector<int>(targetS + 1, 0));

    vector<vector<int>> freq(wordS, vector<int>(26, 0));

    for (int j = 0; j < wordS; j++)
        for (int i = 0; i < words.size(); i++)
            freq[j][words[i][j] - 97]++;

    for (int j = wordS; j >= 0; j--)
        for (int i = targetS; i >= 0; i--)
        {
            if (i == targetS)
            {
                dp[j][i] = 1;
                continue;
            }
            if (j == wordS)
            {
                dp[j][i] = 0;
                continue;
            }

            int frequency = freq[j][target[i] - 97];
            int ways = 0;
            int nott = dp[j+1][i];

            if(frequency  > 0){
                int curr = frequency;
                int next = dp[j+1][i+1];
                ways = (curr * (long long)next) % mod;
            }
            dp[j][i] = ((ways + nott ) % mod);
        }

    return dp[0][0];
    // int m = words.size(), n = words[0].size();
    // vector<vector<int>> freq(n, vector<int>(26, 0));
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         char ch = words[i][j];
    //         freq[j][ch - 'a']++; // freq of 'ch' in jth col
    //     }
    // }
    // //===================================================================================================
    // // TOP DOWN =>
    // //  1)[colIdx = j], we expected results for [colIdx = j + 1]
    // //  2)[targetIdx = k], we expected results for [targetIdx = k + 1]
    // // BOTTOM UP =>
    // //  1) We calculate [col = j + 1] results first
    // //     Then use them in [colIdx = j] :)
    // //  2) We calculate [targetIdx = k + 1] results first
    // //     Then use them in [targetIdx = k] :)

    // int targetSize = target.size();
    // vector<vector<int>> dp(n + 1, vector<int>(targetSize + 1, 0));
    // for (int colIdx = n; colIdx >= 0; colIdx--)
    // {
    //     for (int targetIdx = targetSize; targetIdx >= 0; targetIdx--)
    //     {
    //         // SAME BASE CONDITIONS AS IN TOP DOWN
    //         if (targetIdx == targetSize)
    //         {
    //             dp[colIdx][targetIdx] = 1;
    //             continue;
    //         }
    //         if (colIdx == n)
    //         {
    //             dp[colIdx][targetIdx] = 0;
    //             continue;
    //         }

    //         char targetCh = target[targetIdx];
    //         int notPickWays = dp[colIdx + 1][targetIdx];
    //         //===================================================================
    //         int pickWays = 0;
    //         if (freq[colIdx][targetCh - 'a'] != 0)
    //         {
    //             int currWays = freq[colIdx][targetCh - 'a'];
    //             int nextWays = dp[colIdx + 1][targetIdx + 1];
    //             pickWays = (currWays * (long long)nextWays) % mod;
    //         }
    //         //====================================================================
    //         dp[colIdx][targetIdx] = ((pickWays + (long long)notPickWays) % mod);
    //     }
    // }
    // return dp[0][0];
}

int main()
{

    vector<string> words = {"kidbjae", "bfchgfb", "gaaehef", "agjakgg", "abkkdjc", "bahgbig", "fedidah"};
    string target = "fd";

    cout << numWays(words, target);
    return 0;
}