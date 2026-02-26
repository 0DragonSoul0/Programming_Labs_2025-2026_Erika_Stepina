# CMakeList.txt: проект CMake для Semestr_2_lab_3_variant_2_Stepina_Erika; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Semestr_2_lab_3_variant_2_Stepina_Erika "Semestr_2_lab_3_variant_2_Stepina_Erika.cpp" "Semestr_2_lab_3_variant_2_Stepina_Erika.h" "car.h" "car.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Semestr_2_lab_3_variant_2_Stepina_Erika PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
