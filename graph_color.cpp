class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        stack<int>color_stack;
        for(int i=0; i<graph.size(); i++){
            
            if(color[i]==-1){
                color_stack.push(i);
                color[i]=0;
            }

            while(!color_stack.empty()){
                int index=color_stack.top();
                color_stack.pop();
                
                for(int j=0; j<graph[index].size(); j++){
                    if(color[graph[index][j]]==-1){
                        color[graph[index][j]]=color[index]^1;
                        color_stack.push(graph[index][j]);
                    }
                    else{
                        if(color[graph[index][j]]!=color[index^1])
                            return false;
                    }
                }

            }
        }
        return true;


    }
};