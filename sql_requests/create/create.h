#ifndef CREATE_H
#define CREATE_H

#include <vector>

#include "sql_requests.h"

class Create : public SqliteRequest{
private:
    std::string name_table_;
    std::string request_{"CREATE TABLE IF NOT EXISTS "};
    std::vector<std::vector<std::string>> name_columns_;
public:
    explicit Create(const std::string_view name_table, const std::vector<std::vector<std::string>> &name_columns)
        :name_table_(name_table), name_columns_(name_columns) {}

    void SQL_request() override;

    std::string GetRequest() override {
        return request_;
    }
};



#endif //CREATE_TABLE_H
