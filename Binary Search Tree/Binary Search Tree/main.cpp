//
//  main.cpp
//  Binary Search Tree
//
//  Created by Hemant Jadon on 19/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <math.h>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
    
public:
    //  Constructor
    Node(int data=0,Node* left=NULL,Node* right=NULL):data(data),left(left),right(right)
    {}
    
    
    //  Setters
    
    void setData(int data){
        this->data = data;
    }
    
    void setLeft(Node* left){
        this->left = left;
    }
    
    void setRight(Node* right){
        this->right = right;
    }
    
    
    //  Getters
    
    int getData() const {
        return this->data;
    }
    
    Node* getLeft() const {
        return this->left;
    }
    
    Node* getRight() const {
        return this->right;
    }
};

class BinaryTree{
private:
    Node* root;
    
public:
    //  Constructor
    BinaryTree(Node* root=NULL):root(NULL)
    {}
    
    
    //  Setters
    
    void setRoot(Node* root){
        this->root = root;
    }
    
    
    //  Getters
    
    Node* getRoot() const {
        return this->root;
    }
    
    
    //  Creators
    
    void CreateTree(){
        vector<vector<Node*>> matrix;
        
        int value = 0;
        bool flag = false;
        int i=0;
        do {
            flag = false;
            vector<Node*> level;
            for (int j=0; j<pow(2,i); j++) {
                cin >> value;
                if (value != -1) {
                    flag = true;
                    Node* temp = new Node(value);
                    level.push_back(temp);
                }
                else{
                    level.push_back(NULL);
                }
            }
            matrix.push_back(level);
            i++;
        } while (flag);
        
        for (int x=0; x<matrix.size(); x++) {
            for (int y=0; y<matrix[x].size(); y++) {
                if (matrix[x][y] == NULL) {
                    continue;
                }
                matrix[x][y]->setLeft(matrix[x+1][2*y]);
                matrix[x][y]->setRight(matrix[x+1][2*y+1]);
            }
        }
        this->setRoot(matrix[0][0]);
    }
    
    
    //  Traversals
    
    void InOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        InOrderTraversal(root->getLeft());
        cout << root->getData() << " ";
        InOrderTraversal(root->getRight());
    }
    
    void PreOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        cout << root->getData() << " ";
        PreOrderTraversal(root->getLeft());
        PreOrderTraversal(root->getRight());
    }
    
    void PostOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        PostOrderTraversal(root->getLeft());
        PostOrderTraversal(root->getRight());
        cout << root->getData() << " ";
    }
    
    void TopView(Node* root,Node* parent=NULL){
        if (root == NULL) {
            return;
        }
        
        if (parent == NULL) {
            TopView(root->getLeft(),root);
            cout << root->getData() << " ";
            TopView(root->getRight(),root);
        }
        else if (parent->getRight() == root){
            cout << root->getData() << " ";
            TopView(root->getRight(),root);
        }
        else if (parent->getLeft() == root){
            TopView(root->getLeft(),root);
            cout << root->getData() << " ";
        }
    }
    
    void LeftView(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<pair<Node*,int>> node_queue;
        pair<Node*, int> joint (root,1);
        node_queue.push(joint);
        
        int last_printed_level = 0;
        
        while (!node_queue.empty()) {
            Node* p = node_queue.front().first;
            int level = node_queue.front().second;
            node_queue.pop();
            
            if (level != last_printed_level) {
                cout << p->getData() << " ";
                last_printed_level = level;
            }
            
            if (p->getLeft()) {
                pair<Node*, int> joint(p->getLeft(),level+1);
                node_queue.push(joint);
            }
            if (p->getRight()) {
                pair<Node*, int> joint(p->getRight(),level+1);
                node_queue.push(joint);
            }
        }
    }
    
    void LevelOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<Node*> node_queue;
        node_queue.push(root);
        
        while (!node_queue.empty()) {
            Node* p = node_queue.front();
            node_queue.pop();
            
            cout << p->getData() << " ";
            if (p->getLeft()) {
                node_queue.push(p->getLeft());
            }
            if (p->getRight()) {
                node_queue.push(p->getRight());
            }
        }
    }
    
private:
    void VerticalOrderTraversal_Recur(Node* root,map<int, vector<Node*>> &map,int hd=0){
        if (root == NULL) {
            return;
        }
        
        map[hd].push_back(root);
        
        VerticalOrderTraversal_Recur(root->getLeft(), map, hd+1);
        VerticalOrderTraversal_Recur(root->getRight(), map, hd-1);
    }
