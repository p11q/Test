#ifndef INSERT_BUILDER_H
#define INSERT_BUILDER_H

#include "builder.h"
#include "insert/insert.h"
#include "SQLiteCpp/Backup.h"

class InsertBuilder : public IBuilder {
private:
    std::shared_ptr<SQLite::Database> db_;
    std::string table_name_;
    std::vector<std::string> column_name_;
    std::vector<std::string> values_;
    Insert insert_;
public:
    InsertBuilder(const std::shared_ptr<SQLite::Database> &db, const std::string_view table_name, const std::vector<std::string> &column_name, const std::vector<std::string> &values)
        : db_(db), table_name_(table_name), column_name_(column_name), values_(values) {}

    void CreateTableName() override{
        insert_.AddTableName(table_name_);
    }

    void CreateColumns() override {
        insert_.AddColumns(column_name_);
    }

    void CreateValues() override {
        insert_.AddValues(values_);
    }

    void GetRequest() override {
        db_->exec(insert_.GetRequestPlainText());
    }
};


#endif //INSERT_BUILDER_H
