#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    const bool custom_sort_position_time(pair<int,int> p1,pair<int,int> p2){
        if(p1.first>p1.first){
            return true;
        }
        return false;
    }

    void printCppVersion(){
        if (__cplusplus == 201703L) std::cout << "C++17\n";
        else if (__cplusplus == 201402L) std::cout << "C++14\n";
        else if (__cplusplus == 201103L) std::cout << "C++11\n";
        else if (__cplusplus == 199711L) std::cout << "C++98\n";
        else std::cout << "pre-standard C++\n";
    }

    string strToLower(string s){
            std::transform(s.begin(),s.end(),s.begin(),::tolower);
            return s;
    }

    string strToUpper(string s){
        std::transform(s.begin(),s.end(),s.begin(),::toupper);
        return s;
    }

    bool isMapFull(unordered_map<char,int> map, unordered_map<char,int> tStrMap){
        bool ret=true;
        for(const auto& ele:tStrMap){
            if(map.count(ele.first) && (map[ele.first]<ele.second)){
                return false;
            }
        }
        return ret;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> tStringMap;

        for(int tt=0;tt<t.size();tt++){
            tStringMap[t[tt]]++;
        }

        bool flag=false;
        string res="";
        int min_global=INT_MAX;

        int i=0;
        int j=t.size()-1;
        int win_size=t.size();
        unordered_map<char,int> map;



        for(int i=0;i<t.size();i++){
            map[t[i]]=0;
        }

        for(int itr=i;itr<=j;itr++){
            if(t.find(s[itr])!=string::npos){
                map[s[itr]]++;
            }
        }


        while(j<s.size()){
            // if((j==s.size()-1) &&  (j-i+1) == win_size){
            //     break;
            // }

            if(isMapFull(map,tStringMap)){
                if( (j-i+1) < min_global){
                    res=s.substr(i,j-i+1);
                }
                min_global=min(min_global,j-i+1);
                map[s[i]]--;
                i++;
                int it;
                for(it=i;it<=j;it++){
                    if(t.find(s[it])!=string::npos){
                        break;
                    }
                    //do nothing
                }
                i=it;

            }else{
                while(j<s.size() && !isMapFull(map,tStringMap)){
                    j++;
                    if(j>s.size()){
                        break;
                    }
                    if(t.find(s[j])!=string::npos){
                        map[s[j]]++;
                    }
                }
            }
        }
        if(flag){
            return strToUpper(res);
        }
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i=0;i<tokens.size();i++){
            int isNum=0;
            string tok=tokens[i];
            int ele;
            string eleStr="";

            if(tok=="+"|| tok=="-"|| tok=="*" || tok=="/"){
                ele=tok[0];
            }else{
                isNum=1;
                ele=stoi(tok);
            }

            if(isNum){
                stk.push(ele);
            }else{
                //operand
                int op2=stk.top();
                stk.pop();
                int op1=stk.top();
                stk.pop();
                char test=char(ele);
                switch(char(ele)){
                    case('/'):
                        stk.push(op1/op2);
                        break;
                    case('*'):
                        stk.push(op1*op2);
                        break;
                    case('+'):
                        stk.push(op1+op2);
                        break;
                    case('-'):
                        stk.push(op1-op2);
                        break;
                    default:
                        throw "default error\n";
                }
            }

        }
        return stk.top();
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //using monotonic stack approach 
        int n=temperatures.size();
        vector<int> res(n);
        stack<pair<int,int>> stk;

        for(int i=0;i<n;i++){
            int ele=temperatures[i];
            
            if(stk.empty()){
                stk.push(make_pair(ele,i));
            }else{
                if(stk.top().first>=ele){
                    stk.push(make_pair(ele,i));
                }else{
                    while(!stk.empty() && ele>stk.top().first){
                        int pop_ele=stk.top().first;
                        int pop_ele_idx=stk.top().second;
                        stk.pop();
                        res[pop_ele_idx]=i-pop_ele_idx;
                    }
                    stk.push(make_pair(ele,i));
                }
            }
        }
        return res;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //using monotonic stack idea
        stack<pair<int,int>> stk;
        vector<int> mono_vec(nums2.size(),-1);

        vector<int> res(nums1.size(),-1);

        for(int i=0;i<nums2.size();i++){
            int val=nums2[i];
            if(stk.empty()){
                stk.push(make_pair(val,i));
            }else{
                while(!stk.empty() && stk.top().first<val){
                    int ele=stk.top().first;
                    int ele_idx=stk.top().second;
                    stk.pop();

                    mono_vec[ele_idx]=i-ele_idx;
                }
                stk.push(make_pair(val,i));
            }
        }

        for(int i=0;i<nums1.size();i++){
            int nums_ele_idx= distance(nums2.begin(),find(nums2.begin(),nums2.end(),nums1[i]));
            if(mono_vec[nums_ele_idx]>-1){
                res[i]=nums2[nums_ele_idx+mono_vec[nums_ele_idx]]; 
            }
        }

        return res;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res=0;
        
        int n=position.size();
        vector<float> time(n);
        vector<int> dist(n);

        for(int i=0;i<position.size();i++){
            dist[i]=target-position[i];
        }

        for(int i=0;i<n;i++){
            time[i]=dist[i]*1.0/speed[i];
        }

        vector<pair<int,float>> position_time_vec(n);
        for(int i=0;i<n;i++){
            position_time_vec[i]=make_pair(position[i],time[i]);
        }

        sort(position_time_vec.begin(),position_time_vec.end(),[](pair<int,float>p1, pair<int,float> p2){return p1.first>=p2.first;});
        for(int i=0;i<n;i++){
            time[i]=position_time_vec[i].second;
        }

        //check if last two elements are of form arr[n-1]<arr[n-2];
        //for some weird reason writing this direclty throws error in lc not on VSC
        bool flag2=false;
        if(n>=2 && time[n-2]<=time[n-1]){
            flag2=true;
        }

        if(time.size()==1){
            return 1;
        }

        for(int i=0;i<n;){
        bool flag=false;
            while(i<n-1 && time[i]>=time[i+1]){
                i++;
                flag=true;

                // if(i==(n-1) && time[i]<=time[i-1]){
                //     flag2=true;
                // }
            }
            if(flag==true){
                res++;
                flag=false;
            }else{
                i++;
            }
       }  
        if(flag2==false){
            return res;
        }
        return res+1;
    }

    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> res;
        vector<int> temp(1,1);
        res.push_back(temp);

        for(int i=1;i<n;i++){
            int n=i+1;
            vector<int> vec(n);
            for(int j=0;j<n;j++){
                int l= (j==0)?0:res[i-1][j-1];
                int r= (j==(n-1))?0:res[i-1][j];
                vec[j]=l+r;
            }
            res.push_back(vec);
        }
        return res;
    }

    int fib(int n) {
        static vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;

        if(dp[n]!=-1){
            return dp[n];
        }

        if(n>1){
            dp[n]=fib(n-1)+fib(n-2);
        }

        return dp[n];
    }

    ListNode* foo(ListNode* head,int n){
            static int count=0;

        if(head==NULL){
            return head;
        }

        if(n<1){
            return head;
        }

        if(head->next==NULL && n==1){
            return NULL;
        }

        if(head->next==NULL && n>1){
            return head;
        }

        ListNode* right=foo(head->next,n);
        count++;

        if(count==n){
            head->next=head->next->next;
        }
        
        return head;

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return foo(head,n);
    }

   //https://leetcode.com/problems/divisor-game/
    bool foo2(int n){

        if(n==0 || n==1){
            return false;
        }

        if(n==2){
            return true;
        }

        bool ans=false;
        
        for(int i=1;(i<n && n%i==0);i++){
            ans|=foo2(n-i);
        }

        return ans;
    } 


    int foo3(vector<int>& cost, int index){    
        int n=cost.size()-1;
        
        if(index==n-1){
            return cost[index];
        }
        
        if(index==n){
            return cost[n];
        }
        
        long int cst1=foo3(cost,index+1);
        long int cst2=foo3(cost,index+2);
        
        return cost[index]+min(cst1,cst2);
    }


    
    int foo4(vector<int>& cost, int index){
        
        static vector<int> cache(cost.size(),-1);
        
        int n=cost.size()-1;
        
        if(cache[index]!=-1){
            return cache[index];
        }
        
        //base case
        if(index==n || index==n-1){
            return cost[index];
        }
        
        long int cst1=foo4(cost,index+1);
        long int cst2=foo4(cost,index+2);
        cache[index+2]=cst2;
        cache[index+1]=cst1;
        
        cache[index]=cost[index]+min(cst1,cst2);
        
        return cache[index];
        
        
    }


    int fibT(int n) {
    //tabular approach 
    vector<int> dp(n+1,0);
    
    dp[0]=0;
    dp[1]=1;
    
    if(n==0 || n==1){
        return n;
    }
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    return dp[n];
}




    //********* CLASS END **********//
};



