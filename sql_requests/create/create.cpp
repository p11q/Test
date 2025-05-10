#include "create.h"

void Create::SQL_request() {
    request_ += name_table_ + "(";
    for (size_t i{0}; i < name_columns_.size(); i++) {
        if(i == name_columns_.size() - 1) {
            request_ += "'" + name_columns_[i][kFirstValue] + "' " + name_columns_[i][kSecondValue] + ")";
        } else {
            request_ += "'" + name_columns_[i][kFirstValue] + "' " + name_columns_[i][kSecondValue] + ", ";
        }
    }
}

