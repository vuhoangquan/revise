/*
 imported from snippet - may not be newest updated version
 imported on 20/9/2020
 */

#ifndef H_nodeBST
#define H_nodeBST
//---------------------------------------------------
#include<iostream>
using namespace std;
//---------------------------------------------------
template <class elemType>
struct nodeType {
    elemType info;
    nodeType<elemType>* lLink;
    nodeType<elemType>* rLink;
    int numberNo=0;
};
template <class elemType>
class nodeBST {
public:
    nodeBST();
    ~nodeBST();
    bool search(const elemType& searchItem)const;
    void insert(const elemType& insertItem);
    void deleteNode(const elemType& deleteItem);
    bool isEmpty()const;
    void inorderTraversal()const;
    void inOrderIterative();
    void BST_to_inOrder(int* int_array);
    void preorderTraversal()const;
    void postorderTraversal()const;
    void destroy(nodeType<elemType>*& p);
    nodeType<elemType> getRoot()const;
    /*
     //not needed - mistake
     bool operator==(const elemType&, const elemType&);
     bool operator<(const elemType&, const elemType&);
     */
    void addToIntAraay(int* arrayptr);
    nodeType<elemType>* sortedArrayToBST(int nums[], int nums_size);
private:
    void inorder(nodeType<elemType>* p)const;
    void preorder(nodeType<elemType>* p)const;
    void postorder(nodeType<elemType>* p)const;
    
    void inorderToArray(int* intarray,nodeType<elemType>* p);

    nodeType<elemType>* root;
    int counter=0;
    nodeType<elemType>* helper(int nums[], int low, int high);
};
//---------------------------------------------------
//---------------------------------------------------
//implementation
/*
 //not needed - mistake
 template <class elemType>
 bool nodeBST<elemType>::operator==(elemType& leftHS, elemType& rightHS)
 {
 return (strcmp(leftHS.info, rightHS) == 0);
 }
 template <class elemType>
 bool nodeBST<elemType>::operator<(elemType& leftHS, elemType& rightHS)
 {
 return (strcmp(leftHS.info, rightHS) < 0);
 }
 */
template <class elemType>
nodeBST<elemType>::nodeBST() {
    root = NULL;
}
template <class elemType>
nodeBST<elemType>::~nodeBST() {
    destroy(root);
}
template <class elemType>
void nodeBST<elemType>::insert(const elemType& insertItem) {
    nodeType<elemType>* current;
    nodeType<elemType>* trailCurrent = NULL;
    nodeType<elemType>* newNode;
    newNode = new nodeType<elemType>;//invoke default construct
    newNode->info = insertItem;
    newNode->numberNo=counter;
    newNode->lLink = NULL;
    newNode->rLink = NULL;
    if (root == NULL)
        root = newNode;
    else {
        current = root;
        while (current != NULL) {
            trailCurrent = current;
            if (insertItem == current->info) {//compare struct
                /*cout << "dupplicate are not allowed"
                 << "value: " << insertItem << endl;*/
                return;
            }
            else
                if (insertItem < current->info)//compare string
                    current = current->lLink;
                else
                    current = current->rLink;
        }//end while
        if (insertItem < trailCurrent->info)//compare string
            trailCurrent->lLink = newNode;
        else
            trailCurrent->rLink = newNode;
    }
    counter++;
}
template <class elemType>
bool nodeBST<elemType>::search(const elemType& searchItem)const {
    nodeType<elemType>* current;
    bool found = false;
    if (root == NULL)
        cout << "cannot search empty tree" << endl;
    else {
        current = root;
        while (current != NULL && !found) {
            if (searchItem == current->info)
                found = true;
            else if (searchItem < current->info)
                current = current->lLink;
            else
                current = current->rLink;
        }
    }
    return found;
}
template <class elemType>
void nodeBST<elemType>::deleteNode(const elemType& deleteItem) {
    nodeType<elemType>* current;
    current = root;
    if (root == NULL) {
        cout << "empty node " << endl;
    }
    else {
        while (current != NULL) {
            if (deleteItem == current->info)
                current->info = NULL;
            else if (deleteItem < current->info)
                current = current->lLink;
            else
                current = current->rLink;
            
        }
        
    }
}
template <class elemType>
bool nodeBST<elemType>::isEmpty() const {
    return (root == NULL);
}

