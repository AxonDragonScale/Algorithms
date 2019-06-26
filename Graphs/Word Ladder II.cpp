// https://www.interviewbit.com/problems/word-ladder-ii/

struct Item {
    string s;
    int dist;
};

bool isAdjacent(const string &a, const string &b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) count++;
    }

    return count == 1;
}

vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dictionary) {
    queue<vector<string>> q;
    vector<vector<string>> ans;
    set<string> dict(dictionary.begin(), dictionary.end());
    set<string> visited;

    if (start == end) {
        ans.push_back({start});
        return ans;
    }

    int level = 1, minLevel = INT_MAX;

    q.push({start});
    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();

        if (path.size() > level) {       // we reached next level
            if (path.size() > minLevel)  // all new paths will be longer
                break;
            else
                level = path.size();

            for (string s : visited) {  // remove all words used in previous level
                dict.erase(s);          // even if later there were to be a path with these, they would be longer
            }
            visited.clear();
        }

        string s = path.back();
        for (auto it = dict.begin(); it != dict.end(); it++) {
            string next = *it;
            if (isAdjacent(s, next)) {
                vector<string> newPath = path;
                newPath.push_back(next);
                visited.insert(next);

                if (next == end) {
                    minLevel = level;
                    ans.push_back(newPath);
                } else {
                    q.push(newPath);
                }
            }
        }
    }

    return ans;
}