void printVec(vector<int> vec){
    for(auto ele:vec){
        cout<<ele<<" ";
    }
}

void printLinkedList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next; 
    }
    cout<<"\n";
}

int countLL(ListNode* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}


bool fooWordBreak(string s,vector<string>& dict,int index){
    
    
}

bool wordBreak(string s, vector<string>& wordDict) {

}

int fooMemo(string s,vector<string>& wordDict,vector<int> dp,int idx){
    int n=s.size();
    
    if(dp[idx]!=-1){
        return dp[idx];
    }
    
    string part="";
    for(int i=idx;i<n;i++){
        bool belong=find(wordDict.begin(),wordDict.end(),part)!=wordDict.end();
        dp[i]=fooMemo(s,wordDict,dp,i+1);
        if(belong==true && dp[i]==1){
            return 1;
        }
        
    }
    
    return dp[idx]=0;
    
}


//main
int main(){
    Solution lc=Solution();
    string s="aa";
    string t="aa";
    vector<string> tkn={"4","13","5","/","+"};
    vector<int> temps={73,74,75,71,69,72,76,73};
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};

    vector<int> position={0,2,4};
    vector<int> speed={4,2,1};

    // cout<<"ans->"<<lc.carFleet(100,position,speed);
    // lc.printCppVersion();
    // vector<int> ans = lc.carFleet(12,nums1,nums2);
    // printVec(ans);
    // cout<<"ans ->"<<lc.evalRPN(tkn);


    ListNode* n1= new ListNode(1);
    ListNode* n2= new ListNode(2);
    // ListNode* n3= new ListNode(3);
    // ListNode* n4= new ListNode(4);
    // ListNode* n5= new ListNode(5);

    n1->next=n2;
    n2->next=NULL;
    // n3->next=n4;
    // n4->next=n5;
    // n5->next=NULL;

    // n1=lc.foo(n1,1);
    // printLinkedList(n1);
    // cout<<"Lenght: "<<countLL(n1)<<"\n";

    // vector<int> cost={1,100,1,1,1,100,1,1,100,1};

    // cout<<"ans:"<<lc.fibT(0);

    // cout<<"ans: "<<min(lc.foo4(cost,0),lc.foo4(cost,1));

    string s="leetcode";
    vector<string> dic={"leet","code"};
    int n=s.size();
    vector<int> dp(n+1,-1);
    cout<<fooMemo(s,dic,dp,0);

}








