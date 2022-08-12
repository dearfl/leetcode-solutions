/*
In a special ranking system, each voter gives a rank from highest to lowest to
all teams participated in the competition.

The ordering of teams is decided by who received the most position-one votes. If
two or more teams tie in the first position, we consider the second position to
resolve the conflict, if they tie again, we continue this process until the ties
are resolved. If two or more teams are still tied after considering all
positions, we rank them alphabetically based on their team letter.

Given an array of strings votes which is the votes of all voters in the ranking
systems. Sort all teams according to the ranking system described above.

Return a string of all teams sorted by the ranking system.

Example 1:
    Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
    Output: "ACB"
    Explanation: Team A was ranked first place by 5 voters. No other team was
voted as first place so team A is the first team. Team B was ranked second by 2
voters and was ranked third by 3 voters. Team C was ranked second by 3 voters
and was ranked third by 2 voters. As most of the voters ranked C second, team C
is the second team and team B is the third. Example 2: Input: votes =
["WXYZ","XYZW"] Output: "XWYZ" Explanation: X is the winner due to tie-breaking
rule. X has same votes as W for the first position but X has one vote as second
position while W doesn't have any votes as second position. Example 3: Input:
votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"] Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
    Explanation: Only one voter so his votes are used for the ranking.

Constraints:
    1 <= votes.length <= 1000
    1 <= votes[i].length <= 26
    votes[i].length == votes[j].length for 0 <= i, j < votes.length.
    votes[i][j] is an English uppercase letter.
    All characters of votes[i] are unique.
    All the characters that occur in votes[0] also occur in votes[j] where 1 <=
j < votes.length.
*/

#include <bits/stdc++.h>
using namespace std;

// 稍微普适一点的做法
class Solution {
public:
  string rankTeams(vector<string> &votes) {
    int n = votes.back().length();
    unordered_map<char, unordered_map<int, int>> um;
    for (auto v : votes) {
      for (int i = 0; i < n; i++) {
        um[v[i]][i]++;
      }
    }
    vector<char> vec(votes.back().begin(), votes.back().end());
    sort(vec.begin(), vec.end(), [&](auto c1, auto c2) {
      for (int i = 0; i < n; i++) {
        if (um[c1][i] == um[c2][i]) {
          continue;
        }
        return um[c1][i] > um[c2][i];
      }
      return c1 < c2;
    });
    return string(vec.begin(), vec.end());
  }
};

class SimplerSolution {
public:
  string rankTeams(vector<string> &votes) {
    vector<vector<int>> cnt(26, vector<int>(26));
    for (auto v : votes) {
      for (int i = 0; i < v.length(); i++) {
        cnt[v[i] - 'A'][i]++;
      }
    }
    string res = votes.back();
    sort(res.begin(), res.end(), [&](auto c1, auto c2) {
      return cnt[c1 - 'A'] > cnt[c2 - 'A'] ||
             cnt[c1 - 'A'] == cnt[c2 - 'A'] && c1 < c2;
    });
    return res;
  }
};

class TrickierSolution {
public:
  string rankTeams(vector<string> &votes) {
    vector<vector<int>> cnt(26, vector<int>(27));
    // 加入自身，消除排序时的特殊判断
    for (char c : votes.back()) {
      cnt[c - 'A'][26] = c;
    }
    for (auto &vote : votes) {
      for (int i = 0; i < vote.length(); i++) {
        --cnt[vote[i] - 'A'][i];
      }
    }
    // 使用vector统计，可以直接sort vector
    sort(cnt.begin(), cnt.end());
    string res;
    for (int i = 0; i < votes.back().length(); i++) {
      res += cnt[i][26];
    }
    return res;
  }
};
