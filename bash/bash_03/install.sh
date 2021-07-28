export D_WORKER_PROCESS=

set -x

if [ "$1" != "" ]; then
    D_WORKER_PROCESS="-j${1}"
fi

./script/test_1.sh
./test_d/test_2.sh

make $D_WORKER_PROCESS
make clean

echo $D_WORKER_PROCESS
