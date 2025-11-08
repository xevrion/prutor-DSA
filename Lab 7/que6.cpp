class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int wordLength = words[0].length();
        vector<int> result;
        unordered_map<string, int> wordCount;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<wordLength; j++){
                wordCount[words[i]]++;
            }
        }

        int i = 0, j = 0;
        while(i<n-wordLength*m+1){
            unordered_map<string, int> seenWords;
            j = i;
            bool check = true;
            while(j<i+wordLength*m){
                string word = s.substr(j, wordLength);
                if(wordCount.find(word) == wordCount.end()){
                    check = false;
                    break;
                } else {
                    seenWords[word]++;
                    if(seenWords[word] > wordCount[word]){
                        check = false;
                        break;
                    }
                }
                j += wordLength;
            }
            if(check){
                result.push_back(i);
            }
            i++;
            // for(j = i; j<i+wordLength*m; j++){
            //     if(wordCount.find(s[j]) == wordCount.end()){
            //         check = false;
            //         break;
            //     } else if(wordCount.find(s[j]) != wordCount.end()){
            //         seenWords[s[j]]++;
            //         if(seenWords[s[j]] > wordCount[s[j]]){
            //             check = false;
            //             break;
            //         }
            //     } else {

            //     }
                
            // }
            // for(auto it : seenWords){
            //     if(it.second != wordCount[it.first]){
            //         check = false;
            //         break;
            //     }
            // }
            // if(check){
            //     result.push_back(i);
            // }

            // i = j+1;

        }
        return result;
    }
};