/*************************************************************************
	> File Name: problem5_Longest_Palindromic_Substring_Dynamic_Programming.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Apr 2018 07:50:01 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string pre_process(string s){
        int n = s.length();
        string new_s(2 * n + 1, '#');
        for(int i = 0; i < n; i++) new_s[2 * i + 1] = s[i];
        return new_s;
    }

    string post_process(string s){
        int n = s.length();
        char* str = new char(n);
        char* temp = str;

        for (int i = 0; i < n; i++){
            if(s[i] != '#') *temp = s[i], temp++;
        }

        *temp = '\0';
        return str;
    }

    string longestPalindrome(string s) {
        string new_s = pre_process(s);
        int n = new_s.length(), R = 0, C = 0;
        int P[n];

        for (int i = 0; i < n; i++){
            int i_mirror = 2 * C - i;

            if (R > i && i_mirror >= 0) P[i] = min(P[i_mirror], R - i);
            else P[i] = 0;

            while(new_s[i + P[i] + 1] == new_s[i - P[i] - 1] && i - P[i] - 1 >=0 && i + P[i] + 1 < n) 
                P[i]++;

            if (i + P[i] > R) C = i, R = i + P[i];
        }

        int max_len = 0, center = 0;

        for (int i = 0; i < n; i++) {
            if (P[i] > max_len) max_len = P[i], center = i;
        }

        string result = new_s.substr(center - max_len, 2 * max_len + 1);
        return post_process(result);
    }
};

int main() {
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    Solution solu;
    string ans = solu.longestPalindrome(s);
    cout << "original string is: " << s << endl;
    cout << "output sub_string is: " << ans << endl;
}


