# CMakeList.txt: проект CMake для Lab_7_Stepina_Erika_variant_10; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab_7_Stepina_Erika_variant_10 "Lab_7_Stepina_Erika_variant_10.cpp" "Lab_7_Stepina_Erika_variant_10.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_7_Stepina_Erika_variant_10 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
