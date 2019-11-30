#ifndef TWEETER_H_
#define TWEETER_H_

#include <string>
#include "person.hpp"

namespace LCPP {

  /**
   * A more specific person, that is capable of writing tweets
   */
  class Tweeter: public Person {
    public:
      Tweeter(std::string first, std::string last, int arbitrary,
        std::string handle);
      ~Tweeter();
    private:
      std::string twitterHnd;
  };

}

#endif // TWEETER_H_