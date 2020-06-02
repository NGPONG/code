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
 " tags
 Plug 'ludovicchabant/vim-gutentags'
 Plug 'universal-ctags/ctags'
 Plug 'skywind3000/gutentags_plus'
 " syntax check
 Plug 'dense-analysis/ale'
 " visual tree
 Plug 'preservim/nerdtree'
 Plug 'ryanoasis/vim-devicons'
 Plug 'tiagofumo/vim-nerdtree-syntax-highlight'

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
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

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

" ALE
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 0
let g:ale_sign_error = '✗'
let g:ale_sign_warning = '⚡'
let g:ale_statusline_format = ['✗ %d', '⚡ %d', '✔ OK']
let g:ale_completion_delay = 500
let g:ale_echo_delay = 20
let g:ale_lint_delay = 500
let g:ale_lint_on_text_changed = 'normal'
let g:ale_lint_on_insert_leave = 1
let g:airline#extensions#ale#enabled = 1
let g:ale_c_gcc_options = '-Wall -O2 -std=c99'
let g:ale_cpp_gcc_options = '-Wall -O2 -std=c++14'
let g:ale_c_cppcheck_options = ''
let g:ale_cpp_cppcheck_options = ''

" set tags
set tags=./.tags;,.tags
let $GTAGSLABEL = 'native-pygments'
let $GTAGSCONF = '/usr/local/share/gtags/gtags.conf'
let g:gutentags_project_root = ['.root', '.svn', '.git', '.hg', '.project']
let g:gutentags_ctags_tagfile = '.tags'
let g:gutentags_modules = []
if executable('ctags')
	let g:gutentags_modules += ['ctags']
endif
if executable('gtags-cscope') && executable('gtags')
	let g:gutentags_modules += ['gtags_cscope']
endif
let g:gutentags_cache_dir = expand('~/.cache/tags')
let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
let g:gutentags_ctags_extra_args += ['--c++-kinds=+px']
let g:gutentags_ctags_extra_args += ['--c-kinds=+px']
let g:gutentags_ctags_extra_args += ['--output-format=e-ctags']
let g:gutentags_auto_add_gtags_cscope = 0
let g:gutentags_define_advanced_commands = 1

" nerd tree
map <F1> :NERDTreeToggle<CR>
let g:NERDTreeChDirMode = 2
let g:NERDTreeHidden=0
let NERDTreeShowBookmarks=1
autocmd BufEnter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) |cd %:p:h |endif
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1
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
nnoremap <C-Left> :bp<Esc>
nnoremap <C-Right> :bn<Esc>
nnoremap bw :bw<Esc>

