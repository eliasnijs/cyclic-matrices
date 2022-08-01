@echo off

cd %~dp0
IF NOT EXIST ..\data\ mkdir ..\data\
pushd ..\data
..\..\build\matrices.exe

