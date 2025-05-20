#ifndef SELECT_DIRECTOR_H
#define SELECT_DIRECTOR_H


#include "builder.h"
#include "director.h"

class SelectDirector : public IDirector {
private:
    IBuilder& builder_;
public:
    explicit SelectDirector(IBuilder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateTableName();
        builder_.CreateColumns();
        builder_.GetRequest();
    }

    void SetBuilder(IBuilder &builder) override {
        builder_ = builder;
    }

};

#endif //SELECT_DIRECTOR_H
