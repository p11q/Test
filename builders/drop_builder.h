#ifndef DROP_BUILDER_H
#define DROP_BUILDER_H

#include "builder.h"
#include "drop/drop.h"
#include "SQLiteCpp/Backup.h"

class DropBuilder : public IBuilder {
private:
    std::shared_ptr<SQLite::Database> db_;
    std::string table_name_;
    Drop drop_;
public:
    DropBuilder(const std::shared_ptr<SQLite::Database> &db, const std::string_view table_name)
        : db_(db), table_name_(table_name) {}

    void CreateTableName() override{
        drop_.AddTableName(table_name_);
    }

    void GetRequest() override {
        db_->exec(drop_.GetRequestPlainText());
    }
};


#endif //DROP_BUILDER_H
