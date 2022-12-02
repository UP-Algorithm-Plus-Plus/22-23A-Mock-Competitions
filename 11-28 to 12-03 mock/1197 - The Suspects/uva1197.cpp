#include <bits/stdc++.h>

using namespace std;

int root(int head[], int i){
  while(head[i] != i)
    i = head[head[i]];

  return i;
}

void connect(int head[], int size[], int x, int y){
  int rootx = root(head, x);
  int rooty = root(head, y);

  if(rootx == rooty)
    return;

  if(size[rootx] >= size[rooty]){
    head[rooty] = rootx;
    size[rootx] += size[rooty];
  }else{
    head[rootx] = rooty;
    size[rooty] += size[rootx];
  }

  return;
}

int main(void){
  int n, m, k;

  while(cin >> n >> m){
    if(!n && !m)
      break;

    int head[n];
    int size[n];

    for(int i = 0; i < n; i++){
      head[i] = i;
      size[i] = 1;
    }

    for(int i = 0; i < m; i++){
      cin >> k;

      int prev, temp;

      cin >> prev;

      for(int j = 1; j < k; j++){
        cin >> temp;
        connect(head, size, prev, temp);
      }
    }

    cout << size[root(head, 0)] << endl;
  }

  return 0;
}
