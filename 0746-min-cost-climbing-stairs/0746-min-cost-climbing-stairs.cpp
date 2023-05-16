class Solution {
public:
    
    int foo(vector<int>& cost, int index, vector<int>& cache){
        
        int n=cost.size()-1;
        
        if(cache[index]!=-1){
            return cache[index];
        }
        
        //base case
        if(index==n || index==n-1){
            return cost[index];
        }
        
        long int cst1=foo(cost,index+1,cache);
        long int cst2=foo(cost,index+2,cache);
        cache[index+2]=cst2;
        cache[index+1]=cst1;
        
        cache[index]=cost[index]+min(cst1,cst2);
        
        return cache[index];
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
            vector<int> cache(cost.size(),-1);
            return min(foo(cost,0,cache),foo(cost,1,cache));
    }
};