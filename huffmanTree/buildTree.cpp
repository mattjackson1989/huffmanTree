#include "buildTree.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>

#define MAX_LINE_LEN 4
using namespace std;
// Array of nodes that must be sorted first
void HuffmanTree::sortList(){
    Node* temp;
    for(int i = 0; i < this->size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(this->priorityQueue[j]->freq > this->priorityQueue[j + 1]->freq){
                temp = priorityQueue[j];
                this->priorityQueue[j] = this->priorityQueue[j+1];
                this->priorityQueue[j + 1] = temp;
            }// if frequencies are equal but have different keys...sort based on alphabetical order and special characters go last
            else if(this->priorityQueue[j]->freq == this->priorityQueue[j + 1]->freq){
                if(strcmp(priorityQueue[j]->key, priorityQueue[j+1]->key) > 0){
                    temp = priorityQueue[j];
                    this->priorityQueue[j] = this->priorityQueue[j+1];
                    this->priorityQueue[j + 1] = temp;
                }
            }
        }
    }
    //cout<<"Priority Queue last node: "<<this->priorityQueue[size-1]->freq<<endl;
    this->priorityQueue[size - 1]->next = NULL;
}
void HuffmanTree::combinedNode(Node* p, int counter){
    cout<<"COMBINED NODE:"<<endl;
    cout<<"Current node is: "<<p->freq<<" "<<p->key<<endl;
    if(p->next->freq <= 0){
            pointer = p;
        // assign "root" status to the new node for the tree
        cout<<"Finished building tree"<<endl;

        return;
    }
    char integer_string[32];
    // make a new node, have left child be the 1st element in array, have right child be the 2nd element in array. then assign new nodes NEXT pointer to the pointers next next
    Node* parentNode = new Node();

    parentNode->left_child = p; // smallest
    parentNode->right_child = p->next; // largest

    // Append the key to be $ + counter
    sprintf(integer_string, "%d", counter);
    parentNode->key[0] = '$';
    //strcat(parentNode->key, integer_string);
    // Give the frequency
    cout<<"Adding "<<parentNode->left_child->freq<<" + "<<parentNode->right_child->freq<<endl;
    parentNode->freq = parentNode->left_child->freq + parentNode->right_child->freq;
    parentNode->next = parentNode->right_child->next;
    cout<<"Parent frequency: "<<parentNode->freq<<" "<<"Parent Key: "<<parentNode->key<<endl;
    cout<<"Child_LEFT of Parent: "<<parentNode->left_child->freq<<" "<<"Child_RIGHT of Parent: "<<parentNode->right_child->freq<<endl;
    p = parentNode; // connect pointer to the newly created parentNode
    cout<<"Sending "<<p->freq<<p->key<<endl;
    cout<<"Next node to this node: "<<p->next->freq<<" "<<p->next->key<<endl;
//    string test;
//    cin>>test;
    // Now we sort
    if(sortQueue(p, true) == true){
        p = pointer;
    }
    //cin>>test;
    //cout<<"Current pointer is: "<<p->freq<<p->key<<endl;
    counter++;
    combinedNode(p, counter);


}
bool HuffmanTree::sortQueue(Node* node, bool firstSwap){
    bool swapped;
    if(node->next == NULL){
            pointer = node;
        return false;
    }

    if(node->freq >= node->next->freq && node->next->freq != 0){

        char tempKey[2];
        if(firstSwap){
            pointer = node;
            firstSwap = false;
        }
        strcpy(tempKey, node->key);

        // tempKey= node->key;
        int tempNodeFreq = node->freq;

        // swap contents between nodes
        strcpy(node->key, node->next->key);
        // node->key = node->next->key;
        node->freq = node->next->freq;
        strcpy(node->next->key, tempKey);
        // node->next->key = tempKey;
        node->next->freq = tempNodeFreq;

        // exchange children

        Node* tempR = node->right_child;
        Node* tempL = node->left_child;

        if(!node->next->right_child && !node->next->left_child){
            node->right_child = NULL;
            node->left_child = NULL;

        }else{
            node->right_child = node->next->right_child;
            node->left_child = node->next->left_child;
        }
        node->next->left_child = tempR;
        node->next->right_child = tempL;

        sortQueue(node->next, false);
        return true;
        //pointer->next = secondPointer;

    }else{
        return false; // no swap occurred
    }
}
// Build queue from the priorityQueue array -- COMPLETE
void HuffmanTree::buildQueue(Node* p, int n){
    if(n > size - 1){
        return;
    }
    if(n == 0){
            p = priorityQueue[0];
            p->parent = NULL;
            head = p;
            p->next = priorityQueue[n + 1];
            cout<<p->key<<endl;
            //cout<<p->key<<" "<<p->freq<<endl;

        }
    else{
            p->next = priorityQueue[n + 1];

            //cout<<p->key<<" "<<p->freq<<endl;
    }
        n++;
        buildQueue(p->next, n);

}
// get binary code
void HuffmanTree::searchList(Node* p, char temp, string binary, ofstream& out, int flag){
    cout<<temp<<endl;
    p->key[0];

    if(temp == p->key[0]){
        cout<<"Found it!"<<endl;
//        if(temp == 'g'){
//            //binary += "0";
//        }
//        if(flag == 0){
//            binary += "0";
//        }
//        if(flag == 1){
//            binary += 1;
//        }
        p->binary = binary;
        out <<p->key<<" "<<p->binary <<endl;

        return;
    }
    if(p->right_child != NULL){
        binary += "1";
        searchList(p->right_child, temp, binary, out, 1);
        binary.erase( binary.size() - 1 );
    }
    if(p->left_child != NULL){
        binary += "0";
        searchList(p->left_child, temp, binary, out, 0);
        binary.erase( binary.size() - 1 );
    }

    return;
}
