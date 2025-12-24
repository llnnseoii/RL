@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015B~1
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b_x64\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=QuickRS_mex
set MEX_NAME=QuickRS_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015B~1\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for QuickRS > QuickRS_mex.mki
echo COMPILER=%COMPILER%>> QuickRS_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> QuickRS_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> QuickRS_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> QuickRS_mex.mki
echo LINKER=%LINKER%>> QuickRS_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> QuickRS_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> QuickRS_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> QuickRS_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> QuickRS_mex.mki
echo BORLAND=%BORLAND%>> QuickRS_mex.mki
echo OMPFLAGS= >> QuickRS_mex.mki
echo OMPLINKFLAGS= >> QuickRS_mex.mki
echo EMC_COMPILER=lcc64>> QuickRS_mex.mki
echo EMC_CONFIG=optim>> QuickRS_mex.mki
"C:\Program Files\MATLAB\R2015b_x64\bin\win64\gmake" -B -f QuickRS_mex.mk
