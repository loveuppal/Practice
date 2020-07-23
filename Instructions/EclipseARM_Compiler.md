# Installing ARM Cross Compiler in the windows.
## Things required
- ARM GCC Package for NON-Linux &nbsp;&nbsp;:https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
  - Recommended Download for Beaglebone : **AArch32 target with hard float (arm-none-linux-gnueabihf)**
- Eclipse IDE for C/C++
- Make 3.81 &nbsp;&nbsp;&nbsp; :https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81.exe/download?use_mirror=cfhcable&download=
## Steps
- Install the Eclipse.
- Install the Make
- Extract the GCC Compiler Package at ```C:\Program Files```
- Add GCC and Make PATHS to Environment Variable.
```
Open System Properties     : Win+R > Type: sysdm.cpl SystemProperties or sysdm.cpl DisplaySYSDMCPL :: Enter
```
```
In System Properties     : Advanced Tab > Environment Variable > System Variables > Double-Click on PATH > New
```

```
ADD GCC PATH  :  C:\Program Files\gcc-arm-9.2-2019.12-mingw-w64-i686-arm-none-linux-gnueabihf\bin
ADD MAKE PATH :  C:\Program Files (x86)\GnuWin32\bin
```
### In Eclipse.
```
New Project > C Project > Hello ANSI C Project :: Cross GCC > Select Configration :: (Down-Right) Advanced.
```
```
C/C++ Build > Builder type: Internal.

Tool Settings > Setting > Cross Settings > Path: C:\Program Files\gcc-arm-9.2-2019.12-mingw-w64-i686-arm-none-linux-gnueabihf\bin.
    Cross GCC Compiler : arm-none-linux-gnueabihf-gcc
    Cross GCC Linker : arm-none-linux-gnueabihf-gcc
    Cross GCC Assembler : arm-none-linux-gnueabihf-as
```
