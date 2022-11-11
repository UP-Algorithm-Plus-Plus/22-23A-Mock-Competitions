/*
*OnlineJudge
*11332 - Summing Digits
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

void func (int N) {
    if (N < 10) {
        cout << N << endl;
        return;
    }

    int sum = 0;
    while (N) {
        sum += (N%10);
        N /= 10;
    }

    func(sum);
    
    return;
}

int main ()
{
    int N;
    while (1) {
        cin >> N;
        if (!N)
            break;
        
        func(N);
    }
    return 0;
}
