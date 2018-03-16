//
//  deque.h
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

#ifndef deque_h
#define deque_h
#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class Deque {
private:
    LinkList deque;
    
public:
    bool isEmpty();
    int Size();
    string begin();
    string end();
    string display();
    void push_back(int number, string first, string last, string destination, string season, string booking);
    void push_front(int number, string first, string last, string destination, string season, string booking);
    void pop_front();
    void pop_back();
    void insert(int number, string first, string last, string destination, string season, string booking);
    void clear();
    
};

//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

bool Deque::isEmpty() {
    if (deque.size() == 0) {
        return true;
    }
    return false;
}

int Deque::Size() {
    cout << "the size is " << deque.size() << endl;
    return deque.size();
}

string Deque::begin() {
    cout << "the front of the double ended queue is: " << deque.displayFront() << endl;
    return deque.displayFront();
}

string Deque::end() {
    cout << "the back of the double ended queue is: " << deque.displayBack() << endl;
    return deque.displayBack();
}

void Deque::push_back(int number, string first, string last, string destination, string season, string booking) {
    if (deque.size() == 0) {
        deque.createANode(number, first, last, destination, season, booking);
        return;
    }
    deque.addAtBack(number, first, last, score);
}

void Deque::push_front(int number, string first, string last, string destination, string season, string booking) {
    if (deque.size() == 0) {
        deque.createANode(number, first, last, destination, season, booking);
        return;
    }
    deque.addAtFront(number, first, last, destination, season, booking);
}

void Deque::pop_front() {
     deque.deleteAtFront();
}

void Deque::pop_back() {
    deque.deleteAtBack();
}

void Deque::insert(int number, string first, string last, string destination, string season, string booking, int atPos) {
    deque.insertAtPosition(number, first, last, destination, season, booking, atPos);
    
}

string Deque::display() {
    return deque.displayTheList();
}

void Deque::clear() {
    while (deque.size() != 0) {
        deque.deleteAtFront();
    }
}
#endif /* deque_h */
