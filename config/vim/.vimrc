"------------------------------BY_CODING-------------------------------------------
" 1. set syntax highlight
if has("syntax")
  syntax on
endif


"------------------------------BY_PLUGINS-------------------------------------------
call plug#begin('~/.vim/plugged')
" theme: one-darkd
Plug 'tomasiser/vim-code-dark'
" theme: dark-plus
Plug 'joshdick/onedark.vim'
" more syntax
Plug 'sheerun/vim-polyglot'
" remove whitespace in world trailing
Plug 'bronson/vim-trailing-whitespace'
" airline
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
call plug#end()

"------------------------------BY_NORMAL-------------------------------------------
" Make configuration changes effective immediately
autocmd BufWritePost $MYVIMRC source $MYVIMRC
" line number
set number
" tabwidth
set tabstop=4 softtabstop=0 expandtab shiftwidth=2 smarttab
" set auto indent
set autoindent
" set colorscheme
colorscheme codedark
" share cliboard by sys
set clipboard^=unnamed,unnamedplus
" encoding
set encoding=utf-8
set fileencoding=utf-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
" air line
let g:airline_powerline_fonts = 1
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#whitespace#symbol = '!'
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
let g:airline#extensions#tabline#enabled = 1

"------------------------------BY_KEYS-------------------------------------------
nnoremap <Home> ^
vnoremap <Home> ^
inoremap <Home> <Esc>^i
vnoremap <End> $h
nnoremap <BS> "_X
vnoremap <BS> "_X
"nnoremap p P
nnoremap x "_x
nnoremap X "_X
vnoremap x "_x
vnoremap X "_X
nnoremap <tab> V>
vnoremap <tab> >gv
vnoremap i I
vnoremap w aw
nmap <CR> o<Esc>
