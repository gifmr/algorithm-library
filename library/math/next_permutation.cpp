#include <bits/stdc++.h>
using namespace std;

template <class Iterator> bool next_permutation(Iterator first, Iterator last) {
  if (first == last)
    return false;
  Iterator i = last;
  if (first == --i)
    return false;
  while (1) {
    Iterator i1 = i, i2;
    if (*--i < *i1) {
      i2 = last;
      while (!(*i < *--i2))
        ;
      iter_swap(i, i2);
      reverse(i1, last);
      return true;
    }
    if (i == first) {
      reverse(first, last);
      return false;
    }
  }
}