#ifndef FUNCTIONS_HEADER_
#define FUNCTIONS_HEADER_

namespace LCPP {

  /**
   * Return the greater of two values
   */
  template<class T>
  T max(T const& t1, T const& t2) {
    return t1 > t2 ? t1 : t2;
  }

}



#endif // FUNCTIONS_HEADER_