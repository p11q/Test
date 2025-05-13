#include <iostream>
#include <vector>

#include "SQLiteCpp/Database.h"
#include "create_build/create_build.h"
#include "directors/create_director.h"
#include "directors/insert_director.h"
#include "directors/select_director.h"
#include "insert_builder/insert_builder.h"
#include "select_builder/select_builder.h"


// TODO: как передать в конструктор класса const ссылку на БД ? А иначе при выходе из класса для БД вызывается деструктор

void UserInputColumns(std::vector<std::vector<std::string>> &name_columns) {

    int count_columns;
    std::cout << "Enter the number of columns: ";
    std::cin >> count_columns;
    name_columns.resize(count_columns, std::vector<std::string>());

    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();

    for (int i{0}; i < count_columns; i++) {
        std::cout << "Enter the name of the column: ";

        std::string name_column;
        std::getline(std::cin, name_column);;

        name_columns[i].push_back(name_column);

        std::cin.ignore(std::cin.rdbuf()->in_avail());

        std::cout << "Enter the corresponding data type: ";
        std::string data_type_column;
        std::getline(std::cin, data_type_column);

        name_columns[i].push_back(data_type_column);

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
    UserOutputManual();
    int flag{0};

    while (flag == 0) {
        std::cout << ">> ";
        std::string name_first_argument_select;
        std::getline(std::cin, name_first_argument_select);
        if (name_first_argument_select == "0") {
            flag++;
        } else {
            vec_name_first_argument_select.push_back(name_first_argument_select);
        }
    }
}

void InsertValues(const std::vector<std::vector<std::string>> &name_columns, std::vector<std::string> &columns_values) {
    for (int i{0}; i < name_columns.size(); i++) {
            std::cout << "Enter the column value " <<  name_columns[0][i] << ": ";

            std::string value_column;
            std::getline(std::cin, value_column);

            columns_values.push_back(value_column);

            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cout << std::endl;

    }
}

int main() {
    try {
        // Создание базы данных
        SQLite::Database db ("/home/user/C++/Test/test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
        std::shared_ptr<SQLite::Database> db_ptr(&db);

        // Имя базы данных
        std::cout << "Enter of the name for database: ";
        std::string name_table;
        std::cin >> name_table;

        // Наименование столбцов
        std::vector<std::vector<std::string>> name_columns{{}};
        UserInputColumns(name_columns);

        // Создание таблицы в базе данных
        CreateBuilder create_builder(&db_ptr.operator*(), name_table, name_columns);
        CreateDirector create_director(create_builder);
        create_director.CreateSqliteRequest();

        // Заполнение таблицы
        std::vector<std::string> columns_values{};
        InsertValues(name_columns, columns_values);
        InsertBuilder insert_builder(*db_ptr, name_table,columns_values);
        InsertDirector insert_director(insert_builder);
        insert_director.CreateSqliteRequest();

        // Вывод таблицы
        std::vector<std::string> select_arguments{};
        UserOutput(select_arguments);
        SelectBuilder select_builder(*db_ptr, name_table, select_arguments);
        SelectDirector select_director(select_builder);
        select_director.CreateSqliteRequest();


    } catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

}


