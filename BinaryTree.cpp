#include <iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* left, *right;
     Node(int n){
         data = n;
         left = right = NULL;
     }
};

void PrintInorder(Node* node){
    // ?? Function to print node inorderly which is left, root, right
    if(node == NULL){
        return;
    }else{
        //?? Print Left first
        PrintInorder(node->left);

        //?? Print the data of the node
        cout << node->data << " ";

        //?? Finally print the right of the node
        PrintInorder(node->right);
    }
}

void PrintPostorder(Node* node){
    // ?? Function to print node postorderly which is left, right, root
    if(node == NULL){
        return;
    }else{
        //?? Print Left first
        PrintPostorder(node->left);

        //?? Seccond print the right of the node
        PrintPostorder(node->right);

        //?? Finally Print the data of the node
        cout << node->data << " ";
    }
}

void PrintPreorder(Node* node){
    // ?? Function to print node preorderly which is root, left, right
    if(node == NULL){
        return;
    }else{
        //?? Firtly Print the data of the node
        cout << node->data << " ";

        //?? Seccond Print Left
        PrintPostorder(node->left);

        //?? Third print the right of the node
        PrintPostorder(node->right);
    }
}

int main(){
    Node* head = NULL;
    Node* seccond = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;

    head = new Node(1);
    seccond = new Node(2);
    third = new Node(3);
    fourth = new Node(4);
    fifth = new Node(5);

    head->left = seccond;
    head->right = third;

    seccond->left = fourth;
    seccond->right = fifth;

    cout << "Print Inorderly : ";
    PrintInorder(head);
    cout << endl;

    cout << "Print Postorderly : ";
    PrintPostorder(head);
    cout << endl;

    cout << "Print Preorderly : ";
    PrintPreorder(head);
    cout << endl;
}
