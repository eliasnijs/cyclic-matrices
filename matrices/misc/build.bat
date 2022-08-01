@echo off

cd %~dp0
IF NOT EXIST ..\..\build\ mkdir ..\..\build\
pushd ..\..\build\
cl -MT -nologo -Gm- -GR- -EHa- -Oi -WX -W4 -wd4996 -wd4201 -wd4100 -wd4189 -wd4701 -wd4505 -DMATRICES_INTERNAL=1 -DMATRICES_SLOW=1 -DHANDMADE_WIN32=1 -FC -Z7 \matrices\source\matrices.cpp user32.lib gdi32.lib 
popd

