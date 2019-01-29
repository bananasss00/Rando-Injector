# Rando-Injector

## Changes
**It has been edited to include interactive mode (you provide process name and dll name on the go, not hardcoding it) - that's the only change.**  
If you want to hardcode something, follow these steps:
### Process name
1) Comment or delete lines **71** and **72**
2) Edit line **68** to this: `char process[MAX_PATH] = "process_name.exe";`  
*(replace `process_name.exe` with your process name)*
### DLL name
1) Comment or delete lines **74** and **75**
2) Edit line **69** to this: `char dll[MAX_PATH] = "dll_name.dll";`  
*(replace `dll_name.dll` with your dll name)*

## How to compile?
1) Change all bytes (0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
2) Change size of this block by adding new bytes
3) Compile (VS2017 - `F9` or `Ctrl+Shift+B`)

## Source
[bananasss00/Rando-Injector](https://github.com/bananasss00/Rando-Injector)

## Video
[![How to compile?](https://img.youtube.com/vi/bA3CcQ4p1QQ/0.jpg)](https://www.youtube.com/watch?v=bA3CcQ4p1QQ)
