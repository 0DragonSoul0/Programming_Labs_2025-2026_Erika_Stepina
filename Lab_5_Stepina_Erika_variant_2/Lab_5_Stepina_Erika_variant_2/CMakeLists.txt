# CMakeList.txt: проект CMake для Lab_5_Stepina_Erika_variant_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab_5_Stepina_Erika_variant_2 "Lab_5_Stepina_Erika_variant_2.cpp" "Lab_5_Stepina_Erika_variant_2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_5_Stepina_Erika_variant_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
