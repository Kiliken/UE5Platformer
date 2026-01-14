@echo off

set thisPath=%cd%

if exist "C:\Program Files\Epic Games\UE_5.5\Templates" set ueTempPath=C:\Program Files\Epic Games\UE_5.5\Templates
if exist "D:\Program Files\Epic Games\UE_5.5\Templates" set ueTempPath=D:\Program Files\Epic Games\UE_5.5\Templates


::for %%f in (%cd%) do set projName=%%~nxf


echo Settingup heavy stuffs...

:: Starting Contents
robocopy "%ueTempPath%\..\Samples\StarterContent\Content" "%cd%\Content" /E /NFL /NDL /NJH /NJS /NC /NS

:: Characters
robocopy "%ueTempPath%\TemplateResources\High\Characters\Content" "%cd%\Content\Characters" /E /NFL /NDL /NJH /NJS /NC /NS

:: LevelPrototyping
robocopy "%ueTempPath%\TemplateResources\High\LevelPrototyping\Content" "%cd%\Content\LevelPrototyping" /E /NFL /NDL /NJH /NJS /NC /NS


::powershell -ExecutionPolicy Bypass -File TemplateSetup.ps1 -OldName %template% -NewName %projName%

pause