@echo off
echo ========================================
echo Music Player - Build and Deploy Script
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
echo Step 5: Creating deployment package...
cmake --build . --target deploy

echo.
echo Step 6: Creating installer (if NSIS is available)...
cmake --build . --target installer

echo.
echo ========================================
echo Build and deployment completed!
echo ========================================
echo.
echo Files created:
echo - Executable: build\Release\MusicPlayer.exe
echo - Deployment: build\deploy\
echo - Installer: build\installer\MusicPlayer-Setup-1.0.0.exe (if NSIS available)
echo.
echo To run the application:
echo - Double-click: build\Release\MusicPlayer.exe
echo - Or copy the entire 'deploy' folder to any location
echo.
pause 