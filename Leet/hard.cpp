1) Given two array.find median of the two sorted arrays. [1, 3][2] = [1, 2, 3] ans = 2, again[1, 2], [3, 4] = 2.5

class Solution {
  double Fun(vector < int > v1, vector < int > v2) {
    double ans;
    int x = v1.size(), y = v2.size();
    int low = 0, high = x;
    while (low <= high) {
      int first = (low + high) / 2;
      int second = (x + y + 1) / 2 - first;

      int firstLeft = (first == 0) ? INT_MIN : v1[first - 1];
      int firstRight = (first == x) ? INT_MAX : v1[first];

      int secondLeft = (second == 0) ? INT_MIN : v2[second - 1];
      int secondRight = (second == y) ? INT_MAX : v2[second];

      if (firstLeft <= secondRight && secondLeft <= firstRight) {
        if ((x + y) & 1) ans = (double) max(firstLeft, secondLeft);
        else ans = ((double) max(firstLeft, secondLeft) + min(firstRight, secondRight)) / 2;
        break;
      } else if (firstLeft > secondRight) high = first - 1;
      else low = first + 1;
    }
    return ans;
  }

  public:
    double findMedianSortedArrays(vector < int > & v1, vector < int > & v2) {
      if (v1.size() <= v2.size()) return Fun(v1, v2);
      else return Fun(v2, v1);
    }
};

2) input string(s) and a pattern(p). '.' Matches any single character.​​​​ '*' Matches zero or more of the preceding element "aab", p = "c*a*b" => true c can be repeated 0 times, a can be repeated 1 time.Therefore, it matches "aab".
class Solution {
  public:
    bool isMatch(string text, string pattern) {
      int dp[25][35] = {};
      dp[0][0] = 1;
      for (int i = 1; i <= pattern.size(); i++) {
        if (pattern[i - 1] == '*') dp[0][i] = dp[0][i - 2];
      }

      for (int i = 1; i <= text.size(); i++) {
        for (int j = 1; j <= pattern.size(); j++) {
          if (pattern[j - 1] == '.' || text[i - 1] == pattern[j - 1]) dp[i][j] = dp[i - 1][j - 1];
          else if (pattern[j - 1] == '*') {
            dp[i][j] = dp[i][j - 2];
            if (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) {
              dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
          } else dp[i][j] = 0;
        }
      }
      return dp[text.size()][pattern.size()];
    }
};

3) Longest Valid Parentheses.Input: s = ")()())" Output: 4, The longest valid parentheses substring is "()()".
class Solution {
  public:
    int longestValidParentheses(string s) {
      stack < int > Stk;
      Stk.push(-1);
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') Stk.push(i);
        else {
          Stk.pop();
          if (Stk.empty()) {
            Stk.push(i);
          } else {
            ans = max(ans, i - Stk.top());
          }
        }
      }
      return ans;
    }
};
4)Sudoku lover
class Solution {

  bool valid(vector < vector < char >> & vec, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
      if (vec[row][i] == num) return false;
      if (vec[i][col] == num) return false;
      if (vec[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == num) return false;
    }
    return true;
  }

