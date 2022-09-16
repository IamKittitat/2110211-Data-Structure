#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    T *newMData = new T[size()-pos.size()];
    int idx = 0,idx2 = 0;
    for(int i = 0; i<mSize;i++){
        if(i != pos[idx]){
            newMData[idx2] = mData[i];
            idx2++;
        }
        else{
            if(idx+1<pos.size())idx++;
        }
    }
    delete [] mData;
    mData = newMData;
    mSize = size()-pos.size();
    mCap = mSize;
    /*for(int i = pos.size()-1;i>=0;i--){
        erase(begin()+pos[i]);
    }*/

}

#endif
