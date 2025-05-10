#ifndef INSERT_DIRECTOR_H
#define INSERT_DIRECTOR_H

#include "builder.h"

class InsertDirector : public Director {
private:
    Builder& builder_;
public:
    explicit InsertDirector(Builder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateSQLRequest();
        builder_.UsegeSQLRequests();
    }

};


#endif //INSERT_DIRECTOR_H
