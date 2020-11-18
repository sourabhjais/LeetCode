class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        queue<int> Q;
        vector<int> degree(n,0);
        vector<int> ans;
        list<int> adj[n];
        if(n==1)
            ans.push_back(0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }    
        for(int i=0;i<degree.size();i++){
            if(degree[i]==1){
                Q.push(i);
            }
        }       
        while(n>2){
            int popEle=Q.size();
            n-=popEle;
            for(int i =0;i<popEle;i++){
                int t=Q.front();
                Q.pop();
                for(auto i=adj[t].begin();i!=adj[t].end();i++){
                    degree[*i]--;
                    if(degree[*i]==1){
                        Q.push(*i);
                    }
                }
            }
        }
        while (!Q.empty())
        {
            ans.push_back(Q.front());
            Q.pop();
        }
            return ans;
    }    
};
