@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015B~1
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b_x64\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=NumberCrunching_50000_mex
set MEX_NAME=NumberCrunching_50000_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015B~1\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for NumberCrunching_50000 > NumberCrunching_50000_mex.mki
echo COMPILER=%COMPILER%>> NumberCrunching_50000_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> NumberCrunching_50000_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> NumberCrunching_50000_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> NumberCrunching_50000_mex.mki
echo LINKER=%LINKER%>> NumberCrunching_50000_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> NumberCrunching_50000_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> NumberCrunching_50000_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> NumberCrunching_50000_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> NumberCrunching_50000_mex.mki
echo BORLAND=%BORLAND%>> NumberCrunching_50000_mex.mki
echo OMPFLAGS= >> NumberCrunching_50000_mex.mki
echo OMPLINKFLAGS= >> NumberCrunching_50000_mex.mki
echo EMC_COMPILER=lcc64>> NumberCrunching_50000_mex.mki
echo EMC_CONFIG=optim>> NumberCrunching_50000_mex.mki
"C:\Program Files\MATLAB\R2015b_x64\bin\win64\gmake" -B -f NumberCrunching_50000_mex.mk
