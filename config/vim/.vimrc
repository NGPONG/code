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

"------------------------------BY_GLOBAL-------------------------------------------
" Make configuration changes effective immediately
autocmd BufWritePost $MYVIMRC source $MYVIMRC
" line number
set number
" set syntax highlight
if has("syntax")
  syntax on
endif
" tabwidth
set tabstop=4 softtabstop=0 expandtab shiftwidth=2 smarttab
" set auto indent
set autoindent
" Set 24-bit (true-color) mode in Vim/Neovim when outside tmux
if (empty($TMUX))
  if (has("nvim"))
    let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  endif
  if (has("termguicolors"))
    set termguicolors
  endif
endif
" set colorscheme
" dark_plus: codedark;
"  one_dark: onedark;
colorscheme codedark
" share cliboard by sys
set clipboard^=unnamed,unnamedplus
" cursor
set ve+=onemore
" encoding
set encoding=utf-8
set fileencoding=utf-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
" air_line
let g:airline_powerline_fonts = 1
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#whitespace#symbol = '!'
let g:airline#extensions#hunks#enabled=1
let g:airline#extensions#branch#enabled=1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter = 'unique_tail'
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif

"------------------------------BY_KEYS-------------------------------------------
nnoremap <Home> ^
vnoremap <Home> ^
inoremap <Home> <Esc>^i
vnoremap <End> $h
nnoremap <End> $l
nnoremap <BS> "_X
vnoremap <BS> "_X
nnoremap <Space> i<Space><Esc>l
nnoremap x "_x
nnoremap X "_X
vnoremap x "_x
vnoremap X "_X
nnoremap <tab> V>
vnoremap <tab> >gv
vnoremap i "_xI
vnoremap w aw
nnoremap <CR> i<CR><Esc>
