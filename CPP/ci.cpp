#include <iostream>
#include <fstream>
#include "stdio.h"
#include "bits/stdc++.h"
#include <fcntl.h>
using namespace std;

int main()
{
    //   int f = open("akshay.txt",O_CREAT);
    //    bitset<30000> m ("1");

    fstream f;
    f.open("akshaggggade.txt", ios ::out);

    for (int i = 0; i < 30000; i++)
        f << 0;

    // int i = 9;
    //    write(f,&i,sizeof(i));

    //  fscanf(ptr, "%s %s %s %d", str1, str2, str3, &year);
}