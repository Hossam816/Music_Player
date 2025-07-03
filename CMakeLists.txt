cmake_minimum_required(VERSION 3.16)
project(MusicPlayer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Set application properties
set(APP_NAME "Music Player")
set(APP_VERSION "1.0.0")
set(APP_DESCRIPTION "A modern Qt6/QML-based music player application")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Multimedia Widgets)

qt_standard_project_setup()

# Set Qt policies to suppress warnings
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

# Define source files
set(SOURCES
    main.cc
    src/song_model.cc
    src/MusicController.cc
)

# Define header files
set(HEADERS
    header/song_model.h
    header/MusicController.h
)

# Create resource file
set(RESOURCES
    resources.qrc
)

qt_add_executable(MusicPlayer
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
)

# Set application properties
set_target_properties(MusicPlayer PROPERTIES
    OUTPUT_NAME "MusicPlayer"
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_include_directories(MusicPlayer PRIVATE header)

target_link_libraries(MusicPlayer
    PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Multimedia
    Qt6::Widgets
)

# Installation configuration
install(TARGETS MusicPlayer
    BUNDLE DESTINATION .
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)

# Install resources
install(FILES ${RESOURCES} DESTINATION bin)

# Create deployment configuration
if(WIN32)
    # Windows deployment
    set(DEPLOY_DIR "${CMAKE_BINARY_DIR}/deploy")
    
    # Create deployment directory
    add_custom_command(TARGET MusicPlayer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
        COMMENT "Creating deployment directory"
    )
    
    # Copy executable to deployment directory first
    add_custom_command(TARGET MusicPlayer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MusicPlayer> ${DEPLOY_DIR}/
        COMMENT "Copying executable to deployment directory"
    )
    
    # Deploy Qt dependencies (only if executable exists)
    add_custom_command(TARGET MusicPlayer POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/windeployqt.exe --qmldir ${CMAKE_SOURCE_DIR}/qml ${DEPLOY_DIR}/MusicPlayer.exe
        COMMENT "Deploying Qt dependencies"
        DEPENDS MusicPlayer
    )
    
    # Create installer script
    configure_file(
        "${CMAKE_SOURCE_DIR}/installer/installer.nsi.in"
        "${CMAKE_BINARY_DIR}/installer/installer.nsi"
        @ONLY
    )
    
    # Install NSIS if available
    find_program(NSIS_MAKENSIS makensis)
    if(NSIS_MAKENSIS)
        add_custom_target(installer
            COMMAND ${NSIS_MAKENSIS} ${CMAKE_BINARY_DIR}/installer/installer.nsi
            DEPENDS MusicPlayer
            COMMENT "Creating installer"
        )
    endif()
    
elseif(APPLE)
    # macOS deployment
    set(DEPLOY_DIR "${CMAKE_BINARY_DIR}/deploy")
    
    # Deploy Qt dependencies for macOS
    add_custom_command(TARGET MusicPlayer POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/macdeployqt ${DEPLOY_DIR}/MusicPlayer.app
        COMMENT "Deploying Qt dependencies for macOS"
    )
    
else()
    # Linux deployment
    set(DEPLOY_DIR "${CMAKE_BINARY_DIR}/deploy")
    
    # Create desktop file
    configure_file(
        "${CMAKE_SOURCE_DIR}/installer/musicplayer.desktop.in"
        "${CMAKE_BINARY_DIR}/installer/musicplayer.desktop"
        @ONLY
    )
    
    # Install desktop file
    install(FILES "${CMAKE_BINARY_DIR}/installer/musicplayer.desktop"
        DESTINATION share/applications
    )
    
    # Install icon
    if(EXISTS "${CMAKE_SOURCE_DIR}/installer/musicplayer.png")
        install(FILES "${CMAKE_SOURCE_DIR}/installer/musicplayer.png"
            DESTINATION share/pixmaps
            RENAME "musicplayer.png"
        )
    endif()
endif()

# Create a simple deployment target that just copies the executable
add_custom_target(deploy_simple
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPLOY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MusicPlayer> ${DEPLOY_DIR}/
    DEPENDS MusicPlayer
    COMMENT "Creating simple deployment package"
)