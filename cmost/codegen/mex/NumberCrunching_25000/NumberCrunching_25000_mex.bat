@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015B~1
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b_x64\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=NumberCrunching_25000_mex
set MEX_NAME=NumberCrunching_25000_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015B~1\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for NumberCrunching_25000 > NumberCrunching_25000_mex.mki
echo COMPILER=%COMPILER%>> NumberCrunching_25000_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> NumberCrunching_25000_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> NumberCrunching_25000_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> NumberCrunching_25000_mex.mki
echo LINKER=%LINKER%>> NumberCrunching_25000_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> NumberCrunching_25000_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> NumberCrunching_25000_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> NumberCrunching_25000_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> NumberCrunching_25000_mex.mki
echo BORLAND=%BORLAND%>> NumberCrunching_25000_mex.mki
echo OMPFLAGS= >> NumberCrunching_25000_mex.mki
echo OMPLINKFLAGS= >> NumberCrunching_25000_mex.mki
echo EMC_COMPILER=lcc64>> NumberCrunching_25000_mex.mki
echo EMC_CONFIG=optim>> NumberCrunching_25000_mex.mki
"C:\Program Files\MATLAB\R2015b_x64\bin\win64\gmake" -B -f NumberCrunching_25000_mex.mk