  bool Fun(vector < vector < char >> & vec) {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (vec[row][col] == '.') {
          for (char num = '1'; num <= '9'; num++) {
            if (valid(vec, row, col, num)) {
              vec[row][col] = num;
              if (Fun(vec)) return true;
              vec[row][col] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  public:
    void solveSudoku(vector < vector < char >> & vec) {
      Fun(vec);
    }
};

5) First Missing Positive from an unsorted array. [3, 4, -1, 1] = 2
class Solution {
  public:
    int firstMissingPositive(vector < int > & v) {
      int n = v.size();
      int ok = 1;
      for (int i = 0; i < n; i++) {
        if (v[i] == 1) ok = 0;
        if (v[i] > n || v[i] <= 0) v[i] = 1;
      }

      if (ok) return 1;

      for (int i = 0; i < n; i++) {
        int idx = abs(v[i]) - 1;
        if (v[idx] > 0) v[idx] = -1 * v[idx];
      }

      for (int i = 0; i < n; i++) {
        if (v[i] > 0) return i + 1;
      }

      return n + 1;
    }
};
6) Trapping Rain Water, height of the piller = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] Output: 6
class Solution {
  public:
    int trap(vector < int > & v1) {
      int n = v1.size(), ans = 0, mx = 0;
      vector < int > v2(n, 0);

      for (int i = 0; i < n; i++) {
        mx = max(mx, v1[i]); // max from left
        v2[i] = mx;
      }
      mx = 0;
      for (int i = n - 1; i >= 0; i--) {
        mx = max(mx, v1[i]); // max from right
        v2[i] = min(mx, v2[i]); // took minimum btwn left and right
      }
      for (int i = 0; i < n; i++) ans += (v2[i] - v1[i]);
      return ans;
    }
};

7) Permutation Sequence.Given n and k,return the kth permutation sequence.
class Solution {
  public:
    string getPermutation(int n, int k) {
      string s = "";
      for (char ch = '1'; n; ch++, n--) s += ch;

      do {
        k--;
        if (k == 0) break;
      }
      while (next_permutation(s.begin(), s.end()));
      return s;
    }
};
8) Minimum Window Substring.minimum window in s which will contain all the characters in t. Input: s = "ADOBECODEBANC", t = "ABC" Output: "BANC"
class Solution {
  public:
    string minWindow(string s, string t) {
      vector < int > map(128, 0);
      for (auto c: t) map[c]++;
      int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
      while (end < s.size()) {
        if (map[s[end++]]--> 0) counter--; //in t
        while (counter == 0) //valid
        {
          if (end - begin < d) d = end - (head = begin);
          if (map[s[begin++]]++ == 0) counter++; //make it invalid
        }
      }
      return d == INT_MAX ? "" : s.substr(head, d);
    }
};

9) largest rectangle containing only 1 's and return its area.[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]] = 6
class Solution {

  int Fun(vector < int > & v) {
    int n = v.size();
    vector < int > left(n), right(n);
    for (int i = 0; i < n; i++) {
      left[i] = i + 1;
      right[i] = n - i;
    }
    stack < int > Stk1, Stk2;
    for (int i = 0; i < n; i++) {
      while (!Stk1.empty() && v[Stk1.top()] > v[i]) Stk1.pop();
      if (!Stk1.empty()) left[i] = i - Stk1.top();
      Stk1.push(i);
    }

    for (int i = 0; i < n; i++) {
      while (!Stk2.empty() && v[Stk2.top()] > v[i]) {
        right[Stk2.top()] = i - Stk2.top();
        Stk2.pop();
      }
      Stk2.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, (left[i] + right[i] - 1) * v[i]);
    }
    return ans;
  }

  public:
    int maximalRectangle(vector < vector < char >> & vec) {
      if (vec.empty()) return 0;
      int row = vec.size(), col = vec[0].size();
      int arr[row + 5][col + 5];
      memset(arr, 0, sizeof arr);
      for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) arr[i + 1][j + 1] = vec[i][j] - '0';

      for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
          if (arr[i][j]) arr[i][j] += arr[i - 1][j];
        }
      }
      int ans = 0;
      for (int i = 1; i <= row; i++) {
        vector < int > v;
        for (int j = 1; j <= col; j++) {
          v.push_back(arr[i][j]);
        }
        ans = max(ans, Fun(v));
      }
      return ans;
    }
};

10) Word Ladder.beginWord = "hit", endWord = "cog", wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
Output: 5 Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog ", which is 5 words long.
class Solution {
  int bfs(string src, string des, set < string > & st) {
    queue < pair < string, int > > Q;
    Q.push({src,1});

    while (!Q.empty()) {
      pair < string, int > temp = Q.front();
      Q.pop();
      string s = temp.first;
      if (s == des) return temp.second;

      for (int j = 0; j < s.size(); j++) {
        char ch1 = s[j];
        for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
          if (ch1 != ch2) {
            s[j] = ch2;
            if (st.count(s)) {
              Q.push({s,temp.second + 1});
              st.erase(s);
            }
            s[j] = ch1;
          }
        }
      }
    }
    return 0;
  }

  public:
    int ladderLength(string s, string d, vector < string > & ans) {
      set < string > st(ans.begin(), ans.end());
      if (!st.count(d)) return 0;

      return bfs(s, d, st);
    }
};

