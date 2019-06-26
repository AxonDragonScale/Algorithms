// https://www.interviewbit.com/problems/justified-text/

// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully
// (left and right) justified. You should pack your words in a greedy approach; that is, pack as many words as you can
// in each line. Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters. Extra spaces between
// words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between
// words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of
// text, it should be left justified and no extra space is inserted between words.

vector<string> Solution::fullJustify(vector<string> &v, int l) {
    vector<string> ans;

    int i = 0;
    while (i < v.size()) {
        int count = v[i].size();

        int j = i + 1;
        while (j < v.size() && count + 1 + v[j].size() <= l) {
            count += 1 + v[j].size();
            j++;
        }

        int spaces = l - count + (j - i - 1);
        string cur;
        if (j == i + 1) {
            cur = v[i] + string(spaces, ' ');
        } else if (j == v.size()) {
            cur = v[i];
            for (int k = i + 1; k < j; k++) {
                cur += " " + v[k];
            }
            cur += string(l - cur.size(), ' ');
        } else {
            int each = spaces / (j - i - 1);
            int rem = spaces % (j - i - 1);

            cur = v[i];
            for (int k = i + 1; k < j; k++) {
                if (rem-- > 0) cur += " ";
                cur += string(each, ' ') + v[k];
            }
        }

        ans.push_back(cur);
        i = j;
    }

    return ans;
}