template <class elemType>
void nodeBST<elemType>::preorderTraversal() const {
    preorder(root);
}
template <class elemType>
void nodeBST<elemType>::inorderTraversal()const {
    inorder(root);
}
template <class elemType>
void nodeBST<elemType>::postorderTraversal()const {
    postorder(root);
}
template <class elemType>
void nodeBST<elemType>::preorder(nodeType<elemType>* p)const {
    if (p != NULL) {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}
template <class elemType>
void nodeBST<elemType>::inorder(nodeType<elemType>* p)const {
    if (p != NULL) {
        inorder(p->lLink);
        cout << p->info << " ";
        cout << p->numberNo << "\n";
        inorder(p->rLink);
    }
}
/* Iterative function for inorder tree traversal */
template <class elemType>
void nodeBST<elemType>::inOrderIterative()
{
    stack<nodeType<elemType> *> s;
    nodeType<elemType> *curr = root;
  
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->lLink;
        }
  
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
        cout << curr->info << " ";
  
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->rLink;
  
    } /* end of while */
}
//output this BST to a prealloc size array
//param: prealloc sized array
//modified inorder tree traversal - above
template <class elemType>
void nodeBST<elemType>::BST_to_inOrder(int * int_array)
{
    stack<nodeType<elemType> *> s;
    nodeType<elemType> *curr = root;
  
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->lLink;
        }
        curr = s.top();
        s.pop();
        
        *int_array = curr->info;//cout << curr->info << " ";
        int_array++;
        
        curr = curr->rLink;
    }
}
template <class elemType>
void nodeBST<elemType>::postorder(nodeType<elemType>* p)const {
    if (p != NULL) {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//pointer arithmatic is bad -> onenote/github-revise to see more
template<class elemType>
void nodeBST<elemType>::addToIntAraay(int* intarray){
    inorderToArray(intarray, root);
}

template <class elemType>
void nodeBST<elemType>::inorderToArray(int* intarray, nodeType<elemType>* p) {
    if (p != NULL) {
        inorderToArray(intarray, p->lLink);
        *intarray = p->info;
         p->numberNo = counter;

        cout<<" counter ="<<counter<<":"<<" number ="<< p->numberNo<<" ";
        cout << *intarray << " "<<intarray<<endl;

        intarray++;
        counter++;
        inorderToArray(intarray, p->rLink);
    }
}

template <class elemType>
nodeType<elemType>* nodeBST<elemType>::sortedArrayToBST(int nums[], int nums_size) {
   return helper(nums, 0, nums_size - 1);
}

template <class elemType>
nodeType<elemType>* nodeBST<elemType>::helper(int nums[], int low, int high){
    if(low > high) {
        return NULL;
    }
    int mid = low + (high - low)/2;
    //center val of sorted array as the root of the bst
    nodeType<elemType>* head;
    head = new nodeType<elemType>;
    head->info = nums[mid];
    head->lLink = NULL;
    head->rLink = NULL;
    if(root==NULL){root=head;}
    //left of the mid value should go to the left of this root node to satisfy bst
    head->lLink = helper(nums, low, mid - 1);
    //right of the mid value should go to the right of this root node to satisfy bst
    head->rLink = helper(nums, mid + 1, high);
    return head;
    
}
//----------------------------------------------------------------
/*code above referenced(C++) from leetcode:
 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/856976/clean-c%2B%2B-solution
 
 TreeNode* sortedArrayToBST(vector<int>& nums) {
    return addNode(nums, 0, nums.size() - 1);
}
TreeNode* addNode(vector<int>& nums, int l, int r) {
    if (l > r) return NULL;
    int mid = (r-l)/2 + l;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = addNode(nums, l, mid-1);
    root->right = addNode(nums, mid+1, r);
    return root;
 
 and referenced (Java) from medium: https://medium.com/@harycane/convert-sorted-array-to-bst-35781e940ca5
 
 class Solution {
     public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.length - 1);
     }
     
     private TreeNode helper(int[] nums, int low, int high) {
         if(low > high) {
             return null;
         }
         int mid = low + (high - low)/2;
         //center val of sorted array as the root of the bst
         TreeNode head = new TreeNode(nums[mid]);
         //left of the mid value should go to the left of this root node to satisfy bst
         head.left = helper(nums, low, mid - 1);
         //right of the mid value should go to the right of this root node to satisfy bst
         head.right = helper(nums, mid + 1, high);
         return head;
     }
     //T O(log n) S O(n) recursion stack space
 }
}*/
//----------------------------------------------------------------


template <class elemType>
void nodeBST<elemType>::destroy(nodeType<elemType>*& p) {
    if (p != NULL) {
        destroy(p->lLink);
        destroy(p->rLink);
        p = NULL;
        delete p;
    }
}
template <class elemType>
nodeType<elemType> nodeBST<elemType>::getRoot() const {
    return *root;
}
#endif //nodeBST_H


