enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_definitions(-DBOOST_TEST_DYN_LINK)
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories(${Boost_INCLUDE_DIRS})

macro(addTest testName)
    add_executable(${testName} ${testName}.cpp)
    target_link_libraries(${testName} ${Boost_LIBRARIES} ${PROJECT_NAME})
    PKG_CONFIG_USE_DEPENDENCY(${testName} eigen-qld)
    PKG_CONFIG_USE_DEPENDENCY(${testName} eigen-quadprog)
    if(${EIGEN_LSSOL_FOUND})
        PKG_CONFIG_USE_DEPENDENCY(${testName} eigen-lssol)
        add_definitions(-DLSSOL_SOLVER_FOUND)
    endif()
    add_test(${testName}Unit ${testName})
endmacro(addTest)

addTest(TestSolvers)
addTest(TestPreviewControl)