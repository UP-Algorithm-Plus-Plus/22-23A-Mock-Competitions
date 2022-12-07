/*
*OnlineJudge
*111 - History Grading
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    cin >> N;
    while (1) {
        if (cin.peek() == EOF)
            break;

        // rank in correct order of events
        int rank[N];
        for (int n = 0; n < N; n++)
            cin >> rank[n];

        getchar();
        while (1) {
            if ((cin.peek() == EOF) || (cin.peek() == '\n'))
                break;

            string S;
            getline(cin, S);
            stringstream ss (S);

            // responses
            // response is order given
            vector <int> resp;
            int x;
            while (ss >> x)
                resp.push_back(x);

            if (resp.size() == 1) {
                N = resp[0];
                break;
            }

            // chronological order according to responses
            int resp_order[N];
            for (int n = 0; n < N; n++) {
                resp_order[resp[n]-1] = n+1;
            }

            // ranking of events of the order given by the student
            int resp_rank[N];
            for (int n = 0; n < N; n++) 
                resp_rank[n] = rank[resp_order[n]-1];

            int ans = 0;
            int lis[N];
            lis[0] = 1;
            for (int i = 1; i < N; i++) {
                lis[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (resp_rank[i] > resp_rank[j])
                        lis[i] = max(lis[i], lis[j] + 1);
                }
                ans = max(ans, lis[i]);
            }

            cout << ans << endl;
        }
    }
    return 0;
}