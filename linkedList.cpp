#include <iostream>
using namespace std;

class Node
{
public:
    double data;
    Node* next;
};

class linkedList
{
public:
    linkedList();
    ~linkedList();
    bool isEmpty() { return head==NULL; };
    void diplayList();
    Node* addNewNode(int index, double value);
    int findNode(double value);
    int deleteNode(double value);
private:
    Node* head;
    int length;
};

linkedList::linkedList(){
    this->head = NULL;
    this->length = 0;
}

linkedList::~linkedList(){
    Node* next = head;
    Node* cur = NULL;
    while(next!=NULL){
        cur = next;
        next = next->next;
        delete cur;
    }
    cout << "linkedList deleted!" << endl;
}

void linkedList::diplayList(){
    Node* head = head;
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* linkedList::addNewNode(int index, double value){
    if(index<0) return NULL;
    
    int currIndex = 0;
    Node* currNode = head;
    while(currNode and currIndex!=index){
        currNode = currNode->next;
        currIndex++;
    }
    
    if(index>0 and currNode==NULL) return NULL;
    
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = currNode->next;
    currNode->next = newNode;
    return newNode;
}

int linkedList::findNode(double value){
    Node* currNode = head;
    int currIndex = 0;
    while(currNode and currNode->data!=value) {
        currNode = currNode->next;
        currIndex++;
    }
    return currIndex;
}

int linkedList::deleteNode(double value){
    Node* prevNode = NULL;
    Node* currNode = head;
    int currIndex = 0;
    while(currNode and currNode->data!=value){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if(currNode){
        if(prevNode){
            prevNode->next = currNode->next;
            delete currNode;
        }
    }
    return currIndex;
}

int main(int argc, const char * argv[]) {
    linkedList* list = new linkedList;
    list->addNewNode(2,5.0);
//    list->diplayList();
    return 0;
}
