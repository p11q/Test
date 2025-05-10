#include "insert.h"

//INSERT INTO table_name VALUES(value1, value2, value3, ...);

void Insert::SQL_request() {
    request_ += name_table_ + " VALUES (";
    for (int i{0}; i < columns_values_.size(); i++) {
        if(i != columns_values_.size() - 1) {
            request_ += "'" + columns_values_[i] + "', ";
        } else {
            request_ += "'" + columns_values_[i] + "')";
        }
    }
}
