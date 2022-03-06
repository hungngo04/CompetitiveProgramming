//
//  main.cpp
//  Binary Search Tree Implement
//
//  Created by Tien Hung
//

#include <iostream>
#include <vector>
using namespace std;

class BST {
    
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    Node* MakeEmpty(Node* p){
        if(p == NULL)
            return p;
        else{
            MakeEmpty(p->left);
            MakeEmpty(p->right);
            delete p;
        }
        return NULL;
    }
    
    Node* Insert(int x, Node* p){
        if(p == NULL){
            p = new Node;
            p->data = x;
            p->left = p->right = NULL;
        }
        else if(x <= p->data)
            Insert(x, p->left);
        else if(x > p->data)
            Insert(x, p->right);
        return p;
    }
    
    Node* findMin(Node* p){
        if(p == NULL)
            return NULL;
        else if(p->left == NULL)
            return p;
        else
            return findMin(p->left);
    }
    
    Node* FindMax(Node* p){
        if(p == NULL)
            return NULL;
        else if(p->right == NULL)
            return p;
        else
            return FindMax(p->right);
    }
    
    Node* Remove(int x, Node* p){
        Node* temp;
        if(p == NULL)
            return NULL;
        else if(x < p->data)
            p->left = Remove(x, p->left);
        else if(x > p->data)
            p->right = Remove(x, p->right);
        else if(p->left && p->right){
            temp = findMin(p->right);
            p->data = temp->data;
            p->right = Remove(p->data, p->right);
        }
        else{
            temp = p;
            if(p->left == NULL)
                p = p->right;
            else if(p->right == NULL)
                p = p->left;
            delete temp;
        }
        return p;
    }

    void Inorder(Node* p){
        if(p == NULL)
            return;
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }

    Node* Find(Node* p, int x){
        if(p == NULL)
            return NULL;
        else if(x < p->data)
            return Find(p->left, x);
        else if(x > p->data)
            return Find(p->right, x);
        else
            return p;
    }
    
};

int main(int argc, const char * argv[]) {
    return 0;
}
