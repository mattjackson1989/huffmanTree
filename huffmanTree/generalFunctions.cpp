#include "generalFunctions.h"
#include "buildTree.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#define MAX_LINE_LEN 4
using namespace std;

void readFromFile(HuffmanTree* tree, string infile, string outfileTree, string outfileBinary){
    // cout<<"Please select an option for file:\n1.) Basic Freq\n2.) Complex Freq"<<endl;

    if(infile == "NULL" || outfileTree == "NULL" || outfileBinary == "NULL")
    {
        infile = "complex_freq.txt";
        outfileBinary = "binaryTest.txt";
        outfileTree = "serializedTree.txt";
    }

    int userschoice = 1;
    //infile = "basic_freq.txt";
    //outfileBinary = "binaryTree.txt";
    //outfileTree = "serializedTree.txt";

    string line;
    char binaryArray[30];
    // small file ******************************************************************************
    if(userschoice == 1){
            char LINE[MAX_LINE_LEN]; // char array size = 4

            FILE* fp = fopen(infile.c_str(), "r");

            if(fp == NULL){
                cout<<"Cannot find file: basic_freq.txt"<<endl;
            }

            // char temp;
            // read in data from file and place in an array

           for(int i = 0; i < tree->size; i++){
                //tree->priorityQueue[n]->key = temp;
                fscanf(fp, " %c %d", tree->priorityQueue[i]->key, &tree->priorityQueue[i]->freq);
                binaryArray[i] = tree->priorityQueue[i]->key[0];
                fgets(LINE, MAX_LINE_LEN, fp);
           }
          fclose(fp);
    }else{
        cout<<"Option Unavailable"<<endl;
    }


    // sort list ******************************************************************************************************
    tree->sortList();

    tree->buildQueue(tree->pointer, 0); // this will pull the elements from the array and place them into a linked list

    tree->pointer = tree->head;
     //DEBUG
    cout<<"Freq: smallest to greatest. Character's alphabetical."<<endl;
    for(int n = 0; n < 30; n++){
        std::cout<<tree->pointer->key<<tree->pointer->freq<<endl;
        if(tree->pointer->next == NULL){
            break;
        }
        tree->pointer = tree->pointer->next;
    }

    tree->pointer = tree->head; // re-assign pointer to the head

    tree->combinedNode(tree->pointer, 0);

    cout<<"POINTER IS: "<<tree->pointer->key<<" "<<tree->pointer->freq<<endl;
    Node* myPointer  = tree->pointer;
//    string test;
//    cin>>test;

    string testing;
    ofstream out(outfileBinary.c_str());

    // find the binary values of each node character and port them to a file.
    for(int i = 0; i< tree->size; i++){
        tree->searchList(tree->pointer, binaryArray[i], testing, out, 2);
    }
    out.close();
    ofstream serialize(outfileTree.c_str());

    tree->pointer = tree->head;
    serializedTree(myPointer, serialize);
    serialize.close();
}
void serializedTree(Node* node, ofstream& out){

    if(node == NULL){

       out << "/";
        return;
    }

    cout<<node->key<<endl;

    out << node->key;
    serializedTree(node->left_child, out);
    serializedTree(node->right_child, out);

}
