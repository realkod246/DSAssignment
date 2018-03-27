//
//  BSTree.h
//  DSAssignment
//
//  Created by Jelani on 23/03/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h



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
    BinarySearchNode(void) {ID = 0; fName = lName = destination = season = booking = ""; Right = Left = NULL;}
    BinarySearchNode(int Id, string first, string last, string dest, string sea, string book);
    
    // Mutators
    void setID ( int Id ) {ID = Id;}
    void setFName(string first ) {fName = first;}
    void setLName(string last ) {lName = last;}
    void setDestination(string dest ) {destination = dest;}
    void setSeason(string sea ) {season = sea;}
    void setBooking(string book ) {booking = book;}
    
    // Accessors
    int getID(void) {return ID;}
    string getFName() {return fName;}
    string getLName() {return lName;}
    string getDestination() {return destination;}
    string getSeason() {return season;}
    string getBooking() {return booking;}
    
}; //End of Definitions
BinarySearchNode::BinarySearchNode(int Id, string first, string last, string dest, string sea, string book) {
    ID = Id;
    fName = first;
    lName = last;
    destination = dest;
    season = sea;
    booking = book;
    Right=Left=NULL;
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
    void insert(int Id, string first, string last, string dest, string sea, string book) {root = insertHelper(root, Id, first, last, dest, sea, book);}
    void remove (int Id) {root = deleteNode(root, Id);}
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

BinarySearchNode* BSTree::insertHelper(BinarySearchNode* ptr, int Id, string first, string last, string dest, string sea, string book) {
    if (ptr == NULL) {
        ptr = new BinarySearchNode(Id, first, last, dest, sea, book);
    }
    else {
        if (Id >= ptr->getID()) {
            ptr->Right = insertHelper(ptr->Right, Id, first, last, dest, sea, book);
        }
        else {
            ptr->Left = insertHelper(ptr->Left, Id, first, last, dest, sea, book);
        }
    }
    
    return ptr;
}

BinarySearchNode* BSTree::deleteNode(BinarySearchNode* ptr, int Id) {
    BinarySearchNode* next;
    if (ptr == NULL) {
        return NULL;
    }
    else {
        if (Id > ptr->getID()) {
            ptr->Right = deleteNode(ptr->Right, Id);
        }
        else if (Id < ptr->getID()) {
            ptr->Left = deleteNode(ptr->Left, Id);
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
       
            FName.append(" ");
        
        str.append(FName);
        
        string LName = ptr->getLName();
        
            LName.append(" ");
       
        str.append(LName);
        
        string theDestination = ptr->getDestination();
        
            theDestination.append(" ");
        
        str.append(theDestination);
        
        string theSeason = ptr->getSeason();
     
            theSeason.append(" ");
        
        str.append(theSeason);
        
        string theBooking = ptr->getBooking();
        
            theBooking.append(" ");
        
        str.append(theBooking);
    }
    return str;
}

string BSTree::preOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( to_string( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string fName = ptr->getFName();
        
            fName.append(" ");
        
        str.append( fName );
        
        string lName = ptr->getLName();
        
            lName.append(" ");
        
        str.append( lName );
        
        string theDestination = ptr->getDestination();
        
            theDestination.append(" ");
        
        str.append( theDestination );
        
        string theSeason = ptr->getSeason();
        
            theSeason.append(" ");
        
        
        string theBooking = ptr->getBooking();
        
            theBooking.append(" ");
        
        
        str.append( "\n");
        
        str.append( preOrderHelper(ptr->Left) );
        str.append( preOrderHelper(ptr->Right) );
    }
    return str;
}

string BSTree::postOrderHelper(BinarySearchNode* ptr) {
    string str = "";
    
    if ( ptr != NULL )
    {
        str.append( postOrderHelper(ptr->Left) );
        str.append( postOrderHelper(ptr->Right) );
       
        str.append( to_string( ptr->getID() ) );
        str.append(" [");
        str.append( getLeftID(ptr) );
        str.append(", ");
        str.append( getRightID(ptr) );
        str.append("]\t   ");
        
        string fName = ptr->getFName();
        
        fName.append(" ");
        
        str.append( fName );
        
        string lName = ptr->getLName();
        
        lName.append(" ");
        
        str.append( lName );
        
        string theDestination = ptr->getDestination();
        
        theDestination.append(" ");
        
        str.append( theDestination );
        
        string theSeason = ptr->getSeason();
        
        theSeason.append(" ");
        
        
        string theBooking = ptr->getBooking();
        
        theBooking.append(" ");
        
        
        str.append( "\n");
        
        
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
