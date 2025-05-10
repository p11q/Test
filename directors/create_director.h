#ifndef CREATE_DIRECTOR_H
#define CREATE_DIRECTOR_H

#include <director.h>

class CreateDirector : public Director {
private:
    Builder& builder_;
public:
    explicit CreateDirector(Builder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateSQLRequest();
        builder_.UsegeSQLRequests();
    }

};


#endif //CREATE_DIRECTOR_H
