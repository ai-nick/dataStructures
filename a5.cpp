#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BinTree {
    public:
    BinTree();
    ~BinTree();
    string getLeft(int node);
    string getRight(int node);
    void insert(int index, string val, string left, string right);
    int getSize();
    std::vector<string> treeArray;
    private:
    int treeSize;
    string rootNode;
};

BinTree::~BinTree(){
    
}
string BinTree::getLeft(int node){
    node++;
    try{ 
        string val = treeArray.at((node*2)-1);
        return treeArray.at((node*2)-1);
    } catch (const std::exception& e){
        return "";
}
}
string BinTree::getRight(int node){
    node++;
    try {
        treeArray.at((node*2));
        return treeArray.at((node*2));
    } catch (const std::exception& e){
        return "";
    }
}
int BinTree::getSize(){
    return this->treeSize;
}
BinTree::BinTree(){
    this->treeArray.resize(50);
    this->treeArray[0] = "";
    this->treeSize = 0;
}
void BinTree::insert(int index, string val, string side, string anime){
    int right = ((index+1)*2);
    int left = ((index+1)*2)-1;
    if (this->treeArray[0] == ""){
        this->treeArray[0] = val;
        this->treeArray[1] = "";
        this->treeArray[2] = "";
    } else {
        string temp = this->treeArray.at(index);
        this->treeArray.insert(this->treeArray.begin(), val);
        string tempLeft = this->getLeft(index);
        string tempRight = this->getRight(index);
        if (side == "no"){
            this->treeArray.insert(this->treeArray.begin()+left, anime);
            //this->treeArray.insert(this->treeArray.begin()+left, temp);
        } else if (side == "yes"){
            this->treeArray.insert(this->treeArray.begin()+right, anime);
            //this->treeArray.insert(this->treeArray.begin()+left, temp);
        }
    }
}
int askQuestion(int key, BinTree treeObj, bool leaf){
    string re;
    int left = ((key+1)*2);
    int right = ((key+1)*2)-1;
    if(leaf){
        cout <<"is it "+treeObj.treeArray[key]+"?" << endl;
        cin >> re;
        if (re == "no"){
            cin.ignore();
            string newCharacter;
            string newQuestion;
            string newAnswer;
            cout << "What is the character's name" << endl;
            getline(cin, newCharacter); 
            cout << "what would distinguish "<<newCharacter<<" from "<<treeObj.treeArray[key]<<endl;
            std::getline (std::cin,newQuestion);
            cout <<"how would "<<newCharacter<<" answer this question (yes or no)?"<<endl;
            std::getline(cin, newAnswer);
            treeObj.insert(0,newQuestion,newAnswer,newCharacter);
            askQuestion(0, treeObj,false);
        }
    } else {
        cout<<treeObj.treeArray[key]<<endl;
        getline(cin, re);
        if (re == "no"){
            if(treeObj.getRight(right) == "" or treeObj.getLeft(right) == ""){
                askQuestion(right, treeObj, true);
            } else {
                askQuestion(right, treeObj, false);
            }
        } else {
            if(treeObj.getRight(left) == "" or treeObj.getLeft(left) == ""){
                askQuestion(left, treeObj, true);
            } else {
                askQuestion(left, treeObj, false);
            }
        }
    }
    return key+1;
}
int main(void){
    BinTree tree = BinTree();
    tree.insert(0, "deadpool","","");
    string choices = "(yes/no)";
    string firstQuest = "are you thinking of a character?";
    string response;
    cout << firstQuest << endl;
    cin >> response;
    if (response == "yes"){
        cout << "lets begin" << endl;
        int index = 0;
        askQuestion(0, tree,true);
        //cout<< tree.treeArray.at(0) << endl;
    } else {
        cout << "okay byebye now" << endl;
    }
    return 0;
}
