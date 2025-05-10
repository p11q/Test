#ifndef DROP_H
#define DROP_H

#include "sql_requests.h"

class Drop : public SqliteRequest{
private:
    std::string name_table_;
    std::string request_{"DROP TABLE IF EXISTS "};
public:
    explicit Drop(const std::string_view name_table)
        :name_table_(name_table) {}

    void SQL_request() override {
        request_ += name_table_;
    };

    std::string GetRequest() override {
        return request_;
    }
};




#endif //DROP_H
