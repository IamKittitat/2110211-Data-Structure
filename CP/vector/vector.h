#ifndef CP_VECTOR
#define CP_VECTOR

#include<iostream>
#include <stdexcept>
namespace CP{
    template <typename T>
    class vector{
        public:
            typedef T* iterator;
        protected:
            T *mData;
            size_t mSize;
            size_t mCap;

            void ensureCapacity(size_t capacity){
                if(capacity > mCap){
                    size_t s = (capacity > 2*mCap) ? capacity : 2*mCap;
                    expand(s);
                }
            }
            void expand(size_t s){
                T *newMData = new T[s]();
                for(size_t i = 0;i<mSize;i++){
                    newMData[i] = mData[i];
                }
                delete []mData;
                mData = newMData;
                mCap = s;
            }
            void rangeCheck(int n){
                if(n<0 || (size_t)n>=mSize){
                    throw std::out_of_range("Index out of range");
                }
            }
        public:
            //-------------- constructor & copy operator ----------
            // default constructor
            vector(){
                int cap = 1;
                mData = new T[cap]();
                mCap = cap;
                mSize = 0;
            }
            // constructor with initial size
            vector(size_t n){
                mData = new T[n]();
                mCap = n;
                mSize = n;
            }
            // copy constructor
            vector(vector<T> &other){
                mData = new T[other.capacity()]();
                mCap = other.capacity();
                mSize = other.size();
                for(size_t i = 0 ; i < mSize;i++){
                    mData[i] = other[i];
                }
            }
            // copy assignment operator using copy-and-swap idiom
            vector<T>& operator=(vector<T> other){
                using std::swap;
                swap(this->mData,other.mData);
                swap(this->mSize,other.mSize);
                swap(this->mCap,other.mCap);
                return *this;
            }

            // desctructor
            ~vector(){
                delete []mData;
            }

             //----------------- access -----------------
             T& at(int index){
                rangeCheck(index);
                return mData[index];
             }
             T& operator[](int index){
                return mData[index];
             }

             //----------------- modifier -------------
             void push_back(const T& element){ //!!!
                /*ensureCapacity(mSize+1);
                mData[mSize] = element;
                mSize++;*/
                insert(end(),element);
             }
             void pop_back(){
                mSize--;
             }

             iterator insert(iterator it,const T& element){
                size_t pos = it-begin();
                ensureCapacity(mSize+1);
                for(size_t i = mSize;i>pos;i--){
                    mData[i] = mData[i-1];
                }
                mData[pos] = element;
                mSize++;
                return begin()+pos;
             }

             void erase(iterator it){
                while(it != end()){
                    *it = *(it+1);
                    it++;
                }
                mSize--;
             }

             void clear(){
                mSize = 0;
             }

             //------------- capacity function -------------------
             bool empty() const{
                return mSize == 0;
             }
             size_t size() const{
                return mSize;
             }
             size_t capacity() const{
                return mCap;
             }

             void resize(size_t n){
                ensureCapacity(n);
                if(n > mSize){
                    T init = T();
                    for(size_t i=mSize;i<n;i++) mData[i] = init;
                }
                mSize = n;
             }

             //----------------- iterator ---------------
             iterator begin(){
                return &mData[0];
             }
             iterator end(){
                return begin()+mSize;
             }

             //-------------- extra (unlike STL) ------------------
             void insert_by_pos(size_t it,const T& element){
                insert(begin()+it,element);
             }

             void erase_by_pos(int index){
                erase(begin()+index);
             }

             void erase_by_value(const T& element){
                int i = index_of(element);
                if(i != -1) erase_by_pos(i);
             }

             bool contains(const T& element){
                return index_of(element) != -1;
             }

             int index_of(const T& element){
                for (int i = 0;i < mSize;i++) {
                    if (mData[i] == element) return i;
                }
                return -1;
             }
    };
}
#endif // CP_VECTOR
