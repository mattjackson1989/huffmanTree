#ifndef GENERALFUNCTIONS_H_INCLUDED
#define GENERALFUNCTIONS_H_INCLUDED
#include "buildTree.h"
#include <fstream>
void readFromFile(HuffmanTree*);
void serializedTree(Node*, std::ofstream&);

#endif // GENERALFUNCTIONS_H_INCLUDED
