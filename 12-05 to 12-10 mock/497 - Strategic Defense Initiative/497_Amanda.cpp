/*
*OnlineJudge
*497 - Strategic Defense Initiative
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// despite the function, this is still bottom-up DP
void constructLIS(vector <int> arr, int n)
{
    
}

int main ()
{
    int N;
    cin >> N;
    getchar();

    bool first = true;
    for (int n = 0; n < N; n++) {
        if (first)
            first = false;
        else
            cout << endl;

        getchar();
        vector <int> arr;
        while(1) {
            if ((cin.peek() == '\n') || (cin.peek() == EOF))
                break;
            
            int x;
            cin >> x;
            getchar();
            arr.push_back(x);
        }

        int sz = arr.size();

        // L[i] - The longest increasing sub-sequence ending with arr[i]
        vector <vector<int>> L(sz);
        L[0].push_back(arr[0]);
    
        // LIS
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1))
                    L[i] = L[j];
            }
            L[i].push_back(arr[i]);
        }
    
        vector <int> max = L[0];
        for (int i = 0; i < (int) L.size(); i++)
            if (L[i].size() > max.size())
                max = L[i];
    
        // output LIS length
        cout << "Max hits: " << max.size() << endl;
        for (int i = 0; i < (int) max.size(); i++)
            cout << max[i] << endl;
    }
    return 0;
}