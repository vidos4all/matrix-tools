# CMakeList.txt: проект CMake для matrix-tools; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("matrix-tools")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (matrix-tools "main.cpp" "includes.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
