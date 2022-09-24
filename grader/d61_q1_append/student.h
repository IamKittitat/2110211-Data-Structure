#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while(!s.empty()){
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            push(q.front());
            q.pop();
        }
    }
}
