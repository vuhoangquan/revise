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
private:
    void inorder(nodeType<elemType>* p)const;
    void preorder(nodeType<elemType>* p)const;
    void postorder(nodeType<elemType>* p)const;
    
    void inorderToArray(int* intarray,nodeType<elemType>* p);

    nodeType<elemType>* root;
    int counter=0;
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
        inorder(p->rLink);
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

        intarray= intarray + p->numberNo;
        counter++;
        inorderToArray(intarray, p->rLink);
    }
}


template <class elemType>
void nodeBST<elemType>::destroy(nodeType<elemType>*& p) {
    if (p != NULL) {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
        
    }
}
template <class elemType>
nodeType<elemType> nodeBST<elemType>::getRoot() const {
    return *root;
}
#endif //nodeBST_H


