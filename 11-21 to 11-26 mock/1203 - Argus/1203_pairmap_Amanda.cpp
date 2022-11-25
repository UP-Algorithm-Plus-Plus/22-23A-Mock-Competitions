/*
*OnlineJudge
*1203 - Argus
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair <int,int>

int main ()
{
    string reg;
    int q_num, period;
    priority_queue <pii, vector <pii>, greater<pii>> argus;
    map <int, int> qp;
    while (cin >> reg) {
        if (reg == "#")
            break;
        cin >> q_num >> period;
        argus.push(make_pair(period, q_num));
        qp[q_num] = period;
    }

    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
        pii print = argus.top();
        argus.pop();
        cout << print.second << endl;
        print.first += qp[print.second];
        argus.push(print);
    }

    return 0;
}