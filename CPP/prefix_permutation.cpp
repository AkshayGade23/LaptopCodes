#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool backtrack(int sum, int curr, int i, deque<int> &answer)
{
    if (sum % i == 0)
        return false;
}

void calculate(int n)
{
     vector<int> values;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        values.push_back(i);
        sum += i;
    }

    if (sum % n == 0)
    {
        cout << -1 << endl;
        ;
        return;
    }

    for (int i = n; i > 1; i--)
    {
        deque<int> answer;
        answer.push_front(i);
        values.

        if (backtrack(sum - i, i, n - 1))
        {
            for (int i = 0; i < answer.size(); i++)
            {
                cout << answer[i] << " ";
            }
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        calculate(n);
    }
    return 0;
}
