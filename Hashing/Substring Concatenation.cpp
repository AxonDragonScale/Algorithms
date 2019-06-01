// https://www.geeksforgeeks.org/find-starting-indices-substrings-string-s-made-concatenating-words-listl/
// https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string s, const vector<string> &l) {
    vector<int> ans;

    map<string, int> listWords;
    int totalLen = 0;
    for (string temp : l) {
        listWords[temp]++;
        totalLen += temp.size();
    }

    if (totalLen > s.size()) return ans;

    for (int i = 0; i <= (int)s.size() - totalLen; i++) {
        map<string, int> tempMap = listWords;
        int start = i, len = 1;
        while (start + len <= i + totalLen) {
            if (tempMap.find(s.substr(start, len)) != tempMap.end() && tempMap[s.substr(start, len)] != 0) {
                tempMap[s.substr(start, len)]--;
                start = start + len;
                len = 1;
            } else {
                len++;
            }
        }

        bool isConCat = true;
        for (pair<string, int> p : tempMap) {
            if (p.second != 0) {
                isConCat = false;
            }
        }

        if (isConCat) ans.push_back(i);
    }

    return ans;
}
