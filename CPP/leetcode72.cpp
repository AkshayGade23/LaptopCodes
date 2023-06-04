#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>


string simplifyPath(string path)
{
    int slash = 0;
    int dots = 0;
    string ans;
    stack<char> st;

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '.')
        {
            st.push(path[i]);
            dots++;
            slash = 0;
        }
        else
        {
            if (dots == 1 && path[i] == '/' && path[i - 1] == '/')
            {
                st.pop();
                st.pop();
            }

            if (dots == 2 && path[i] == '/' && path[i - 2] == '/')
            {
                int count = 0;
                while (!st.empty() && count != 2)
                {
                    if (st.top() == '/')
                        count++;
                    st.pop();
                }
            }

            if (path[i] == '/')
            {
                if (!slash)
                    st.push(path[i]);
                slash++;
            }
            else
            {
                st.push(path[i]);
                slash = 0;
            }
            dots = 0;
        }
        cout << st.top() << endl;
    }

    if (dots == 1)
    {
        st.pop();
        st.pop();
    }

    if (dots == 2)
    {
        int count = 0;
        while (!st.empty() && count != 2)
        {
            if (st.top() == '/')
                count++;
            st.pop();
        }
    }
    if (st.empty())
        return "/";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() != 1 && ans[ans.size() - 1] == '/')
        ans.erase(ans.size() - 1, 1);
    return ans;
}

int main()
{
    cout << simplifyPath("/hello../world");
    return 0;
}