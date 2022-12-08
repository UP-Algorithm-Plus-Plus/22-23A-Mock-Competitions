/*
*OnlineJudge
*437 - The Tower of Babylon
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    int C = 1;
    while (cin >> N) {
        if (!N)
            break;

        vector <pair <pair <int, int>, int>> arr;
        int a, b, c;
        for (int n = 0; n < N; n++) {
            cin >> a >> b >> c;
            arr.push_back(make_pair(make_pair(a, b), c));
            arr.push_back(make_pair(make_pair(b, a), c));
            arr.push_back(make_pair(make_pair(a, c), b));
            arr.push_back(make_pair(make_pair(c, a), b));
            arr.push_back(make_pair(make_pair(b, c), a));
            arr.push_back(make_pair(make_pair(c, b), a));
        }

        sort(arr.begin(), arr.end());

        int lis[arr.size()];
        lis[0] = arr[0].second;
        int ans = 0;
        for (int i = 1; i < (int) arr.size(); i++) {
            lis[i] = arr[i].second;
            for (int j = 0; j < i; j++) {
                if ((arr[i].first.first > arr[j].first.first) &&
                    (arr[i].first.second > arr[j].first.second)) {
                    lis[i] = max(lis[i], lis[j] + arr[i].second);
                }
            }
            ans = max(ans, lis[i]);
        }

        printf("Case %d: maximum height = %d\n", C++, ans);
    }
    return 0;
}