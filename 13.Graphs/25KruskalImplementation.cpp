
// Here in place of an object of Edge class, we are given a vector of 3 integers, 
// where first two integers are the vertices and the third integer is the weight of the edge. 
// So we will have to modify our comparator accordingly.

class Solution {
    vector<int> parent, rank;
    
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);
        
        if(pa==pb) return;
        
        if(rank[pa]>rank[pb]) parent[pb] = pa;
        else if(rank[pb]>rank[pa]) parent[pa] = pb;
        else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }
    
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        for(int i=0; i<V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }

        // FOCUS HERE
        // We are sorting the edges based on their weights in ascending order using a lambda function as a comparator.
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });
             
        int t=0;
        int count = 0;
        
        for(vector<int> a: edges){
            int u = a[0];
            int v = a[1];
            int w = a[2];
            
            int pu = find(u);
            int pv = find(v);
            
            if(pu!=pv){
                Union(u,v);
                t+=w;
                count++;
            }
            
            if(count==V) return t;
            
        }
        
        return t;
        
        
        
    }
};