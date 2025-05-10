#ifndef DROP_DIRECTOR_H
#define DROP_DIRECTOR_H


#include "builder.h"

class DropDirector : public Director {
private:
    Builder& builder_;
public:
    explicit DropDirector(Builder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateSQLRequest();
        builder_.UsegeSQLRequests();
    }

};

#endif //DROP_DIRECTOR_H
