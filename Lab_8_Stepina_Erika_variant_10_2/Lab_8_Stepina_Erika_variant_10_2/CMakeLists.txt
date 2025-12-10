# CMakeList.txt: проект CMake для Lab_8_Stepina_Erika_variant_10_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab_8_Stepina_Erika_variant_10_2 "Lab_8_Stepina_Erika_variant_10_2.cpp" "Lab_8_Stepina_Erika_variant_10_2.h" "func_4.cpp" "func_5.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_8_Stepina_Erika_variant_10_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
