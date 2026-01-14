@echo off

set thisPath=%cd%

set true=1 EQU 1
set false=0 EQU 1


if exist "C:\Program Files\Epic Games\UE_5.5\Templates" set ueTempPath=C:\Program Files\Epic Games\UE_5.5\Templates
if exist "D:\Program Files\Epic Games\UE_5.5\Templates" set ueTempPath=D:\Program Files\Epic Games\UE_5.5\Templates


::for %%f in (%cd%) do set projName=%%~nxf


echo Settingup heavy stuffs...

:: Starting Contents
if %true% robocopy "%ueTempPath%\..\Samples\StarterContent\Content" "%cd%\Content" /E /NFL /NDL /NJH /NJS /NC /NS

:: Characters
if %true% robocopy "%ueTempPath%\TemplateResources\High\Characters\Content" "%cd%\Content\Characters" /E /NFL /NDL /NJH /NJS /NC /NS

:: LevelPrototyping
if %true% robocopy "%ueTempPath%\TemplateResources\High\LevelPrototyping\Content" "%cd%\Content\LevelPrototyping" /E /NFL /NDL /NJH /NJS /NC /NS

:: Plugins
if not exist "%cd%\Plugins" powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0PluginsSetup.ps1"


pause
