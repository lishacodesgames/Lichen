@echo off

if "%~1"=="" (
   echo Usage: scripts\run.bat ^<preset^>
   exit /b 1
)

set PRESET=%~1
set EXEC=bin\%PRESET%\Sandbox\Sandbox.exe

if not exist "%EXEC%" (
   echo Executable not found: %EXEC%
   exit /b 1
)

"%EXEC%"