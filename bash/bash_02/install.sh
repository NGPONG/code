#!/bin/bash

source /etc/os-release

set -euo pipefail # Set [x] option if wanna debug

# colors
RED="\033[0;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
NC="\033[0m"

function print_date {
  echo -n "[$(date '+%F %T')]: "
}
function error {
  echo -ne "[${RED}ERROR${NC}]"
  print_date
  echo "$@"
}
function info {
  echo -ne "[${GREEN}INFO${NC}]"
  print_date
  echo "$@"
}
function debug {
  echo -ne "[${YELLOW}DEBUG${NC}]"
  print_date
  echo "$@"
}

function set_proxy {
  info "start set proxy"

  if [[ $(which curl) == "" ]]; then
    sudo apt install curl
  fi
  
  # download qv2ray and install
  local qv2ray_pkg="qv2ray_2.6.3-1stable1_amd64.deb"
  if [[ ! -e /tmp/$qv2ray_pkg ]]; then
    curl -L https://github.com/Qv2ray/Qv2ray/releases/download/v2.6.3/$qv2ray_pkg -o /tmp/$qv2ray_pkg
  fi
  set +e
  sudo dpkg -i /tmp/$qv2ray_pkg
  if [[ $? == "1" ]]; then    
    sudo apt-get -f install
  fi
  set -e

  if [[ ! -e ~/.config/qv2ray ]]; then
    mkdir ~/.config/qv2ray
    mkdir ~/.config/qv2ray/vcore
    mkdir ~/.config/qv2ray/plugins
  fi

  # set up v2ray-core
  local v2ray_core_pkg="v2ray-linux-64.zip"
  if [[ ! -e /tmp/$v2ray_core_pkg ]]; then
    curl -L https://github.com/v2ray/v2ray-core/releases/download/v4.28.2/$v2ray_core_pkg -o /tmp/$v2ray_core_pkg
  fi
  unzip -o -d ~/.config/qv2ray/vcore/ /tmp/$v2ray_core_pkg

  # set up qv2ray plugins
  local trojan_lib="QvTrojanPlugin.v2.0.0.linux-x64.so"
  if [[ ! -e /tmp/$trojan_lib ]]; then
    curl -L https://github.com/Qv2ray/QvPlugin-Trojan/releases/download/v2.0.0/$trojan_lib -o /tmp/$trojan_lib
  fi
  cp /tmp/$trojan_lib ~/.config/qv2ray/plugins/
  
  # set up system proxy
  echo "export https_proxy="http://127.0.0.1:8889"
export http_proxy="http://127.0.0.1:8889"" | sudo tee -a ~/.bashrc > /dev/null
  echo "Acquire::http::Proxy "http://127.0.0.1:8889";
Acquire::https::Proxy "http://127.0.0.1:8889";" | sudo tee -a /etc/apt/apt.conf > /dev/null
  
  info "set proxy ended"
}
function check_env {
  info "start check system environment"

  # check system
  if [[ $NAME != "Ubuntu" && $NAME != "Debian" ]]; then
    error "Only supports systems: ubuntu, debian"
    exit 1
  fi

  # check proxy
  if [[ ! $(cat ~/.bashrc) =~ https_proxy ]]; then
    error "In order to ensure the transmission speed, you must first set up a proxy"
    set_proxy
    exit 1
  fi

  info "check successed"
}
function install_ide() {
  info "start install ide"

  sudo apt install neovim
  
  # install vim-plug
  if [[ ! -e ~/.local/share/nvim/site/autoload/plug.vim ]]; then
    curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
           https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  fi

  # config nvim configs
  if [[ ! -e ~/.config/nvim ]]; then
    mkdir ~/.config/nvim
    cd ~
    git clone https://github.com/NGPONG/code
    ln -s /home/$USER/code/config/nvim/coc-settings.json ~/.config/nvim/coc-settings.json
    ln -s /home/$USER/code/config/nvim/init.vim ~/.config/nvim/init.vim
    mkdir ~/.config/nvim/ultisnips
    ln -s /home/$USER/code/config/nvim/ultisnips/c.snippets ~/.config/nvim/ultisnips/c.snippets
    ln -s /home/$USER/code/config/nvim/ultisnips/json.snippets ~/.config/nvim/ultisnips/json.snippets
  fi

  # install ccls language-server
  if [[ $(which ccls) == "" ]]; then
    cd ~
    git clone --depth=1 --recursive https://github.com/MaskRay/ccls
    cd ./ccls
    git submodule update --init
    sudo cmake -H. -BRelease -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/path/to/clang+llvm-xxx
    sudo cmake --build Release --target install

    cd ..
    sudo rm -rf ./ccls
  fi

  info "completed install ide"
}
function install_fronted_tools {
  info "start install fronted tools"

  sudo apt install nodejs npm
  
  # yarn
  if [[ ! $(cat /etc/apt/sources.list) =~ yarnpkg ]]; then
    curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
    echo -e "\ndeb https://dl.yarnpkg.com/debian/ stable main" | sudo tee -a /etc/apt/sources.list
    apt update
    apt --no-install-recommends install yarn
  fi

  info "completed install fronted tools"
}
function install_common_tools {
  info "start install common tools"

  sudo apt install curl \
    net-tools \
    tree \
    htop \
    ripgrep \
    python2 \
    python2-dev \
    python3 \
    python3-dev 

  info "completed install common tools"
}
function install_gnu_tools {
  info "start install gnu tools";

  sudo apt install build-essential \
    git \
    gcc \
    g++ \
    manpages-dev \
    libtool \
    autoconf

  git config --global http.proxy http://127.0.0.1:8889
  git config --global https.proxy http://127.0.0.1:8889

  info "completed install gnu tools";
}
function install_llvm_tools {
  info "start install llvm tools";

  if [[ $(which clang) == "" ]]; then
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key|sudo apt-key add -
    echo -e "\n# i386 not available
deb http://apt.llvm.org/focal/ llvm-toolchain-focal main
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal main
# 10
deb http://apt.llvm.org/focal/ llvm-toolchain-focal-10 main
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-10 main
# 11
deb http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main
deb-src http://apt.llvm.org/focal/ llvm-toolchain-focal-11 main" | sudo tee -a /etc/apt/sources.list

    sudo apt update

    sudo apt install clang-11 \
      lldb-11 \
      lld-11 \
      libllvm-11-ocaml-dev \
      libllvm11 \
      llvm-11 \
      llvm-11-dev \
      llvm-11-doc \
      llvm-11-examples \
      llvm-11-runtime \
      clang-tools-11 \
      clang-11-doc \
      libclang-common-11-dev \
      libclang-11-dev \
      libclang1-11 \
      clang-format-11 \
      clangd-11 \
      libfuzzer-11-dev \
      libc++-11-dev \
      libc++abi-11-dev \
      cmake
    
    # set soft link
    local clang_path=$(which clang-11) 
    sudo ln -s $(which clang-11) ${clang_path/clang-11/clang}
  fi

  info "completed install llvm tools"
}

function init_dev_env() {
  # If in China, should change the software source in advance, without restriction here.
  # BTW, make sure have a proxy setup
  sudo apt update && sudo apt upgrade

  install_gnu_tools
  install_common_tools
  install_llvm_tools
  install_fronted_tools
  install_ide
}

function main {
  check_env
  init_dev_env

  info "Congratulations, you have completed the all of the configurable items"
  info "Enjoy it!"
}

main
