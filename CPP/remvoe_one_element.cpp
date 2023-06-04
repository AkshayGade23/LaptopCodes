#include <bits/stdc++.h>
using namespace std;

// int XchosenByBob(vector<long long> arr1, vector<long long> arr2, int N)
// {
//     int diff1Front = arr2[0] - arr1[0];
//     int diff2Front = arr2[0] - arr1[1];

//     int diff1Back = arr2[N - 2] - arr1[N - 2];
//     int diff2Back = arr2[N - 2] - arr1[N - 1];

//     cout << diff1Front << "|" << diff1Back << endl;
//     cout << diff2Front << "|" << diff2Back << endl;

//     if (diff1Front < 0)
//         diff1Front = diff2Front;
//     if (diff1Back < 0)
//         diff1Back = diff2Back;
//     if (diff2Front < 0)
//         diff2Front = diff1Front;
//     if (diff2Back < 0)
//         diff2Back = diff1Back;

//     if (diff1Front == diff1Back || diff2Back == diff1Front)
//     {
//         if (diff2Back == diff2Front && diff1Front > diff2Front)
//         {
//             return diff2Front;
//         }
//         return diff1Front;
//     }

//     if (diff2Front == diff2Back)
//         return diff2Front;

//     return -1;
// }

// int main()
// {
//     // int T;
//     // cin >> T;

//     // while (T--)
//     // {
//     long long N;
//     cin >> N;
//     vector<long long> arr1(N);
//     vector<long long> arr2(N - 1);

//     for (long long i = 0; i < N; i++)
//         cin >> arr1[i];
//     cout << "akshay";

//     for (long long i = 0; i < N - 1; i++)
//         cin >> arr2[i];

//     sort(arr1.begin(), arr1.end());
//     sort(arr2.begin(), arr2.end());
//     cout << XchosenByBob(arr1, arr2, N) << endl;
//     // }

//     return 0;
// }

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n - 1);
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        for (long long i = 0; i < n - 1; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        map<long long, long long> answer;
        for (long long i = 0; i < n - 1; i++)
        {
            long long m1 = b[i] - a[i];
            long long m2 = b[i] - a[i+1];
            if (m1 != m2)
            {
                if (m1 > 0)
                    answer[m1] += 1;
                if (m2 > 0)
                    answer[m2] += 1;
            }
            else
            {
                if (m1 > 0)
                    answer[m1] += 1;
            }
        }

        for (auto i : answer)
        {
            if (i.second == n - 1)
            {
                cout << i.first << endl;
                break;
            }
        }
    }
}
