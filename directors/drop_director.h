#ifndef DROP_DIRECTOR_H
#define DROP_DIRECTOR_H


#include "builder.h"
#include "director.h"

class DropDirector : public IDirector {
private:
    IBuilder& builder_;
public:
    explicit DropDirector(IBuilder& builder)
        : builder_(builder){}

    void CreateSqliteRequest() override {
        builder_.CreateTableName();
        builder_.GetRequest();
    }

};
#endif //DROP_DIRECTOR_H
