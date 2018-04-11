//
//  Set.h
//  DSAssignment
//
//  Created by Jelani on 09/04/2018.
//  Copyright © 2018 Tap. TOUCH. All rights reserved.
//

#ifndef Set_h
#define Set_h

#include "Heap.h"

class Set {
private:
    vector<Node> set;
    

public:
    Set(void) {set.resize(0);}
    void purge() {set.resize(0);}
    int getNumElements () {return set.size();}
    bool find (int);
    string add (int, string, string,string,string,string);
    void remove(int);
    void show()const;
    void unionSet(Set*, Set*);          // Union of 2 sets
    void intersectionSet(Set*, Set*);   // Intersection of 2 sets
    string displaySet();
    bool isSubset (Set*);
    bool isDisjoint (Set*);
};

bool Set::find (int iDno)
{
    for (int i = 0; i < set.size(); i++)
    {
        if (set[i].getID() == iDno)
            return true;
    }
    return false;
}

string Set::add (int iDno, string FirstName, string LastName,
                 string destination, string season, string booking)
{
    Node *temp = new Node(iDno, FirstName, LastName, destination, season, booking);
    string result = "";
    
    // Check if the element is already in the set
    bool found = find (iDno);
    
    if (found)      //elem is in the set already
        result.append("Data already in the set...");
    
    else     //elem is Not found in set
    {               // add the new set
        set.push_back(*temp);
        result.append("New element added..");
    }
    return result;
}

void Set::remove(int iDno)
{
    bool found = find (iDno);
    string result = " ";
    int x = 0;
    
    if (!found)
    {
        result.append("Data is not in the set...");
        return;
    }
    else
    {
        while(set[x].getID() != iDno)
            x++;
        
        set[x] = set[set.size()-1];
        set.pop_back();
    }
    return;
}

void Set::unionSet(Set *setA,  Set *setB)
{
    int y;
    
    set.resize(0);
    
    //    Copy contents of setA to the union-set
    set = setA->set;
    y = setA->set.size();
    
    //    Copy contents of setB which are missing from setA to the union-set
    for (int x = 0; x < setB->set.size(); x++)
    {
        if (!find(setB->set[x].getID()) )
        {
            set.push_back(setB->set[x]);
            y++;
        }
    }
}

void Set::intersectionSet(Set* setA,  Set* setB)
{
    set.resize(0);
    
    for (int x = 0; x < setA->set.size(); x++)
    {
        if ( setA->set[x].getDestination() == "Trinidad," )
            set.push_back(setA->set[x]);
    }
    for (int x = 0; x < setB->set.size(); x++)
    {
        if ( setB->set[x].getDestination() == "Trinidad,")
            set.push_back(setB->set[x]);
    }
    
}

string Set::displaySet()
{
    string str = "";
    
    
    for (int x = 0; x < set.size(); x++)
    {
        
        str.append(set[x].getRecord());
        str.append("\n");
    }
    return str;
}

bool Set::isSubset(Set* SetA)
{
    for (int x = 0; x < set.size(); x++)
    {
        if ( !SetA->find(set[x].getID()) )
            return false;
    }
    return true;
}


bool Set::isDisjoint(Set* SetA)
{
    for (int x = 0; x < set.size(); x++)
    {
        if ( SetA->find(set[x].getID()) )
            return false;
    }
    return true;
}


#endif /* Set_h */
