/*
*OnlineJudge
*514 - Rails
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    bool first = true;
    while (1) {
        cin >> N;
        if (N == 0)
            break;

        if (first) 
            first = false;
        else
            cout << endl;

        bool stop = false;

        while (1) {
            int train_out, train_in = 1;
            stack <int> train;
            for (int n = 0; n < N; n++) {
                cin >> train_out;
                if (!train_out) {
                    stop = true;
                    break;
                }

                while (train.empty() || (train.top() != train_out)) {
                    train.push(train_in);
                    train_in++;

                    if (train_in >= N)
                        break;
                }

                if (train.top() == train_out)
                    train.pop();
            }

            if (stop)
                break;

            if (train.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    cout << endl; // F. ito ung nire-refer ng blank sa null input
    return 0;
}