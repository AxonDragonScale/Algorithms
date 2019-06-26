// https://www.interviewbit.com/problems/copy-list/

// Random can point to a previous node or a node somewhere ahead or NULL. Make sure no cycles or extra nodes are made
// due to this

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *util(RandomListNode *l, unordered_map<RandomListNode *, RandomListNode *> &hashMap) {
    if (l == NULL) return NULL;
    if (hashMap.find(l) != hashMap.end()) return hashMap[l];

    RandomListNode *temp = new RandomListNode(l->label);
    hashMap[l] = temp;  // save in map before calling util to avoid cycles

    temp->next = util(l->next, hashMap);
    temp->random = util(l->random, hashMap);
    return temp;
}

RandomListNode *Solution::copyRandomList(RandomListNode *l) {
    unordered_map<RandomListNode *, RandomListNode *> hashMap;
    return util(l, hashMap);
}