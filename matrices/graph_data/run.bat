@echo off
IF "%2"=="" GOTO ERROR
python.exe %~dp0\graph.py %*
rem start %3\%1.gif
goto FINISHED
:ERROR
echo no input and/or output path was provided!
:FINISHED
