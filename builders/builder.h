#ifndef BUILDER_H
#define BUILDER_H
#include "sql_requests.h"


class IBuilder {
public:
    virtual ~IBuilder() = default;

    virtual void CreateTableName() {}
    virtual void CreateColumns() {}
    virtual void CreateValues() {}
    virtual void CreateColumnTypes() {}

    virtual void GetRequest() = 0;

};

#endif //BUILDER_H
