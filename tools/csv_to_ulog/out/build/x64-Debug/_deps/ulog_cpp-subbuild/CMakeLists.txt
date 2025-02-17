# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.21.21080301-MSVC_2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(ulog_cpp-populate NONE)

# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[GIT_EXECUTABLE-NOTFOUND]==])
set(GIT_VERSION_STRING [==[]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[GIT_EXECUTABLE-NOTFOUND;]==]
)


include(ExternalProject)
ExternalProject_Add(ulog_cpp-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/PX4/ulog_cpp.git" "GIT_TAG" "cf24ec6"
                    SOURCE_DIR          "C:/Users/Ученик/Downloads/smel-ok/smel-ok/tools/csv_to_ulog/out/build/x64-Debug/_deps/ulog_cpp-src"
                    BINARY_DIR          "C:/Users/Ученик/Downloads/smel-ok/smel-ok/tools/csv_to_ulog/out/build/x64-Debug/_deps/ulog_cpp-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


