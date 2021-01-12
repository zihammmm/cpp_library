//
// Created by zihan on 2021/1/12.
//
#include "lru.h"
#include <iostream>

template<class T>
zhy::LRU<T>::LRU(size_t capacity) {
    if (capacity <= 0) {
        throw std::range_error("capacity must be a positive");
    }
    this->capacity = capacity;
    this->size = 0;
    lru_list = new List<T>(capacity);
}

template<class T>
zhy::LRU<T>::~LRU<T>() {
    lru_list->~List();
}

template<class T>
void zhy::LRU<T>::addData(T data) {
    if (size >= capacity) {
        lru_queue.erase(lru_queue.find(lru_list->removeLast()));
    }
    auto node = new Node<T>(data);
    lru_list->addFirst(node);
    lru_queue[data] = node;
    ++size;
}

template<class T>
zhy::Node<T> *zhy::LRU<T>::visit(T data) {
    auto it = lru_queue.find(data);
    if (it == lru_queue.end()) {
        addData(data);
    } else {
        lru_list->visit(lru_queue[data]);
    }
#ifdef LRU_DEBUG
    print();
#endif
    return lru_queue[data];
}

template<class T>
void zhy::LRU<T>::print() {
    lru_list->print();
}