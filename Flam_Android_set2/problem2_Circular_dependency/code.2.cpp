#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool hasCircularDependency(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indeg(n,0);
        for(auto & it : edges){
            int u = it[0];
            int v = it[1];
            g[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
               
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto & it : g[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                q.push(it);
               
            }

            }
        }

        return (cnt != n);
    }

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
      int n;
      cin>>n;
      int m;  // edges size
      cin>>m;

      vector<vector<int>> edges(m, vector<int>(2));
      for(int i = 0; i < m; i++){
          cin>> edges[i][0] >> edges[i][1];
          
      }

      bool f = hasCircularDependency(n,edges);
      if(f){
        cout<<"True"<<endl;
      }
      else{
        cout<<"False"<<endl;
      }
    
    return 0;
}