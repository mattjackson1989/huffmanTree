// TODO: Sort is complete. Now need to build tree from array

#include <iostream>
#include <stdio.h>
#include "buildTree.h"
#include "generalFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
//    FILE* fp = fopen("basic_freq.txt", "r"); // default
//    if(argc <=1 && fp == NULL){
//        cout<<"Not enough inputs try again"<<endl;
//        return 1;
//    }
//    fclose(fp);
    string myString1 = "NULL";
    string myString2 = "NULL";
    string myString3 = "NULL";
    if(argc == 3){
        myString1 = argv[1];
        myString2 = argv[2];
        myString3 = argv[3];

    }
    else{
        cout<<"There is not an appropriate argument count\nUsing default files"<<endl;
    }

    HuffmanTree* newTree = new HuffmanTree();
    readFromFile(newTree, myString1, myString2, myString3);
    cout<<"Tree building complete"<<endl;
    return 0;
}
