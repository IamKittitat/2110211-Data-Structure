#ifndef CP_PRIORITY_QUEUE
#define CP_PRIORITY_QUEUE

#include<iostream>
#include<stdexcept>
#include<vector>

namespace CP{
    template<typename T,typename Comp = std::less<T>>
    class priority_queue{
        protected:
            T* mData;
            size_t mSize;
            size_t mCap;
            Comp mLess;

            void expand(size_t capacity){
                T *arr = new T[capacity]();
                for(size_t i = 0; i< mSize;i++){
                    arr[i] = mData[i];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
            }

            void fixUp(size_t idx){
                T tmp = mData[idx];
                while(idx>0){
                    size_t p = (idx-1)/2;
                    if(mLess(tmp,mData[p])) break;
                    mData[idx] = mData[p];
                    idx = p;
                }
                mData[idx] = tmp;
            }

            void fixDown(size_t idx){
                T tmp = mData[idx];
                size_t c;
                while((c = 2*idx+1) < mSize){
                    if(c+1<mSize && mLess(mData[c],mData[c+1])) c++;
                    if(mLess(mData[c],tmp)) break;
                    mData[idx] = mData[c];
                    idx = c;
                }
                mData[idx] = tmp;
            }

        public:
            //-------------- constructor ----------
            // default constructor
            priority_queue(const Comp& c = Comp()):
                mData(new T[1]),
                mSize(0),
                mCap(1),
                mLess(c)
            {}

            // copy constructor
            priority_queue(priority_queue<T,Comp>& a):
                mData(new T[a.mCap]()),
                mSize(a.mSize),
                mCap(a.mCap),
                mLess(a.mLess)
            {
                for(size_t i = 0; i < a.mCap;i++){
                    mData[i] = a.mData[i];
                }
            }

            // copy assignment operator
            priority_queue<T,Comp>& operator=(priority_queue<T,Comp> other){
                using std::swap;
                swap(mData,other.mData);
                swap(mSize,other.mSize);
                swap(mCap,other.mCap);
                swap(mLess,other.mLess);
                return *this;
            }

            // constructor from vector (logn)
            priority_queue(std::vector<T> &v,const Comp& c = Comp()):
                mData(new T[v.size()]()),mSize(v.size()),mCap(v.size()),mLess(c)
            {
                for(size_t i = 0;i<mSize;i++) mData[i] = v[i];
                for(int i = mSize/2-1;i>=0;i--) fixDown(i);
            }

            // destructor
            ~priority_queue(){
                delete [] mData;
            }

            //------------- capacity function -------------------
            bool empty() const {
              return mSize == 0;
            }

            size_t size() const {
              return mSize;
            }

            //----------------- access -----------------
            const T& top(){
                if (size() == 0) throw std::out_of_range("index of out range") ;
                return mData[0];
            }

            //----------------- modifier -------------
            void push(const T& element){
                if(mSize + 1>mCap){
                    expand(mCap*2);
                }
                mData[mSize] = element;
                fixUp(mSize);
                mSize++;
            }

            void pop(){
                if (size() == 0) throw std::out_of_range("index of out range");
                mData[0] = mData[mSize-1];
                mSize--;
                fixDown(0);
            }

    };
}

#endif // CP_PRIORITY_QUEUE
