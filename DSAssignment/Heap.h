//
//  Heap.h
//  DSAssignment
//
//  Created by Jelani on 07/04/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

// appending to string
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BHNode
{
private:
    int idNo;
    string name;
    string surname;
    string theDestination;
    string theSeason;
    string theBooking;
    
    
    
    BHNode* nextPtr;
    
public:
    // Constructor functions
    BHNode() {idNo = 0; name = surname = theDestination = theSeason = theBooking = ""; nextPtr = NULL;}
    BHNode(int error) {idNo = error; name = surname = theDestination = theSeason = theBooking = ""; nextPtr = NULL;}
    BHNode(int, string fn, string ln, string dest, string sea, string book);
    
    // Accessor functions;
    int getID() {return idNo;}
    string getName() {return name;}
    string getSurname() {return surname;}
    string getDestination() {return theDestination;}
    string getBooking() {return theBooking;}
    string getSeason() {return theSeason;}
    BHNode* getNext()  {return nextPtr;}
    
    //Mutator Functions
    void setID(int id) {idNo = id;}
    void setFName(string fn) {name = fn;}
    void setLName(string ln) {surname = ln;}
    void setDestination(string dest) {theDestination = dest;}
    void setSeason(string sea) { theSeason = sea;}
    void setBooking(string book) {theBooking = book;}
    void setNxt(BHNode* nx) {nextPtr = nx;}
    
    
};
//===========================================================================
//          Member functions' definition
//===========================================================================

BHNode::BHNode(int id, string fn, string ln, string dest, string sea, string book) {
    idNo = id; name = fn; surname = ln; theDestination = dest; theSeason = sea; theBooking = book; nextPtr = NULL;
}






class Heap
{
private:
    vector <BHNode*> elements;
    
public:
    // Constructor Function
    Heap () { elements.resize(1); }
    
    //void Purge ( void ) { string purge = sortMinHeap(); }
    
    // Mutator Functions
    void addMinHeap(int, string, string, string, string, string);   // Add to MinHeap
    void minHeapify(unsigned int);      // Heapify MinHeap
    void deleteMinHeapVal(int);         // Delete element from MinHeap
    void removeMinRoot();
    string sortMinHeap();
    string to_String ( int i );
    
    void setData ( vector <BHNode*> data ) { elements = data; }
    
    //Accessor Function
    string displayHeap();
    string getLeftID  ( int  );
    string getRightID ( int  );
    int    Size       ( void )  { return elements.size(); }
    bool   find       ( int, string );
    int    getIDAt      ( int i ) { return elements[i]->getID();    }
    string getFnameAt ( int i ) { return elements[i]->getName(); }
    string getLnameAt ( int i ) { return elements[i]->getSurname(); }
    string getDestinationAt ( int i ) { return elements[i]->getDestination(); }
    string  getSeasonAt   ( int i ) { return elements[i]->getSeason();   }
    string getBookingAt (int i) {return elements[i]->getBooking(); }
    
    vector <BHNode*> getData ( void ) { return elements; }
};

//===================================================================================
// Add new element to MinHeap
//===================================================================================
void Heap::addMinHeap(int id, string fn, string ln, string dest, string sea, string book)
{
    BHNode* element = new BHNode(id, fn, ln, dest, sea, book);
    elements.push_back(element);
    minHeapify(elements.size() - 1);
}

//===================================================================================
// Recursive heapify function for a MinHeap
//===================================================================================
void Heap::minHeapify(unsigned int index)
{
    unsigned int left, right, minn;
    left = 2*index;
    right = (2*index) + 1;
    
    // Base case
    if (index == 0)
        return;
    
    // Check the children if they exist and pick the larger for swapping
    if ( left < elements.size() && elements[left]->getID() < elements[index]->getID() )
        minn = left;
    else
        minn = index;
    
    if ( right < elements.size() && elements[right]->getID() < elements[minn]->getID() )
        minn = right;
    
    if (minn != index)
    {
        BHNode* temp = elements[minn];
        elements[minn] = elements[index];
        elements[index] = temp;
        minHeapify(minn);
    }
    
    // Now check the parent, if it exists
    minHeapify(index/2);
}

