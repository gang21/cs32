//
//  linear.cpp
//  HW3
//
//  Created by Gabriella Ang on 2/5/22.
//

#include <stdio.h>
#include <iostream>

bool somePredicate(double x) {
    return x > 0;
}

// Return true if the somePredicate function returns false for at
    // least one of the array elements, false otherwise.
  bool anyFalse(const double a[], int n)
  {
      if(n <= 0)
          return false;
      if (n == 1)
          return !somePredicate(a[0]);
      
      return (!somePredicate(a[n-1]) || anyFalse(a, n-1));
  }

    // Return the number of elements in the array for which the
    // somePredicate function returns false.
  int countFalse(const double a[], int n)
  {
      return -999;  // This is incorrect.
  }

    // Return the subscript of the first element in the array for which
    // the somePredicate function returns true.  If there is no such
    // element, return -1.
  int firstTrue(const double a[], int n)
  {
      return -999;  // This is incorrect.
  }

    // Return the subscript of the largest element in the array (i.e.,
    // return the smallest subscript m such that a[m] >= a[k] for all
    // k such that k >= 0 and k < n).  If there is no such subscript,
    // return -1.
  int locateMax(const double a[], int n)
  {
      return -999;  // This is incorrect.
  }

    // If all n2 elements of a2 appear in the n1 element array a1, in
    // the same order (though not necessarily consecutively), then
    // return true; otherwise (i.e., if the array a1 does not contain
    // a2 as a not-necessarily-contiguous subsequence), return false.
    // (Of course, if a2 is empty (i.e., n2 is 0), return true.)
    // For example, if a1 is the 7 element array
    //    10 50 40 20 50 40 30
    // then the function should return true if a2 is
    //    50 20 30
    // or
    //    50 40 40
    // and it should return false if a2 is
    //    50 30 20
    // or
    //    10 20 20
  bool contains(const double a1[], int n1, const double a2[], int n2)
  {
      return false;  // This is not always correct.
  }


int main() {
    double a[] = {};
    std::cout << anyFalse(a, 0) << std::endl;
    double b[2] = {1, -2};
    std::cout << anyFalse(b, 2) << std::endl;
    double c[2] = {1, 1};
    std::cout << anyFalse(c, 2) << std::endl;
    double d[3]{-1, 2, 3};
    std::cout << anyFalse(d, 3) << std::endl;
}
