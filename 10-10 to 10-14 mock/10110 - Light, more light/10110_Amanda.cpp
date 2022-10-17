/*
*OnlineJudge
*10110 - Light, more light
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    unsigned int n;
    cin >> n;
    while (n) {
        unsigned int root = sqrt(n);
        if ((root*root) == n)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        cin >> n;
    }
    return 0;
}
