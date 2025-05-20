#ifndef CREATE_TABLE_BUILD_H
#define CREATE_TABLE_BUILD_H

#include "builder.h"
#include "create/create.h"
#include "SQLiteCpp/Database.h"


class CreateBuilder : public IBuilder {
private:
    std::shared_ptr<SQLite::Database> db_;
    std::string table_name_;
    std::vector<std::string> column_name_;
    std::map<std::string, std::string> columns_type_;
    CreateTable create_table_;
public:
    CreateBuilder(const std::shared_ptr<SQLite::Database> &db, const std::string_view table_name, const std::vector<std::string> &column_name, const std::map<std::string, std::string>& columns_type)
        : db_(db), table_name_(table_name), column_name_(column_name), columns_type_(columns_type) {}

    void CreateTableName() override{
        create_table_.AddTableName(table_name_);
    }

    void CreateColumns() override {
        create_table_.AddColumns(column_name_);
    };

    void CreateColumnTypes() override {
        create_table_.AddColumnTypes(columns_type_);
    };

    // CREATE TABLE IF NOT EXISTS new_table2 (id Integer);
    void GetRequest() override {
        db_->exec(create_table_.GetRequestPlainText());
    }

};

#endif //CREATE_TABLE_BUILD_H
