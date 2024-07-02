#!/usr/bin/env bash
project=${PWD##*/}
pid=$1

ex=(
    -ex "set logging overwrite on" 
    -ex "set logging file ${project}.bt" 
    -ex "set logging on" 
    -ex "set pagination off"
    -ex "handle SIG33 pass nostop noprint"

    # set gdb run logic
    -ex "b sema_manager.cc:610"
    -ex "signal SIGCONT"
    -ex "c"
    -ex "c"

    -ex "echo [NGPONG][INFO] *clang\n"
    -ex "p *clang"
    -ex "echo \n"

    -ex "echo [NGPONG][INFO] *session\n"
    -ex "p *session"
    -ex "echo \n"

    -ex "echo [NGPONG][INFO] *ci\n"
    -ex "p *ci"
    -ex "echo \n"
    
    -ex "echo [NGPONG][INFO] dc\n"
    -ex "p dc"
    -ex "echo \n"
    
    -ex "echo [NGPONG][INFO] *preamble\n"
    -ex "p *preamble"
    -ex "echo \n"

    -ex "echo [NGPONG][INFO] task.path\n"
    -ex "p task.path"
    -ex "echo \n"

    -ex "set logging off"
    -ex "quit"
)

echo 0 | gdb -batch-silent "${ex[@]}" -p $pid
