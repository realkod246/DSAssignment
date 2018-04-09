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
    
    
public:
public:
    Heap data;
    //~Set ( void ) { data.Purge(); }
    
    int    getNumElements ( void   ) { return data.Size(); }
    bool   search         ( int ID, string FName ) { return data.find(ID, FName);  }
    inline void   add            ( int id, string fn, string ln, string theDestination, string theSeason, string theBooking )
    {
        data.addMinHeap(id, fn, ln, theDestination, theSeason, theBooking);
    }
    Heap unionSet(Set*, Set*);          // Union of 2 sets
    Heap intersectionSet(Set*, Set*);   // Intersection of 2 sets
    string displaySet() { return data.displayHeap(); }
};

Heap Set::unionSet(Set* setA,  Set* setB)
{
    Set Uset;
    Uset.data.setData( setA->data.getData() );
    
    for (int x = 1; x < setB->data.Size(); x++)
    {
        if ( !setA->search( setB->data.getIDAt(x), setB->data.getFnameAt(x) ) )
        {
            Uset.add( setB->data.getIDAt(x), setB->data.getFnameAt(x),
                     setB->data.getLnameAt(x), setB->data.getDestinationAt(x),
                     setB->data.getSeasonAt(x), setB->data.getBookingAt(x) );
        }
    }
    return Uset.data;
}

Heap Set::intersectionSet(Set* setA,  Set* setB)
{
    Set checkA;
    Set checkB;
    Set Iset;
    
    for (int x = 1; x < setA->data.Size(); x++)
    {
        if (setA->data.getSeasonAt(x) == "Winter,"   )
        {
            checkA.add( setA->data.getIDAt(x), setA->data.getFnameAt(x),
                       setA->data.getLnameAt(x), setA->data.getDestinationAt(x),
                       setA->data.getSeasonAt(x), setA->data.getBookingAt(x) );
        }
        
    }
    for (int x = 1; x < setB->data.Size(); x++)
    {
        if (setB->data.getSeasonAt(x) == "Winter,")
        {
            checkB.add( setB->data.getIDAt(x), setB->data.getFnameAt(x),
                       setB->data.getLnameAt(x), setB->data.getDestinationAt(x),
                       setB->data.getSeasonAt(x), setB->data.getBookingAt(x) );
        }
        if ( checkA.data.Size() > 1 && checkB.data.Size() > 1 )
        {
            for (int x = 1; x < checkA.data.Size(); x++)
            {
                Iset.add( checkA.data.getIDAt(x), checkA.data.getFnameAt(x),
                         checkA.data.getLnameAt(x), checkA.data.getDestinationAt(x),
                         checkA.data.getSeasonAt(x), checkA.data.getBookingAt(x) );
            }
            for (int x = 1; x < checkB.data.Size(); x++)
            {
                if ( !checkA.search( checkB.data.getIDAt(x), checkB.data.getFnameAt(x) ) )
                {
                    Iset.add( checkB.data.getIDAt(x), checkB.data.getFnameAt(x),
                             checkB.data.getLnameAt(x), checkB.data.getDestinationAt(x),
                             checkB.data.getSeasonAt(x), checkB.data.getBookingAt(x) );
                }
            }
        }
        
        
    }
    return Iset.data;
}



#endif /* Set_h */
