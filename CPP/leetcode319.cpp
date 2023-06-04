#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

int bulbSwitch(int bulb){


    // vector<bool> onOff(bulb+1);

    // for(int i = 1 ; i<=bulb; i++){
    //     onOff[i] = true;
    // }

    // for(int i= 2 ;  i <=bulb ; i++){
    //     for(int j = i ; j <= bulb ; j = j + i){
    //         onOff[j] = !onOff[j];
    //     }
    // }

    // int count = 0;  
    // for(int i = 1 ;i <= bulb ; i++)
    //     if(onOff[i])count++;

    // return count;

    return sqrt(bulb);
}

int main(){

    int val;
    cin >> val;
   cout << bulbSwitch(val);
}