public:
    void VerticalOrderTraversal(Node* root){
        map<int , vector<Node*>> m;
        
        VerticalOrderTraversal_Recur(root, m);
        
        map<int, vector<Node*>>::reverse_iterator it;
        
        for (it = m.rbegin(); it != m.rend(); it++) {
            vector<Node*>::iterator v_it;
            
            for (v_it = it->second.begin(); v_it != it->second.end(); v_it++) {
                cout << (*v_it)->getData() << " ";
            }
            cout << endl;
        }
    }
    
    void ReverseLevelOrderTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        queue<Node*> Q;
        stack<Node*> ST;
        
        Q.push(root);
        
        while (!Q.empty()) {
            Node* ref = Q.front();
            Q.pop();
            
            cout << ref->getData() << " ";
            
            if (ref->getLeft()) {
                ST.push(ref->getLeft());
            }
            if (ref->getRight()) {
                ST.push(ref->getRight());
            }
            
            while (!ST.empty()) {
                Q.push(ST.top());
                ST.pop();
            }
        }
    }
    
private:
    void DiagonalTraversal_Recur(Node* root,map<int, vector<Node*>> &m,int diag_level=0){
        if (root == NULL) {
            return;
        }
        
        m[diag_level].push_back(root);
        
        DiagonalTraversal_Recur(root->getLeft(), m, diag_level+1);
        DiagonalTraversal_Recur(root->getRight(), m, diag_level);
    }
    
public:
    void DiagonalTraversal(Node* root){
        map<int, vector<Node*>> m;
        
        DiagonalTraversal_Recur(root, m);
        
        map<int, vector<Node*>>::iterator it;
        
        for (it=m.begin(); it != m.end(); it++) {
            vector<Node*>::iterator v_it;
            
            for (v_it = it->second.begin(); v_it != it->second.end(); v_it++) {
                cout << (*v_it)->getData() << " ";
            }
            cout << endl;
        }
    }
    
    void LevelOrderSpiralTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        stack<Node*> ST1;
        stack<Node*> ST2;
        
        ST1.push(root);
        
        
        while (!ST1.empty() || !ST2.empty()) {
            while (!ST1.empty()) {
                Node* ref = ST1.top();
                cout << ref->getData() << " ";
                ST1.pop();
                
                if (ref->getLeft()) {
                    ST2.push(ref->getLeft());
                }
                if (ref->getRight()) {
                    ST2.push(ref->getRight());
                }
            }
            while (!ST2.empty()) {
                Node* ref = ST2.top();
                cout << ref->getData() << " ";
                ST2.pop();
                
                if (ref->getRight()) {
                    ST1.push(ref->getRight());
                }
                if (ref->getLeft()) {
                    ST1.push(ref->getLeft());
                }
            }
        }
    }
    
    // Construct Tree from traversals

    
    Node* Construct_from_PreOrder_and_InOrder(int preorder[],int inorder[],
                                             int low,int high,int* pre_index){
        if (low > high) {
            return NULL;
        }
        
        int in_index = __search(inorder, low, high, preorder[(*pre_index)]);
        if (in_index == -1) {
            return NULL;
        }
        (*pre_index)++;
        Node* left = Construct_from_PreOrder_and_InOrder(preorder, inorder, low, in_index-1, pre_index);
        Node* right = Construct_from_PreOrder_and_InOrder(preorder, inorder, in_index+1, high, pre_index);
        return new Node(inorder[in_index],left,right);
    }
private:
    Node* Construct_from_LevelOrder_and_InOrder_Recur(vector<pair<int,bool>>
                                                      levelorder,int inorder[],int low,int high){
        if (low > high) {
            return NULL;
        }
        
        int in_index = -1;
        for (int i=0; i<levelorder.size(); i++) {
            if (levelorder[i].second == true) {
                continue;
            }
            in_index = __search(inorder, low, high, levelorder[i].first);
            if (in_index == -1) {
                continue;
            }
            else {
                levelorder[i].second = true;
                break;
            }
        }
        if (in_index == -1) {
            return NULL;
        }
        
        Node* left = Construct_from_LevelOrder_and_InOrder_Recur(levelorder, inorder, low, in_index-1);
        Node* right =Construct_from_LevelOrder_and_InOrder_Recur(levelorder, inorder, in_index+1, high);
        return new Node(inorder[in_index],left,right);
    }

