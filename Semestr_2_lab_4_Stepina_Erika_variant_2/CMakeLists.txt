cmake_minimum_required(VERSION 3.19)
project(Semestr_2_lab_4_Stepina_Erika_variant_2)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Semestr_2_lab_4_Stepina_Erika_variant_2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(Semestr_2_lab_4_Stepina_Erika_variant_2
    PRIVATE
        Qt::Core
        Qt::Widgets
        carlib
)

include(GNUInstallDirs)

install(TARGETS Semestr_2_lab_4_Stepina_Erika_variant_2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Semestr_2_lab_4_Stepina_Erika_variant_2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_subdirectory(carlib)
