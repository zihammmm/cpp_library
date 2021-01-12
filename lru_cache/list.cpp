//
// Created by zihan on 2021/1/12.
//
#include "list.h"

template<class T>
zhy::Node<T>::Node() {
    prev = next = nullptr;
}

template<class T>
zhy::Node<T>::Node(T data) {
    this->data = data;
    prev = next = nullptr;
}

template<class T>
bool zhy::List<T>::isEmpty() {
    return size == 0;
}

template<class T>
void zhy::List<T>::print() {
    auto p = head->next;
    while (p != tail) {
        std::cout << p->data << "->";
        p = p->next;
    }
    std::cout<<std::endl;
}

template<class T>
size_t zhy::List<T>::getSize() {
    return size;
}

/**
 * 插入到链表最上面(前提是数据不存在)
 * @tparam T
 * @param node
 * @return
 */
template<class T>
bool zhy::List<T>::addFirst(Node<T> *node) {
    if (size >= capacity) {
        removeLast();
    }

    head->next->prev = node;
    node->next = head->next;
    node->prev = head;
    head->next = node;
    ++size;
    return node;
}

/**
 * 访问数据
 * 相当于先移除，然后插入到头部
 * @tparam T
 * @param node
 */
template<class T>
void zhy::List<T>::visit(Node<T> *&node) {
    // h->2->1->0->t,  visit 0
    remove(node);
    addFirst(node);
}

/**
 * 移除最末尾的结点
 * @tparam T
 * @return
 */
template<class T>
T zhy::List<T>::removeLast() {
    if (size > 0) {
        Node<T> *t = tail->prev;
        remove(t);
        return t->data;
    } else {
        throw std::runtime_error("size is 0!");
    }
}

/**
 * 从链表中移除指定结点，但不删除
 * @tparam T
 * @param node
 */
template<class T>
void zhy::List<T>::remove(Node<T> *&node) {
    if (node == head || node == tail) {
        return;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->prev = node->next = nullptr;
    --size;
}

template<class T>
zhy::List<T>::List(size_t capacity) {
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;
    size = 0;
    this->capacity = capacity;
}

template<class T>
zhy::List<T>::~List<T>() {
    if (size > 0) {
        auto p = head->next;
        while (p != nullptr) {
            auto t = p;
            p = p->next;
            delete t;
        }
    }
    delete head;
    head = tail = nullptr;
    capacity = size = 0;
}