public:
    void Construct_from_LevelOrder_and_InOrder(int levelorder[],int inorder[],int n){
        
        vector<pair<int, bool>> paired_array;
        
        for (int i=0; i<n; i++) {
            pair<int,bool> joint(levelorder[i],false);
            paired_array.push_back(joint);
        }
        
        this->setRoot(Construct_from_LevelOrder_and_InOrder_Recur(paired_array, inorder, 0, n-1));
    }
    
    Node* ConstructSpecial_fromInOrder(int inorder[],int low,int high){
        if (low > high) {
            return NULL;
        }
        
        int max_index = __max_in_array(inorder, low, high);
        
        Node* root = new Node(inorder[max_index]);
        
        Node* leftChild = ConstructSpecial_fromInOrder(inorder, low, max_index-1);
        
        Node* rightChild = ConstructSpecial_fromInOrder(inorder, max_index+1, high);
        
        root->setLeft(leftChild);
        root->setRight(rightChild);
        
        return root;
    }
    
    Node* ConstructSpecial_from_PreOrder(int pre[],char preLN[],int n,int* preindex){
        
        Node* root = new Node(pre[(*preindex)]);
        
        if (preLN[(*preindex)] == 'L') {
            return root;
        }
        
        (*preindex)++;
        Node* leftChild = ConstructSpecial_from_PreOrder(pre, preLN, n, preindex);
        (*preindex)++;
        Node* rightChild = ConstructSpecial_from_PreOrder(pre, preLN, n,preindex);
        
        root->setLeft(leftChild);
        root->setRight(rightChild);
        
        return root;
    }
    
    Node* ConstructFullBinaryTree_from_PreOrder_and_PostOrder(int preorder[],int postorder[],int low,int high,int* preindex){
        
        if (low > high) {
            return NULL;
        }
        
        Node* root = new Node(postorder[high]);
        (*preindex)++;
        
        int index = __search(postorder, low, high-1, preorder[(*preindex)]);
        
        if (index == -1) {
            return root;
        }
        
        Node* left = ConstructFullBinaryTree_from_PreOrder_and_PostOrder(preorder, postorder, low, index, preindex);
        Node* right = ConstructFullBinaryTree_from_PreOrder_and_PostOrder(preorder, postorder, index+1, high-1, preindex);
        
        root->setLeft(left);
        root->setRight(right);
        return root;
    }
    
    Node* ConstructBinaryTree_from_Parent_Array(int parent[],int n,bool visited[],int toFind = -1){
        int i;
        for (i=0; i<n; i++) {
            if (parent[i] == toFind && visited[i] == false) {
                visited[i] = true;
                break;
            }
        }
        if (i == n) {
            return NULL;
        }
        
        Node* root = new Node(i);
        
        Node* leftChild = ConstructBinaryTree_from_Parent_Array(parent, n, visited, i);
        Node* rightChild = ConstructBinaryTree_from_Parent_Array(parent, n, visited, i);
        
        root->setLeft(leftChild);
        root->setRight(rightChild);
        
        return root;
    }
    
    // Other Functions
    
    int size(Node* root){
        int s = 0;
        if (root == NULL) {
            return s;
        }
        s++;
        s += size(root->getLeft());
        s += size(root->getRight());
        return s;
    }
    
    Node* max(Node* root,Node* maxNode=NULL){
        if (root == NULL) {
            return maxNode;
        }
        
        if (maxNode) {
            if (maxNode->getData() < root->getData()) {
                maxNode = root;
            }
        }
        else {
            maxNode = root;
        }
        
        maxNode = max(root->getLeft(),maxNode);
        maxNode = max(root->getRight(),maxNode);
        
        return maxNode;
    }
    
    Node* min(Node* root,Node* minNode=NULL){
        if (root == NULL) {
            return minNode;
        }
        
        if (minNode) {
            if (minNode->getData() > root->getData()) {
                minNode = root;
            }
        }
        else {
            minNode = root;
        }
        
        minNode = min(root->getLeft(),minNode);
        minNode = min(root->getRight(),minNode);
        
        return minNode;
    }

    
    int height(Node* root){
        
        if (root == NULL) {
            return 0;
        }
        
        return __max(height(root->getLeft()), height(root->getRight()))+1;
    }
    
    int diameter(Node* root){
        if (root == NULL) {
            return 0;
        }
        
        int leftHeight = height(root->getLeft());
        int rightHeight = height(root->getRight());
        
        int leftDiameter = diameter(root->getLeft());
        int rightDiameter = diameter(root->getRight());
        
        return __max(__max(leftDiameter,rightDiameter),leftHeight+rightHeight+1);
    }
    
    int min_depth(Node* root){
        if (root == NULL) {
            return 0;
        }
        
        int leftDepth = min_depth(root->getLeft());
        int rightDepth = min_depth(root->getRight());
        
        return (__min(leftDepth, rightDepth)+1);
    }
    
    void mirror(Node* root){
        if (root == NULL) {
            return;
        }
        
        Node* temp = root->getLeft();
        root->setLeft(root->getRight());
        root->setRight(temp);
        
        mirror(root->getLeft());
        mirror(root->getRight());
    }
    
    bool isStructuralMirror(Node* root_1,Node* root_2){
        if (root_1 == NULL && root_2 == NULL) {
            return true;
        }
        
        if (root_1 == NULL || root_2 == NULL) {
            return false;
        }
        
        bool leftMirror = isStructuralMirror(root_1->getLeft(), root_2->getRight());
        
        bool rightMirror = isStructuralMirror(root_1->getRight(), root_2->getLeft());
        
        return (leftMirror && rightMirror);
    }
    
    void levelSwap(Node* root,int level,int curr_level=1){
        if (root == NULL) {
            return;
        }
        
        if (level == curr_level) {
            Node* temp = root->getLeft();
            root->setLeft(root->getRight());
            root->setRight(temp);
            return;
        }
        
        levelSwap(root->getLeft(), level, curr_level+1);
        levelSwap(root->getRight(), level, curr_level+1);
    }
    
    void printPathsToAllLeaves(Node* root,string path=""){
        if (root == NULL) {
            return;
        }
        
        path += to_string(root->getData()) += " ";
        
        if (root->getLeft() == NULL && root->getRight() == NULL) {
            cout << path << endl;
            return;
        }
        
        printPathsToAllLeaves(root->getLeft(),path);
        printPathsToAllLeaves(root->getRight(),path);
    }
    
    bool childrenSumProperty(Node* root){
        if (root == NULL || (root->getLeft() == NULL && root->getRight() == NULL)) {
            return true;
        }
        
        int leftData = 0;
        int rightData = 0;
        if (root->getLeft()) {
            leftData = root->getLeft()->getData();
        }
        if (root -> getRight()) {
            rightData = root->getRight()->getData();
        }
        
        int rootData = root->getData();
        
        return ((leftData+rightData == rootData)
                && childrenSumProperty(root->getLeft())
                && childrenSumProperty(root->getRight()));
    }
    
    void ConvertToTreeHavingChildrenSumProperty(Node* root){
        if (root == NULL) {
            return;
        }
        
        ConvertToTreeHavingChildrenSumProperty(root->getLeft());
        ConvertToTreeHavingChildrenSumProperty(root->getRight());
        
        bool isStable = childrenSumProperty(root);
        if (isStable) {
            return;
        }
        
        else {
            int diff = 0;
            if (root->getLeft()) {
                diff += root->getLeft()->getData();
            }
            if (root->getRight()) {
                diff += root->getRight()->getData();
            }
            
            diff -= root->getData();
            
            if (diff < 0) {
                if (root->getLeft()) {
                    int leftData = root->getLeft()->getData();
                    int newLeftData = leftData + abs(diff);
                    root->getLeft()->setData(newLeftData);
                    ConvertToTreeHavingChildrenSumProperty(root->getLeft());
                }
                else {
                    int rightData = root->getRight()->getData();
                    int newRightData = rightData + abs(diff);
                    root->getLeft()->setData(newRightData);
                    ConvertToTreeHavingChildrenSumProperty(root->getRight());
                }
            }
            else {
                int rootData = root->getData();
                int newRootData = rootData + abs(diff);
                root->setData(newRootData);
            }
        }
        
    }
    
    bool isHeightBalanced(Node* root){
        if (root == NULL) {
            return true;
        }
        
        bool leftSubtree_State = isHeightBalanced(root->getLeft());
        bool rightSubtree_State = isHeightBalanced(root->getRight());
        
        int leftHeight = height(root->getLeft());
        int rightHeight = height(root->getRight());
        
        return (leftSubtree_State
                && rightSubtree_State
                &&(abs(leftHeight - rightHeight) <= 1));
    }
    
    void doubleTree(Node* root){
        if (root == NULL) {
            return;
        }
        
        doubleTree(root->getLeft());
        doubleTree(root->getRight());
        
        Node* temp = new Node(root->getData());
        Node* root_left = root->getLeft();
        root->setLeft(temp);
        temp->setLeft(root_left);
    }
    
