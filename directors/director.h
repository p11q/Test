#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"


class Director {
public:
    virtual ~Director() = default;
    virtual void CreateSqliteRequest() = 0;
    //virtual void SetBuilder(Builder& builder) = 0;
};

#endif //DIRECTOR_H
