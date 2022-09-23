#ifndef CP_STACK
#define CP_STACK

#include<iostream>
namespace CP{
    template<typename T>
    class stack{
        protected:
            T *mData;
            size_t mSize;
            size_t mCap;

            void ensureCapacity(size_t n){
                if(n > mCap){
                    size_t capacity = n > 2*mCap ? n : 2*mCap;
                    expand(capacity);
                }
            }

            void expand(size_t capacity){
                T *newMData = new T[capacity]();
                for(size_t i = 0;i<mSize;i++){
                    newMData[i] = mData[i];
                }
                delete []mData;
                mData = newMData;
                mCap = capacity;
            }
        public:
            //-------------- constructor ----------

            // Default Constructor
            stack(){
                int cap = 1;
                mData = new T[cap]();
                mSize = 0;
                mCap = cap;
            }

            // copy constructor
            stack(const CP::stack<T> &a){
                mData = new T[a.mCap]();
                mSize = a.mSize;
                mCap = a.mCap;
                for(size_t i = 0;i<a.size();i++){
                    mData[i] = a.mData[i];
                }
            }

            // copy assignment operator
            stack<T>& operator=(CP::stack<T> a){
                using std::swap;
                swap(mData,a.mData);
                swap(mSize,a.mSize);
                swap(mCap,a.mCap);
                return *this;
            }

            ~stack(){
                delete []mData;
            }

            //------------- capacity function -------------------

            bool empty() const {
                return mSize == 0;
            }
            size_t size() const {
                return mSize;
            }

            //----------------- access -----------------
            T& top() const {
                if(size() == 0 ) throw std::out_of_range("index out of range");
                return mData[mSize-1];
            }

            //----------------- modifier -------------
            void push(const T &element){
                ensureCapacity(mSize+1);
                mData[mSize] = element;
                mSize++;
            }

            void pop(){
                if(size() == 0) throw std::out_of_range("index out of range");
                mSize--;
            }
    };





}
#endif // CP_STACK
