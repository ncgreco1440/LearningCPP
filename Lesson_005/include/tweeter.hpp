#ifndef TWEETER_H_
#define TWEETER_H_

#include "person.hpp"
#include <string>

namespace LCPP {

  /**
   * A more specific person, that is capable of writing tweets
   */
  class Tweeter: public Person {
    public:
    Tweeter(std::string first, std::string last, int arbitrary, std::string handle);
    ~Tweeter();
    std::string getName() const;

    private:
    std::string twitterHnd;
  };

} // namespace LCPP

#endif // TWEETER_H_