private:
    void width_Recur(Node* root,int level,int level_node_count[]){
        if (root == NULL) {
            return;
        }
        level_node_count[level]++;
        width_Recur(root->getLeft(), level+1, level_node_count);
        width_Recur(root->getRight(), level+1, level_node_count);
    }
    
public:
    int width(Node* root){
        /**
         * Can also do level order traversal and count the nodes then.
         */
        if (root == NULL) {
            return 0;
        }
        int h = height(root);
        int level_node_count[h];
        for (int i=0; i<h; i++) {
            level_node_count[i]=0;
        }
        width_Recur(root, 0, level_node_count);
        
        int max = 0;
        for (int i=0; i<h; i++) {
            if (level_node_count[i] > max) {
                max = level_node_count[i];
            }
        }
        
        return max;
    }
    
    bool isFoldable(Node* root){
        if (root == NULL) {
            return true;
        }
        return isStructuralMirror(root->getLeft(), root->getRight());
    }
    
    void nodesAtLevelK(Node* root,int k,int curr_level=1){
        if (k == 0 || root == NULL) {
            return;
        }
        
        if (curr_level == k) {
            cout << root->getData() << " ";
            return;
        }
        
        nodesAtLevelK(root->getLeft(), k, curr_level+1);
        nodesAtLevelK(root->getRight(), k, curr_level+1);
    }
    
    bool printAncestors_Recursive(Node* root,int el){
        if (root == NULL) {
            return false;
        }
        
        if (root->getData() == el) {
            return true;
        }
        
        bool el_in_left = printAncestors_Recursive(root->getLeft(), el);
        bool el_in_right = printAncestors_Recursive(root->getRight(), el);
        
        if (el_in_left || el_in_right) {
            cout << root->getData() << " ";
            return true;
        }
        
        return false;
    }
    
    void printAncestors_Iterative(Node* root, int el){
        if (root == NULL) {
            return;
        }
        
        stack<Node*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                if (root->getData() == el) {
                    while (!stack.empty()) {
                        root = stack.top();
                        stack.pop();
                        cout << root->getData() << " ";
                    }
                    root = NULL;
                }
                else {
                    stack.push(root);
                    root = root->getLeft();
                }
            }
            else {
                root = stack.top();
                if (root->getData() == el) {
                    while (!stack.empty()) {
                        root = stack.top();
                        stack.pop();
                        cout << root->getData() << " ";
                    }
                    root = NULL;
                }
                else {
                    if (root->getRight() == NULL) {
                        stack.pop();
                        Node* ref = root;
                        
                        while (!stack.empty() && stack.top()->getRight() == ref) {
                            ref = stack.top();
                            stack.pop();
                        }
                        
                        root =NULL;
                    }
                    else {
                        root = root->getRight();
                    }
                }
            }
        }
    }
    
    bool isSumTree(Node* root){
        if (root == NULL || (root->getLeft() == NULL && root->getRight() == NULL)) {
            return true;
        }
        
        bool leftPart = isSumTree(root->getLeft());
        bool rightPart = isSumTree(root->getRight());
        
        int leftData = 0;
        int rightData = 0;
        int rootData = root->getData();
        
        if(root->getLeft()){
            leftData = root->getLeft()->getData();
        }
        if (root->getRight()) {
            rightData = root->getRight()->getData();
        }
        
        return (leftPart && rightPart && (rootData == leftData+rightData));
    }
    
    int ConvertToSumTree(Node* root){
        if (root == NULL) {
            return 0;
        }
        
        if (root->getLeft() == NULL && root->getRight() == NULL) {
            int value = root->getData();
            root->setData(0);
            return value;
        }
        
        int leftValue = ConvertToSumTree(root->getLeft());
        int rightValue = ConvertToSumTree(root->getRight());
        
        int rootData = root->getData();
        
        root->setData(leftValue + rightValue);
        
        return root->getData() + rootData;
    }
    
