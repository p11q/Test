#ifndef SELECT_BUILDER_H
#define SELECT_BUILDER_H

#include <vector>

#include "select/select.h"
#include "builder.h"
#include "SQLiteCpp/Database.h"

class SelectBuilder : public IBuilder {
private:
    std::shared_ptr<SQLite::Database> db_;
    std::string table_name_;
    std::vector<std::string> column_name_;
    Select select_;
public:
    SelectBuilder(const std::shared_ptr<SQLite::Database> &db, const std::string_view table_name, const std::vector<std::string> &column_name)
        : db_(db), table_name_(table_name), column_name_(column_name) {}

    void CreateTableName() override{
        select_.AddTableName(table_name_);
    }

    void CreateColumns() override {
        select_.AddColumns(column_name_);
    };

    void GetRequest() override {


        SQLite::Statement   query(*db_, select_.GetRequestPlainText());
        std::cout << "SELECT:\n";
        while (query.executeStep())
        {
            std::cout << "row (\"" << query.getColumn(0) << ", " << query.getColumn(1)   << "\")\n";
        }
    }
};


#endif //SELECT_BUILDER_H