11) Same like Word Ladder, But have to print all possible combination.
"hit" -> "hot" -> "dot" -> "dog" -> "cog", "hit" -> "hot" -> "lot" -> "log" -> "cog"
class Solution {
  map < string, int > Mp, visited;
  map < string, set < string > > adj;
  void bfs(string src, string des, set < string > & st) {
    queue < string > Q;
    Q.push(src);
    visited[src] = 1;
    while (!Q.empty()) {
      string temp = Q.front();
      Q.pop();
      string s = temp;

      for (int i = 0; i < s.size(); i++) {
        char ch1 = s[i];
        for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
          if (ch1 == ch2) continue;
          s[i] = ch2;
          if (st.count(s)) {
            if (!visited[s]) {
              visited[s] = visited[temp] + 1;
              Q.push(s);
              adj[temp].insert(s);
            }
            if (1 + visited[temp] == visited[s]) {
              adj[temp].insert(s);
            }
          }
          s[i] = ch1;
        }
      }
    }
  }

  void Fun(string src, string des, vector < vector < string >> & vec, vector < string > & v) {
    v.push_back(src);
    if (src == des) {
      vec.push_back(v);
      v.pop_back();
      return;
    }

    for (auto s: adj[src]) {
      Fun(s, des, vec, v);
    }
    v.pop_back();
  }

  public:
    vector < vector < string >> findLadders(string src, string des, vector < string > & ans) {
      vector < vector < string >> vec;
      vector < string > v;
      set < string > st(ans.begin(), ans.end());
      if (!st.count(des)) return vec;
      st.insert(des);
      bfs(src, des, st);

      Fun(src, des, vec, v);
      return vec;
    }
};

12) Longest Consecutive Sequence. [100, 4, 200, 1, 3, 2] => 4, seq is[1, 2, 3, 4]
class Solution {
  public:
    int longestConsecutive(vector < int > & v) {
      int ans = 0;
      unordered_map < int, int > Mp;
      for (int i = 0; i < v.size(); i++) {
        Mp[v[i]] = 1;
      }
      for (int i = 0; i < v.size(); i++) {
        if (Mp[v[i] - 1]) continue;
        else {
          int cnt = 0, x = v[i];
          while (Mp[x]) cnt++, x++;
          ans = max(ans, cnt);
        }
      }
      return ans;
    }
};
13) Palindrome Partitioning II('I' in 30 days)."aab" => 1, he palindrome partitioning["aa", "b"] could be produced using 1 cut.

class Solution {
  public:
    int minCut(string s) {
      int n = s.size();
      int palindrome[2005][2005] = {};

      for (int i = 0; i < n; i++) {
        palindrome[i][i] = 1;
      }

      for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) palindrome[i][i + 1] = 1;
      }

      for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
          int j = i + len - 1;
          if (s[i] == s[j] && palindrome[i + 1][j - 1]) palindrome[i][j] = 1;
        }
      }

      int arr[2005];
      for (int i = 0; i < n; i++) arr[i] = INT_MAX;

      for (int i = 0; i < n; i++) {
        if (palindrome[0][i]) arr[i] = 0;
        else {
          for (int j = 0; j < i; j++) {
            if (palindrome[j + 1][i]) {
              arr[i] = min(arr[i], 1 + arr[j]);
            }
          }
        }
      }

      return arr[n - 1];

    }
};

14) Find Minimum in Rotated Sorted Array I and II
I(No Duplicate)
class Solution {
  int Fun(vector < int > & v) {
    int n = v.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int pre = (mid - 1 + n) % n, next = (mid + 1) % n;
      if (v[pre] >= v[mid] && v[mid] <= v[next]) {
        return v[mid];
      } else if (v[mid] <= v[high]) high = mid - 1;
      else low = mid + 1;
    }
    return v[low];
  }
  public:
    int findMin(vector < int > & v) {
      return Fun(v);
    }
};
II(Duplicate)
class Solution {
  public:
    int findMin(vector < int > & nums) {
      int l = 0, r = nums.size() - 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] > nums[r]) {
          l = m + 1;
        } else if (nums[m] < nums[r]) {
          r = m;
        } else {
          r--;
        }
      }
      return nums[l];
    }
};

15) Word Search I and II
  (I) board = [["A", "B", "C", "E"],["S", "F", "C", "S"],["A", "D", "E", "E"]], word = "ABCCED"
