#ifndef BUILDTREE_H_INCLUDED
#define BUILDTREE_H_INCLUDED
#define SIMPLE_SIZE 30
#include <iostream>
#include <fstream>>
class Node{
    public:
    char key[2];
    int freq;
    std::string binary;
    Node* next;
    Node* parent;

    Node* left_child = NULL;
    Node* right_child = NULL;

};
class HuffmanTree{
    public:
    Node* priorityQueue[SIMPLE_SIZE];
    Node* pointer; // pointer used to traverse list
    Node* secondPointer;
    Node* root; // always points to front of list
    Node* head;

    int size; // size of list :: When size is <= 2, tree is created

    //constructor-choose the type of tree you wish to build 0 for small size 1 for large size
    HuffmanTree(){
        std::cout<<"Simple tree or complex (0 or 1)?"<<std::endl;
        int answer;

        std::cin>>answer;
        // fill priority queue with new new nodes
        if(answer == 0){
            this->size = SIMPLE_SIZE;
            for(int i = 0; i < SIMPLE_SIZE; i++){
                this->priorityQueue[i] = new Node();
                this->priorityQueue[i]->binary = "";
            }
        }else if(answer == 1){

        }

    }
    void searchList(Node*, char, std::string, std::ofstream&, int);
    void buildQueue(Node*, int);
    bool sortQueue(Node*, bool);
    void combinedNode(Node*, int);
    void sortList(); // FINISHED - BUBLE SORT

};


#endif // BUILDTREE_H_INCLUDED
