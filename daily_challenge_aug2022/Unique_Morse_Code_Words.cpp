class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mp={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        int ans=0;
        for(auto i: words){
            string transform="";
            for(int j=0;j<i.length();j++){
                transform+=mp[i[j]-'a'];
            }
            if(s.find(transform)==s.end()){
                s.insert(transform);
                ans++;
            }
        }
        return ans;
    }
};
