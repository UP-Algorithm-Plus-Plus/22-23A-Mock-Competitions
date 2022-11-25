/*
*OnlineJudge
*13190 - Rockabye Tobby
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair <int,int>

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K;
        priority_queue <pii, vector <pii>, greater <pii>> medsched;
        map <string, int> medfreq;
        vector <string> medimp;

        cin >> N >> K;
        
        for (int n = 0; n < N; n++) {
            string med;
            int freq;
            cin >> med >> freq;
            medsched.push(make_pair(freq,medimp.size()));
            medfreq[med] = freq;
            medimp.push_back(med);
        }

        for (int k = 0; k < K; k++) {
            pii med = medsched.top();
            medsched.pop();

            cout << med.first << " " << medimp[med.second] << endl;

            med.first += medfreq[medimp[med.second]];
            medsched.push(med);
        }
    }
    return 0;
}