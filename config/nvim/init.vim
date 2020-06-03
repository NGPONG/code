"------------------------------BY_PLUGINS-------------------------------------------
call plug#begin('~/.local/share/nvim/plugged')

 " themes
 Plug 'tomasiser/vim-code-dark'
 Plug 'joshdick/onedark.vim'

 " common
 Plug 'bronson/vim-trailing-whitespace'

 " Intelligent
 Plug 'neoclide/coc.nvim', {'branch': 'release'}

 " visual tree
 Plug 'preservim/nerdtree'
 Plug 'ryanoasis/vim-devicons'
 Plug 'Xuyuanp/nerdtree-git-plugin'

 " airline
 Plug 'vim-airline/vim-airline'
 Plug 'vim-airline/vim-airline-themes'

call plug#end()
"----------------------------------------------------------------------------------



"------------------------------BY_GLOBAL-------------------------------------------
" remember postion
if has("autocmd")
    au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" Reloads vimrc after saving
autocmd! BufWritePost $MYVIMRC source $MYVIMRC

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
"if (empty($TMUX))
"  if (has("nvim"))
"    let $NVIM_TUI_ENABLE_TRUE_COLOR=1
"  endif
"  if (has("termguicolors"))
"    set termguicolors
"  endif
"endif

" share cliboard by sys
set clipboard^=unnamed,unnamedplus

" cursor
set ve+=onemore
set cursorline
set guicursor=
"set cursorcolumn

" hide status bar in bottom
set shortmess=F
set noshowmode
set noruler
set laststatus=0
set noshowcmd
set noshowcmd
set cmdheight=1

" encoding
set encoding=UTF-8
set fileencoding=utf-8

"--------------------------------------------------------------------------------



"------------------------------BY_PLUGINS----------------------------------------
" set colorscheme
" dark_plus: codedark;
"  one_dark: onedark;
colorscheme codedark

" air_line
let g:airline_powerline_fonts = 1
let g:airline#extensions#whitespace#enabled = 0
let g:airline#extensions#whitespace#symbol = '!'
let g:airline#extensions#hunks#enabled=0
let g:airline#extensions#branch#enabled=1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter = 'unique_tail'
let g:airline#extensions#tabline#tab_nr_type = 1
let g:airline#extensions#tabline#show_tab_nr = 1
let g:airline#extensions#tabline#buffer_nr_show = 0
let g:airline#extensions#tabline#fnametruncate = 16
let g:airline#extensions#tabline#fnamecollapse = 2
let g:airline#extensions#tabline#buffer_idx_mode = 1
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
let g:airline_section_x=''
let g:airline_skip_empty_sections = 1


" nerd tree
map <silent> <C-e> :NERDTreeToggle<CR>
autocmd BufEnter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) |cd %:p:h |endif
autocmd BufEnter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let g:NERDTreeChDirMode = 2
let g:NERDTreeHidden=0
let NERDTreeShowBookmarks=0
let g:NERDTreeUpdateOnWrite = 1
let g:NERDTreeHighlightCursorline = 0
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1
let NERDTreeAutoDeleteBuffer = 1
let g:NERDTreeDirArrowExpandable = ''
let g:NERDTreeDirArrowCollapsible = ''
let g:NERDTreeDirArrowExpandable = '▸'
let g:NERDTreeDirArrowCollapsible = '▾'
let g:NERDTreeIndicatorMapCustom = {
        \ "Modified"  : "✹",
        \ "Staged"    : "✚",
        \ "Untracked" : "✭",
        \ "Renamed"   : "➜",
        \ "Unmerged"  : "═",
        \ "Deleted"   : "✖",
        \ "Dirty"     : "✗",
        \ "Clean"     : "✔︎",
        \ 'Ignored'   : '☒',
        \ "Unknown"   : "?"
\}


let g:webdevicons_enable_nerdtree = 1
let g:WebDevIconsUnicodeDecorateFolderNodes = 1
let g:WebDevIconsNerdTreeGitPluginForceVAlign = 1
let g:DevIconsEnableFoldersOpenClose = 1
let g:WebDevIconsOS = 'Darwin'
let g:WebDevIconsUnicodeDecorateFileNodes = 0
let g:webdevicons_conceal_nerdtree_brackets = 1
let g:WebDevIconsNerdTreeAfterGlyphPadding = ' '
" adding to vim-airline's tabline
let g:webdevicons_enable_airline_tabline = 1
" adding to vim-airline's statusline
let g:webdevicons_enable_airline_statusline = 1

" after a re-source, fix syntax matching issues (concealing brackets):
if exists('g:loaded_webdevicons')
  call webdevicons#refresh()
endif

"--------------------------------------------------------------------------------



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
vnoremap i I
nnoremap <tab> V>
vnoremap <tab> >gv
vnoremap w aw
nnoremap <CR> i<CR><Esc>
nnoremap <silent> <C-Left> :bp<Esc>
nnoremap <silent> <C-Right> :bn<Esc>
nnoremap <silent> bw :bw<Esc>
"---------------------------------------------------------------------------------
