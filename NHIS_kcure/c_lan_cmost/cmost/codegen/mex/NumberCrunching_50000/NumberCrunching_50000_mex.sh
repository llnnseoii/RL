MATLAB="/cluster/apps/matlab/8.5/x86_64"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/cluster/home/misselwb/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for NumberCrunching_50000" > NumberCrunching_50000_mex.mki
echo "CC=$CC" >> NumberCrunching_50000_mex.mki
echo "CFLAGS=$CFLAGS" >> NumberCrunching_50000_mex.mki
echo "CLIBS=$CLIBS" >> NumberCrunching_50000_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> NumberCrunching_50000_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> NumberCrunching_50000_mex.mki
echo "CXX=$CXX" >> NumberCrunching_50000_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> NumberCrunching_50000_mex.mki
echo "CXXLIBS=$CXXLIBS" >> NumberCrunching_50000_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> NumberCrunching_50000_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> NumberCrunching_50000_mex.mki
echo "LD=$LD" >> NumberCrunching_50000_mex.mki
echo "LDFLAGS=$LDFLAGS" >> NumberCrunching_50000_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> NumberCrunching_50000_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> NumberCrunching_50000_mex.mki
echo "Arch=$Arch" >> NumberCrunching_50000_mex.mki
echo OMPFLAGS= >> NumberCrunching_50000_mex.mki
echo OMPLINKFLAGS= >> NumberCrunching_50000_mex.mki
echo "EMC_COMPILER=gcc" >> NumberCrunching_50000_mex.mki
echo "EMC_CONFIG=optim" >> NumberCrunching_50000_mex.mki
"/cluster/apps/matlab/8.5/x86_64/bin/glnxa64/gmake" -B -f NumberCrunching_50000_mex.mk
