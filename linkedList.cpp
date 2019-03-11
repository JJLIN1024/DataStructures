#include <iostream>
using namespace std;

class listNode
{

private:
    int data;
    listNode* next;
public:
    listNode(){data = 0;}
    listNode(int n){data = n;}
    friend class linkedList;
};

class linkedList
{
public:
    linkedList();
    ~linkedList();
    bool isEmpty() { return head==NULL; };
    void printList();
    void pushFront(int value);
    void pushBack(int value);
    listNode* insertNode(int index, int value);
    int findNode(int value);
    int deleteNode(int value);
private:
    listNode* head;
};

linkedList::linkedList(){
    this->head = NULL;
}

linkedList::~linkedList(){
    listNode* next = head;
    listNode* cur = NULL;
    while(next!=NULL){
        cur = next;
        next = next->next;
        delete cur;
    }
    cout << "linkedList deleted!" << endl;
}

void linkedList::printList(){
    
    if (head == NULL){
        cout << "The list is empty!" << endl;
        return;
    }
    listNode* currNode = head;
    while(currNode){
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << "\n";
}
void linkedList::pushFront(int value){
    listNode* newNode = new listNode(value);
    newNode->next = head;
    head = newNode;
}

void linkedList::pushBack(int value){
    listNode* newNode = new listNode(value);
    if (head==NULL){
        head = newNode;
        return;
    }
    listNode* currNode = head;
    while(currNode and currNode->next){
        currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
}
listNode* linkedList::insertNode(int index, int value){
    if(index<0) return NULL;
    int currIndex = 0;
    listNode* currNode = head;
    while(currNode and currIndex!=index){
        currNode = currNode->next;
        currIndex++;
    }
    
    if(index>0 and currNode==NULL) return NULL;
    
    listNode* newNode = new listNode;
    newNode->data = value;
    
    if (index==0){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return newNode;
}

int linkedList::findNode(int value){
    listNode* currNode = head;
    int currIndex = 0;
    while(currNode and currNode->data!=value) {
        currNode = currNode->next;
        currIndex++;
    }
    cout << "Node " << value << " is at index: " << currIndex << endl;
    return currIndex;
}

int linkedList::deleteNode(int value){
    listNode* prevNode = NULL;
    listNode* currNode = head;
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
        else{
            head = currNode->next;
            delete currNode;
        }
    }
    return currIndex;
}

int main(int argc, const char * argv[]) {
    linkedList* list = new linkedList;
    list->printList();
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    list->pushBack(7);
    list->insertNode(0, 3);
    list->printList();
    list->findNode(7);
    list->deleteNode(3);
    list->printList();
    return 0;
}