return true or false
class Solution {
  int visited[205][205];
  int ok = 0, row, col;
  bool Fun(int pos, int i, int j, vector < vector < char >> & arr, string s) {
    if (pos == s.size() - 1) return true;

    visited[i][j] = 1;
    if (i < row - 1 && !visited[i + 1][j] && arr[i + 1][j] == s[pos + 1] && Fun(pos + 1, i + 1, j, arr, s)) return true;
    if (i > 0 && !visited[i - 1][j] && arr[i - 1][j] == s[pos + 1] && Fun(pos + 1, i - 1, j, arr, s)) return true;
    if (j < col - 1 && !visited[i][j + 1] && arr[i][j + 1] == s[pos + 1] && Fun(pos + 1, i, j + 1, arr, s)) return true;
    if (j > 0 && !visited[i][j - 1] && arr[i][j - 1] == s[pos + 1] && Fun(pos + 1, i, j - 1, arr, s)) return true;
    visited[i][j] = 0;
    return false;
  }
  public:
    bool exist(vector < vector < char >> & arr, string s) {
      row = arr.size(), col = arr[0].size();
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          if (arr[i][j] == s[0] && !visited[i][j]) {
            if (Fun(0, i, j, arr, s)) return true;
          }
        }
      }
      return false;
    }
};

(II) Input: board = [["o", "a", "a", "n"],["e", "t", "a", "e"],["i", "h", "k", "r"],["i", "f", "l", "v"]], words = ["oath", "pea", "eat", "rain"] Output: ["eat", "oath"] return all words on the board.
struct node {
  bool endmark;
  node * next[27];

  node() {
    endmark = false;
    for (int i = 0; i < 26; i++) {
      next[i] = nullptr;
    }
  }
};

class Solution {
  void Insert(node * root, string s) {
    node * curr = root;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int id = s[i] - 'a';
      if (curr -> next[id] == nullptr) {
        curr -> next[id] = new node();
      }
      curr = curr -> next[id];
    }
    curr -> endmark = true;
  }

  int row, col;
  void dfs(vector < vector < char >> & arr, int i, int j, set < string > & st, node * root, string s) {
    if (i < 0 || j < 0 || i == row || j == col || arr[i][j] == '#') return;

    char ch = arr[i][j];
    arr[i][j] = '#';

    if (root -> next[ch - 'a']) {
      root = root -> next[ch - 'a'];
      string str = s + ch;
      if (root -> endmark) st.insert(str);

      dfs(arr, i - 1, j, st, root, str);
      dfs(arr, i, j - 1, st, root, str);
      dfs(arr, i + 1, j, st, root, str);
      dfs(arr, i, j + 1, st, root, str);
    }
    arr[i][j] = ch;
  }

  public:
    vector < string > findWords(vector < vector < char >> & arr, vector < string > & v) {
      if (v.empty()) return {};
      node * root = new node();
      for (auto s: v) Insert(root, s);

      set < string > st;
      row = arr.size(), col = arr[0].size();
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          dfs(arr, i, j, st, root, "");
        }
      }
      vector < string > ans(st.begin(), st.end());
      return ans;
    }
};

16) The Skyline Problem, Input: buildings = [[2, 9, 10],[3, 7, 15],[5, 12, 12],[15, 20, 10],[19, 24, 8]
Output: [[2, 10],[3, 15],[7, 12],[12, 0],[15, 10],[20, 8],[24, 0]]
bool cmp(pair < pair < int, int > , int > A, pair < pair < int, int > , int > B) {
  if (A.first.first < B.first.first) return true;
  else if (A.first.first == B.first.first && A.second < B.second) return true;
  else if (A.first.first == B.first.first && A.second == B.second) {
    if (A.second == 1 && A.first.second > B.first.second) return true;
    else if (A.second == 2 && A.first.second < B.first.second) return true;
  }
  return false;
}

class Solution {
  public:
    vector < vector < int >> getSkyline(vector < vector < int >> & buildings) {
      vector < pair < pair < int, int > , int > > vec;
      vector < vector < int >> ans;
      for (int i = 0; i < buildings.size(); i++) {
        vec.push_back({{buildings[i][0], buildings[i][2]},1});
        vec.push_back({{buildings[i][1], buildings[i][2]},2});
	}
      sort(vec.begin(), vec.end(), cmp);
      //for( auto x : vec ) cout << x.first.first << " " << x.first.second << " " << x.second << endl ;
      multiset < int > S {0};
      int mx = 0;
      for (auto x: vec) {
        if (x.second == 1) {
          S.insert(x.first.second);
          int val = * prev(S.end());
          if (val != mx) {
            ans.push_back({x.first.first, val});
            mx = val;
          }
        } else {
          auto it = S.lower_bound(x.first.second);
          S.erase(it);
          int val = * prev(S.end());
          if (val != mx) {ans.push_back({x.first.first,val});
            mx = val;
          }
        }
      }

      return ans;
    }
};

17) Sliding Window Maximum, Each time the sliding window moves right by one position.
Return the max sliding window.Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3 Output: [3, 3, 5, 5, 6, 7]

