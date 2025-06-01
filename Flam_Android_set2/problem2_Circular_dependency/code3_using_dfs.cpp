#include<bits/stdc++.h>
using namespace std;
using ll = long long;

 bool dfs(int node, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& pathvis) {
      vis[node] = 1;
      pathvis[node] = 1;
      for (auto it: g[node]) {
        if (!vis[it]) {
          if (dfs(it, g, vis, pathvis)) return true;
        } else if (pathvis[it]) {
          return true;
        }
      }
      pathvis[node] = 0;
      return false;
}

bool hasCircularDependency(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> vis(n,0),pathvis(n,0);
        for(auto & it : edges){
            int u = it[0];
            int v = it[1];
            g[u].push_back(v);
            
        }
        
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                if(dfs(i,g,vis,pathvis)) return true;
            }
        }


        return false;
        
       

        
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