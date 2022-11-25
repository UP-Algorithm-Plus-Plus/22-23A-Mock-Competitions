/*
*OnlineJudge
*11849 - CD
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// note: not much difference between implementing bsearch and using bsearch function (i.e. not modifying start)
int start = 0;

int binarysearch (int arr[], int l, int r, int CD)
{
    if (r >= l) {
        int mid = l + (r-l)/2;

        if (arr[mid] == CD)
            return mid;
        
        if (arr[mid] > CD)
            return binarysearch(arr, l, mid-1,CD);
        else
            return binarysearch(arr, mid+1, r, CD);
    }

    return -1;
}
int main ()
{
    int N, M;
    while (1) {
        cin >> N >> M;
        if (!N && !M)
            break;

        int Jack[N];
        int ans = 0;
        for (int n = 0; n < N; n++) { // list Jack's CDs
            int CD;
            scanf("%i", &CD);
            Jack[n] = CD;
        }

        start = 0;
        for (int m = 0; m < M; m++) { // check if Jill owns a duplicate
            int CD;
            scanf("%i", &CD);
            int bs = binarysearch(Jack, start, N, CD);
            if (bs != -1) {
                start = bs;
                ans++;
            }
        }

        printf("%i\n", ans);
    }
    return 0;
}