#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
typedef pair<int, int> pd;

struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};

unordered_map<int, int> mp;

int dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &totalColr, string &color, int curr)
{
    visited[curr] = true;
    totalColr[color[curr] - 97]++;
    int maxx = 0;

    for (int i = 0; i < graph[curr].size(); i++)
        if (!visited[graph[curr][i]])
            maxx = max(maxx, dfs(graph, visited, totalColr, color, graph[curr][i]));
        
    if (!maxx)
        for (auto val : totalColr)
            if (maxx < val)
                maxx = val;

    visited[curr] = false;
    totalColr[color[curr] - 97]--;
    return maxx;
}

int largestPathValue(string colors, vector<vector<int>> &edges)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> p1;
    vector<vector<int>> graph(colors.size());
    int maxx = 0;
    vector<bool> visited(colors.size());

    for (int i = 0; i < edges.size(); i++)
        graph[edges[i][0]].push_back(edges[i][1]);

    for (int i = 0; i < colors.size(); i++)
    {
        p1.push(make_pair(i, graph[i].size()));
    }

    while (!p1.empty())
    {
        vector<int> totalColrs(26);
       maxx = max(maxx, dfs(graph, visited, totalColrs, colors, p1.top().first));
        p1.pop();
    }
    return maxx;
}

int main()
{

    return 0;
}
