#ifndef BUILDER_H
#define BUILDER_H
#include <sql_requests.h>
#include <create/create.h>


class Builder {
public:
    virtual ~Builder() = default;
    virtual void CreateSQLRequest() = 0;
    virtual void UsegeSQLRequests() = 0;
    
};

#endif //BUILDER_H
