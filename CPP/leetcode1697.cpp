#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>



bool dfs(int curr, int end, int limit, int n, vector<vector<priority_queue<int, vector<int>, greater<int>>>> &graph, vector<bool> &vis)
{
    vis[curr] = true;

    if(d[curr][end]!= -1 && d[curr][end] < limit) return true;

    if (curr == end)
        return true;

    for (int j = 0; j < n; j++)
    {
        if (vis[j])
            continue;

        if (!graph[curr][j].empty() && graph[curr][j].top() < limit)
        {
            if (dfs(j, end, limit, n, graph, vis))
                return true;
        }
    }
    return false;
}


vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
{
    vector<vector<priority_queue<int, vector<int>, greater<int>>>> graph(n, vector<priority_queue<int, vector<int>, greater<int>>>(n));

   vector<vector<int>> dp(n,vector<int> (n,-1));

    for (int i = 0; i < edgeList.size(); i++)
    {
        int src = edgeList[i][0];
        int dest = edgeList[i][1];
        int val = edgeList[i][2];
        graph[src][dest].push(val);
        graph[dest][src].push(val);

    }
    vector<bool> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        vector<bool> vis(n, false);
        ans.push_back(dfs(queries[i][0], queries[i][1], queries[i][2], n, graph, vis));
    }

    for(int  i  = 0 ; i< ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return ans;
}


int main()
{

    vector<vector<int>> edgeList = {
        {0, 1, 2},
        {1, 2, 4},
        {2, 0, 8},
        {1, 0, 16},
    };

    vector<vector<int>> queries = {
        {0, 1, 2},
        {0, 2, 5},
    };

    distanceLimitedPathsExist(3, edgeList, queries);
    return 0;
}