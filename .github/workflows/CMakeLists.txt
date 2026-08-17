cmake_minimum_required(VERSION 3.25)

project(AIBotOverlay VERSION 1.0.0 LANGUAGES CXX)

find_package(Geode REQUIRED)

add_geode_mod(
    AIBotOverlay
    SRC
        src/main.cpp
)

