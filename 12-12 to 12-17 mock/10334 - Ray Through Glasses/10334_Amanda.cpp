/*
*OnlineJudge
*10334 - Ray Through Glasses
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

ostream& operator << (ostream& os, vector <int> A)
{
    int sz = A.size();
    for (int i = A.size() - 1; i >= 0; i--)
        os << A[i];
    return os;
}

// A is always the bigger number
vector <int> addAB (vector <int> A, vector <int> B)
{
    int sz = B.size();
    int carry = 0;

    int i;
    for (i = 0; i < sz; i++) {
        int temp = (A[i] + B[i] + carry)%10;
        carry = (A[i] + B[i] + carry)/10;
        A[i] = temp;
    }

    if (i < (int) A.size()) {
        if ((A[i] + carry) < 10)
            A[i] = (A[i] + carry);
        else {
            A[i] = (A[i] + carry)%10;
            A.push_back(carry);
        }
    } else if (carry)
        A.push_back(carry);

    return A;
}

int main ()
{
    vector <vector <int>> fib(1001);
    fib[0].push_back(1);
    fib[1].push_back(2);
    for (int i = 2; i <= 1000; i++)
        fib[i] = addAB(fib[i-1], fib[i-2]);
    
    int n;
    while (cin >> n)
        cout << fib[n] << endl;
        
    return 0;
}