#include "select.h"

void Select::SQL_request() {
    for (int i{0}; i < columns_.size(); i++) {
        if(i != columns_.size() - 1) {
            request_ += columns_[i] + ", ";
        } else {
            request_ += columns_[i];
        }
    }
    request_ += " FROM " + name_table_;
}
