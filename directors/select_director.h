#ifndef SELECT_DIRECTOR_H
#define SELECT_DIRECTOR_H


#include "builder.h"

class SelectDirector : public Director {
private:
    Builder& builder_;
public:
    explicit SelectDirector(Builder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateSQLRequest();
        builder_.UsegeSQLRequests();
    }

};

#endif //SELECT_DIRECTOR_H
