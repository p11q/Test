#ifndef INSERT_BUILDER_H
#define INSERT_BUILDER_H

#include "builder.h"
#include "insert/insert.h"
#include "SQLiteCpp/Backup.h"

class InsertBuilder : public Builder {
private:
    Insert insert_;
    SQLite::Database db_;
public:
    InsertBuilder(SQLite::Database &db, const std::string_view name_table, std::vector<std::string> &columns_values)
        : db_(std::move(db)), insert_{name_table, columns_values}{}

    void CreateSQLRequest() override {
        insert_.SQL_request();
    }

    void UsegeSQLRequests() override {
        db_.exec(insert_.GetRequest());
    }

};

#endif //INSERT_BUILDER_H
