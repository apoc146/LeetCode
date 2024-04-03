class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans="";
        for(auto& str:strs){
            ans+= ( to_string(str.size())+"#"+str);
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        stringstream iss(s);
        string token;
        vector<string> ans;
        int idx=0;
        while(idx<s.size()){
            int pos_of_delimit=s.find("#",idx);
            int str_len=stoi(s.substr(idx,pos_of_delimit-idx));
            ans.push_back(s.substr(pos_of_delimit+1,str_len));
            idx=pos_of_delimit+1+str_len;
        }
        return ans;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));