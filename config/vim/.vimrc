" Make configuration changes effective immediately
autocmd BufWritePost $MYVIMRC source $MYVIMRC

" line number
set number

" key bound <home>
nnoremap <Home> ^
inoremap <Home> <Esc>^i

" key bound <end>
vnoremap <End> $h
