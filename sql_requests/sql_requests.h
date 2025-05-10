#ifndef SQL_REQUESTS_H
#define SQL_REQUESTS_H

#include <string>

constexpr int kFirstValue{0};
constexpr int kSecondValue{1};


class SqliteRequest {
public:
    virtual ~SqliteRequest() = default;

    virtual void SQL_request() = 0;

    virtual std::string GetRequest() = 0;

};

#endif //SQL_REQUESTS_H
