#ifndef NODE_H
#define NODE_H

// appending to string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node
    {
        private:
            int idNo;
            string name;
            string surname;
        string theDestination;
        string theBooking;
        string theSeason;
        
        
            Node* nextPtr;
        
        public:
            // Constructor functions
            Node();
            Node(int, string, string, string, string,string);
        
            // Accessor functions;
            string getName();
            string getRecord();                     // You need to write that function!
            int getID() { return idNo;}      // Inline function
            Node* getNextPtr() { return nextPtr;}   // Inline function
        
            //Mutator functions
            void setData(int, string, string, string, string, string);
            void setNextPtr(Node* ptr) { nextPtr = ptr;}   // Inline function
    };
#endif // NODE_H



//===========================================================================
//          Member functions' definition
//===========================================================================

Node::Node()
    {
        idNo = 0;
        name = "";
        surname = "";
        theDestination = "";
        theSeason = "";
        theBooking = "";
        nextPtr = NULL;
    }




Node::Node(int number, string first, string last, string destination, string season, string booking)
    {
        idNo    = number;
        name    = first;
        surname = last;
        theDestination = destination;
        theSeason = season;
        theBooking = booking;
        nextPtr = NULL;
    }




string Node::getName()
    {
        string nameStr = name;
        nameStr.append(" ");
        nameStr.append(surname);
        
        return nameStr;
    }




string Node::getRecord()
{
    string recStr = "";
    

    
    stringstream ss;
    ss << idNo << ", " << name << " " << surname << ", " << theDestination << " " << theSeason << " " << theBooking;
    /***** Enter the code here ****/
    string recStrr = ss.str();
    recStr.append(recStrr);
    return recStr;
}




void Node::setData(int number, string first, string last, string destination, string season, string booking)
    {
        idNo    = number;
        name    = first;
        surname = last;
        theDestination = destination;
        theSeason = season;
        theBooking = booking;
    }


