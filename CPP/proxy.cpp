#include <iostream>
using namespace std;
#include <vector>

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int present = 0;
        cin >> n;

        vector<int> stud(n);
        vector<int> sir(n);

        for (int i = 0; i < n; i++)
        {
            bool val;
            cin >> val;
            stud[i] = val;

            if (val == true)
                present++;
        }

        cout << present << "hii";
        int canProxy = present;
        for (int i = 0; i < n; i++)
        {
            cin >> sir[i];

            if (!sir[i] && stud[i])
            {
                canProxy--;
            }
        }

        cout << present + (present - canProxy);
    }
    return 0;
}
