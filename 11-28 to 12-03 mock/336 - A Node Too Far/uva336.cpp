#include <bits/stdc++.h>

using namespace std;

map<int, int> dist;
int reached;

void bfs(map<int, vector<int> > track, int start, int ttl){
  dist.clear();
  queue<int> q;
  dist[start] = 0;
  q.push(start);

  //algo starts here
  int curr_node, next_node;
  while(!q.empty()){
    curr_node = q.front(); q.pop();

    for(int i = 0; i < (int) track[curr_node].size(); ++i){
      next_node = track[curr_node][i];

      if(!dist.count(next_node)){//if not visited
        dist[next_node] = dist[curr_node] + 1;
        q.push(next_node);
				if(dist[next_node] <= ttl)
					reached++;
      }
    }
  }

	return;
}

int main(void){
	int NC;
	int case_num = 1;

	while(cin >> NC){
		if (NC == 0)
			break;

		int node1, node2;
		map<int, vector<int> > track;
		set<int> nodes;
		int uni = 0;

		for (int i = 0; i < NC; i++){
			cin >> node1 >> node2;
			track[node1].push_back(node2);
			track[node2].push_back(node1);
			if(!nodes.count(node1)){
				uni++;
				nodes.insert(node1);
			}
			if(!nodes.count(node2)){
				uni++;
				nodes.insert(node2);
			}
		}

		int init, ttl;
		while(cin >> init >> ttl){
			if(!init && !ttl)
				break;

			if(!nodes.count(init)){
				reached = 0;
			}else{
				reached = 1;
				bfs(track, init, ttl);
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", case_num, uni - reached, init, ttl);
			case_num++;
		}
	}

	return 0;
}
