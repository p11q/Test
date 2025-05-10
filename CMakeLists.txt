cmake_minimum_required(VERSION 3.28)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

list(APPEND ${PROJECT_NAME}_SOURCES main.cpp
                                    sql_requests/sql_requests.cpp
                                    sql_requests/insert/insert.cpp
                                    sql_requests/create/create.cpp
                                    sql_requests/select/select.cpp

                                    builders/create_build/create_build.cpp
                                    builders/insert_builder/insert_builder.cpp
                                    builders/select_builder/select_builder.cpp
                                    builders/drop_builder/drop_builder.cpp

)

add_executable(Tests ${${PROJECT_NAME}_SOURCES})

target_include_directories(Tests PUBLIC "${CMAKE_SOURCE_DIR}/lib/JSON/include"
                                        "${CMAKE_SOURCE_DIR}/sql_requests"
                                        "${CMAKE_SOURCE_DIR}/builders"
                                        "${CMAKE_SOURCE_DIR}/directors/"
                                        )

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/SQLiteCpp")
target_link_libraries(Tests SQLiteCpp
        sqlite3
        pthread
        dl)

