class comp{
    public:
        string order="";
        bool operator ()(char a,char b){
            int aIdx=order.find(a);
            int bIdx=order.find(b);
            if(aIdx<bIdx){
                return true;
            }
            return false;
        }
};

class Solution {
public:
    comp cmp;
    string customSortString(string order, string s) {
        cmp.order=order;
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};