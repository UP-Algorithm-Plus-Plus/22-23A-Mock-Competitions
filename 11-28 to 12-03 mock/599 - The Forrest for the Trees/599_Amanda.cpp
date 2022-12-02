/*
*OnlineJudge
*599 - The Forrest for the Trees
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find (int parent[], int A) {
    while (A != parent[A])
        A = parent[A];
    return A;
}

void union_ (int parent[], int A, int B) {
    int rootA = find(parent,A);
    int rootB = find(parent,B);

    parent[rootA] = rootB;
    
    return;
}

int main ()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        char tapon;
        cin >> tapon;
        
        int parent[26];
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        string S;
        while (1) { // not end
            if (tapon == '*')
                break; 
            
            cin >> S;
            stringstream ss(S);
            char nodeA, nodeB;
            ss >> nodeA >> tapon >> nodeB >> tapon;

            union_(parent, nodeA - 'A', nodeB - 'A');

            cin >> tapon;
        }

        while (cin.peek() == '*')
            cin >> tapon;

        int tree = 0, acorn = 0;
        int parentlist[26] = {0};
        cin >> S;
        stringstream ss(S);

        char c;
        vector <char> nodes;
        while (ss >> c) {
            if (c == ',')
                continue;

            nodes.push_back(c);
        }

        for (int i = 0; i < (int) nodes.size(); i++) {
            parentlist[find(parent,nodes[i] - 'A')]++;
        }

        for (int i = 0; i < 26; i++) {
            if (parentlist[i] == 1)
                acorn++;
            else if (parentlist[i] > 1)
                tree++;
        }

        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}