# Music Player

A modern Qt6/QML-based music player application with a beautiful user interface.

## Features

- 🎵 Play, pause, next, and previous controls
- 📁 Load music from folders (supports MP3, WAV, FLAC)
- 🔊 Volume control with slider
- ⏱️ Progress tracking with seekable timeline
- 🎨 Modern, responsive UI
- 🔄 Auto-play next song
- 📱 Cross-platform (Windows, macOS, Linux)

## Requirements

- Qt 6.5 or later
- CMake 3.16 or later
- C++17 compatible compiler
- Qt6 components: Core, Gui, Qml, Quick, Multimedia, Widgets

## Quick Start

### Windows
```cmd
# Run the deployment script
deploy.bat
```

### Linux/macOS
```bash
# Make script executable
chmod +x deploy.sh

# Run the deployment script
./deploy.sh
```

## Manual Build

### Prerequisites

1. Install Qt6 from [qt.io](https://www.qt.io/download) or your package manager
2. Make sure Qt6 is in your PATH or set `CMAKE_PREFIX_PATH`

### Build Steps

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .
```

### Windows with Visual Studio

```bash
# Using Visual Studio 2022
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build . --config Release
```

### Linux/macOS

```bash
cmake -G "Unix Makefiles" ..
make
```

## Deployment

### Creating a Deployable Package

After building, create a deployment package:

```bash
# From the build directory
cmake --build . --target deploy
```

This creates a `deploy/` folder containing all necessary files to run the application on any machine.

### Creating an Installer (Windows)

If you have NSIS installed:

```bash
# From the build directory
cmake --build . --target installer
```

This creates `MusicPlayer-Setup-1.0.0.exe` in the `installer/` folder.

### Distribution

#### Windows
- **Portable**: Copy the entire `deploy/` folder
- **Installer**: Run `MusicPlayer-Setup-1.0.0.exe`

#### Linux
- **Portable**: Copy the entire `deploy/` folder
- **System Install**: Run `sudo make install` from build directory

#### macOS
- **App Bundle**: Copy `MusicPlayer.app` from `deploy/` folder
- **DMG**: Create a disk image containing the app bundle

## Usage

1. Run the application
2. Click "📁 Open Music Folder" to select a folder with music files
3. Use the control buttons to play, pause, and navigate through your playlist
4. Adjust volume with the volume slider
5. Seek through songs using the progress bar
6. The player will automatically advance to the next song when one finishes

## Supported Audio Formats

- MP3
- WAV
- FLAC

## Project Structure

```
├── CMakeLists.txt          # Build configuration
├── main.cc                 # Application entry point
├── qml/
│   └── Main.qml           # User interface
├── header/
│   ├── MusicController.h  # Music control logic
│   └── song_model.h       # Song data model
├── src/
│   ├── MusicController.cc # Music controller implementation
│   └── song_model.cc      # Song model implementation
├── installer/             # Installer scripts and resources
│   ├── installer.nsi.in   # NSIS installer template
│   └── musicplayer.desktop.in # Linux desktop file
├── deploy.bat            # Windows deployment script
├── deploy.sh             # Linux/macOS deployment script
└── LICENSE.txt           # MIT License
```

## Development

### Adding New Features

1. **New Audio Formats**: Add extensions to `mSupportedExtensions` in `MusicController.h`
2. **UI Improvements**: Modify `qml/Main.qml`
3. **New Controls**: Add methods to `MusicController` class

### Qt6 Multimedia Notes

This project uses Qt6's new multimedia architecture:
- `QMediaPlayer` with `setSource()` instead of `setMedia()`
- `QAudioOutput` for volume control
- Manual playlist management (no `QMediaPlaylist` in Qt6)

## Troubleshooting

### Common Issues

1. **"Cannot find Qt6"**: Make sure Qt6 is installed and `CMAKE_PREFIX_PATH` is set
2. **Audio not playing**: Check if your system has the required audio codecs
3. **Build errors**: Ensure you're using C++17 or later
4. **Deployment issues**: Make sure all Qt dependencies are included

### Debug Output

The application outputs debug information to the console:
- Number of songs loaded from folder
- Playback state changes
- File loading status

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

---

Enjoy your music! 🎶