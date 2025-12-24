MATLAB="/cluster/apps/matlab/8.5/x86_64"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/cluster/home/misselwb/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for NumberCrunching_25000" > NumberCrunching_25000_mex.mki
echo "CC=$CC" >> NumberCrunching_25000_mex.mki
echo "CFLAGS=$CFLAGS" >> NumberCrunching_25000_mex.mki
echo "CLIBS=$CLIBS" >> NumberCrunching_25000_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> NumberCrunching_25000_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> NumberCrunching_25000_mex.mki
echo "CXX=$CXX" >> NumberCrunching_25000_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> NumberCrunching_25000_mex.mki
echo "CXXLIBS=$CXXLIBS" >> NumberCrunching_25000_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> NumberCrunching_25000_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> NumberCrunching_25000_mex.mki
echo "LD=$LD" >> NumberCrunching_25000_mex.mki
echo "LDFLAGS=$LDFLAGS" >> NumberCrunching_25000_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> NumberCrunching_25000_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> NumberCrunching_25000_mex.mki
echo "Arch=$Arch" >> NumberCrunching_25000_mex.mki
echo OMPFLAGS= >> NumberCrunching_25000_mex.mki
echo OMPLINKFLAGS= >> NumberCrunching_25000_mex.mki
echo "EMC_COMPILER=gcc" >> NumberCrunching_25000_mex.mki
echo "EMC_CONFIG=optim" >> NumberCrunching_25000_mex.mki
"/cluster/apps/matlab/8.5/x86_64/bin/glnxa64/gmake" -B -f NumberCrunching_25000_mex.mk
