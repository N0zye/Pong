[![Release](https://img.shields.io/github/v/release/N0zye/Pong)](https://github.com/N0zye/Pong/releases/latest)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.txt)

# C++ Pong

An old style pong game made in C++ using the raylib library

## Precompiled Version: [latest](https://github.com/N0zye/Pong/releases/latest)  only for windows(x64).
alternatively you can dowload the source and compile it yourself, see the steps int the compilation

## How to Compile

1. Clone the repository:
```pws
git clone https://github.com/N0zye/Pong.git
cd Pong
```
2. Compile
compile it using the following comand (only for powershell and MingW compiler) <br>
```pws
g++ "${PWD}/src/*.cpp" -o "${PWD}/build/out.exe" -O2 -std=c++17 -mwindows -w -I "${PWD}/include/" -L "${PWD}/lib/" -l:libraylibdll.a
```
3. Have fun!
