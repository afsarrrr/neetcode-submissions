class Solution {
public:
    bool oneDiff(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diff++;

            if (diff > 1)
                return false;
        }

        return diff == 1;
    }

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        bool found = false;

        for (auto &w : wordList) {
            if (w == endWord) {
                found = true;
                break;
            }
        }

        if (!found)
            return 0;

        wordList.push_back(beginWord);

        int n = wordList.size();

        unordered_map<string,int> id;

        for (int i = 0; i < n; i++) {
            id[wordList[i]] = i;
        }

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (oneDiff(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int src = id[beginWord];
        int dest = id[endWord];

        queue<pair<int,int>> q; 
        vector<bool> vis(n, false);

        q.push({src, 1});
        vis[src] = true;

        while (!q.empty()) {

            auto [u, dist] = q.front();
            q.pop();

            if (u == dest)
                return dist;

            for (int v : graph[u]) {

                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, dist + 1});
                }
            }
        }

        return 0;
    }
};