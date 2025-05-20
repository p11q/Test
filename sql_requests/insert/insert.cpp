#include "insert.h"

//INSERT INTO table_name (column_name, ... , column_name) VALUES (value1, value2, value3, ...);

std::string Insert::GetRequestPlainText() {
    request_ += " " + table_name_ + "(";
    for (const auto& column_name : column_names_) {
        request_ += " '" + column_name + "',";
    }
    request_.back() = ')';

    request_ += " " + std::string("VALUES") + "(";
    for (const auto& val : values_) {
        request_ += " '" + val + "',";
    }
    request_.back() = ')';
    return request_;
}
