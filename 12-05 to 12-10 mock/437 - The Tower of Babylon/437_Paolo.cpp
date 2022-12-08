#include <bits/stdc++.h>

using namespace std;

#define MAX_N 30*6

typedef long long int lli;
vector< vector<lli> > a;
vector<lli> memo;

// Top down solution
// lli dp(int idx) {
//     if (idx == a.size() - 1)
//         return a[idx][2];

//     if (memo[idx] != -1)
//         return memo[idx];

//     lli ans = a[idx][2];

//     for (int i = idx; i < a.size(); ++i) {
//         if (a[idx][0] < a[i][0] && a[idx][1] < a[i][1])
//             ans = max(ans, dp(i) + a[idx][2]);
//     }

//     return memo[idx] = ans;
// }

int main() {

    int n;
    int ctr = 1;
    while (true) {

        scanf("%d", &n);
        if (n == 0)
            break;

        a.clear();
        memo.clear();

        vector<int> v(3);
        for (int i = 0; i < n; ++i) {
            // Get the dimensions
            scanf("%d %d %d", &v[0], &v[1], &v[2]);

            // Consider all possible orientations
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    if (x==y)
                        continue;
                    for (int z = 0; z < 3; ++z) {
                        if (x == z || y == z)
                            continue;
                        
                        a.push_back({v[x], v[y], v[z]}); // push to array
                    }
                }
            }
        }

        memo.resize(a.size());

        // Sort in increasing order
        sort(a.begin(), a.end());

        lli ans = 0;
        
        // Longest increasing subsequence
        for (int i = a.size() - 1; i >= 0; --i) {
            memo[i] = a[i][2]; // at least the block itself

            for (int j = i; j < a.size(); ++j) {
                // increasing condition: first two dimensions of the block below are larger
                if (a[i][0] < a[j][0] && a[i][1] < a[j][1])
                    memo[i] = max(memo[i], memo[j] + a[i][2]); // add the height of the block
            }

            ans = max(memo[i], ans);
        }

        cout << "Case " << ctr++ << ": maximum height = " << ans << endl;
    }

    return 0;
}
