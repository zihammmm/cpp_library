//
// Created by zihan on 2021/1/12.
//
#include <iostream>

#ifndef ZHY_LIST
#define ZHY_LIST
namespace zhy{
    template<class T>
    class List;

    /**
* 双向链表结点
* @tparam T
*/
    template<class T>
    class Node {
        friend class List<T>;

    private:
        T data;
        Node *prev;
        Node *next;
    public:
        Node();
        Node(T data);
    };

    template<class T>
    class List {
    private:

        Node<T> *head;
        Node<T> *tail;
        size_t size;
        size_t capacity;

    public:
        List(size_t capacity = 8);

        ~List();

        bool addFirst(Node<T> *node);

        void visit(Node<T> *&node);

        T removeLast();

        void remove(Node<T>* &node);

        bool isEmpty();

        void print();

        size_t getSize();
    };

}
#endif