"------------------------------BY_PLUGINS-------------------------------------------
call plug#begin('~/.local/share/nvim/plugged')

 " themes
 Plug 'tomasiser/vim-code-dark'
 Plug 'w0ng/vim-hybrid'
 Plug 'rakr/vim-one'

 " more syntax
 Plug 'jackguo380/vim-lsp-cxx-highlight'

 " common
 "Plug 'bronson/vim-trailing-whitespace'

 " Intelligent
 Plug 'neoclide/coc.nvim', {'brnch': 'release'}

 " visual tree
 Plug 'preservim/nerdtree'
 Plug 'ryanoasis/vim-devicons'
 Plug 'Xuyuanp/nerdtree-git-plugin'

 " airline
 Plug 'vim-airline/vim-airline'
 Plug 'vim-airline/vim-airline-themes'

 " file
 Plug 'Yggdroot/LeaderF', { 'do': './install.sh' }

 " debug
 Plug 'puremourning/vimspector'

 " git
 Plug 'airblade/vim-gitgutter'

 " async
 Plug 'skywind3000/asyncrun.vim'

call plug#end()
"----------------------------------------------------------------------------------



"------------------------------BY_GLOBAL-------------------------------------------

" remember_postion() {

if has("autocmd")
    au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" }

" reloads_vimrc_after_saving() {

autocmd! BufWritePost $MYVIMRC source $MYVIMRC

" }


" line_number() {

set number

" }


" set_syntax_highlight() {

if has("syntax")
  syntax on
endif

" }


" tabwidth() {

set tabstop=4 softtabstop=0 expandtab shiftwidth=2 smarttab

" }


" set_auto_indent() {

set autoindent

" }


" share_cliboard_by_sys() {

set clipboard^=unnamed,unnamedplus

" }


" use_terminal_color_policy() {

if (empty($TMUX))
  if (has("nvim"))
  let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  endif
    if (has("termguicolors"))
    set termguicolors
  endif
endif

" }


" cursor() {

set ve+=onemore
set cursorline
"set guicursor=
set mousehide

" }


" hide_status_bar_in_bottom() {

set shortmess=F
set shortmess+=c
set noshowmode
set noruler
set laststatus=0
set noshowcmd
set cmdheight=1

" }


" encoding() {

set encoding=UTF-8
set fileencoding=utf-8

" }


" some_state_options {

set hidden
set relativenumber

" }


" defualt_split_policy() {

set splitbelow
set splitright

" }


" improve_coc_expreience() {

set nobackup
set nowritebackup
set updatetime=300
set signcolumn=yes

" }

"--------------------------------------------------------------------------------



"------------------------------BY_PLUGINS----------------------------------------
" colorscheme() {

" dark_plus: codedark;
"   hy_bird: hybrid
"            set background=dark;
"       one: one
"            set background=dark;
"            let g:one_allow_italics = 1; " may be dont support
colorscheme one
set background=dark
let g:one_allow_italics = 1

" }


" air_line() {

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

" }


" nerd tree() {

function! Refresh_tree()
  if(exists("g:NERDTree") && g:NERDTree.IsOpen())
    execute 'NERDTreeRefresh'
  endif
endfunction
function! Open_tree()
  execute 'NERDTreeToggle'
  call Refresh_tree()
endfunction
map <silent> <C-e> :call Open_tree()<CR>
autocmd BufWritePost * call Refresh_tree()
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let g:NERDTreeIgnore = ['^.ccls-cache$']
let g:NERDTreeChDirMode = 2
let NERDTreeShowBookmarks=0
let g:NERDTreeUpdateOnWrite = 1
let g:NERDTreeHighlightCursorline = 0
let NERDTreeMinimalUI = 1
let g:NERDTreeWinSize=23
let g:Tlist_WinWidth=60
let NERDTreeShowHidden=1
let NERDTreeDirArrows = 1
let NERDTreeAutoDeleteBuffer = 1
let g:NERDTreeDirArrowExpandable = ''
let g:NERDTreeDirArrowCollapsible = ''
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
let NERDTreeCustomOpenArgs = {'file': {'reuse': 'all', 'where': 'p', 'stay': 1}, 'dir': {}}
"autocmd VimEnter * if argc() == 1 | NERDTree | wincmd p | endif

" }


" set_nerd_tree_icons() {

