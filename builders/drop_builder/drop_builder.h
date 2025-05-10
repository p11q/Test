#ifndef DROP_BUILDER_H
#define DROP_BUILDER_H

#include "builder.h"
#include "SQLiteCpp/Backup.h"


class DropBuilder : public Builder {
private:
    Drop drop_;public:
    SQLite::Database db_;
public:
    DropBuilder(const std::string_view name_table, SQLite::Database db)
        : drop_(name_table), db_(std::move(db)){}

    void CreateSQLRequest() override {
        drop_.SQL_request();
    }

    void UsegeSQLRequests() override {
        db_.exec(drop_.GetRequest());
    }
};

#endif //DROP_BUILDER_H
