#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <string>

namespace LCPP {

  class Resource {
    public:
    explicit Resource(std::string n);
    ~Resource(void);
    std::string GetName() const {
      return this->name;
    }

    private:
    std::string name;
  };

} // namespace LCPP

#endif // RESOURCE_H_
