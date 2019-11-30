#ifndef STATUS_H_
#define STATUS_H_

namespace LCPP {

  enum Network {
    OK,
    PENDING,
    ERROR
  };

  enum class FileOperation {
    READ = 'read',
    WRITE = 'write',
    READ_WRITE = 'read/write',
    COPY = 'copy'
  };

}

#endif // STATUS_H_