let g:WebDevIconsOS = 'Darwin'
let g:webdevicons_enable_nerdtree = 1
let g:webdevicons_enable_airline_tabline = 1
let g:webdevicons_enable_airline_statusline = 1
let g:WebDevIconsNerdTreeGitPluginForceVAlign = 1
let g:WebDevIconsNerdTreeAfterGlyphPadding = ' '
let g:DevIconsEnableFoldersOpenClose = 1
if exists('g:loaded_webdevicons')
  call webdevicons#refresh()
endif

" }


" set_nerd_tree_icons_color() {

:hi Directory guifg=#FFFFFF ctermfg=white
let g:sol = {
	\"gui": {
		\"base03": "#002b36",
		\"base02": "#073642",
		\"base01": "#586e75",
		\"base00": "#657b83",
		\"base0": "#839496",
		\"base1": "#93a1a1",
		\"base2": "#eee8d5",
		\"base3": "#fdf6e3",
		\"yellow": "#ffd500",
        \'wheat': "#b5a867",
		\"orange": "#cb4b16",
		\"red": "#dc322f",
		\"magenta": "#d33682",
		\"violet": "#ba89f3",
        \"dark_violet": "#b55cb1",
		\"blue": "#268bd2",
        \"dark_blue": "#009aeb",
		\"cyan": "#2aa198",
		\"green": "#719e07",
        \"dark_green": "#3d9939",
        \"cream": "#ffc56b"
	\},
	\"cterm": {
		\"base03": 8,
		\"base02": 0,
		\"base01": 10,
		\"base00": 11,
		\"base0": 12,
		\"base1": 14,
		\"base2": 7,
		\"base3": 15,
		\"yellow": 3,
        \'wheat': 3,
		\"orange": 9,
		\"red": 1,
		\"magenta": 5,
		\"violet": 13,
        \"dark_violet": 13,
        \"dark_blue": 13,
		\"blue": 4,
		\"cyan": 6,
		\"green": 2,
        \"dark_green": 2,
        \"cream": 10
	\}
\}
function! DeviconsColors(config)
  let colors = keys(a:config)
  augroup devicons_colors
    autocmd!
	for color in colors
      if color == 'normal'
        exec 'autocmd FileType nerdtree,startify if &background == ''dark'' | '.
          \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base01.' ctermfg='.g:sol.cterm.base01.' | '.
          \ 'else | '.
          \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base1.' ctermfg='.g:sol.cterm.base1.' | '.
          \ 'endif'
          elseif color == 'emphasize'
              exec 'autocmd FileType nerdtree,startify if &background == ''dark'' | '.
                  \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base1.' ctermfg='.g:sol.cterm.base1.' | '.
                  \ 'else | '.
                  \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base01.' ctermfg='.g:sol.cterm.base01.' | '.
                  \ 'endif'
          else
              exec 'autocmd FileType nerdtree,startify highlight devicons_'.color.' guifg='.g:sol.gui[color].' ctermfg='.g:sol.cterm[color]
          endif
          exec 'autocmd FileType nerdtree,startify syntax match devicons_'.color.' /\v'.join(a:config[color], '|').'/ containedin=ALL'
      endfor
  augroup END
endfunction
let g:devicons_colors = {
	\'normal': ['', ''],
	\'emphasize': ['', '', '', '', '', '', '', ''],
	\'yellow': ['', '', '', '', ''],
    \'wheat': [''],
	\'orange': ['', '', '', 'λ', '', ''],
	\'red': ['', '', '', '', '', '', '', '', ''],
	\'magenta': [''],
	\'violet': ['', '', '', ''],
	\'blue': ['', '', '', '', '', '', '', '', '', '', '', ''],
	\'cyan': ['', '', '', ''],
	\'green': ['', '', '', ''],
    \'cream': ['', '', ''],
    \'dark_blue': ['',''],
    \'dark_green': [''],
    \'dark_violet': ['']
\}
call DeviconsColors(g:devicons_colors)

" }


" coc() {

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocActionAsync('doHover')
  endif
endfunction
nnoremap <silent><C-p> :call <SID>show_documentation()<CR>

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction
inoremap <silent><expr> <TAB>
  \ pumvisible() ? coc#_select_confirm() :
  \ coc#expandableOrJumpable() ?
  \ "\<C-r>=coc#rpc#request('doKeymap', ['snippets-expand-jump',''])\<CR>" :
  \ <SID>check_back_space() ? "\<TAB>" :
  \ coc#refresh()
