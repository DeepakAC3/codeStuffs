#include<iostream>

using namespace std;

//binary search tree using class
class BST
{
    int data;
    BST *left, *right;

public:
    //default constructor
    BST();

    //parameterized constructor
    BST(int);

    //insert function
    BST* insert(BST*, int);

    //inorder traversal
    void inorder(BST*);

    //search function
    BST* search(BST*, int);

    void delete_node(BST*, int);

};

//default constructor
BST :: BST() : data(0), left(NULL), right(NULL){}

//parameterized constructor
BST :: BST(int value)
{
    data = value;
    left = right = NULL;
}

//insert function
BST* BST :: insert(BST* root, int value)
{
    if(!root)
    {
        return new BST(value);
    }

    //insert data
    if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }

    return root;
}

//inorder traversal
void BST :: inorder(BST* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//search function
BST* BST :: search(BST* root, int value){
    if(!root || root->data == value){
        return root;
    }
    if(value > root->data){
        return search(root->right, value);
    }
    return search(root->left, value);
}

void BST::delete_node(BST* root,int value){
    if(!root){
        return;
    }
    if(value > root->data){
        delete_node(root->right,value);
    }
    else if(value < root->data){
        delete_node(root->left,value);
    }
    else{
        if(!root->left && !root->right){
            delete root;
            root = NULL;
        }
        else if(!root->left){
            BST* temp = root;
            root = root->right;
            delete temp;
        }
        else if(!root->right){
            BST* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            BST* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            root->data = temp->data;
            delete_node(root->right,temp->data);
        }
    }
}

//write a code to compare 2 binary search trees
//write a code to find the height of a binary search tree
int max(int a,int b){
    return a>b?a:b;
}

int height(BST* root){
    if(!root){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}
//write a code to find the size of a binary search tree
int size(BST* root){
    if(!root){
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
//write a code to find the diameter of a binary search tree
int diameter(BST* root){
    if(!root){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

//write a code to find the lowest common ancestor of a binary search tree
int lowest_common_ancestor(BST* root,int a,int b){
    if(!root){
        return -1;
    }
    if(root->data == a || root->data == b){
        return root->data;
    }
    int left = lowest_common_ancestor(root->left,a,b);
    int right = lowest_common_ancestor(root->right,a,b);
    if(left != -1 && right != -1){
        return root->data;
    }
    return left != -1 ? left : right;
}
//write a code to find the kth smallest element in a binary search tree
int kth_smallest(BST* root,int k){
    if(!root){
        return -1;
    }
    int left = size(root->left);
    if(left == k-1){
        return root->data;
    }
    else if(left > k-1){
        return kth_smallest(root->left,k);
    }
    else{
        return kth_smallest(root->right,k-left-1);
    }
}
//write a code to find the kth largest element in a binary search tree
int kth_largest(BST* root,int k){
    if(!root){
        return -1;
    }
    int right = size(root->right);
    if(right == k-1){
        return root->data;
    }
    else if(right > k-1){
        return kth_largest(root->right,k);
    }
    else{
        return kth_largest(root->left,k-right-1);
    }
}
//write a code to find the inorder successor of a binary search tree
int inorder_successor(BST* root,int value){
    if(!root){
        return -1;
    }
    BST* temp = search(root,value);
    if(temp->right){
        temp = temp->right;
        while(temp->left){
            temp = temp->left;
        }
        return temp->data;
    }
    else{
        BST* successor = NULL;
        BST* ancestor = root;
        while(ancestor != temp){
            if(temp->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor->data;
    }
}
//write a code to find the inorder predecessor of a binary search tree
int inorder_predecessor(BST* root,int value){
    if(!root){
        return -1;
    }
    BST* temp = search(root,value);
    if(temp->left){
        temp = temp->left;
        while(temp->right){
            temp = temp->right;
        }
        return temp->data;
    }
    else{
        BST* predecessor = NULL;
        BST* ancestor = root;
        while(ancestor != temp){
            if(temp->data > ancestor->data){
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else{
                ancestor = ancestor->left;
            }
        }
        return predecessor->data;
    }
}
//write a code to find the level order traversal of a binary search tree
void level_order(BST* root){
    if(!root){
        return;
    }
    queue<BST*> q;
    q.push(root);
    while(!q.empty()){
        BST* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
//write a code to find the spiral order traversal of a binary search tree
void spiral_order(BST* root){
    if(!root){
        return;
    }
    stack<BST*> s1;
    stack<BST*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            BST* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right){
                s2.push(temp->right);
            }
            if(temp->left){
                s2.push(temp->left);
            }
        }
        while(!s2.empty()){
            BST* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }
    }
}
//write a code to find the vertical order traversal of a binary search tree without using maps
void vertical_order(BST* root){
    if(!root){
        return;
    }
    queue<pair<BST*,int>> q;
    q.push({root,0});
    int min = 0;
    int max = 0;
    while(!q.empty()){
        pair<BST*,int> temp = q.front();
        q.pop();
        if(temp.second < min){
            min = temp.second;
        }
        if(temp.second > max){
            max = temp.second;
        }
        if(temp.first->left){
            q.push({temp.first->left,temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(int i=min;i<=max;i++){
        q.push({root,0});
        while(!q.empty()){
            pair<BST*,int> temp = q.front();
            q.pop();
            if(temp.second == i){
                cout<<temp.first->data<<" ";
            }
            if(temp.first->left){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        }
        cout<<endl;
    }
}

//write a code to find the top view of a binary search tree
void top_view(BST* root){
    if(!root){
        return;
    }
    queue<pair<BST*,int>> q;
    q.push({root,0});
    int min = 0;
    int max = 0;
    while(!q.empty()){
        pair<BST*,int> temp = q.front();
        q.pop();
        if(temp.second < min){
            min = temp.second;
        }
        if(temp.second > max){
            max = temp.second;
        }
        if(temp.first->left){
            q.push({temp.first->left,temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(int i=min;i<=max;i++){
        q.push({root,0});
        while(!q.empty()){
            pair<BST*,int> temp = q.front();
            q.pop();
            if(temp.second == i){
                cout<<temp.first->data<<" ";
                break;
            }
            if(temp.first->left){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        }
    }
}
//write a code to find the bottom view of a binary search tree
void bottom_view(BST* root){
    if(!root){
        return;
    }
    queue<pair<BST*,int>> q;
    q.push({root,0});
    int min = 0;
    int max = 0;
    while(!q.empty()){
        pair<BST*,int> temp = q.front();
        q.pop();
        if(temp.second < min){
            min = temp.second;
        }
        if(temp.second > max){
            max = temp.second;
        }
        if(temp.first->left){
            q.push({temp.first->left,temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(int i=min;i<=max;i++){
        q.push({root,0});
        while(!q.empty()){
            pair<BST*,int> temp = q.front();
            q.pop();
            if(temp.second == i){
                cout<<temp.first->data<<" ";
            }
            if(temp.first->left){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        }
    }
}
//write a code to find the left view of a binary search tree
void left_view(BST* root){
    if(!root){
        return;
    }
    queue<BST*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            BST* temp = q.front();
            q.pop();
            if(i == 0){
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
//write a code to find the right view of a binary search tree
void right_view(BST* root){
    if(!root){
        return;
    }
    queue<BST*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            BST* temp = q.front();
            q.pop();
            if(i == n-1){
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
//write a code to find the boundary traversal of a binary search tree
void left_boundary(BST* root){
    if(!root){
        return;
    }
    if(root->left){
        cout<<root->data<<" ";
        left_boundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        left_boundary(root->right);
    }
}
//write a code to find the number of leaf nodes and no. of edges in a binary search tree
void leaf_nodes(BST* root,int& leaf,int& edges){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        leaf++;
    }
    else{
        edges++;
    }
    leaf_nodes(root->left,leaf,edges);
    leaf_nodes(root->right,leaf,edges);
}

bool is_same(BST* root1,BST* root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    return root1->data == root2->data && is_same(root1->left,root2->left) && is_same(root1->right,root2->right);
}

bool same_leaf_nodes(BST* root1,BST* root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    if(!root1->left && !root1->right && !root2->left && !root2->right){
        return true;
    }
    if(!root1->left || !root1->right || !root2->left || !root2->right){
        return false;
    }
    return same_leaf_nodes(root1->left,root2->left) && same_leaf_nodes(root1->right,root2->right);
}

bool has_two_or_no_children(BST* root){
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        return true;
    }
    if(!root->left || !root->right){
        return false;
    }
    return has_two_or_no_children(root->left) && has_two_or_no_children(root->right);
}

int main()
{
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.inorder(root);
    cout<<endl;

    int value;
    cin>>value;
    if(b.search(root, value))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    return 0;
}