//
// Created by zihan on 2021/1/12.
//
#include <iostream>
#include <unordered_map>
#include "list.h"

#ifndef ZHY_LRU_CACHE
#define ZHY_LRU_CACHE
namespace zhy {
    template<class T>
    class LRU {
    private:
        std::unordered_map<T, Node<T> *> lru_queue;
        List<T> *lru_list;
        size_t size;
        size_t capacity;
        void addData(T data);
    public:
        LRU(size_t capacity = 8);
        ~LRU();
        Node<T> *visit(T data);
        void print();
    };
}
#endif