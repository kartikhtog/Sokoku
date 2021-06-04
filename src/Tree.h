#include "SodokuDefinations.h"
#include <map>
#include <queue>
#include <stack>
using namespace std;

#ifndef TREE_H
#define TREE_H

template <typename t>
class Node {
    map<t, Node*> children;
    public:
        int data;
        Node(t data){
            this->data = data;
        }

        ~Node() {
            destroy();
        }

        void destroy() {
            for(auto it = children.begin();it != children.end();it++) {
                auto node = (*it).second;
                node->destroy();
                delete node;
                node = nullptr;
            }
            children.clear();
        }

        void insertSequence(queue<t> sequence) {
            if (!sequence.empty()) {
                int childData = sequence.front();
                sequence.pop();
                if (children.count(childData) == 0){
                    children[childData] = new Node(childData);
                }
                children[childData]->insertSequence(sequence);
            }
        }
        
        void insertSequence(t* array,int length) {
            queue<t> sequence;
            for(int i = 0; i < length; i++){
                sequence.push(array[i]);
            }
            this->insertSequence(sequence);
        }

        void insert(Node *child) {
            /// items have to unquie
            if (children.count(child->data) != 0) {
                throw new Exception("Duplicate data");
            }
            children[child->data] = child;
        }
};

#endif