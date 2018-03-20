//
//  stack.h
//  Lab001
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

#ifndef stack_h
#define stack_h
#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class stack {
private:
    LinkList Stack;
    
public:
    bool isEmpty(); // tells us if the stack is empty.
    int Size(); // tells us the size of the Stack.
    string top(); // tells us the top of the the stack without removing it.
    void push(int number, string first, string last, string destination, string season, string booking); // Pushes an element on the top of the stack.
    string displayStack(); // displays the elements in the stack.
    string pop(); // pops the top of the stack.
    void clear(); // clears the stack from the front.
    void searchStack(int number, string first, string last, string destination, string season, string booking);
    ~stack();
};



//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//


bool stack::isEmpty() {
    if (Stack.size() == 0) {
        return true;
    }
    return false;
}

int stack::Size() {
    return Stack.size();
}

string stack::top() {
    cout << "The top of the stack is: ";
    cout << Stack.displayFront() << endl;
    return Stack.displayFront();
}

void stack::push(int number, string first, string last, string destination, string season, string booking) {
    
    if (Stack.size() == 0) {
        Stack.createANode(number, first, last, destination, season, booking);
        return;
    }
    Stack.addAtFront(number, first, last, destination, season, booking);
    
    
}

string stack::pop() {
    
        return Stack.deleteAtFront();
    
}

void stack::clear() {
    while (Stack.size() != 0) {
        Stack.deleteAtFront();
    }
}



string stack::displayStack() {
    cout << "The Stack is " << endl;
    
    return Stack.displayTheList();
}

void stack::searchStack(int number, string first, string last, string destination, string season, string booking) {
    Stack.searchList(number, first, last, destination, season, booking);
}

stack::~stack() {
    Stack.~LinkList();
}
#endif /* stack_h */
