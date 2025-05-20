#ifndef INSERT_DIRECTOR_H
#define INSERT_DIRECTOR_H

#include "builder.h"
#include "director.h"

class InsertDirector : public IDirector {
private:
    IBuilder& builder_;
public:
    explicit InsertDirector(IBuilder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateTableName();
        builder_.CreateColumns();
        builder_.CreateValues();
        builder_.GetRequest();
    }

    void SetBuilder(IBuilder &builder) override {
        builder_ = builder;
    }
};


#endif //INSERT_DIRECTOR_H
