# CMakeList.txt: проект CMake для Lab_8_Stepina_Erika_variant_10_3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Lab_8_Stepina_Erika_variant_10_3 "Lab_8_Stepina_Erika_variant_10_3.cpp" "Lab_8_Stepina_Erika_variant_10_3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_8_Stepina_Erika_variant_10_3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
