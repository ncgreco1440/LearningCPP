#ifndef ACCUM_HEADER_
#define ACCUM_HEADER_

#include <string>

namespace LCPP {

  template<class T>
  class Accum {
    public:
    explicit Accum(T start): total(start){};
    T operator+=(T const& inc) {
      return total += inc;
    }

    T GetTotal() const {
      return this->total;
    }

    private:
    T total;
  };

  /**
   * Template specialization for std::string
   * Let's assume that when concat strings we actually just want to accumulate
   * the amount of characters.
   */
  template<>
  class Accum<std::string> {
    public:
    explicit Accum(std::string start): total(start.length()){};
    int operator+=(std::string const& inc) {
      return total += inc.length();
    }
    int GetTotal() const {
      return this->total;
    }

    private:
    int total;
  };

} // namespace LCPP

#endif // ACCUM_HEADER_
