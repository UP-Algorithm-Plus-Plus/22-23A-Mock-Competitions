#include <bits/stdc++.h>

using namespace std;

int root(int head[], int i){
  while(i != head[i]){
    i = head[head[i]];
  }

  return i;
}

void connect(int head[], int x, int y){
  int rootx = root(head, x);
  int rooty = root(head, y);

  if(rootx == rooty)
    return;
  else
    head[rootx] = rooty;

  return;
}

int main(void){
  int cases;

  cin >> cases;
  cin.ignore();
  for(;cases > 0; cases--){
    string input;
    int head[26];
    stringstream in;
    char buf, buf1, edge1, edge2;
    int node[26] = {0};

    for(int i = 0; i < 26; i++)
      head[i] = i;

    while(getline(cin, input)){
      if(input[0] == '*')
        break;

      in.str("");
      in << input;
      in >> buf >> edge1 >> buf1 >> edge2;
      connect(head, edge1 - 'A', edge2 - 'A');
    }

    in.str("");
    getline(cin , input);
    in << input;
    while(in >> buf){
      if(buf != ',')
       node[root(head, buf - 'A')]++;
    }

    int trees = 0, acorn = 0;
    for(int i = 0; i < 26; i++){
      if(node[i] == 1)
        acorn++;
      else if(node[i] > 1)
        trees++;
    }

    printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
  }

  return 0;
}
