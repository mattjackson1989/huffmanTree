// TODO: Sort is complete. Now need to build tree from array

#include <iostream>
#include "buildTree.h"
#include "generalFunctions.h"

using namespace std;

int main()
{

    HuffmanTree* newTree = new HuffmanTree();
    readFromFile(newTree);

    return 0;
}
