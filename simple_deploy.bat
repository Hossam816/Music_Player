@echo off
echo ========================================
echo Music Player - Simple Build and Deploy
echo ========================================

echo.
echo Step 1: Cleaning previous builds...
if exist build rmdir /s /q build

echo.
echo Step 2: Creating build directory...
mkdir build
cd build

echo.
echo Step 3: Configuring with CMake...
cmake -G "Visual Studio 17 2022" -A x64 ..

echo.
echo Step 4: Building the project...
cmake --build . --config Release

echo.
echo Step 5: Creating deployment directory...
if not exist deploy mkdir deploy

echo.
echo Step 6: Copying executable to deployment folder...
copy Release\MusicPlayer.exe deploy\

echo.
echo Step 7: Deploying Qt dependencies...
if exist "C:\QT\6.9.0\msvc2022_64\bin\windeployqt.exe" (
    C:\QT\6.9.0\msvc2022_64\bin\windeployqt.exe --qmldir ..\qml deploy\MusicPlayer.exe
    echo Qt dependencies deployed successfully!
) else (
    echo Warning: windeployqt.exe not found. Qt dependencies may be missing.
    echo You may need to install Qt6 or adjust the Qt path.
)

echo.
echo ========================================
echo Build and deployment completed!
echo ========================================
echo.
echo Files created:
echo - Executable: build\Release\MusicPlayer.exe
echo - Deployment: build\deploy\
echo.
echo To run the application:
echo - Double-click: build\Release\MusicPlayer.exe
echo - Or copy the entire 'deploy' folder to any location
echo.
echo Note: If you see missing DLL errors, make sure Qt6 is installed
echo and the windeployqt.exe path is correct in this script.
echo.
pause 