private:
    void maximumSumPath_FindPath_Recur(Node* root,int* max_sum,Node** leaf_ref,int curr_sum=0){
        if (root == NULL) {
            return;
        }
        
        
        curr_sum = curr_sum + root->getData();
        if ((*max_sum) < curr_sum) {
            if (root->getLeft() == NULL && root->getRight() == NULL) {
                (*max_sum) = curr_sum;
                (*leaf_ref) = root;
            }
        }
        maximumSumPath_FindPath_Recur(root->getLeft(), max_sum ,leaf_ref);
        maximumSumPath_FindPath_Recur(root->getRight(), max_sum ,leaf_ref);
        
    }
    
    void printPath(Node* root, Node* leaf_ref, string path=""){
        if (root == NULL) {
            return;
        }
        if (root->getLeft() == NULL && root->getRight() == NULL) {
            if (root == leaf_ref) {
                cout << path << endl;
                return;
            }
            else {
                return;
            }
        }
        
        path += to_string(root->getData());
        path += " ";
        
        printPath(root->getLeft(), leaf_ref, path);
        printPath(root->getRight(), leaf_ref, path);
    }
    
public:
    void maximumSumPath(Node* root){
        int max_sum = INT_MIN;
        
        Node* leaf_ref = NULL;
        maximumSumPath_FindPath_Recur(root, &max_sum, &leaf_ref);
        
        printPath(root, leaf_ref);
        
        cout << max_sum << endl;
    }
    
    vector<int> maximumSumPath_Advanced(Node* root){
        if (root == NULL) {
            vector<int> vct;
            vct.push_back(0);
            vct.push_back(0);
            return vct;
        }
        
        vector<int> left = maximumSumPath_Advanced(root->getLeft());
        vector<int> right = maximumSumPath_Advanced(root->getRight());
        
        vector<int> vct;
        
        (left[0] > right[0]) ? vct.push_back(left[0]+root->getData()) : vct.push_back(right[0]+root->getData());
        
        if (left[1] > right[1]) {
            if (left[1] > left[0] + right[0] + root->getData()) {
                vct.push_back(left[1]);
            }
            else {
                vct.push_back(left[0] + right[0] + root->getData());
            }
        }
        else {
            if (right[1] > left[0] + right[0] + root->getData()) {
                vct.push_back(right[1]);
            }
            else {
                vct.push_back(left[0]+right[0] + root->getData());
            }
        }
        return vct;
    }
    
    
