#include "select_builder.h"

#include <iostream>


void SelectBuilder::UsegeSQLRequests() {

    SQLite::Statement   query(db_, select_.GetRequest());
    std::cout << "SELECT ";
    for (int i{0}; i < agruments_select_.size(); i++) {
        if(i != agruments_select_.size() - 1) {
            std::cout << agruments_select_[i] << ", ";
        } else {
            std::cout << agruments_select_[i];
        }
    }

    std::cout << " FROM " << name_table_ << " :" << std::endl;

    while (query.executeStep()) {
        std::cout << "row (";
        for (int j{0}; j < agruments_select_.size(); j++){
            if(j != agruments_select_.size() - 1) {
                std::cout << query.getColumn(j) << ", ";
            } else {
                std::cout << query.getColumn(j) << ")";
            }
        }
    }
}
