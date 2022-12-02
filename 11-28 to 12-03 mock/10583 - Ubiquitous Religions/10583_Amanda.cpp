/*
*OnlineJudge
*10583 - Ubiquitous Religions
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
    int C = 1;
    while (cin >> N >> M) {
        if (!N && !M)
            break;
        
        int students[N];
        for (int n = 0; n < N; n++)
            students[n] = n;

        for (int m = 0; m < M; m++) {
            int i, j;
            cin >> i >> j;
            union_(students, i-1, j-1);
        }

        set <int> religion;
        for (int n = 0; n < N; n++) {
            int rel = find(students, n);
            if (religion.find(rel) == religion.end())
                religion.insert(rel);
        }

        printf("Case %d: %d\n", C++, (int) religion.size());
    }
    return 0;
}