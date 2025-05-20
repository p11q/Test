#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"


class IDirector {
public:
    virtual ~IDirector() = default;
    virtual void CreateSqliteRequest() = 0;
    virtual void SetBuilder(IBuilder& builder) = 0;
};

#endif //DIRECTOR_H
