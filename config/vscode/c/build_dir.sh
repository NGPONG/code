dir=$1

if [ ! -d "$1/DEBUG/" ];then
  mkdir $1/DEBUG/
  cd ./DEBUG/
  mkdir ./TEST
fi
