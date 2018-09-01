
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

// On sorting and going from the node to the node on its initial index and repeating this on it will
// give a cycle (because initial position of no two elements could have been the same)
// cycleLen-1 is the number of swaps needed to get all elements to their initial position

// This same concept can also be used to find the minimum number of swaps needed to convert
// a binary tree into a BST, just take the inOrder of the binary tree in an array and do this

int minSwaps(int arr[], int N){
    vector< pair<int,int> > arrPos(N);
    for(int i = 0; i<N; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    
    sort(arrPos.begin(), arrPos.end());
    
    int j, ans = 0, cycleLen;
    vector<bool> visited(N, false);
    for(int i = 0; i<N; i++) {
        if(visited[i] || arrPos[i].second == i) {
            // if i has already been visited or arr[i] was already in its correct
            // position and didn't need to be swapped
            continue;
        } 

        cycleLen = 0;
        j = i;
        while(!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycleLen++;
        }
        
        ans += cycleLen-1;
    }
    
    return ans;
}