class Solution {
  public:
    vector < int > maxSlidingWindow(vector < int > & v, int k) {
      multiset < int > S;
      vector < int > ans;
      for (int i = 0; i < k; i++) {
        S.insert(v[i]);
      }
      ans.push_back( * prev(S.end()));

      for (int i = k; i < v.size(); i++) {
        S.insert(v[i]);
        auto it = S.lower_bound(v[i - k]);
        S.erase(it);
        ans.push_back( * prev(S.end()));
      }

      return ans;
    }
};

18) Find Median from Data Stream.#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template < typename T > using orderset = tree < T, null_type, less < T > , rb_tree_tag, tree_order_statistics_node_update > ;

class MedianFinder {
  public:
     orderset < pair < int, int > > os;
     map < int, int > Mp;
     int idx = 0;
  MedianFinder() {

  }

  void addNum(int n) {
    os.insert({n,idx});
    idx++;
  }

  double findMedian() {
    double ans = 0;
    int siz = os.size();
    if (siz & 1) {
      ans = ( * os.find_by_order(siz / 2)).first;
    } else {
      ans += ( * os.find_by_order((siz / 2) - 1)).first;
      ans += ( * os.find_by_order(siz / 2)).first;
      ans /= 2.0;
    }
    return ans;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

19) Burst Balloons.Input: nums = [3, 1, 5, 8] Output: 167 Explanation: nums = [3, 1, 5, 8]--> [3, 5, 8]--> [3, 8]--> [8]--> [] coins = 3 * 1 * 5 + 3 * 5 * 8 + 1 * 3 * 8 + 1 * 8 * 1 = 167
class Solution {
  public:
    int maxCoins(vector < int > & nums) {
      vector < int > v;
      v.push_back(1);
      for (auto x: nums) v.push_back(x);
      v.push_back(1);

      int n = v.size();
      int dp[n][n];
      memset(dp, 0, sizeof dp);

      for (int k = 1; k < n; k++) {
        for (int left = 0; left < n - k; left++) {
          int right = left + k;
          for (int i = left + 1; i < right; i++) {
            dp[left][right] = max(dp[left][right], dp[left][i] + v[left] * v[i] * v[right] + dp[i][right]);
          }
        }
      }
      return dp[0][n - 1];
    }
};
20) Count of Smaller Numbers After Self.Input: nums = [5, 2, 6, 1] Output: [2, 1, 1, 0]#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template < typename T > using orderset = tree < T, null_type, less < T > , rb_tree_tag, tree_order_statistics_node_update > ;

class Solution {
  public:
    vector < int > countSmaller(vector < int > & v) {
      orderset < pair < int, int > > os;
      map < int, int > Mp;
      for (int i = v.size() - 1; i >= 0; i--) {
        Mp[v[i]] = i + 1;
        os.insert({v[i],Mp[v[i]]});
        int idx = os.order_of_key({v[i],Mp[v[i]]});
        v[i] = idx;
      }
      return v;
    }
};
21) Longest Increasing Path in a Matrix.Input: matrix = [[9, 9, 4],[6, 6, 8],[2, 1, 1]] Output: 4 Explanation: The longest increasing path is[1, 2, 6, 9].
class Solution {
  int row, col, ans = 1;
  int Fun(vector < vector < int >> & arr, vector < vector < int >> & dp, int i, int j) {
    if (dp[i][j]) return dp[i][j];
    int r1 = 1, r2 = 1, r3 = 1, r4 = 1;
    if (i < row - 1 && arr[i][j] > arr[i + 1][j]) r1 = 1 + Fun(arr, dp, i + 1, j);
    if (i > 0 && arr[i][j] > arr[i - 1][j]) r2 = 1 + Fun(arr, dp, i - 1, j);
    if (j < col - 1 && arr[i][j] > arr[i][j + 1]) r3 = 1 + Fun(arr, dp, i, j + 1);
    if (j > 0 && arr[i][j] > arr[i][j - 1]) r4 = 1 + Fun(arr, dp, i, j - 1);
    return dp[i][j] = max({r1,r2,r3,r4});
  }

