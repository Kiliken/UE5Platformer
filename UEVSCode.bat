@echo off

set thisPath=%cd%

if exist "C:\Program Files\Epic Games\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" set unrealBuilder="C:\Program Files\Epic Games\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"
if exist "D:\Program Files\Epic Games\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" set unrealBuilder="D:\Program Files\Epic Games\UE_5.5\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"

set projExt=*.uproject

pushd %thisPath%
for %%a in (%projExt%) do set projName=%%a
popd

%unrealBuilder% -ProjectFiles -Project="%thisPath%\%projName%" -Game -Engine -vscode


for %%i in (code.cmd) do for %%j in ("%%~dp$PATH:i\..") do set "VSCODE_PARENT=%%~fj"
start "" "%VSCODE_PARENT%\Code.exe" .

exit

