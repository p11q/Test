project(Google_tests)

add_subdirectory("${CMAKE_SOURCE_DIR}/google_test/lib/googletest")

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target a
dd_executable(Google_Tests_run testDB.cpp)

# linking Google_Tests_run with
target_link_libraries(Google_Tests_run "${CMAKE_SOURCE_DIR}/lib/JSON/include"
                                        "${CMAKE_SOURCE_DIR}/sql_requests"
                                        "${CMAKE_SOURCE_DIR}/builders"
                                        "${CMAKE_SOURCE_DIR}/directors/"
)

target_link_libraries(Google_Tests_run gtest gtest_main)