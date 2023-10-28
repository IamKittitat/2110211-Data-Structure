#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos, Comp comp) const
{
  // your code here
  sort(pos.begin(), pos.end());
  T ans = mData[(mFront + pos[0]) % mCap];

  for (int i = 0; i < pos.size(); i++)
  {
    int idx = pos[i];
    if (idx < mSize && comp(mData[(mFront + idx) % mCap], ans))
    {
      ans = mData[(mFront + idx) % mCap];
    }
  }
  // should return something
  return ans;
}

#endif
