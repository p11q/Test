#ifndef COLUMNS_H
#define COLUMNS_H

#include <utility>
#include <vector>

#include "sql_requests.h"

class Select : public SqliteRequest{
private:
    std::string name_table_;
    std::string request_{"SELECT "};
    std::vector<std::string> columns_{};
public:

    explicit Select(const std::string_view name_table, std::vector<std::string> &columns)
        :name_table_(name_table), columns_(std::move(columns)) {}

    void SQL_request() override;

    std::string GetRequest() override {
        return request_;
    }
};



#endif //COLUMNS_H
