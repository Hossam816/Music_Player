#!/bin/bash

echo "========================================"
echo "Music Player - Build and Deploy Script"
echo "========================================"

echo ""
echo "Step 1: Cleaning previous builds..."
rm -rf build

echo ""
echo "Step 2: Creating build directory..."
mkdir build
cd build

echo ""
echo "Step 3: Configuring with CMake..."

# Detect OS and configure accordingly
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    cmake -G "Unix Makefiles" ..
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    cmake -G "Unix Makefiles" ..
else
    # Other Unix-like systems
    cmake -G "Unix Makefiles" ..
fi

echo ""
echo "Step 4: Building the project..."
make -j$(nproc)

echo ""
echo "Step 5: Creating deployment package..."
make deploy

echo ""
echo "Step 6: Installing (optional)..."
echo "To install system-wide, run: sudo make install"

echo ""
echo "========================================"
echo "Build and deployment completed!"
echo "========================================"
echo ""
echo "Files created:"
echo "- Executable: build/MusicPlayer"
echo "- Deployment: build/deploy/"
echo ""
echo "To run the application:"
echo "- ./build/MusicPlayer"
echo "- Or copy the entire 'deploy' folder to any location"
echo "" 