  public:
    int longestIncreasingPath(vector < vector < int >> & arr) {
      if (arr.empty()) return 0;
      row = arr.size(), col = arr[0].size();
      vector < vector < int > > dp(row, vector < int > (col, 0));

      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          ans = max(ans, Fun(arr, dp, i, j));
        }
      }
      return ans;
    }
};
22) Reverse Pairs.Given an array nums, we call(i, j) an important reverse pair
if i < j and nums[i] > 2 * nums[j].Input: [1, 3, 2, 3, 1] Output: 2

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template < typename T > using orderset = tree < T, null_type, less < T > , rb_tree_tag, tree_order_statistics_node_update > ;

class Solution {
  public:
    int reversePairs(vector < int > & v) {
      int ans = 0;
      map < long, long > Mp;
      orderset < pair < long, long > > S;
      for (int i = 0; i < v.size(); i++) {
        int idx = S.order_of_key({2 LL * v[i],Mp[2 LL * v[i]] + 1});
        ans += (int) S.size() - idx;
        Mp[v[i]]++;
        S.insert({v[i],Mp[v[i]]});
      }
      return ans;
    }
};
or
class Solution {
  void Merge(vector < int > & v, int low, int mid, int high, int & sum) {
    for (int i = mid + 1; i <= high; i++) {
      int pos = upper_bound(v.begin() + low, v.begin() + mid + 1, 2 LL * v[i]) - v.begin();
      sum += ((mid + 1) - pos);
    }

    vector < int > temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
      if (v[left] <= v[right]) temp.push_back(v[left++]);
      else temp.push_back(v[right++]);
    }
    while (left <= mid) temp.push_back(v[left++]);
    while (right <= high) temp.push_back(v[right++]);
    for (int i = 0; i < temp.size(); i++) {
      v[low++] = temp[i];
    }
  }

  void mergesort(vector < int > & v, int low, int high, int & sum) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergesort(v, low, mid, sum);
    mergesort(v, mid + 1, high, sum);
    Merge(v, low, mid, high, sum);
  }

  public:
    int reversePairs(vector < int > & v) {
      int sum = 0;
      mergesort(v, 0, v.size() - 1, sum);
      return sum;
    }
};
23) Unique Path(I, II, III)

(I) m x n grid, (A robot is located at the top - left corner, The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).How many possible unique paths are there ? m = 3, n = 7 => 28 class Solution {

    int Fun(int i, int j, int row, int col, vector < vector < int >> & dp) {
      if (i == row || j == col) return 0;
      if (i == row - 1 && j == col - 1) return 1;
      if (dp[i][j] != -1) return dp[i][j];
      return dp[i][j] = Fun(i + 1, j, row, col, dp) + Fun(i, j + 1, row, col, dp);
    }
    public:
      int uniquePaths(int m, int n) {
        vector < vector < int > > dp(m, vector < int > (n, -1));
        return Fun(0, 0, m, n, dp);
      }
  };
  (II) Input : obstacleGrid = [[0, 0, 0],[0, 1, 0],[0, 0, 0]] Output: 2 
class Solution {
    int row, col;
    int dp[105][105];
    int Fun(int i, int j, vector < vector < int >> & arr) {
      if (i == row || j == col) return 0;
      if (arr[i][j]) return 0;
      if (i == row - 1 && j == col - 1) return 1;
      if (dp[i][j] != -1) return dp[i][j];
      return dp[i][j] = Fun(i + 1, j, arr) + Fun(i, j + 1, arr);
    }
    public:
      int uniquePathsWithObstacles(vector < vector < int >> & arr) {
        row = arr.size(), col = arr[0].size();
        memset(dp, -1, sizeof dp);
        return Fun(0, 0, arr);
      }
  };

  (III) On a 2 - dimensional grid, there are 4 types of squares: 1, 2, 0, -1, Input: [[1, 0, 0, 0],[0, 0, 0, 0],[0, 0, 2, -1]] Output: 2 
