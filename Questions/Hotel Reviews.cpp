// https://www.interviewbit.com/problems/hotel-reviews/

// Also  See and understand interviewbit solution that uses trie

// my solution
vector<int> Solution::solve(string goodWords, vector<string> &reviews) {
    // Insert goodWords in a set
    set<string> gWords;
    int start = 0, end = 0;
    while ((end = goodWords.find('_', start)) != string::npos) {
        gWords.insert(goodWords.substr(start, end - start));
        start = end + 1;
    }
    gWords.insert(goodWords.substr(start));

    // for each review, count how many gooWrods it has and store the review's index correspoding to the key
    map<int, vector<int>> m;  // count, index list
    int i = 0;
    for (string review : reviews) {
        int count = 0;
        start = 0;
        end = 0;
        while ((end = review.find('_', start)) != string::npos) {
            if (gWords.find(review.substr(start, end - start)) != gWords.end()) {
                count++;
            }
            start = end + 1;
        }
        if (gWords.find(review.substr(start)) != gWords.end()) count++;
        m[count].push_back(i);
        i++;
    }

    vector<int> ans;
    auto it = m.rbegin();
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        for (int i : (*it).second) {
            ans.push_back(i);
        }
    }

    return ans;
}
