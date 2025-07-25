@echo off
set prjName=Circl.mh
copy %prjName%\premake5.lua ..
copy glfw\premake5.lua ..\%prjName%\vendor\glfw
copy glad\premake5.lua ..\%prjName%\vendor\glad
copy imgui\premake5.lua ..\%prjName%\vendor\imgui
cd ..
vendor\premake5-x86_64-windows\premake5.exe vs2022
del premake5.lua
del %prjName%\vendor\glfw\premake5.lua
del %prjName%\vendor\glad\premake5.lua
del %prjName%\vendor\imgui\premake5.lua
pause