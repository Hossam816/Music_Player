@echo off
echo Cleaning build directory...
if exist build rmdir /s /q build

echo Creating build directory...
mkdir build
cd build

echo Configuring with CMake...
cmake -G "Visual Studio 17 2022" -A x64 ..

echo Building project...
cmake --build . --config Debug

echo Build complete!
echo Running application...
cd Debug
MusicPlayer.exe
pause 