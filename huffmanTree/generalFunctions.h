#ifndef GENERALFUNCTIONS_H_INCLUDED
#define GENERALFUNCTIONS_H_INCLUDED
#include "buildTree.h"
#include <fstream>
void readFromFile(HuffmanTree*, std::string, std::string, std::string);
void serializedTree(Node*, std::ofstream&);

#endif // GENERALFUNCTIONS_H_INCLUDED
