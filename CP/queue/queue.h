#ifndef CP_QUEUE
#define CP_QUEUE

#include<iostream>
namespace CP{
    template<typename T>
    class queue{
        protected:
            T *mData;
            size_t mCap;
            size_t mSize;
            size_t mFront;

            void ensureCapacity(size_t capacity){
                if(capacity > mCap){
                    size_t n = capacity > 2*mCap ? capacity : 2*mCap;
                    expand(n);
                }
            }
            void expand(size_t n){
                T *newMData = new T[n]();
                for(size_t i = 0 ; i < mCap ;i++){
                    newMData[i] = mData[(mFront+i)%mCap];
                }
                delete [] mData;
                mData = newMData;
                mCap = n;
                mFront = 0;
            }

        public:
            //-------------- constructor ----------

            // Default Constructor
            queue(): mData(new T[1]()),mCap(1),mSize(0),mFront(0){}

            // Copy Constructor
            queue(const queue<T> &other){
                mData = new T[other.mCap];
                mSize = other.mSize;
                mCap = other.mCap;
                for(size_t i = 0 ; i<mSize;i++){
                    mData[i] = other.mData[(other.mFront+i)%mCap];
                }
            }

            // copy assignment operator
            queue<T>& operator=(queue<T> &other){
                using std::swap;
                swap(mData,other.mData);
                swap(mSize,other.mSize);
                swap(mCap,other.mCap);
                swap(mFront,other.mFront);
                return *this;
            }

            // Destructor
            ~queue(){
                delete [] mData;
            }

            //------------- capacity function -------------------
            bool empty() const {
                return mSize==0;
            }
            size_t size() const{
                return mSize;
            }

            //----------------- access -----------------
            const T& front() const {
                if (size() == 0) throw std::out_of_range("index of out range") ;
                return mData[mFront];
            }
            const T& back() const {
                if (size() == 0) throw std::out_of_range("index of out range") ;
                return mData[(mFront+mSize-1)%mCap];
            }

            //----------------- modifier -------------
            void push(const T &element){
                ensureCapacity(mSize+1);
                mData[(mFront+mSize)%mCap] = element;
                mSize++;
            }

            void pop(){
                if (size() == 0) throw std::out_of_range("index of out range") ;
                mFront = (mFront+1)%mCap;
                mSize--;
            }


    };
}


#endif // CP_QUEUE
