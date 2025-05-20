#include "select.h"

std::string Select::GetRequestPlainText() {
    for (const auto& column_name : column_names_) {
        request_ += " " + column_name + " ";
    }
    request_ += "FROM " + table_name_;

    return request_;
}
