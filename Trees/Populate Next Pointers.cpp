// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Easiest
void Solution::connect(TreeLinkNode* root) {
    TreeLinkNode* cur;

    while (root) {
        TreeLinkNode* temp = new TreeLinkNode(-1);  // temp is node before 1st node of next level
        cur = temp;
        while (root) {
            if (root->left) {
                cur->next = root->left;
                cur = cur->next;
            }
            if (root->right) {
                cur->next = root->right;
                cur = cur->next;
            }

            root = root->next;  // go to next node of root's level
        }

        root = temp->next;  // temp->next is first node of next level
    }
}

// Okayish
void Solution::connect(TreeLinkNode* root) {
    TreeLinkNode *nextLevelStart, *prev, *cur = root;

    while (cur) {
        prev = NULL;
        nextLevelStart = NULL;

        while (cur) {
            if (cur->left) {
                if (prev)
                    prev->next = cur->left;
                else
                    nextLevelStart = cur->left;  // if no prev, this is the first node in level
                prev = cur->left;
            }

            if (cur->right) {
                if (prev)
                    prev->next = cur->right;
                else
                    nextLevelStart = cur->right;  // if no prev, this is the first node in level
                prev = cur->right;
            }

            cur = cur->next;  // move to next node of cur's level
        }

        cur = nextLevelStart;  // move to next level
    }
}

// Uses Extra Memory
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeLinkNode* temp = q.front();
        q.pop();

        if (temp) {
            temp->next = q.front();  // q.front() will be NULL if last node of level
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        } else if (!q.empty()) {
            q.push(NULL);
        }
    }
}

// Confusing, What the heck, ignore
void Solution::connect(TreeLinkNode* root) {
    while (root) {
        TreeLinkNode *cur = root, *rightMost = NULL;
        while (cur) {
            if (!cur->left && !cur->right) {
                cur = cur->next;
            } else {
                if (rightMost) rightMost->next = cur->left ? cur->left : cur->right;
                if (cur->left) cur->left->next = cur->right;
                rightMost = cur->right ? cur->right : cur->left;
                cur = cur->next;
            }
        }

        while (root && !root->left && !root->right) {
            root = root->next;
        }

        if (root) {
            root = root->left ? root->left : root->right;
        }
    }
}