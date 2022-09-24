#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        stack<T> tmp_this;
        stack<T> tmp_s;
        while(!empty()){
            tmp_this.push(top());
            pop();
        }
        while(!s.empty()){
            tmp_s.push(s.top());
            s.pop();
        }
        while(!tmp_s.empty()){
            push(tmp_s.top());
            tmp_s.pop();
        }
        while(!tmp_this.empty()){
            push(tmp_this.top());
            tmp_this.pop();
        }
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> tmp_this;
        stack<T> tmp_q;
        while(!empty()){
            tmp_this.push(top());
            pop();
        }
        while(!q.empty()){
            tmp_q.push(q.front());
            q.pop();
        }
        while(!tmp_q.empty()){
            push(tmp_q.top());
            tmp_q.pop();
        }
        while(!tmp_this.empty()){
            push(tmp_this.top());
            tmp_this.pop();
        }
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
