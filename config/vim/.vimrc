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

 Plug 'ludovicchabant/vim-gutentags'
 Plug 'universal-ctags/ctags'
 Plug 'skywind3000/gutentags_plus'

 Plug 'dense-analysis/ale'

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
set encoding=utf-8
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
"let g:ale_linters_explicit = 1
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
" gutentags 搜索工程目录的标志，当前文件路径向上递归直到碰到这些文件/目录名
let g:gutentags_project_root = ['.root', '.svn', '.git', '.hg', '.project']
" 所生成的数据文件的名称
let g:gutentags_ctags_tagfile = '.tags'
" 同时开启 ctags 和 gtags 支持：
let g:gutentags_modules = []
if executable('ctags')
	let g:gutentags_modules += ['ctags']
endif
if executable('gtags-cscope') && executable('gtags')
	let g:gutentags_modules += ['gtags_cscope']
endif
" 将自动生成的 ctags/gtags 文件全部放入 ~/.cache/tags 目录中，避免污染工程目录
let g:gutentags_cache_dir = expand('~/.cache/tags')
" 配置 ctags 的参数，老的 Exuberant-ctags 不能有 --extra=+q，注意
let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
let g:gutentags_ctags_extra_args += ['--c++-kinds=+px']
let g:gutentags_ctags_extra_args += ['--c-kinds=+px']
" 如果使用 universal ctags 需要增加下面一行，老的 Exuberant-ctags 不能加下一行
let g:gutentags_ctags_extra_args += ['--output-format=e-ctags']
" 禁用 gutentags 自动加载 gtags 数据库的行为
let g:gutentags_auto_add_gtags_cscope = 0


let g:gutentags_plus_switch = 1


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
