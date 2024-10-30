@echo off
mkdir build
pushd build

clang++ ..\woof.cc ..\woof_example.cc -std=c++17 -O2 -DNDEBUG -o release.exe
clang++ ..\woof.cc ..\woof_example.cc -std=c++17 -o debug.exe

popd