#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void DFS(Node *node, vector<bool> visited, vector<Node *> nodeAddress, Node *head)
{

    vector<Node *> neigh;
    visited[node->val] = true;

    for (int i = 0; i < node->neighbors.size(); i++)
    {
        if (nodeAddress[node->neighbors[i]->val])
            neigh.push_back(nodeAddress[node->neighbors[i]->val]);
        
        else
        {
            Node *n = new Node(node->neighbors[i]->val);
            neigh.push_back(n);
            nodeAddress[node->neighbors[i]->val] = n;
        }
        neigh.push_back(new Node(node->neighbors[i]->val));
        if (!visited[node->neighbors[i]->val])
        {
            DFS(node->neighbors[i], visited, nodeAddress, neigh[neigh.size() - 1]);
        }
    }

    head->neighbors = neigh;
}

Node *cloneGraph(Node *node)
{
    vector<bool> visited(101);
    Node *head = NULL;
    DFS(node, visited, head);
    return head;
}
int main()
{

    return 0;
    ;
}