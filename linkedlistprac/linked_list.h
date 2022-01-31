#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>
#include <iostream>

struct MyNode {
    std::string name;
    int score;
    MyNode* next;
    MyNode* prev;
    /**
     * @param	name
     * @param	score
     */
    MyNode(const std::string& name, int score);
};


class MyList {
    size_t _size;
    MyNode* _head;
    MyNode* _tail;
    
 public:
    MyList();
    ~MyList();
    size_t size() const;
    bool empty() const;
    MyNode* head() const;
    void add(const std::string& name, int score);
    void clear();

    /**
     * @param       Name
     * @return      bool
     */
    bool remove(const std::string& name);

    /**
     * @param       name
     * @param       score
     * @param       index
     * @return      a bool
     */
    bool insert(const std::string& name, int score, size_t index);
};

std::ostream& operator<<(std::ostream& os, const MyList& myList);


#endif
