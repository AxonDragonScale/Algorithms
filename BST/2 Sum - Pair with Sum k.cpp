// https://www.interviewbit.com/problems/2sum-binary-tree/

// Method 1 - This is O(n) time and less than O(height) space complexity.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Iterator {
   public:
    stack<TreeNode *> s;

    Iterator(TreeNode *root) { pushAll(root); }

    bool hasNext() { return !s.empty(); }

    int next() {
        TreeNode *temp = s.top();
        s.pop();

        pushAll(temp->right);
        return temp->val;
    }

   private:
    void pushAll(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};

class RevIterator {
   public:
    stack<TreeNode *> s;

    RevIterator(TreeNode *root) { pushAll(root); }

    bool hasNext() { return !s.empty(); }

    int next() {
        TreeNode *temp = s.top();
        s.pop();

        pushAll(temp->left);
        return temp->val;
    }

   private:
    void pushAll(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->right;
        }
    }
};

int Solution::t2Sum(TreeNode *root, int k) {
    Iterator it = Iterator(root);
    RevIterator rIt = RevIterator(root);

    int i, j;
    bool inc = true, dec = true;
    while (true) {
        if (inc) {
            if (it.hasNext())
                i = it.next();
            else
                return 0;
        }

        if (dec) {
            if (rIt.hasNext())
                j = rIt.next();
            else
                return 0;
        }

        if (i >= j)
            return 0;
        else if (i + j == k)
            return 1;
        else if (i + j < k) {
            inc = true;
            dec = false;
        } else {
            inc = false;
            dec = true;
        }
    }
}

// Method 2 - We can store inorder traversal in array and use two pointer method on it. But thats O(n) space complexity.
// or https://www.geeksforgeeks.org/find-pair-given-sum-bst/ use set to keep track of elements, still O(n) space
// complexity.