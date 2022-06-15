cmake_minimum_required( VERSION 3.1.0 )

project( TradeResearcher VERSION 1.0.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address" )
set( Boost_USE_MULTITHREADED ON )
set( CMAKE_THREAD_PREFER_PTHREAD TRUE )
set( THREADS_PREFER_PTHREAD_FLAG TRUE )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )
set( CMAKE_AUTOUIC OF )

################ VARIABLES ###########################
set( KERNEL_FILES src/kernel )
set( EXCEPTIONS_FILES ${KERNEL_FILES}/exceptions )
set( RESEARCHERS_FILES ${KERNEL_FILES}/researchers)
set( TRADES_FILES ${KERNEL_FILES}/trades )
set( LIBS_FILES ${KERNEL_FILES}/libs )
set( MAIN_WINDOW_FILES src/mainwindow )
# set( 
#     UI
#     ${CMAKE_CURRENT_LIST_DIR}/mainwindow.ui
# )
############# END VARIABLES ############################

############### SOURCE FILES ##############################
set(
    HEADER_FILES 
    src/main.hpp
    src/common.hpp
    ${KERNEL_FILES}/common.hpp
    ${RESEARCHERS_FILES}/inc/strategy_researchers.hpp
    ${RESEARCHERS_FILES}/inc/indicator_researchers.hpp
    ${RESEARCHERS_FILES}/inc/abstracts.hpp
    ${TRADES_FILES}/inc/trades.hpp
    ${TRADES_FILES}/inc/abstracts.hpp
    ${EXCEPTIONS_FILES}/inc/exceptions.hpp
    ${MAIN_WINDOW_FILES}/inc/mainwindow.hpp
    ${MAIN_WINDOW_FILES}/inc/ui_mainwindow.hpp
)
set(
    IMPLEMENTED_FILES
    src/main.cpp
    ${RESEARCHERS_FILES}/src/strategy_researchers.cpp
    ${RESEARCHERS_FILES}/src/indicator_researchers.cpp
    ${RESEARCHERS_FILES}/src/abstracts.cpp
    ${TRADES_FILES}/src/trades.cpp
    ${TRADES_FILES}/src/abstracts.cpp
    ${EXCEPTIONS_FILES}/src/exceptions.cpp
    ${MAIN_WINDOW_FILES}/src/mainwindow.cpp
)

set(
    LIBS_HEADER_FILES
    ${LIBS_FILES}/dotenv/include/dotenv.hpp
    # ${LIBS_FILES}/csv/csv.hpp
)

set(
    LIBS_IMPLEMENTED_FILES
    ${LIBS_FILES}/dotenv/src/dotenv.cpp
)
############## END SOURCE FILES ###########################

##################### PACKAGES#######################
find_package( Threads REQUIRED )
find_package( Boost COMPONENTS system REQUIRED )
find_package( CURL REQUIRED )
find_package( OpenSSL REQUIRED )
find_package( nlohmann_json REQUIRED )
find_package( Qt5 COMPONENTS 
    Widgets 
    Core 
    Network 
    Xml 
    WebKit
    WebKitWidgets
    REQUIRED 
)
####################### END PACKAGES#######################

#################### LINKING ##########################
add_subdirectory( ${LIBS_FILES}/TradeCore )

include_directories(
    /usr/local/include
    /usr/include/qt/QtNetwork
    /usr/include/x86_64-linux-gnu/qt5
    /usr/include/x86_64-linux-gnu/qt5/QtCore
    /usr/include/x86_64-linux-gnu/qt5/QtWidgets
    /usr/include/x86_64-linux-gnu/qt5/QtNetwork
    ${MYSQL_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${Qt5Widgets_INCLUDES}
)

add_definitions(
    -UNDEBUG
    -DDTF_HEADER_ONLY
    -D__FLATJSON__CHILDS_TYPE=std::uint32_t
    -D__FLATJSON__VLEN_TYPE=std::uint32_t
    -DHAVE_CURL
    ${Qt5Widgets_DEFINITIONS}
)

# qt5_wrap_ui( UI_HEADERS ${UI} )

add_executable(
    ${PROJECT_NAME}
    ${HEADER_FILES}
    ${IMPLEMENTED_FILES}
    ${LIBS_HEADER_FILES}
    ${LIBS_IMPLEMENTED_FILES}
    # mainwindow.ui
)

target_link_libraries(
    ${PROJECT_NAME}
    z
    crypto
    ssl
    pthread
    mysqlclient
    Threads::Threads
    OpenSSL::SSL
    nlohmann_json::nlohmann_json
    ${CMAKE_THREAD_LIBS_INIT}
    ${OPENSSL_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CURL_LIBRARIES}
    ${PYTHON_LIBRARIES}
    -L${BOOST_LIB_DIR}
    -LTradeCore
    Qt5::Widgets
    Qt5::Network
    Qt5::Xml
    Qt5::WebKit
    Qt5::WebKitWidgets
)
#################### END LINKING ####################################
