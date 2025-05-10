#ifndef SELECT_H
#define SELECT_H

#include "select/select.h"
#include "builder.h"
#include "SQLiteCpp/Database.h"

class SelectBuilder : public Builder {
private:
    SQLite::Database db_;
    Select select_;
    std::string name_table_;
    std::vector<std::string> agruments_select_{};
public:
    SelectBuilder(SQLite::Database &db, const std::string_view name_table, std::vector<std::string> &vec_arguments_select)
        : db_(std::move(db)), select_{name_table, vec_arguments_select}, name_table_(name_table), agruments_select_(vec_arguments_select){}

    void CreateSQLRequest() override {
        select_.SQL_request();
    }

    void UsegeSQLRequests() override;
};

#endif //SELECT_H
