/*
*OnlineJudge
*991 - Safe Salutations
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

long long fact (int A, int B)
{
    long long ans = 1;
    for (int i = A; i <= B; i++)
        ans *= i;
    return ans;
}

int main ()
{
    long long cat[11];
    for (int i = 0; i <= 10; i++)
        cat[i] = fact(i+1, 2*i)/(fact(1,i+1));
    
    int n;
    bool first = true;
    while (cin >> n) {
        if (first)
            first = false;
        else
            cout << endl;

        cout << cat[n] << endl;
    }

    return 0;
}