private:
    bool isIsomorphic_Recur(Node* root_1,Node* root_2){
        if (root_1 == NULL && root_2 == NULL) {
            return true;
        }
        else if (root_1 == NULL || root_2 == NULL){
            return false;
        }
        
        bool a = (root_1->getData() == root_2->getData());
        
        bool b_1 = isIsomorphic_Recur(root_1->getRight(), root_2->getRight());
        bool b_2 = isIsomorphic_Recur(root_1->getLeft(), root_2->getLeft());
        
        bool c_1 = isIsomorphic_Recur(root_1->getLeft(), root_2->getRight());
        bool c_2 = isIsomorphic_Recur(root_1->getRight(), root_2->getLeft());
        
        return (a && ((b_1 && b_2) || (c_1 && c_2)));
    }
public:
    bool isIsomorphic(Node* root){
        if (root == NULL) {
            return true;
        }
        
        return isIsomorphic_Recur(root, root);
    }
    
    bool isPreOrderBST(int preorder[],int n){
        stack<int> st;
        
        int root=INT_MIN;
        
        for (int i=0; i<n; i++) {
            if (preorder[i] < root) {
                return false;
            }
            while (!st.empty() && st.top() < preorder[i]) {
                root = st.top();
                st.pop();\
            }
            st.push(preorder[i]);
        }
        return true;
    }
    
    bool isBST(Node* root,int max = INT_MAX,int min = INT_MIN){
        if (root == NULL) {
            return true;
        }
        
        if ((root->getData() < min) || (root->getData() > max)) {
            return false;
        }
        
        bool a = isBST(root->getLeft(),root->getData(),min);
        bool b = isBST(root->getRight(),max,root->getData());
        
        return (a && b);
    }
    
private:
    
    // Auxilary Functions
    int __max(int a, int b){
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
    
    int __min(int a, int b){
        if (a < b) {
            return a;
        }
        else {
            return b;
        }
    }
    
    int __search(int arr[],int low, int high,int el){
        for (int i=low; i<=high; i++) {
            if (arr[i] == el) {
                return i;
            }
        }
        return -1;
    }
    
    int __max_in_array(int arr[], int low, int high){
        int max = INT_MIN;
        int max_index = -1;
        
        for (int i = low; i<=high; i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_index = i;
            }
        }
        return max_index;
    }
};



/**
 * BST : Binary Search Tree
 */
class BinarySearchTree : public BinaryTree{
public:
    void CreateBST(){
        int n;
        cin >> n;
        
        while (n != -1) {
            Node* temp = new Node(n);
            
            if (this->getRoot() == NULL) {
                this->setRoot(temp);
            }
            
            else {
                Node* root_1 = this->getRoot();

                while (1) {
                    if (n > root_1 -> getData()) {
                        if (root_1->getRight() == NULL) {
                            root_1->setRight(temp);
                            break;
                        }
                        else {
                            root_1 = root_1->getRight();
                        }
                    }
                    else {
                        if (root_1 -> getLeft() == NULL) {
                            root_1->setLeft(temp);
                            break;
                        }
                        else {
                            root_1 = root_1->getLeft();
                        }
                    }
                }
            }
            
            cin >> n;
        }
    }
    
    void insert(Node* root,int value){
        Node* temp = new Node(value);
        
        if (root == NULL) {
            this->setRoot(temp);
        }
        
        else {
            Node* root_1 = this->getRoot();
            
            while (1) {
                if (value > root_1 -> getData()) {
                    if (root_1->getRight() == NULL) {
                        root_1->setRight(temp);
                        break;
                    }
                    else {
                        root_1 = root_1->getRight();
                    }
                }
                else {
                    if (root_1 -> getLeft() == NULL) {
                        root_1->setLeft(temp);
                        break;
                    }
                    else {
                        root_1 = root_1->getLeft();
                    }
                }
            }
        }
    }
    
