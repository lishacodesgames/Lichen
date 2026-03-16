# Lichen
![Latest Tag](https://img.shields.io/github/v/tag/lishacodesgames/Lichen?color=%237DBA84)
![Status Badge](https://img.shields.io/badge/Status-In_Development-yellow)


## Overview
Lichen is a Game Engine written in Raylib (cross-platform wrapper for OpenGL) and C++ <br>
While initially developed on Linux Mint, it plans on being cross-platform for Windows and Mac as well.

I was inspired for this project by the [Hazel](https://github.com/TheCherno/Hazel) game engine, and am actively using it as a reference to how the way things work in this. Thank you so much, TheCherno!

In Hazel, TheCherno uses OpenGL and Visual Studio, developing on Windows. <br>
In Lichen, I'll be using Raylib and VSCode, developing on Linux.

I hope to learn a lot from this project as I have only made simple games till now, in C++ and Raylib.

### Tech Stack
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) 
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) 
![OpenGL](https://img.shields.io/badge/OpenGL-%23FFFFFF.svg?style=for-the-badge&logo=opengl) 
![RayLib](https://img.shields.io/badge/RAYLIB-FFFFFF?style=for-the-badge&logo=raylib&logoColor=black)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

## Features
#### (Planned, so far)
- Window Management system
- Rendering system
- Debugging Support
- C# Scripts
- Entity Component System
- Physics
- Build System
- Custom Asset Types
- Hot Reloading

## Architecture
Coming soon...

## How to Clone
`git clone --recursive` to get the raylib submodule local
<br>

**If you forgot, do:** <br>
`git submodule update --init --recursive` after regular `git clone`

### Build

```bash
cmake --preset Distro
cmake --build --preset Distro
./bin/Distro_<your-OS>-<your-arch>/Sandbox/Sandbox
```
**Note:** <br> 
- for Windows, omit the `./` and add `.exe` at the end
- Make sure you're running from the repo directory `Lichen/`
- Make sure you have cmake and ninja in your path variables

#### Presets
1. Debug — All debug symbols turned on, optimization off
2. Release — Debug symbols on, optimization on
3. Distro — Debug symbols off, optimization on
   
### Linux Dependencies
Raylib requires a lot of libraries that are built-in on Mac and Windows. <br>
No worries, Linux just requires 1 command to install them all:
```bash
sudo apt install \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libgl1-mesa-dev \
    libasound2-dev \
    libpulse-dev \
    libxkbcommon-dev
```

### Requirements
* CMake 3.20+
* C++ compiler: GCC 13.3 / Clang
* Ninja (not *required*, but it's what the presets use)

## License
This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details. <br>
Copyright (c) 2026 lishacodesgames

#### This means you can:
- Use this software for any purpose (personal or commercial).
- Modify the source code to suit your needs.
- Distribute the original or modified versions of the software.
- Sublicense the code under different terms.
#### As long as you:
- Include a copy of the original license and copyright notice.
- State Changes: Clearly mark any significant modifications you made to the files.
- Keep Notices: Retain all existing copyright, patent, and trademark notices.
