MATLAB="/cluster/apps/matlab/8.5/x86_64"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/cluster/home/misselwb/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for QuickRS" > QuickRS_mex.mki
echo "CC=$CC" >> QuickRS_mex.mki
echo "CFLAGS=$CFLAGS" >> QuickRS_mex.mki
echo "CLIBS=$CLIBS" >> QuickRS_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> QuickRS_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> QuickRS_mex.mki
echo "CXX=$CXX" >> QuickRS_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> QuickRS_mex.mki
echo "CXXLIBS=$CXXLIBS" >> QuickRS_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> QuickRS_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> QuickRS_mex.mki
echo "LD=$LD" >> QuickRS_mex.mki
echo "LDFLAGS=$LDFLAGS" >> QuickRS_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> QuickRS_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> QuickRS_mex.mki
echo "Arch=$Arch" >> QuickRS_mex.mki
echo OMPFLAGS= >> QuickRS_mex.mki
echo OMPLINKFLAGS= >> QuickRS_mex.mki
echo "EMC_COMPILER=gcc" >> QuickRS_mex.mki
echo "EMC_CONFIG=optim" >> QuickRS_mex.mki
"/cluster/apps/matlab/8.5/x86_64/bin/glnxa64/gmake" -B -f QuickRS_mex.mk
