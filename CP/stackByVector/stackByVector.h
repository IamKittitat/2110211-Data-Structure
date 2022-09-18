#ifndef CP_STACK_BY_VECTOR
#define CP_STACK_BY_VECTOR

#include<vector>
namespace CP{
    template<typename T>
    class stack{
        protected:
            std::vector<T> v;
        public:
            // Default Constructor
            stack(): v(){};
            // Capacity Function
            bool empty() const {return v.empty();}
            size_t size() const {return v.size();}
            // Access
            const T& top() const{
                if(size() == 0 ) throw std::out_of_range("index out of range");
                return v.back();
            }
            // Modifier
            void push(const T &element){v.push_back(element);};
            void pop(){
                if(size() == 0 ) throw std::out_of_range("index out of range");
                v.pop_back();
            }
    };
}
#endif // CP_STACK_BY_VECTOR
