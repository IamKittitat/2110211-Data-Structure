#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
    if(begin() <= a && a < end() && begin() <= b && b < end() && begin() <= a+m-1 && a+m-1 < end() && begin() <= b+m-1 && b+m-1 < end() && (a+m-1 < b || b+m-1 < a) && m > 0){
        CP::vector<T> v_tmp(m);
        int idx = 0;
        for(auto it = a;it!=a+m;it++,idx++){
            v_tmp[idx] = *it;
            // std::cout << *it << " ";
            *it = *(b+idx);
            // std::cout << *(b+(it-begin())) << " ";
            // std::cout << *it << std::endl;
        }
        // for(auto &x : *this) std::cout << x << " " ;
        auto it = b;
        for (int i = 0 ; i < v_tmp.size();i++){
            // std::cout << "CHECKK";
            *it = v_tmp[i];
            it++;
        }
        return true;
    } else{
        return false;
        }
}

#endif
