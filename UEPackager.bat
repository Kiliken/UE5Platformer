@echo off

md GameBuild

set thisPath=%cd%
if exist "C:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\RunUAT.bat" set builder="C:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\RunUAT.bat"
if exist "D:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\RunUAT.bat" set builder="D:\Program Files\Epic Games\UE_5.5\Engine\Build\BatchFiles\RunUAT.bat"

set projExt=*.uproject

pushd %thisPath%
for %%a in (%projExt%) do set projName=%%a
popd


%builder% BuildCookRun ^
 -project="%thisPath%\%projName%" ^
 -noP4 ^
 -platform=Win64 ^
 -clientconfig=Shipping ^
 -cook -allmaps -build -stage -pak -archive ^
 -archivedirectory="%thisPath%\GameBuild" ^
 -verbose 

:: > GameBuild\build_log.txt 2>&1

pause