#ifndef INSERT_H
#define INSERT_H

#include <utility>
#include <vector>

#include "sql_requests.h"


class Insert : public SqliteRequest{
private:
    std::string name_table_;
    std::vector<std::string> columns_values_;
    std::string request_{"INSERT INTO "};
public:
    explicit Insert(const std::string_view name_table, std::vector<std::string> columns_values)
        :name_table_(name_table),  columns_values_(std::move(columns_values)){}

    void SQL_request() override;

    std::string GetRequest() override {
        // INSERT INTO test VALUES (...)
        return request_;
    }
};


#endif //INSERT_H
