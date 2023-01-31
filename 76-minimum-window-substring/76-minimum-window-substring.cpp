#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
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

    //check if t's all elements are present in the s's substr being considered. map contains count of t's  char present in s btw i&j

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

        //init map to track count of chars in t.
        for(int i=0;i<t.size();i++){
            map[t[i]]=0;
        }

        for(int itr=i;itr<=j;itr++){
            if(t.find(s[itr])!=string::npos){
                map[s[itr]]++;
            }
        }


        while(j<s.size()){
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
};


int main(){
    Solution lc=Solution();
    string s="aa";
    string t="aa";
    // lc.printCppVersion();
    cout<<"ans ->"<<lc.minWindow(s,t);
    
}