class Solution {
    int row, col, cnt = 1, ans = 0;
    void Fun(vector < vector < int >> & arr, int i, int j) {
      if (i < 0 || i >= row || j < 0 || j >= col || arr[i][j] < 0) return;
      if (arr[i][j] == 2) {
        if (cnt == 0) ans++;
        return;
      }

      cnt--;
      arr[i][j] = -2;
      Fun(arr, i + 1, j);
      Fun(arr, i - 1, j);
      Fun(arr, i, j + 1);
      Fun(arr, i, j - 1);
      arr[i][j] = 0;
      cnt++;
    }

    public:
      int uniquePathsIII(vector < vector < int >> & arr) {
        row = arr.size(), col = arr[0].size();
        int x, y;
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (arr[i][j] == 1) x = i, y = j;
            else if (arr[i][j] == 0) cnt++;
          }
        }
        Fun(arr, x, y);
        return ans;
      }
  }; 
24) Minimum Insertion Steps to Make a String Palindrome.Input: s = "mbadm"Output: 2 Explanation: String can be "mbdadbm"or "mdbabdm".
class Solution {
  public:
    int minInsertions(string s1) {
      string s2 = s1;
      int n = s1.size();
      reverse(s2.begin(), s2.end());
      int dp[n + 5][n + 5];
      memset(dp, 0, sizeof dp);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
      return n - dp[n][n];
    }
};
25) Minimum Cost to Cut a Stick.Input: n = 7, cuts = [1, 3, 4, 5] Output: 16
class Solution {
  int Fun(vector < vector < int > > & dp, vector < int > & v, int left, int right) {
    if (right - left <= 1) return 0;
    if (!dp[left][right]) {
      dp[left][right] = INT_MAX;
      for (int k = left + 1; k < right; k++) {
        dp[left][right] = min(dp[left][right], v[right] - v[left] + Fun(dp, v, left, k) + Fun(dp, v, k, right));
      }
    }
    return dp[left][right];
  }
  public:
    int minCost(int n, vector < int > & v) {
      v.push_back(0);
      v.push_back(n);
      sort(v.begin(), v.end());
      vector < vector < int > > dp(105, vector < int > (105, 0));

      return Fun(dp, v, 0, v.size() - 1);
    }
};
26) Best time to buy and Sell Product( I, II, II )
(I) One transaction, Input: prices = [7,1,5,3,6,4] Output: 5,  Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
class Solution {
  public:
    int maxProfit(vector < int > & v) {
      int ans = 0, val = 1e6;
      for (int i = 0; i < v.size(); i++) {
        val = min(val, v[i]);
        ans = max(ans, v[i] - val);
      }
      return ans;
    }
};
(II) As many transaction as you can, Input: prices = [7,1,5,3,6,4] Output: 7,  Buy day 2, sell 3 ( 5-1 = 4 ) + Buy day 4, sell 5 ( 6-1 = 3 )
class Solution {
  public:
    int maxProfit(vector < int > & v) {
      int sum = 0;
      for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) sum += v[i] - v[i - 1];
      }
      return sum;
    }
};
(III) at most two transactions.Input: prices = [3,3,5,0,0,3,1,4] Output: 6, Buy day 4, sell 6 ( 3-0 = 3 ) + Buy day 7, sell 8 ( 4-1 = 3 )
class Solution {
  public:
    int maxProfit(vector < int > & prices) {
      int buy1 = INT_MAX, buy2 = INT_MAX;
      int sell1 = 0, sell2 = 0;
      for (int i = 0; i < prices.size(); i++) {
        buy1 = min(buy1, prices[i]);
        sell1 = max(sell1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - sell1);
        sell2 = max(sell2, prices[i] - buy2);
      }
      return sell2;
    }
};
27) Frog Jump, Input: stones = [0,1,3,5,6,8,12,17] Output: true
class Solution {
    bool dp [2005][2005];
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        dp[0][1] = true;
  
        for(int i = 1; i < N; i++){
            for(int j = 0; j < i; j++){
                int diff = stones[i] - stones[j];
                if(diff < 0 || diff > N || !dp[j][diff]) continue;
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
                if(i == N - 1) return true;
            }
        }
        return false;
    }
};