//===================================================================================
// Delete function for a MinHeap
//===================================================================================
void Heap::deleteMinHeapVal(int id)
{
    int x = 1;
    
    while ( x < elements.size() )
    {
        if ( id == elements[x]->getID() )
        {
            elements[x] = elements[ (elements.size() - 1) ];
            
            elements.pop_back();
            
            minHeapify(x);              // parent
            minHeapify(2 * x);             // left child
            minHeapify((2 * x) + 1 );   // right child
            break;      //No need to search further
        }
        x++;
    }
}

//===================================================================================
// Remove root function for a MinHeap
//===================================================================================
void Heap::removeMinRoot()
{
    if (elements.size() < 2)
        return;
    else
    {
        elements[1] = elements[elements.size() - 1];
        elements.resize(elements.size() - 1);
        minHeapify(1);
    }
    
}

//===================================================================================
// Sort function for a MinHeap
//===================================================================================
string Heap::sortMinHeap()
{
    string str ="";
    
    while (elements.size() > 1)
    {
        str.append( to_String( elements[1]->getID() ) );
        str.append(" [");
        str.append( getLeftID(1) );
        str.append(", ");
        str.append( getRightID(1) );
        str.append("]\t   ");
        
        string FName = elements[1]->getName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = elements[1]->getSurname();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theDest = elements[1]->getDestination();
        while (theDest.size() < 20)
        {
            theDest.append(" ");
        }
        str.append( theDest );
        
        string theSea = elements[1]->getSeason();
        while (theSea.size() < 20) {
            theSea.append(" ");
        }
        str.append(theSea);
        
        string theBook = elements[1]->getBooking();
        while (theBook.size() < 20) {
            theBook.append(" ");
        }
        str.append(theBook);
        
        str.append("\n");
        
        removeMinRoot();
    }
    return str;
}

string Heap::to_String ( int i )
{
    stringstream ss;
    ss << i;
    return ss.str();
}

string Heap::displayHeap()
{
    string str = "";
    
    for (int x = 1; x < elements.size(); x++)
    {
        str.append( to_String( elements[x]->getID() ) );
        str.append(" [");
        str.append( getLeftID(x) );
        str.append(", ");
        str.append( getRightID(x) );
        str.append("]\t   ");
        
        string FName = elements[x]->getName();
        while (FName.size() < 20)
        {
            FName.append(" ");
        }
        str.append( FName );
        
        string LName = elements[x]->getSurname();
        while (LName.size() < 20)
        {
            LName.append(" ");
        }
        str.append( LName );
        
        string theDest = elements[x]->getDestination();
        while (theDest.size() < 20)
        {
            theDest.append(" ");
        }
        str.append( theDest );
        
        string theSea = elements[x]->getSeason();
        while (theSea.size() < 20) {
            theSea.append(" ");
        }
        str.append(theSea);
        
        string theBook = elements[x]->getBooking();
        while (theBook.size() < 20) {
            theBook.append(" ");
        }
        str.append(theBook);
        str.append("\n");
    }
    return str;
}

string Heap::getLeftID ( int index )
{
    if ( ((2*index)+1) > elements.size() )
        return "NULL        ";
    else
        return to_String( elements[(2*index)]->getID() );
}



string Heap::getRightID ( int index )
{
    if ( ((2*index)+2) > elements.size() )
        return "        NULL";
    else
        return to_String( elements[(2*index)+1]->getID() );
}

bool Heap::find ( int id, string fn )
{
    for (int i = 1; i < elements.size(); i++)
    {
        if (elements[i]->getID() == id && elements[i]->getName() == fn)
            return true;
    }
    return false;
}
#endif /* Heap_h */
