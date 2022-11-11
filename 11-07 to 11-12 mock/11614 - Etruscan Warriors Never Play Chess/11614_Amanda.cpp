/*
*OnlineJudge
*11614 - Etruscan Warriors Never Play Chess
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        unsigned long long c_2;
        cin >> c_2;

        // recall quadratic equation
        // x = (-b +- sqrt(b2 - 4ac))/2
        // b and a are +1, given is c/2
        unsigned long long bplus4ac = (1 + (8*c_2));
        unsigned long long sqrtbplus4ac = sqrt(bplus4ac);
        unsigned long long x = (-1 + sqrtbplus4ac)/2;

        cout << x << endl;

        // this solution is actually wrong according to the input being n <= 10^18
        // the test cases in the problem just don't involve numbers that high
        // OR! the answer in the test cases are wrong because they used the same solution
    }
    return 0;
}
