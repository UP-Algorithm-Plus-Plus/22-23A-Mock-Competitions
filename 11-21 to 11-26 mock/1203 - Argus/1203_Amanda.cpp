/*
*OnlineJudge
*1203 - Argus
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string reg;
    int q_num, period;
    priority_queue <int, vector <int>, greater<int>> argus;
    int qp[3000];
    while (cin >> reg) {
        if (reg == "#")
            break;
        cin >> q_num >> period;
        argus.push((period*10000)+q_num);
        qp[q_num-1] = period;
    }

    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
        int print = argus.top();
        argus.pop();
        cout << print%10000<< endl;
        print += qp[print%10000 - 1]*10000;
        argus.push(print);
    }

    return 0;
}