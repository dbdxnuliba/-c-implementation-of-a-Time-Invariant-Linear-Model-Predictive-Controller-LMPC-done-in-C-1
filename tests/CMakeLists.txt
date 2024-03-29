# This file is part of copra.

# copra is free software: you can redistribute it and/or
# modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# copra is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with copra.  If not, see
# <http://www.gnu.org/licenses/>.

set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

macro(addTest testName)
    add_executable(${testName} ${testName}.cpp systems.h tools.h tools.cpp)
    target_link_libraries(${testName} PRIVATE Boost::unit_test_framework ${PROJECT_NAME})
    add_test(${testName}Unit ${testName})
    # Adding a project configuration file (for MSVC only)
    generate_msvc_dot_user_file(${testName} "$(SolutionDir)/src/${PROJECT_NAME}")
endmacro(addTest)

addTest(TestSolvers)
addTest(TestLMPC)