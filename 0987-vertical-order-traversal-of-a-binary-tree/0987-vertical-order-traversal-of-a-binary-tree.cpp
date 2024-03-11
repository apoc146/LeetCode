class comp {
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.second < p2.second) {
            return true;
        } else if (p1.second == p2.second && p1.first < p2.first) { 
            return true;
        }
        return false;
    }
};


class Solution {
public:
    // map[X idx]:<Node Val, Y idx> 
    void dfs(TreeNode* root, int x_idx, int y_idx, map<int, vector<pair<int,int>>>& mp){
        if(root==NULL){
            return ;
        }
        mp[x_idx].push_back(make_pair(root->val,y_idx));
        dfs(root->left, x_idx-1, y_idx+1, mp);
        dfs(root->right,x_idx+1, y_idx+1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        dfs(root,0,0,mp);
        vector<vector<int>> ans;
        for(auto& ele:mp){
            vector<int> temp;
            auto vec = ele.second;
            sort(vec.begin(), vec.end(), comp());
            for(auto& pair:vec){
                temp.push_back(pair.first);
            } 
            ans.push_back(temp);
        }
        return ans;
    }
};
