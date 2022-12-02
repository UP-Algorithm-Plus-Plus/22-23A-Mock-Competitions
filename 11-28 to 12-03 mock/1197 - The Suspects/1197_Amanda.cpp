/*
*OnlineJudge
*1197 - The Suspects
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find (int parent[], int A)
{
    while (A != parent[A])
        A = parent[A];
    return A;
}

void union_ (int parent[], int A, int B)
{
    int rootA = find(parent, A);
    int rootB = find(parent, B);

    if (rootA == rootB)
        return;
    
    parent[rootA] = rootB;

    return;
}

int main ()
{
    int N, M;
    while (cin >> N >> M) {
        if (!N && !M)
            break;

        int parent[N];
        for (int n = 0; n < N; n++)
            parent[n] = n;

        for (int m = 0; m < M; m++) {
            int K;
            cin >> K;
            
            int mom;
            cin >> mom;
            for (int k = 1; k < K; k++) {
                int a;
                cin >> a;
                union_(parent, a, mom);
            }
        }

        int ans = 0;
        for (int n = 0; n < N; n++) {
            if (find(parent, n) == find(parent, 0))
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}