    Node* treeToList(Node* root){
        if (root == NULL) {
            return NULL;
        }
        
        Node* leftList = treeToList(root->getLeft());
        Node* rightList = treeToList(root->getRight());
        
        root->setLeft(root);
        root->setRight(root);
        
        leftList = merge(leftList, root);
        leftList = merge(leftList, rightList);
        
        return leftList;
    }

private:
    Node* merge(Node* a,Node* b){
        if (a == NULL && b == NULL) {
            return NULL;
        }
        
        else if (a == NULL){
            return b;
        }
        
        else if(b == NULL) {
            return a;
        }
        
        Node* a_1 = a;
        Node* b_1 = b;
        
        while (a_1->getRight() != a) {
            a_1 = a_1->getRight();
        }
        
        while (b_1->getRight() != b) {
            b_1 = b_1->getRight();
        }
        
        a_1->setRight(b);
        b->setLeft(a_1);
        
        a->setLeft(b_1);
        b_1->setRight(a);
        
        return a;
    }

public:
    Node* floor(Node* root,int key,Node* current_floor=NULL){
        if (root == NULL) {
            return current_floor;
        }
        
        if (root->getData() == key) {
            return root;
        }
        else if (root->getData() > key) {
            return floor(root->getLeft(), key,current_floor);
        }
        else {
            current_floor = root;
            return floor(root->getRight(), key, current_floor);
        }
    }
    
    Node* ceil(Node* root,int key,Node* current_ceil=NULL){
        if (root == NULL) {
            return current_ceil;
        }
        
        if (root->getData() == key) {
            return root;
        }
        else if(root->getData() < key){
            return ceil(root, key,current_ceil);
        }
        else {
            current_ceil = root;
            return ceil(root, key, current_ceil);
        }
    }
    
    Node* BalancedBSTFromSortedArray(int arr[],int low,int high){
        if (low > high) {
            return NULL;
        }
        
        int mid = low + (high-low)/2;
        
        Node* root = new Node(arr[mid]);
        
        Node* left = BalancedBSTFromSortedArray(arr, low, mid-1);
        Node* right = BalancedBSTFromSortedArray(arr, mid+1, high);
        
        root->setLeft(left);
        root->setRight(right);
        return root;
    }
    
private:
    Node* BalancedBSTFromSortedLL_Recur(list<int> ll,list<int>::iterator &it,int n){
        if (n <= 0) {
            return NULL;
        }
        
        Node* left = BalancedBSTFromSortedLL_Recur(ll, it, n/2);
        
        Node* root = new Node((*it));
        if (left) {
            it++;
        }
        it++;
        
        root->setLeft(left);
        
        Node* right = BalancedBSTFromSortedLL_Recur(ll, it, n/2);
        root->setRight(right);
        if (right) {
            it++;
        }
        return root;
    }
    
public:
    Node* BalancedBSTFromSortedLinkedlist(list<int> ll){
        list<int>::iterator it=ll.begin();
        
        return BalancedBSTFromSortedLL_Recur(ll, it, int(ll.size()));
    }
    
    Node* mergeTwoBST(Node* root1,Node* root2){
        
        return root1;
    }
    
    bool isSumEqual(Node* root, int sum){
        stack<Node*> s1;
        stack<Node*> s2;
        
        Node* x = root;
        Node* y = root;
        
        while (true) {
            while (x) {
                s1.push(x);
                x = x->getLeft();
            }
            
            while (y) {
                s2.push(y);
                y = y->getRight();
            }
            
            if (s1.empty() || s2.empty() || (s1.top()->getData() >= s2.top()->getData())) {
                return false;
            }
            
            int a = s1.top()->getData();
            int b = s2.top()->getData();
            
            if ((a+b) == sum) {
                return true;
            }
            
            if ((a+b) > sum) {
                y = s2.top()->getLeft();
                s2.pop();
            }
            else {
                x = s1.top()->getRight();
                s1.pop();
            }
        }
        return false;
    }
    
    Node* LCA_BST(Node* root,int x,int y){
        if (root == NULL) {
            return NULL;
        }
        
        if ((root->getData() == x) || (root->getData() == y)) {
            return root;
        }
        
        else if ((root->getData() > x) && (root->getData() < y)) {
            return root;
        }
        
        else if ((root->getData() < x) && (root->getData() >y)) {
            return root;
        }
        
        else if ((root->getData() > x) && (root->getData() > y)) {
            return LCA_BST(root->getLeft(), x, y);
        }
        
        else if ((root->getData() < x) && (root->getData() < y)) {
            return LCA_BST(root->getRight(), x, y);
        }
        
        return root;
    }
    
    void SortedOrderPrint_Array_CompleteBST(int arr[],int n,int i=0){
        if (i >= n) {
            return;
        }
        
        int l_idx = 2*i+1;
        int r_idx = 2*i+2;
        
        SortedOrderPrint_Array_CompleteBST(arr, n, l_idx);
        cout << arr[i] << " ";
        SortedOrderPrint_Array_CompleteBST(arr, n, r_idx);
    }
    
