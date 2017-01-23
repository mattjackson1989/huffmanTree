#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


class Node
{
    public:
    Node(char tempkey){
        key = tempkey;
        left = NULL;
        right = NULL;
    }
    char key;
    Node* left, *right;
};

/* Helper function that allocates a new Node with the
   given key and NULL left and right pointers. */

class HuffmanTree{
    public:
        Node* root;

};

void rebuildTree(Node*);
void pullFromFile();
void inorder(Node*);
void writeToFile(Node*, ofstream&);
void binaryFileRetrieve();

int treeCounter = 0;
int binaryCounter = 0;
char treeStructure[119];
string encodedMessage;

int main(int argc, char* argv[])
{
    string messageFile;
    if(argc == 2){
        messageFile = argv[2];
    }else{
        messageFile = "complex_message.txt";
    }
    pullFromFile();

    HuffmanTree* newTree = new HuffmanTree();
    Node* start = new Node('\0');
    newTree->root = start;
    rebuildTree(start);
    Node* pointer = start;
    //read from file for binary line
    binaryFileRetrieve(); // fills the encodedMessage string
    int encodeSize = encodedMessage.length();
    bool valid = true;
    ofstream out("decodedMessage.txt");

    if(out.is_open()){
            while(valid){
                    if(binaryCounter >= encodeSize - 2){
                        valid = false;
                        break;
                    }
                pointer = start;
                writeToFile(pointer, out);
                cout<<binaryCounter<<endl;
//                string test;
//                cin>>test;
                //binaryCounter
            }
    }else{
        cout<<"Cannot find file"<<endl;
    }
    out.close();
    return 0;
}
void pullFromFile(){
    FILE* fp;
    fp = fopen("serializedTree.txt", "r");
    int i = 0;
    int counter = 0;
    while((treeStructure[i] = getc(fp)) != EOF){
            //cout<<treeStructure[i]<<endl;
            i++;
            counter++;
    }
    //cout<<counter<<endl;
    fclose(fp);
}
void rebuildTree(Node *root){
    //cout<<treeCounter<<endl;
    if(treeCounter > 119){

        return;
    }
    if(treeStructure[treeCounter] == '/'){
        root->left = NULL;
        root->right = NULL;
        ++treeCounter;
        return;
    }

        root->key = treeStructure[treeCounter];
        ++treeCounter;
        root->left = new Node('\0');
        rebuildTree(root->left);

        root->right = new Node('\0');
        rebuildTree(root->right);
}
void binaryFileRetrieve(){
    ifstream file("encodedMessage.txt");
    if(file.is_open()){
            while(getline(file, encodedMessage));
        file.close();
    }
            //cout<<encodedMessage<<endl;

}
void writeToFile(Node* node, ofstream& out){
//    for(int i = 0; i < 30; i++){
//        encodedMessage[i];
//    }
//    int test;
//    cin>>test;
    cout<<"KEY: "<<node->key<<endl;
    //cout<<binaryCounter<<endl;
//    cout<<"LEFT KEY: "<<node->left->key<<endl;
//    cout<<"RIGHT KEY: "<<node->right->key<<endl;
    // if this is a leaf node print the character
    if(node->right->key == NULL && node->left->key == NULL){
            cout<<"Writing to file"<<endl;
            if(node->key == '-'){ // for spaces
                out<< ' ';
                return;
            }
            if(node->key == '!'){ // for spaces
                out<< '\n';
                return;
            }

            out << node->key;
            //++binaryCounter;
            return;
    }
    if(encodedMessage[binaryCounter] == '0'){
        cout<<"LEFT:"<<endl;
            ++binaryCounter;
            writeToFile(node->left, out);
            return;
            cout<<"Return from recursion "<<binaryCounter<<endl;
    }
    if(encodedMessage[binaryCounter] == '1'){
        cout<<"RIGHT:"<<endl;
            ++binaryCounter;
            writeToFile(node->right, out);
            return; // need to reset the head of the tree
            cout<<"Return from recursion "<<binaryCounter<<endl;
    }

    return;
}
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->key;
        inorder(root->right);
    }
}
