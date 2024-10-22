#include<iostream>
using namespace std;
struct Node{
    int data;       //Data to store key
    Node* left;     //Pointer to the left child
    Node* right;    //Pointer to the right child
};

//Function to create a new node
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the Binary Search Tree
Node* insert(Node* root,int value){
    // If the tree is empty, return a new Node
    if (root == nullptr){
        return createNode(value);
    }
    //otherwise, recur down the tree
    if (value< root->data){
        //Insert in the left subtree
        root->left = insert(root->left, value);
    } else if (value> root->data){
        // Insert in the right subtree
        root->right = insert(root->right,value);
    }
    //Return the unchanged root pointer
    return root;
}
//Funtion to perfotm in-order traversal
void postOrderTraversal(Node* root){
    if(root == nullptr) return;

    postOrderTraversal(root->left);       //visit left subtree
    postOrderTraversal(root->right);      //visit right subtree
    cout<<root->data<<" ";              //print the node's value
}

int main(){
    Node* root = nullptr;   //start with an empty tree

    //Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    //Display the BST in In-Order traversal
    cout<<"In-order traversal of the BST: ";
    postOrderTraversal(root);

    return 0;
}