// https://www.interviewbit.com/problems/bst-iterator/

struct Node {
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

// Method 1
class BSTIterator {
   public:
    stack<Node *> s;

    BSTIterator(Node *root) { pushAll(root); }

    bool hasNext() { return !s.empty(); }

    int next() {
        Node *temp = s.top();
        s.pop();

        pushAll(temp->right);
        return temp->data;
    }

   private:
    void pushAll(Node *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};

class RevIterator {
   public:
    stack<Node *> s;

    RevIterator(Node *root) { pushAll(root); }

    bool hasNext() { return !s.empty(); }

    int next() {
        Node *temp = s.top();
        s.pop();

        pushAll(root->left);
        return temp->data;
    }

   private:
    void pushAll(Node *root) {
        while (root) {
            s.push(root);
            root = root->right;
        }
    }
};

// Method 2
class BSTIterator {
   public:
    stack<Node *> s;
    Node *cur;

    BSTIterator(Node *root) {
        cur = root;

        if (cur) {
            while (cur->left) {
                s.push(cur);
                cur = cur->left;
            }
        }
    }

    bool hasNext() { return cur == NULL; }

    int next() {
        int ans = cur->data;

        if (cur->right) {
            cur = cur->right;
            while (cur->left) {
                s.push(cur);
                cur = cur->left;
            }
        } else if (!s.empty()) {
            cur = s.top();
            s.pop();
        } else {
            cur = NULL;
        }

        return ans;
    }
};