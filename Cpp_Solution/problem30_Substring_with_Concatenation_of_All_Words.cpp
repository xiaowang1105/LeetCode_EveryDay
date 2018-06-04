/*************************************************************************
	> File Name: problem30_Substring_with_Concatenation_of_All_Words.cpp
	> Author: Xiao Wang
	> Mail: wx961105@outlook.com
	> Created Time: Mon 04 Jun 2018 08:45:21 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), num = words.size();
        vector<int> ans;
        if (n <= 0 || num <= 0) return ans;
        int len = words[0].size();
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;

        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + len * j, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if (j == num) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    Solution solu;
    vector<int> indexes = solu.findSubstring(s, words);
    cout << indexes[0] << ", " << indexes[1] << endl;
}
