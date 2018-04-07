//
//  RBTree.h
//  DSAssignment
//
//  Created by Jelani on 07/04/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef RBTree_h
#define RBTree_h

class RBTNode {
private:
    int ID;
    string first;
    string last;
    string destination;
    string season;
    string booking;
    string color;
    
    
public:
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;
    
    //Constructor Functions
    RBTNode(){right = left = parent= NULL; color = "RED";}
    RBTNode(int, string, string, string, string, string);
    
    //Accessor Functions
    int getID() {return ID;}
    string getFName() {return first;}
    string getLName() {return last;}
    string getDestination() {return destination;}
    string getSeason() {return season;}
    string getBooking() {return booking;}
    string getAllData();
    string getAllDataRBT();
    string strip(string);
    string getColor() {return color;}
    
    // Mutator Functions
    void setID(int id) {ID = id;}
     void setName(string fn)         { first = name }
    void setSurname(string ln)      { last = ln }
    void setDestination(string dest)      { destination = dest; }
    void setSeason(string sea)       { season = sea; }
    void setBooking(string book) {booking = book;}
    
    void setData(int, string, string, string, string, string);
    void setColor(string col){color = col;}
    
};

#endif /* RBTree_h */
