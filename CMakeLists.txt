cmake_minimum_required(VERSION 3.28)
project(My_Tests)

set(CMAKE_CXX_STANDARD 20)

list(APPEND ${PROJECT_NAME}_SOURCES main.cpp
                                    sql_requests/insert/insert.cpp
                                    sql_requests/select/select.cpp
)

add_executable(My_Tests ${${PROJECT_NAME}_SOURCES})

target_include_directories(My_Tests PUBLIC "${CMAKE_SOURCE_DIR}/lib/JSON/include"
                                        "${CMAKE_SOURCE_DIR}/sql_requests"
                                        "${CMAKE_SOURCE_DIR}/builders"
                                        "${CMAKE_SOURCE_DIR}/directors/"
                                        )

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/SQLiteCpp"
                 "${CMAKE_SOURCE_DIR}/unit_tests")

target_link_libraries(My_Tests SQLiteCpp
        sqlite3
        pthread
        dl)

