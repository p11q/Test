#include <iostream>
#include <vector>

#include "SQLiteCpp/Database.h"
#include "directors/create_director.h"
#include "directors/insert_director.h"
#include "directors/select_director.h"

#include "builders/create_build.h"
#include "builders/insert_builder.h"
#include "builders/select_builder.h"

 /*TODO: Часто использую:
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
    Это нормально ? */

void UserInputColumns(std::vector<std::string> &column_name_list, std::map<std::string, std::string> &column_type) {

    int count_columns;
    std::cout << "Enter the number of columns: ";
    std::cin >> count_columns;

    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();

    for (int i = 0; i < count_columns; i++) {
        std::cout << "Enter the name of the column: ";

        std::string column_name;
        std::getline(std::cin, column_name);;

        column_name_list.push_back(column_name);

        std::cin.ignore(std::cin.rdbuf()->in_avail());

        std::cout << "Enter the corresponding data type: ";
        std::string data_type_column;
        std::getline(std::cin, data_type_column);

        column_type[column_name_list[i]] = data_type_column;

        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }

}

void UserOutputManual() {
    std::cout << "Enter the following values to find out: \n"
                 "1. '*' - viewing the values of all columns;\n"
                 "2. 'name 1', 'name 2', ... - viewing values of specific columns;\n"
                 "3. 'COUNT(*)' - viewing the number of columns\n"
                 "4. '0' - complete the input.\n";
}

void UserOutput(std::vector<std::string> &vec_name_first_argument_select) {
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();

    UserOutputManual(); // TODO: Использование флага ?
    int flag{0};

    while (flag == 0) {
        std::cout << ">> ";
        std::string name_argument_select_list;

        std::getline(std::cin, name_argument_select_list);

        if (name_argument_select_list == "0") {
            flag++;
        } else {
            vec_name_first_argument_select.push_back(name_argument_select_list);
        }
    }
}

void InsertValues(const std::vector<std::string> &column_name_list, std::vector<std::string> &columns_values) {
    std::cin.ignore(std::cin.rdbuf()->in_avail());

    for (int i{0}; i < column_name_list.size(); i++) {
            std::cout << "\nEnter the column value " <<  column_name_list[i] << ": ";

            std::string value_column;
            std::getline(std::cin, value_column);

            columns_values.push_back(value_column);

            std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
    //TODO: После крайнего Enter приходится еще раз нажимать Enter
}

int main() {
    try {
        // Создание базы данных
        const auto db = std::make_shared<SQLite::Database> ("/home/user/C++/Test/test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);


        // Имя базы данных
        std::cout << "Enter of the name for database: ";
        std::string name_table;
        std::cin >> name_table;

        // Наименование столбцов
        std::vector<std::string> column_name_list{};
        std::map<std::string, std::string> column_type;
        UserInputColumns(column_name_list, column_type);


        // Создание таблицы в базе данных
        CreateBuilder create_builder(db, name_table, column_name_list, column_type);
        CreateDirector create_director (create_builder);
        create_director.CreateSqliteRequest();


        // Заполнение таблицы
        std::vector<std::string> column_values{};
        InsertValues(column_name_list, column_values);
        InsertBuilder insert_builder(db, name_table,column_name_list, column_values);
        InsertDirector insert_director(insert_builder);
        insert_director.CreateSqliteRequest();


        // Вывод таблицы
        std::vector<std::string> select_arguments{};
        UserOutput(select_arguments);
        SelectBuilder select_builder(db, name_table, select_arguments);
        SelectDirector select_director(select_builder);
        select_director.CreateSqliteRequest();

    } catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

}


