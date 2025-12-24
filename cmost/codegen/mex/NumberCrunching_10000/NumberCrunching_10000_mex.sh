MATLAB="/cluster/apps/matlab/8.5/x86_64"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/cluster/home/misselwb/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for NumberCrunching_10000" > NumberCrunching_10000_mex.mki
echo "CC=$CC" >> NumberCrunching_10000_mex.mki
echo "CFLAGS=$CFLAGS" >> NumberCrunching_10000_mex.mki
echo "CLIBS=$CLIBS" >> NumberCrunching_10000_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> NumberCrunching_10000_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> NumberCrunching_10000_mex.mki
echo "CXX=$CXX" >> NumberCrunching_10000_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> NumberCrunching_10000_mex.mki
echo "CXXLIBS=$CXXLIBS" >> NumberCrunching_10000_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> NumberCrunching_10000_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> NumberCrunching_10000_mex.mki
echo "LD=$LD" >> NumberCrunching_10000_mex.mki
echo "LDFLAGS=$LDFLAGS" >> NumberCrunching_10000_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> NumberCrunching_10000_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> NumberCrunching_10000_mex.mki
echo "Arch=$Arch" >> NumberCrunching_10000_mex.mki
echo OMPFLAGS= >> NumberCrunching_10000_mex.mki
echo OMPLINKFLAGS= >> NumberCrunching_10000_mex.mki
echo "EMC_COMPILER=gcc" >> NumberCrunching_10000_mex.mki
echo "EMC_CONFIG=optim" >> NumberCrunching_10000_mex.mki
"/cluster/apps/matlab/8.5/x86_64/bin/glnxa64/gmake" -B -f NumberCrunching_10000_mex.mk
