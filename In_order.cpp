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
void inOrderTraversal(Node* root){
    if(root == nullptr) return;

    inOrderTraversal(root->left);       //visit left subtree
    cout<<root->data<<" ";              //print the node's value
    inOrderTraversal(root->right);      //visit right subtree
}

int main(){
    Node* root = nullptr;   //start with an empty tree

    int s;
    cout<<"Enter total number of value you want to add :";
    cin>>s;
    for(int i=1; i<=s; i++){
        //Insert nodes into the BST
        cout<<"Enter number  : ";
        cin>>i;
        root = insert(root, i);
    }


    //Display the BST in In-Order traversal
    cout<<"In-order traversal of the BST: ";
    inOrderTraversal(root);

    return 0;
}