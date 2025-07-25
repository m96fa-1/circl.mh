@echo off
set prjName=Circl.mh

cd ..
rd /s /q .vs
rd /s /q bin
rd /s /q bin-int
del *.sln
del %prjName%\*.vcxproj*

rd /s /q %prjName%\vendor\glfw\bin
rd /s /q %prjName%\vendor\glfw\bin-int
del %prjName%\vendor\glfw\*.vcxproj*

rd /s /q %prjName%\vendor\glad\bin
rd /s /q %prjName%\vendor\glad\bin-int
del %prjName%\vendor\glad\*.vcxproj*

rd /s /q %prjName%\vendor\imgui\bin
rd /s /q %prjName%\vendor\imgui\bin-int
del %prjName%\vendor\imgui\*.vcxproj*

pause