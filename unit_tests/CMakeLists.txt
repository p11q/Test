set(PROJECT_NAME unit_tests)

list(APPEND ${PROJECT_NAME}_SOURCES
        "${CMAKE_SOURCE_DIR}/unit_tests/unit_tests.cpp"
)

add_executable(unit_tests ${${PROJECT_NAME}_SOURCES})

target_include_directories(My_Tests PUBLIC "${CMAKE_SOURCE_DIR}/lib/JSON/include"
        "${CMAKE_SOURCE_DIR}/sql_requests"
        "${CMAKE_SOURCE_DIR}/builders"
        "${CMAKE_SOURCE_DIR}/directors/"
        "${CMAKE_SOURCE_DIR}/lib/googletest-1.17.0/googletest/include/gtest"
)

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/SQLiteCpp"
        "${CMAKE_SOURCE_DIR}/lib/googletest-1.17.0")

target_link_libraries(My_Tests SQLiteCpp
        sqlite3
        pthread
        dl)
