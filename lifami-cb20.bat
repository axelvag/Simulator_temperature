
del /S /Q build
.\script\premake4.exe --os=windows --file=premake4.lua --cb-version=cb20 --lifami codeblocks 
.\script\premake4.exe --os=windows --file=premake4.lua --cb-version=cb20 --lifami gmake
copy extern\mingw-cb20\bin\*.dll bin

pause
