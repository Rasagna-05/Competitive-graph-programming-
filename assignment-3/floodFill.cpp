class Solution {
public:
    bool valid(vector<vector<int>>& image, int i, int j, int c){
        if((i>=0) && (j>=0) && (image[i][j]==c) && (i<image.size()) && (j< image[0].size())){
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int c=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>>New=image;
        if(c==color){
            return image;
        }
        while(!q.empty()){
            pair<int,int>curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                pair<int,int>v={curr.first+d[i].first,curr.second+d[i].second};
                if(valid(image,v.first,v.second,c)){
                    q.push({v.first,v.second});
                    New[v.first][v.second]=color;
                }
            }
        }
        return New;
    }
};
