//
//  AVLTree.h
//  DSAssignment
//
//  Created by Jelani on 28/03/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

class AVLNode {
private:
    int ID;
    string fName;
    string lName;
    string destination;
    string season;
    string booking;
    
    
public:
    AVLNode* Left;
    AVLNode* Right;
    
    // Constructors
    AVLNode() {ID = 0; fName = lName = destination = season = booking = ""; Right = Left = NULL;}
    AVLNode(int Id, string first, string last, string dest, string sea, string book);

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
};

AVLNode::AVLNode(int Id, string first, string last, string dest, string sea, string book) {
    ID = Id;
    fName = first;
    lName = last;
    destination = dest;
    season = sea;
    booking = book;
    Right=Left=NULL;
}
class AVLTree {
private:
    AVLNode* root;
    
    AVLNode* insertHelper(AVLNode*, int iD, string first, string last, string theDestination, string theSeason, string theBooking);
    
    AVLNode* removeHelper(AVLNode*, int);
    string inOrderHelper(AVLNode*);
    string preOrderHelper(AVLNode*);
    string postOrderHelper(AVLNode*);
    
    int AVLheight(AVLNode*);
    int calcBalance(AVLNode*);
    
    AVLNode* leftRotate(AVLNode*);
    
    AVLNode* specialCaseLeftRotate(AVLNode*);
    
    AVLNode* rightRotate(AVLNode*);
    
    AVLNode* specialCaseRightRotate(AVLNode*);
    
    int max(int num,int num1);
    void resetHeight(AVLNode*);
    // End of private functions
    
    
public:
    // Constructor and Destructor
    AVLTree() {root = NULL;}
    ~AVLTree() {root = NULL;}
    
    // Mutators
    void insert(int Id, string first, string last, string dest, string sea, string book) {root = insertHelper(root, Id, first, last, dest, sea, book);}
    void remove (int Id) {root = removeHelper(root, Id);}
    
    string to_string(int i);
    
    // Accessors
    AVLNode *getRoot() {return root;}
    string preOrder() {return preOrderHelper(root);}
    string postOrder() {return postOrderHelper(root);}
    string inOrder() {return inOrderHelper(root);}
    string getLeftID(AVLNode*);
    string getRightID(AVLNode*);
    string getWeight(AVLNode*);
    
};
#endif /* AVLTree_h */
