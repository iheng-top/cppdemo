/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

/*
abcabcaa

*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

/*
abcabcdabc

*/

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() ==  0) {
            return 0;
        }
        int max = 1;
        vector<char> v;
        for (int i = 0; i < s.length() - max; ++i) {
            int start = i;
            int p = start + 1;
            int cnt = 0;
            v.push_back(s[start]);
            while (p < s.length() && find(begin(v), end(v), s[p]) == end(v)) {
                v.push_back(s[p]);
                ++cnt;
                ++p;
            }
            if (max < cnt + 1) {
                max = cnt + 1;
            }
            v.clear();
        }
        return max;
    }
};
// @lc code=end


int main() 
{
    Solution s;
    cout << s.lengthOfLongestSubstring("helloworld") << endl;
    return 0;
}
