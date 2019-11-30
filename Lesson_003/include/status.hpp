#ifndef STATUS_H_
#define STATUS_H_

#include <string>

namespace LCPP {

  /**
   * C++11/17 allows you to specify the underlying type of the enum,
   * the type MUST still be an integral data type
   * int
   * short
   * long
   * char
   * 
   * unsigned combinations are available too
   * 
   * @example
   * enum class MyEnum: [integral data type] {
   *  enum1,
   *  enum2
   * }
   */

  enum class Network: unsigned int {
    OK,
    PENDING,
    ERROR
  };

  enum class FileOperation: unsigned char {
    READ,
    WRITE,
    READ_WRITE,
    COPY
  };

  enum class HTTP_STATUS: unsigned short {
    OK = 200,
    MOVED_PERMANENTLY = 301,
    FOUND = 302,
    NOT_MODIFIED = 304,
    NOT_FOUND = 404,
    METHOD_NOT_ALLOWED = 405,
    NOT_ACCEPTABLE = 406,
    PROXY_AUTH_REQUIRED = 407,
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPL = 501,
    BAD_GATEWAY = 502,
    SERVER_UNAVAIL = 503,
    GATEWAY_TIMEOUT = 504
  };

}

#endif // STATUS_H_