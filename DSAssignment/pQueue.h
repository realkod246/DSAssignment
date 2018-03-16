//
//  pQueue.h
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

#ifndef pQueue_h
#define pQueue_h

#include "LinkList.h"
#include <iostream>
#include <string>

using namespace std;

class PQueue {
private:
    LinkList PQ;
    
public:
    bool isEmpty();
    int Size();
    string highestPriority();
    string end();
    string display();
    void push_back(int number, string first, string last, string destination, string season, string booking);
    void pop_front();
    void clear();
    
};


//===========================================================================//
//                   Member functions' definition                            //
//===========================================================================//

bool PQueue::isEmpty() {
    return PQ.isEmpty();
}

int PQueue::Size() {
    return PQ.size();
}

void PQueue::push_back(int number, string first, string last, string destination, string season, string booking) {
    
    
    
    
    
    if (PQ.size() == 0) {
        PQ.createANode(number, first, last, destination, season, booking);
        return;
    }
    if (number > PQ.getFront() -> getID()) {
        PQ.addAtFront(number, first, last, destination, season, booking);
        return;
    }
    if (number <= PQ.getFront() -> getID() && PQ.getFront() -> getNextPtr() == NULL) {
        PQ.addAtBack(number, first, last, destination, season, booking);
        return;
    }
    PQ.traverseList(number, first, last, destination, season, booking);
    
    
}

void PQueue::pop_front() {
    PQ.deleteAtFront();
}

string PQueue::display() {
    return PQ.displayTheList();
}

void PQueue::clear() {
    while (Size() != 0) {
        pop_front();
    }
}

string PQueue::highestPriority() {
    return PQ.displayFront();
}



#endif /* pQueue_h */
