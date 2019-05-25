// https://www.interviewbit.com/problems/anagrams/

// Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers
// representing the index in the original list. Look at the sample case for clarification.

// Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

vector<vector<int> > Solution::anagrams(const vector<string> &strings) {
    vector<vector<int> > ans;
    map<vector<int>, int> sets;

    for (int i = 0; i < strings.size(); i++) {
        string s = strings[i];

        vector<int> set(26, 0);
        for (char c : s) {  // mark count of each character to store in map
            set[c - 'a']++;
        }

        if (sets.find(set) != sets.end()) {   // if group is already present
            ans[sets[set]].push_back(i + 1);  // sets[set] will give index of the group in ans, push current index
        } else {
            ans.push_back(vector<int>(1, i + 1));  // create new group,
            sets[set] = ans.size() - 1;            // store index of the group mapped to it
        }
    }

    return ans;
}

// We can also sort the strings and use them as keys for the map but it will be slower (sorting)