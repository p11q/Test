#ifndef CREATE_TABLE_BUILD_H
#define CREATE_TABLE_BUILD_H

#include <iostream>

#include "builder.h"
#include "SQLiteCpp/Database.h"


class CreateBuilder : public Builder {
private:
    SQLite::Database db_;
    Create create_table_;
public:
    CreateBuilder(SQLite::Database sdb, const std::string_view name_table, const std::vector<std::vector<std::string>> &name_columns)
        : db_(std::move(db)), create_table_{name_table, name_columns}{}

    void CreateSQLRequest() override {
        create_table_.SQL_request();
    }

    void UsegeSQLRequests() override {
        try {
            db_.exec(create_table_.GetRequest());
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

    }

};

#endif //CREATE_TABLE_BUILD_H
