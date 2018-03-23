//
//  BSTree.h
//  DSAssignment
//
//  Created by Jelani on 23/03/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h

using namespace std;

class BinarySearchNode {
private:
    int ID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
public:
    BinarySearchNode* Left;
    BinarySearchNode* Right;
    
    // Constructors
    BinarySearchNode() {ID = 0; fName = lName = destination = season = booking = ""; Right = Left = NULL;}
    BinarySearchNode(int id, string first, string last, string dest, string sea, string book);
    
    // Mutators
    void setID ( int id ) {ID = id;}
    void setFName(string first ) {fName = first;}
    void setLName(string last ) {lName = last;}
    void setDestination(string dest ) {destination = dest;}
    void setSeason(string sea ) {season = sea;}
    void setBooking(string book ) {booking = book;}
    
    // Accessors
    int getID() {return ID;}
    string getFName() {return fName;}
    string getLName() {return lName;}
    string getDestination() {return destination;}
    string getSeason() {return season;}
    string getBooking() {return booking;}
    
}; //End of Definitions
BinarySearchNode::BinarySearchNode(int id, string first, string last, string dest, string sea, string book) {
    ID = id;
    fName = first;
    lName = last;
    destination = dest;
    season = sea;
    booking = book;
}

class BSTree {
private:
    BinarySearchNode* root;
    
    BinarySearchNode* insertHelper(BinarySearchNode*, int, string, string, string, string, string);
    BinarySearchNode* deleteNode(BinarySearchNode*, int);
    string inOrderHelper(BinarySearchNode*);
    string preOrderHelper(BinarySearchNode*);
    string postOrderHelper(BinarySearchNode*);
    
    
public:
    BSTree() {root = NULL;}
    
    ~BSTree() {root = NULL;}
    
    // Mutators
    void insert(int id, string first, string last, string dest, string sea, string book) {root = insertHelper(root, id, first, last, dest, sea, book);}
    void remove (int id) {root = deleteNode(root, id);}
    string toString(int num);
    
    // Accessors
    BinarySearchNode *getRoot() {return root;}
    string preOrder() {return preOrderHelper(root);}
    string postOrder() {return postOrderHelper(root);}
    string inOrder() {return inOrderHelper(root);}
    string getLeftID(BinarySearchNode*);
    string getRightID(BinarySearchNode*);
    
    //Display All Nodes
    string showLevels ();
};

BinarySearchNode* BSTree::insertHelper(BinarySearchNode* ptr, int id, string first, string last, string dest, string sea, string book) {
    if (ptr == NULL) {
        ptr = new BinarySearchNode(id, first, last, dest, sea, book);
    }
    else {
        if (id >= ptr->getID()) {
            ptr->Right = insertHelper(ptr->Right, id, first, last, dest, sea, book);
        }
        else {
            ptr->Left = insertHelper(ptr->Left, id, first, last, dest, sea, book);
        }
    }
    
    return ptr;
}

BinarySearchNode* BSTree::deleteNode(BinarySearchNode* ptr, int id) {
    BinarySearchNode* next;
    if (ptr == NULL) {
        return NULL;
    }
    else {
        if (id > ptr->getID()) {
            ptr->Right = deleteNode(ptr->Right, id);
        }
        else if (id < ptr->getID()) {
            ptr->Left = deleteNode(ptr->Left, id);
        }
        else {
            if (ptr->Right != NULL) {
                next = ptr->Right;
                while(next->Left != NULL){
                    next = next->Left;
                }
                ptr->setID(next->getID());
                ptr->setFName(next->getFName());
                ptr->setLName(next->getLName());
                ptr->setDestination(next->getDestination());
                ptr->setSeason(next->getSeason());
                ptr->setBooking(next->getBooking());
                
                ptr->Right = deleteNode(ptr->Right, ptr->getID());
            }
            else {
                return (ptr->Left);
            }
        }
    }
    return ptr;
}

string BSTree::inOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if (ptr != NULL) {
        str.append(inOrderHelper(ptr->Left));
        
        str.append(toString(ptr->getID()));
        str.append(" [");
        str.append(getLeftID(ptr));
        str.append(", ");
        str.append(getRightID(ptr));
        str.append("]\t  ");
        
        string FName = ptr->getFName();
        while (FName.size() < 20) {
            FName.append(" ");
        }
        str.append(FName);
        
        string LName = ptr->getLName();
        while (LName.size() < 20) {
            LName.append(" ");
        }
        str.append(LName);
        
        string theDestination = ptr->getDestination();
        while (theDestination.size() < 20) {
            theDestination.append(" ");
        }
        str.append(theDestination);
        
        string theSeason = ptr->getSeason();
        while (theSeason.size() < 20) {
            theSeason.append(" ");
        }
        str.append(theSeason);
        
        string theBooking = ptr->getBooking();
        while (theBooking.size() < 20) {
            theBooking.append(" ");
        }
        str.append(theBooking);
    }
    return str;
}

string BSTree::toString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string BSTree::getRightID(BinarySearchNode* cur) {
    BinarySearchNode* right = cur->Right;
    if (right == NULL) {
        return "NULL     ";
    }
    else {
        return toString(right->getID());
    }
}

string BSTree::getLeftID(BinarySearchNode* cur) {
    BinarySearchNode* left = cur->Left;
    if (left == NULL) {
        return "NULL     ";
    }
    else {
        return toString(left->getID());
    }
}
#endif /* BSTree_h */
