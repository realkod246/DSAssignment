//
//  LinkList.h
//  Queue
//
// Copyright © 2018 Tap. TOUCH. All rights reserved.
// Unauthorized copying, via any medium is strictly prohibited.
// Unless written consent by the author, you are not allowed to
// modify, copy, merge, publish, distribute, sublicense, and/or
// sell copies of this code.
//
/*************************************************************************
 *
 * Tap. TOUCH.
 * __________________
 *
 *  [2017] - [2018] Tap. TOUCH.
 * Created by Jelani on 18/02/2018.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHOR OR COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include "Node.h"


using namespace std;

class LinkList {
    
private:
    Node *front, *back;
    int num_elements;
  
public:
    void createANode(int number, string first, string last, string destination, string season, string booking);
    void createABackNode(int number, string first, string last, string destination, string season, string booking);
    void addAtBack(int number, string first, string last, string destination, string season, string booking);
    void addAtFront(int number, string first, string last, string destination, string season, string booking);
    void insertAtPosition(int number, string first, string last, string destination, string season, string booking, int atPos);
    string displayBack();
    string displayFront();
    void traverseList(int number, string first, string last, string destination, string season, string booking);
    void deleteAtFront();
    void deleteAtBack();
    string displayTheList();
    void searchList(int number, string first, string last, string destination, string season, string booking);
    Node* getFront();
    Node* getBack();
    void PQueue(int number, string first, string last, string destination, string season, string booking);
    
    LinkList() {
        front = NULL;
        back = NULL;
        num_elements = 0;
    }
    
    ~LinkList();
    
    int size();
    bool isEmpty();
};

//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

// Done
void LinkList::addAtFront(int number, string first, string last, string destination, string season, string booking) {
    
    
    
    Node* tmp = new Node(number, first, last, destination, season, booking);
    tmp -> setNextPtr(front);
    front = tmp;
    num_elements++;
}


// Done
void LinkList::createANode(int number, string first, string last, string destination, string season, string booking) {
    Node *tmp = new Node(number, first, last, destination, season, booking);
    
    
    if (front == NULL) {
        front = back = tmp;
        front -> setNextPtr(NULL);
    }
    else {
        tmp -> setNextPtr(front);
        front = tmp;
        
    }
    num_elements++;
}


void LinkList::insertAtPosition(int number, string first, string last, string destination, string season, string booking, int atPos) {
    Node *tmp = new Node(number, first, last, destination, season, booking);
    if (atPos == -1 || atPos > num_elements) {
        cout << "Out of range";
        return;
    }
    Node*next = front;
    Node*cur = new Node;
    
    if (atPos == 1) {
        addAtFront(number, first, last, destination, season, booking);
        return;
    }
    
    for (int i = 0; i <= num_elements; i++) {
        
        if (atPos == i) {
            cur = next;
            next = next -> getNextPtr();
            cur -> setNextPtr(tmp);
            tmp -> setNextPtr(next);
            
        }
        
        //next = next -> getNextPtr();
    }
    num_elements++;
}

void LinkList::addAtBack(int number, string first, string last, string destination, string season, string booking) {
    if (front == NULL) {
        cout << "Out of range";
        return;
    }
    
    
    Node *tmp = new Node(number, first, last, destination, season, booking);
    Node *s = front;
    while (s->getNextPtr() != NULL) {
        s = s -> getNextPtr();
    }
    tmp -> setNextPtr(NULL);
    s -> setNextPtr(tmp);
    back = tmp;
    num_elements++;
    
}

void LinkList::deleteAtFront() {
    if (front == NULL) {
        cout  << "out of range";
        return;
        
    }
    string theString = " ";
    Node *delPtr = new Node;
    Node *tmp = new Node;
    tmp = front;
    theString = front -> getRecord();
    front = front -> getNextPtr();
    delPtr = tmp;
    free(delPtr);
    num_elements--;
    
}

void LinkList::deleteAtBack() {
    if (back == NULL) {
        cout  << "out of range";
        return;
        
    }
    Node *tmp = new Node();
    Node *s = front;
    while (s->getNextPtr() != NULL) {
        tmp = s;
        s = s -> getNextPtr();
    }
    back = tmp;
    tmp -> setNextPtr(NULL);
    free(s);
    
    
    
    
    
    num_elements--;
}

string LinkList::displayFront() {
    if (front == NULL) {
        return "Please add to front first.";
        
    }
    Node*tmp = new Node;
    tmp = front;
    
    return tmp -> getRecord();
}



string LinkList::displayBack() {
    if (back == NULL) {
        return "Please add to back first.";
    }
    Node *tmp = back;
    
    return tmp -> getRecord();
}

string LinkList::displayTheList() {
    if (front == NULL) {
        
        return "List is Empty";
    }
    
    Node *tmp = new Node;
    tmp = front;
    
    while (tmp != NULL) {
        cout << tmp->getRecord() << "-> ";
        tmp=tmp->getNextPtr();
        
    }
    if (tmp == NULL) {
        return "The End";
    }
    
    return tmp -> getRecord();
}

int LinkList::size() {
    return num_elements;
}

bool LinkList::isEmpty() {
    return front == NULL;
}

LinkList::~LinkList() {
    front = NULL;
    back = NULL;
}

void LinkList::searchList(int number, string first, string last, string destination, string season, string booking) {
    Node *tmp = new Node(number, first, last, destination, season, booking);
    int counter = 0;
    tmp = front;
    stringstream ss;
    ss << number << ", " << first << " " << last << ", " << destination << " " << season << " " << booking;
    string theStr = ss.str();
    while (tmp != NULL) {
        
        counter++;
        if (tmp -> getRecord() == theStr) {
            cout << "Element " << tmp -> getRecord();
            cout << " found at position " << counter << endl;
            return;
        }
        tmp = tmp -> getNextPtr();
        
        
    }
    
    
    cout << "Element " << theStr << " not found" << endl;
}

void LinkList::traverseList(int number, string first, string last, string destination, string season, string booking) {
    Node* ptr = new Node(number, first, last, destination, season, booking);
    Node* cur = front -> getNextPtr();
    Node *prev = front;
    
    while ( cur != NULL && number <= cur->getID() )
    {
        cur = cur->getNextPtr();
        prev = prev->getNextPtr();
    }
    if (cur == NULL)
        prev->setNextPtr(ptr);
    else
    {
        ptr->setNextPtr(cur);
        prev->setNextPtr(ptr);
    }
    num_elements++;
    
    
    
    
}

Node* LinkList::getBack() {
    return back;
}

Node* LinkList::getFront() {
    return front;
}
void LinkList::PQueue(int number, string first, string last, string destination, string season, string booking){
    Node* ptr = new Node(number, first, last, destination, season, booking);
    Node* cur = front -> getNextPtr();
    Node *prev = front;
    
    while ( cur != NULL && number >= cur->getID() )
    {
        cur = cur->getNextPtr();
        prev = prev->getNextPtr();
    }
    if (cur == NULL)
        prev->setNextPtr(ptr);
    else
    {
        ptr->setNextPtr(cur);
        prev->setNextPtr(ptr);
    }
    num_elements++;
}
#endif /* LinkList_hpp */
