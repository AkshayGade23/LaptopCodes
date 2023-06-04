#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int maxSatisfaction(vector<int> &satisfaction)
{   int ans = INT_MIN;
    sort(satisfaction.begin(),satisfaction.end());
    for(int i = 0; i < satisfaction.size();i++){
        int sum = 0, count = 1;
        for(int j = i ; j < satisfaction.size();j++)
            sum += satisfaction[j] * count++;
        ans = max(ans,sum);
    }
    return ans;
}

int main()
{
    // vector<int> satisfaction = {-1, -8, 0, 5, -9};
    // cout << maxSatisfaction(satisfaction);
    string s= "AKshay";
    std::cout << "Hello world!";

    string ss= new string(s.begin(),s.end());
    std ::cout <<ss;
    return 0;
}
