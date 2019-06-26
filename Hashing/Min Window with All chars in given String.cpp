// https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string s, string t) {
    unordered_map<char, int> tChars;
    for (char c : t) tChars[c]++;

    unordered_map<char, int> sChars;
    int minWindow = INT_MAX, start = 0, minStart = 0;
    for (int i = 0; i < s.size(); i++) {
        sChars[s[i]]++;

        // Remove extra characters from the front
        while (start < i && sChars[s[start]] > tChars[s[start]]) {
            sChars[s[start]]--;
            start++;
        }

        if (sChars[s[i]] == tChars[s[i]]) {
            bool isValid = true;
            for (pair<char, int> p : tChars) {  // check if needed count of all chars in tChars is present in sChars
                if (sChars[p.first] < p.second) {
                    isValid = false;
                    break;
                }
            }

            if (isValid && i - start + 1 < minWindow) {
                minStart = start;
                minWindow = i - start + 1;
            }
        }
    }

    if (minWindow == INT_MAX) return "";
    return s.substr(minStart, minWindow);
}
