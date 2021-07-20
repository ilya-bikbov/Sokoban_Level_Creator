# Sokoban Level Creator
###### Version for Windows/Linux 
#
## Requirements
My computer had the following stuff:
###### Windows 10
*   Windows 10
*   Qt 4.8.4
*   Mingw32 (GCC 4.4.0)
   
###### Linux
*   Ubuntu 20.04
*   Qt 4.8.7
*   GCC 9.3.0

## How to build
1.  qmake
2.  make
3.  ...
4.  your exe file in the "bin" folder (`<sources_root>/bin/Sokoban_Level_Creator`)

## How to run the creator

###### Windows 10
You need to put this libs near the bin file (`<sources_root>/bin/`), they will automatically copy after compiling:

*   QtCore4.dll
*   QtGui4.dll
*   mingwm10.dll
*   libgcc_s_dw2-1.dll

...then start `<sources_root>/bin/Sokoban_Level_Creator.exe`
###### Linux

`cd <sources_root>/bin/`

`export QT_X11_NO_MITSHM=1; ./Sokoban_Level_Creator`
