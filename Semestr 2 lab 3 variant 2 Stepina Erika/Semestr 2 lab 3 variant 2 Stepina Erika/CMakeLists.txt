# CMakeList.txt: проект CMake для Semestr 2 lab 3 variant 2 Stepina Erika; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Semestr 2 lab 3 variant 2 Stepina Erika.cpp" "Semestr 2 lab 3 variant 2 Stepina Erika.h" "car.h" "car.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
