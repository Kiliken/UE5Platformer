@echo off

del TemplateSetup.ps1
del codeDL.ps1
del UECreateProject.bat


if not exist "%cd%\Plugins" powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0PluginsSetup.ps1"

set thisPath=%cd%
if exist "C:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat" set compiler="C:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat"
if exist "D:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat" set compiler="D:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\Build.bat"


set projExt=*.uproject

pushd %thisPath%
for %%a in (%projExt%) do set projName=%%a
popd

call %compiler% %projName:~0,-9%Editor Win64 Development "%thisPath%\%projName%" -waitmutex
