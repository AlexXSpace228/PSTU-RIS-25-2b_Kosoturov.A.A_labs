cmake_minimum_required(VERSION 3.16)
project(graph_app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF) # Включил на всякий случай
# a я выключил

# Ищем Qt 6, так как она у тебя установлена
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(graph_app 
        main.cpp
        ui_node.h
        ui_node.cpp
        data_graph.h
        data_graph.cpp
        ui_edge.h
        ui_edge.cpp
        mainwindow.h
        mainwindow.cpp

        adjacency_dialog.cpp
)

# Линкуем библиотеки Qt 6
target_link_libraries(graph_app
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
