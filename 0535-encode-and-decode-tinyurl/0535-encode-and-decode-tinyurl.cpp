class Solution {
public:
    unordered_map<string,int> encodeDB;
    unordered_map<int,string> decodeDB;
    int count=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeDB.count(longUrl)==0){
            encodeDB[longUrl]=(++count);
            decodeDB[count]=longUrl;
            return to_string(count);
        }
        return "";

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return (decodeDB[stoi(shortUrl)]); 
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));