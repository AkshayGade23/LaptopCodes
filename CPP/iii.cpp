#include "bits/stdc++.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "vector"
using namespace std;

struct CustomBit
{
    char ch;
    bitset<1> bits;
    // bool isBit = true;

    CustomBit()
    {
        bits = NULL;
        ch = NULL;
    }
};

vector<CustomBit> createCustomArray(string text)
{
    vector<CustomBit> cb;

    for (int i = 0; i < text.length(); i++)
    {
        CustomBit b;
        if (text.at(i) == '1' || text.at(i) == '0')
        {
            b.bits = text.at(i);
            cb.push_back(b);
        }
        else
        {
            b.ch = text.at(i);
            // b.isBit = false;
            cb.push_back(b);
        }
    }
    return cb;
}
// A1B0
int main()
{
    vector<CustomBit> cb;
    string text = "vinay1010auibiuab10";
    cb = createCustomArray(text);
    for (int i = 0; i < cb.size(); i++)
    {
        if (cb.at(i).ch)
            cout << cb.at(i).ch;
        else
            cout << cb.at(i).bits;
    }
    cout << endl
         << sizeof(cb);
}