let g:coc_snippet_next = '<tab>'

autocmd! CompleteDone * if pumvisible() == 0 | pclose | endif
autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')

let g:coc_global_extensions = [
  \ 'coc-lists',
  \ 'coc-json',
  \ 'coc-cmake'
  \ ]

" }


" Leaderf() {

let g:Lf_PreviewResult = {
  \ 'Rg': 1
\}
let g:Lf_HideHelp = 1
let g:Lf_UseCache = 0
let g:Lf_UseVersionControlTool = 0
let g:Lf_IgnoreCurrentBufferName = 1
let g:Lf_ReverseOrder = 0
let g:Lf_CommandMap = {'<C-K>': ['<Up>'], '<C-J>': ['<Down>']}
let g:Lf_WindowHeight = 0.2
let g:Lf_PreviewHorizontalPosition = 'right'
let g:Lf_DefaultMode = 'Fuzzy'
function! Find_current()
  let g:Lf_PreviewInPopup = 0
  execute 'Leaderf line --bottom'
endfunction
function! Find_file()
  let g:Lf_PreviewInPopup = 1
  execute 'Leaderf rg --bottom'
endfunction
let g:Lf_NormalMap = {
    \ "_": [ 
    \   ["<C-p>", "p"]
    \ ]
\}

" }


" vimspector() {

let g:vimspector_enable_mappings = 'VISUAL_STUDIO'
function! s:PrintVariable(_val)
  execute 'VimspectorEval '. a:_val
  call feedkeys("G")
endfunction
command! -nargs=1 C call s:PrintVariable(<f-args>)
function! s:WatchVariable(_val)
  execute 'VimspectorWatch '. a:_val
endfunction
command! -nargs=1 W call s:WatchVariable(<f-args>)

" }


" gitgutter() {

set foldtext=gitgutter#fold#foldtext()
highlight GitGutterAdd    guifg=#009900 ctermfg=2
highlight GitGutterChange guifg=#bbbb00 ctermfg=3
highlight GitGutterDelete guifg=#ff2222 ctermfg=1
let g:gitgutter_preview_win_floating = 0

" }


" compile() {

function! s:open_coc_quickfix()
  execute 'CocList --normal --no-quit quickfix'
endfunction
autocmd User AsyncRunStop call s:open_coc_quickfix()
let g:asyncrun_bell = 1
"nnoremap <C-m> :call asyncrun#quickfix_toggle(6)<cr>
"nnoremap <silent> <F8> :AsyncRun gcc -Wall -O2 "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" <cr>
"nnoremap <silent> <F7> :AsyncRun -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" <cr>

" }

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
nmap a i
vmap a i
vmap i I
vnoremap w aw
nnoremap <silent> <C-Left> :bp<Esc>
nnoremap <silent> <C-Right> :bn<Esc>
nnoremap <silent> <C-Del> :setl bufhidden=delete<bar>bprevious<Esc>
nnoremap <silent> <C-S-Left> <C-w><Left>
nnoremap <silent> <C-S-Right> <C-w><Right>
nnoremap <silent> <C-S-Up> <C-w><Up>
nnoremap <silent> <C-S-Down> <C-w><Down>
nnoremap <silent> <C-S-Del> <C-w>q
noremap <silent><F12> :<C-u>call CocActionAsync('jumpDefinition')<CR>
noremap <silent>sf :<C-u>call CocActionAsync('jumpReferences')<CR>
vnoremap <C-k><C-d> :<C-u>call CocActionAsync('formatSelected',visualmode())<CR>
nnoremap <S-Up> <C-u>
nnoremap <S-Down> <C-d>
nnoremap <C-a> gg<S-v>G
nnoremap bl :Leaderf buffer --bottom<CR>
noremap <C-f> :call Find_current()<CR>
noremap <C-g> :call Find_file()<CR>
nnoremap <F36> <C-o>
nnoremap <silent><C-d> :CocList --normal diagnostics<CR>
nnoremap <silent><C-j> :CocList --normal quickfix<CR>
nnoremap <silent><C-b> :call vimspector#ToggleBreakpoint()<CR>
command! Run :call vimspector#Continue()
command! Exit :call vimspector#Reset()
command! Restart :call vimspector#Restart()
"---------------------------------------------------------------------------------
