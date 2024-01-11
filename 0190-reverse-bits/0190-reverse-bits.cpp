class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        string b_str=b.to_string();
        reverse(b_str.begin(),b_str.end());
        return bitset<32>(b_str).to_ulong();
        
    }
};