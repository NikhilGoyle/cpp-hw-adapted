#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    MyNode *newGuy;
    newGuy = new MyNode(name,score);
    if (_size == 0) {
        _size += 1;
        _head = newGuy;
        _tail = newGuy;
    }
    else if (_size == 1) {
        _size += 1;
        _tail = newGuy;
        _head->next = _tail;
        _tail->prev = _head;
    } else {
        _size += 1;
        _tail->next = newGuy;
        newGuy->prev = _tail;
        _tail = newGuy;
    }
}

void MyList::clear() {
    if (_size == 1) {
        delete _head;
    } else if (_size == 0) {
    } else {
        MyNode *current = _head;
        while (current->next != nullptr) {
            current = current->next;
            delete current->prev;
            //_size -= 1;
        }
        delete _tail;
        _size = 0;
    }
}


MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
