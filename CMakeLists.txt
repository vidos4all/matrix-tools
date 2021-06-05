cmake_minimum_required (VERSION 3.8)

project ("matrix-tools")

add_executable (matrix-tools "main.cpp" "includes.h" "matrix/matrix.h" "controllers/controller.h" "controllers/view.h" "matrix/matrix.cpp" "controllers/controller.cpp" "controllers/view.cpp"  "overrides.h")