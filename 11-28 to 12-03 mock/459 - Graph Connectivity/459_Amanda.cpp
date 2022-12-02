/*
*OnlineJudge
*459 - Graph Connectivity
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find(int parent[], int x){
	if (parent[x] == x)
        return x;
    return find(parent, parent[x]);
}

void union_ (int parent[], int x, int y){
	int root_x = find(parent, x);
	int root_y = find(parent, y);

	if(root_x == root_y) 
        return;
    
    parent[root_x] = root_y;
    return;
}

int main ()
{
    int N;
    cin >> N;

    bool first = true;
    for (int n = 0; n < N; n++) {
        if (first)
            first = false;
        else
            cout << endl;

        char maxchar;
        cin >> maxchar;
        getchar();

        int sz = maxchar-'A' + 1;
        int parent[sz];
        for (int i = 0; i < sz; i++)
            parent[i] = i;

        while (1) {
            char a = getchar();
            if ((a == '\n') || (a == EOF))
                break;
                       
            char b = getchar();
            getchar();

            int A = a-'A';
            int B = b-'A';
            union_(parent,A,B);
        }

        set <int> unique_parent;
        for (int i = 0; i < sz; i++)
            if (unique_parent.find(find(parent,i)) == unique_parent.end())
                unique_parent.insert(find(parent,i));

        cout << unique_parent.size() << endl;
    }
    return 0;
}