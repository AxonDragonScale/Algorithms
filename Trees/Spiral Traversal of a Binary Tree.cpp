// Question (similar not same)
// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/?ref=self
// https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/


void spiralTraversal(Node *root) {
    if(root == NULL) {
        return;
    }
     
    deque<Node*> LTRqueue, RTLqueue;
    RTLqueue.push_back(NULL);
    RTLqueue.push_back(root);
    
    bool LTR = false;
    Node *cur;
    while(!LTRqueue.empty() || !RTLqueue.empty()) {
        if(LTR && !LTRqueue.empty()) {
            cur = LTRqueue.front();
            LTRqueue.pop_front();
            
            if(cur == NULL) {
                LTR = !LTR;
                cout<<endl;
                if(!RTLqueue.empty())
                    RTLqueue.push_front(NULL);
                continue;
            }
            
            cout<<cur->data<<" ";
            
            if(cur->left != NULL) RTLqueue.push_back(cur->left);
            if(cur->right != NULL) RTLqueue.push_back(cur->right);
    
        } else if(!LTR && !RTLqueue.empty()) {
            cur = RTLqueue.back();
            RTLqueue.pop_back();
            
            if(cur == NULL) {
                LTR = !LTR;
                cout<<endl; 
                if(!LTRqueue.empty())
                    LTRqueue.push_back(NULL);
                continue;
            }
            
            cout<<cur->data<<" ";
            
            if(cur->right != NULL) LTRqueue.push_front(cur->right);
            if(cur->left != NULL) LTRqueue.push_front(cur->left);
        } else {
            break;
        }
    }
}
