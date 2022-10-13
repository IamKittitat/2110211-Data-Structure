#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    T *newMData = new T[mSize - pos.size()];
    int idx = 0, idxP = 0;
    for(int i = 0 ; i<mSize;i++){
        if(idxP<pos.size()-1 && i > pos[idxP]) idxP++;
        if(i < pos[idxP] || i>pos[pos.size()-1]){
           newMData[idx++] = mData[i];
        }
    }
    delete [] mData;
    mData = newMData;
    mSize = mSize- pos.size();
    mCap = mSize;
}

#endif
