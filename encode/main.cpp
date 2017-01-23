#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
// Globals
int searchArray(char); // returns index
const int SIZE = 30;
char keyArray[30];
string freqArray[30];

// prototypes
void readFromFileFreq(string[]);
void readMessageFile();
void extractData(string[30]);
void encodeMessage(string);
void findSize();


int main(int argc, char* argv[])
{
    string messageFile = "NULL";
    if(argc == 2){
            cout<<"Main Arguements are accepted."<<endl;
        messageFile = argv[1];
    }else{ // default
        messageFile = "complex_message.txt";
    }
    string binaryArray[SIZE]; // for basic

    readFromFileFreq(binaryArray);
    extractData(binaryArray);
    encodeMessage(messageFile);


}
void readFromFileFreq(string binArray[SIZE]){
    string line;
    ifstream freqIn("binaryTest.txt");
    if(freqIn.is_open()){
        int i = 0;
        while(getline(freqIn, line)){
            binArray[i] = line;
            i++;
        }
    }else{
        cout<<"Could not find file!"<<endl;
    }
    freqIn.close();

}
void extractData(string lineData[SIZE]){
    int strLength;
    for(int i = 0; i < SIZE; i++){
        keyArray[i] = lineData[i][0];
        strLength = lineData[i].length();
        freqArray[i] = lineData[i].substr(2, strLength);
    }
}
void encodeMessage(string messageFile){

    ifstream message(messageFile.c_str());
    if(message.is_open() == true){
        //count file lines
        string testLine;
        int counter = 0;
        for (int i = 0; getline(message, testLine); ++i){
            counter++;
        }
        message.clear();
        message.seekg(0, ios::beg);
        //end file count
        string messageLineArray[counter];
        int i = 0;
        string line;
        while(getline(message, line)){
            messageLineArray[i] = line;
            messageLineArray[i] += '\n';
            i++;
        }
        int messageLength = messageLineArray[counter - 1].length();
        //remove newline from the last message line in array
        if(messageLineArray[counter - 1][messageLength - 1] == '\n'){
            messageLineArray[counter - 1][messageLength - 1] = '\0';
        }

        int lineLength;
        // search charArray for index
        int index; // used to store the index

        ofstream out("encodedMessage.txt");
        for(int j = 0; j < counter; j++){

            lineLength = messageLineArray[j].length();

            for(int i = 0; i < lineLength; i++){
                index = searchArray(messageLineArray[j][i]);
                //cout<<messageLineArray[0][i]<<endl;
                cout<<freqArray[index]<<endl;
                out<<freqArray[index];
            }

        }
        message.close();
    }else{
        cout<<"Could not find file!"<<endl;
    }
}
int searchArray(char myChar){
    for(int i = 0; i < SIZE; i++){
        // cout<<myChar<<endl;
        if(myChar == ' '){
            // cout<<"Searching for space"<<endl;
            int spaceIndex = searchArray('-');
            return spaceIndex;
        }
        if(keyArray[i] == myChar){
            // cout<<keyArray[i]<<endl;
            // cout<<"Found it"<<endl;
            return i;
        }
        if(myChar == '\n'){
            cout<<"Searching for new line"<<endl;
            int newLineIndex = searchArray('!');
            return newLineIndex;
        }
    }
    return 0;
}
void findSize(){
    string line;
    ifstream countLines("binaryTest.txt");
    int SIZE = 0;;
    for (int i = 0; getline(countLines, line); ++i){
        SIZE++;
    }
    countLines.close();

}