    Node* KthSmallestElement(Node* root,int k){
        //  Using Morris Traversal
        if (root == NULL) {
            return NULL;
        }
        
        Node* ksmall = NULL;
        
        while (root != NULL) {
            if (root->getLeft() == NULL) {
                k--;
                if (k == 0) {
                    ksmall = root;
                }
                root = root->getRight();
            }
            else {
                Node* predecessor = root->getLeft();
                
                while (predecessor->getRight() != NULL && predecessor->getRight() != root) {
                    predecessor = predecessor->getRight();
                }
                
                if (predecessor->getRight() == NULL) {
                    predecessor->setRight(root);
                    root = root->getLeft();
                }
                else {
                    predecessor->setRight(NULL);
                    k--;
                    if (k == 0) {
                        ksmall = root;
                    }
                    root = root->getRight();
                }
            }
        }
        return ksmall;
    }
    
    void printBSTKeysInGivenRange(Node* root,int k1,int k2){
        if (root == NULL) {
            return;
        }
        if (k1 < root->getData()) {
            printBSTKeysInGivenRange(root->getLeft(), k1, k2);
        }
        if (k1 < root->getData() && k2 > root->getData()) {
            cout << root->getData() << " " ;
        }
        if (k2 > root->getData()) {
            printBSTKeysInGivenRange(root->getRight(), k1, k2);
        }
    }
};



bool isIdentical(Node* root_1,Node* root_2){
    if (root_1 == NULL && root_2 == NULL) {
        return true;
    }
    
    if (root_1 == NULL || root_2 == NULL) {
        return false;
    }
    
    if (root_1 -> getData() != root_2->getData()) {
        return false;
    }
    
    bool a = isIdentical(root_1->getLeft(), root_2->getLeft());
    bool b = isIdentical(root_1->getRight(), root_2->getRight());
    
    if (a && b) {
        return true;
    }
    else {
        return false;
    }
}



/**
 * Auxilary Tree : This tree derives from BST and is used for non conventional functions.
 * Eg. Traversals without recursion, MorrisTraversal
 */
class AuxilaryTree : public BinarySearchTree {
public:
    void InOrderTraversal_withoutRecursion(Node* root){
        if (root == NULL) {
            return;
        }
        stack<Node*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                stack.push(root);
                root = root->getLeft();
            }
            else {
                root = stack.top();
                stack.pop();
                cout << root->getData() << " ";
                root = root->getRight();
            }
        }
    }
    
    void PreOrderTraversal_withoutRecursion(Node* root){
        if (root == NULL) {
            return;
        }
        
        stack<Node*> stack;
        
        while (root || !stack.empty()) {
            if (root) {
                cout << root->getData() << " ";
                stack.push(root);
                root = root->getLeft();
            }
            else {
                root = stack.top();
                stack.pop();
                root = root->getRight();
            }
        }
    }
    
    void PostOrderTraversal_withoutRecursion(Node* root){
        if (root == NULL) {
            return;
        }
        
        stack<Node*> ST;
        
        while (root || !ST.empty()) {
            if (root) {
                if (root->getRight()) {
                    ST.push(root->getRight());
                    ST.push(root);
                    root = root->getLeft();
                }
                else {
                    ST.push(root);
                    root = root->getLeft();
                }
            }
            else {
                root = ST.top();
                ST.pop();
                
                Node* ref = ST.empty() ? NULL : ST.top();
                
                if (root->getRight() && root->getRight() == ref) {
                    ST.pop();
                    ST.push(root);
                    root = root->getRight();
                }
                else{
                    cout << root->getData() << " ";
                    root = NULL;
                }
            }
        }
    }
    
    /** 
     * In-order Traversal without recursion and without stack 
     * This algorithm uses property of Threaded Binary Tree
     * that each nodes right child is its In-order Successor.
     */
    void MorrisTraversal(Node* root){
        if (root == NULL) {
            return;
        }
        
        while (root != NULL) {
            if (root->getLeft() == NULL) {
                cout << root->getData() << " ";
                root = root->getRight();
            }
            else {
                //  Finding In order Predecssor of root.
                //  Which is rightmost child of left subtree of root.
                
                Node* predecessor = root->getLeft();
                while (predecessor->getRight() != NULL && predecessor->getRight() != root) {
                    predecessor = predecessor->getRight();
                }
                
                if (predecessor -> getRight() == NULL) {
                    predecessor->setRight(root);
                    root = root->getLeft();
                }
                
                else {
                    predecessor->setRight(NULL);
                    cout << root->getData() << " ";
                    root = root->getRight();
                }
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    BinarySearchTree tree;
    
    tree.CreateBST();
    tree.printBSTKeysInGivenRange(tree.getRoot(), 2, 7);
}

