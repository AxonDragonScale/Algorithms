// https://www.interviewbit.com/problems/valid-ip-addresses/

// Both methods are same just framed differently

bool isValid(string s) {
    int val = stoi(s);
    if (val < 0 || val > 255 || (s[0] == '0' && s.size() > 1)) {
        return false;
    }
    return true;
}

vector<string> Solution::restoreIpAddresses(string s) {
    int n = s.size();

    vector<string> ans;
    string temp[4];
    for (int i = 1; i <= 3 && i < n; i++) {
        temp[0] = s.substr(0, i);
        if (!isValid(temp[0])) continue;
        for (int j = 1; j <= 3 && i + j < n; j++) {
            temp[1] = s.substr(i, j);
            if (!isValid(temp[1])) continue;
            for (int k = 1; k <= 3 && i + j + k < n; k++) {
                temp[2] = s.substr(i + j, k);
                if (!isValid(temp[2])) continue;
                for (int l = 1; l <= 3; l++) {
                    if (i + j + k + l != n) continue;  // all chars not used

                    temp[3] = s.substr(i + j + k, l);
                    if (!isValid(temp[3])) continue;

                    string cur = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
                    ans.push_back(cur);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// vector<string> Solution::restoreIpAddresses(string s) {
//     int n = s.size();

//     vector<string> ans;
//     for(int i = 1; i<=3; i++) {
//         for(int j = 1; j<=3; j++) {
//             for(int k = 1; k<=3; k++) {
//                 for(int l = 1; l<=3; l++) {
//                     if(i+j+k+l != n) continue; // all chars not used

//                     string temp[4];
//                     temp[0] = s.substr(0, i);
//                     temp[1] = s.substr(i, j);
//                     temp[2] = s.substr(i+j, k);
//                     temp[3] = s.substr(i+j+k, l);

//                     bool isValid = true;
//                     for(int t = 0; t<4; t++) {
//                         int val = stoi(temp[t]);
//                         if(val < 0 || val > 255 || (temp[t][0] == '0' && temp[t].size() > 1)) {
//                             isValid = false;
//                         }
//                         temp[t] = to_string(val);
//                     }
//                     if(!isValid) continue;

//                     string cur = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
//                     ans.push_back(cur);
//                 }
//             }
//         }
//     }

//     sort(ans.begin(), ans.end());
//     return ans;
// }
