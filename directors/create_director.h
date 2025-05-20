#ifndef CREATE_DIRECTOR_H
#define CREATE_DIRECTOR_H

#include <director.h>
#include "builder.h"

class CreateDirector : public IDirector {
private:
    IBuilder& builder_;
public:
    explicit CreateDirector(IBuilder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateTableName();
        builder_.CreateColumns();
        builder_.CreateColumnTypes();
        builder_.GetRequest();
    }

    void SetBuilder(IBuilder &builder) override {
        builder_ = builder;
    }

};


#endif //CREATE_DIRECTOR_H
