"------------------------------BY_PLUGINS-------------------------------------------

call plug#begin('~/.local/share/nvim/plugged')

  " themes
  Plug 'NGPONG/vim-code-dark'
  "Plug 'tomasiser/vim-code-dark'
  "Plug 'w0ng/vim-hybrid'
  Plug 'rakr/vim-one'
  "Plug 'sonph/onehalf', {'rtp': 'vim/'}
  "Plug 'ayu-theme/ayu-vim'
  Plug 'morhetz/gruvbox'
  "Plug 'srcery-colors/srcery-vim'
  "Plug 'dunstontc/vim-vscode-theme'

  " more syntax
  Plug 'jackguo380/vim-lsp-cxx-highlight'
  
  " common
  "Plug 'bronson/vim-trailing-whitespace'
  "Plug 'lyokha/vim-xkbswitch'
  Plug 'preservim/nerdcommenter'
  Plug 'Yggdroot/indentLine'
  Plug 'luochen1990/rainbow'
  Plug 'psliwka/vim-smoothie'
  Plug 'qpkorr/vim-bufkill'
  
  " Intelligent
  Plug 'neoclide/coc.nvim', {'brnch': 'release'}
  Plug 'fatih/vim-go', { 'do': ':GoUpdateBinaries' }
  
  " visual tree
  Plug 'preservim/nerdtree'
  " Plug 'ryanoasis/vim-devicons'
  Plug 'Xuyuanp/nerdtree-git-plugin'
  
  " airline
  Plug 'vim-airline/vim-airline'
  Plug 'vim-airline/vim-airline-themes'
  
  " lightline
  "Plug 'itchyny/lightline.vim'
  "Plug 'mengelbrecht/lightline-bufferline'
  
  " pattern search
  " Plug 'Yggdroot/LeaderF', { 'do': './install.sh' }
  Plug 'mg979/vim-visual-multi'
  Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
  Plug 'junegunn/fzf.vim'
  Plug 'google/vim-searchindex'
  
  " debug
  " Plug 'puremourning/vimspector'
  
  " git
  Plug 'airblade/vim-gitgutter'
  
  " async
  Plug 'skywind3000/asyncrun.vim'

call plug#end()

"----------------------------------------------------------------------------------



"------------------------------BY_GLOBAL-------------------------------------------

" no-wrap for mysql cli
set nowrap

" remember_postion() {

if has("autocmd")
    au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" }


" reloads_vimrc_after_saving() {

autocmd! BufWritePost $MYVIMRC source $MYVIMRC

" }


" line_number() {

"set rulerformat=%l,%v
set number
set ruler

" }


" set_syntax_highlight() {

if has("syntax")
  syntax on
endif

" }


" tabwidth() {

set expandtab
set tabstop=2 softtabstop=2 shiftwidth=2

autocmd Filetype go set tabstop=4 softtabstop=4 shiftwidth=4

" }


" set_auto_indent() {

"set smartindent
"set cindent
"set smarttab
"set linebreak
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
set mousehide
"set scrolloff=20

" }

" display() {

set wrap
set breakindent
set breakindentopt=sbr
set showbreak=➥►
set display+=lastline

" }


" hide_status_bar_in_bottom() {

set shortmess+=F
set shortmess+=c
set shortmess-=S
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
"set relativenumber
set noshowmode

" }


" defualt_split_policy() {

set splitbelow
set splitright

" }


" improve_coc_expreience() {

try
  silent! set signcolumn=auto:4
endtry
set nobackup
set nowritebackup
set updatetime=100

" }

" vim_defualt_search() {

" see: https://harttle.land/2016/08/08/vim-search-in-file.html

set incsearch
set wrapscan

" 这里还可以制定清空 command line 的功能，暂时还不想搞
nnoremap <silent>oh :let @/ = ""<CR>

" highlight Search ctermbg=yellow ctermfg=black 
" highlight IncSearch ctermbg=black ctermfg=yellow 
" highlight MatchParen cterm=underline ctermbg=NONE ctermfg=NONE

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
"       2/1: onehalfdark
"            onehalflight
"   gruvbox: let g:gruvbox_contrast_dark = 'medium'
"            let g:gruvbox_sign_column = 'bg0'
"            let g:gruvbox_italic = 1
"            let g:gruvbox_bold = 1
"            let g:gruvbox_italicize_strings = 0
"            let g:gruvbox_italicize_comments = 1
"            let g:gruvbox_improved_strings = 0
"            gruvbox 
"            set background=dark
"let g:gruvbox_sign_column = 'bg0'
"    srcery: let g:srcery_italic = 1
"            srcery

let g:gruvbox_contrast_dark = 'medium'
let g:gruvbox_sign_column = 'bg0'
" let g:gruvbox_italic = 1
let g:gruvbox_bold = 1
let g:gruvbox_italicize_strings = 0
let g:gruvbox_italicize_comments = 1
let g:gruvbox_improved_strings = 0
colorscheme gruvbox 
set background=dark
let g:gruvbox_sign_column = 'bg0'

" }


" air_line() {

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


" light_line() {

"let g:lightline = {
"      \ 'colorscheme': 'powerline',
"      \ 'active': {
"      \   'left': [ [ 'mode', 'paste' ], [ 'readonly', 'filename', 'modified' ] ]
"      \ },
"      \ 'tabline': {
"      \   'left': [ ['buffers'] ],
"      \   'right': [ ['close'] ]
"      \ },
"      \ 'component_expand': {
"      \   'buffers': 'lightline#bufferline#buffers'
"      \ },
"      \ 'component_type': {
"      \   'buffers': 'tabsel'
"      \ }
"      \ }

"}


" nerd tree() {

function! Refresh_tree()
  if(exists("g:NERDTree") && g:NERDTree.IsOpen())
    silent execute 'NERDTreeRefresh'
  endif
endfunction
function! Open_tree()
  silent execute 'NERDTreeToggle'
  wincmd p
  call Refresh_tree()
endfunction
map <silent> <C-S-e> :call Open_tree()<CR>
autocmd BufWritePost * call Refresh_tree()
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let g:NERDTreeIgnore = ['^.ccls-cache$']
let g:NERDTreeChDirMode = 2
let g:NERDTreeShowBookmarks=0
let g:NERDTreeGitStatusUpdateOnWrite = 1
let g:NERDTreeHighlightCursorline=0
let g:NERDTreeMinimalUI=1
let g:NERDTreeWinSize=23
let g:Tlist_WinWidth=60
let g:NERDTreeShowHidden=1
let g:NERDTreeDirArrows=1
let g:NERDTreeAutoDeleteBuffer=1
let g:NERDTreeQuitOnOpen=0
let g:NERDTreeGitStatusIndicatorMapCustom = {
         \ "Modified"  : "M",
         \ "Staged"    : "A",
         \ "Untracked" : "T",
         \ "Renamed"   : "R",
         \ "Unmerged"  : "U",
         \ "Deleted"   : "D",
         \ "Dirty"     : "X",
 \}
let NERDTreeCustomOpenArgs = {'file': {'reuse': 'all', 'where': 'p', 'stay': 1, 'keepopen': 1}, 'dir': {}}
let NERDTreeNaturalSort=0

"autocmd VimEnter * if argc() == 1 | call Open_tree() | endif

" }


" set_nerd_tree_icons() {

" let g:WebDevIconsOS = 'Darwin'
" let g:webdevicons_enable_nerdtree = 1
" "let g:webdevicons_enable_airline_tabline = 1
" "let g:webdevicons_enable_airline_statusline = 1
" let g:WebDevIconsNerdTreeGitPluginForceVAlign = 1
" let g:WebDevIconsNerdTreeAfterGlyphPadding = ' '
" let g:DevIconsEnableFoldersOpenClose = 1
" if exists('g:loaded_webdevicons')
"   call webdevicons#refresh()
" endif

" }


" set_nerd_tree_icons_color() {

" :hi Directory guifg=#FFFFFF ctermfg=white
" let g:sol = {
" 	\"gui": {
" 		\"base03": "#002b36",
" 		\"base02": "#073642",
" 		\"base01": "#586e75",
" 		\"base00": "#657b83",
" 		\"base0": "#839496",
" 		\"base1": "#93a1a1",
" 		\"base2": "#eee8d5",
" 		\"base3": "#fdf6e3",
" 		\"yellow": "#ffd500",
"         \'wheat': "#b5a867",
" 		\"orange": "#cb4b16",
" 		\"red": "#dc322f",
" 		\"magenta": "#d33682",
" 		\"violet": "#ba89f3",
"         \"dark_violet": "#b55cb1",
" 		\"blue": "#268bd2",
"         \"dark_blue": "#009aeb",
" 		\"cyan": "#2aa198",
" 		\"green": "#719e07",
"         \"dark_green": "#3d9939",
"         \"cream": "#ffc56b"
" 	\},
" 	\"cterm": {
" 		\"base03": 8,
" 		\"base02": 0,
" 		\"base01": 10,
" 		\"base00": 11,
" 		\"base0": 12,
" 		\"base1": 14,
" 		\"base2": 7,
" 		\"base3": 15,
" 		\"yellow": 3,
"         \'wheat': 3,
" 		\"orange": 9,
" 		\"red": 1,
" 		\"magenta": 5,
" 		\"violet": 13,
"         \"dark_violet": 13,
"         \"dark_blue": 13,
" 		\"blue": 4,
" 		\"cyan": 6,
" 		\"green": 2,
"         \"dark_green": 2,
"         \"cream": 10
" 	\}
" \}
" function! DeviconsColors(config)
"   let colors = keys(a:config)
"   augroup devicons_colors
"     autocmd!
" 	for color in colors
"       if color == 'normal'
"         exec 'autocmd FileType nerdtree,startify if &background == ''dark'' | '.
"           \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base01.' ctermfg='.g:sol.cterm.base01.' | '.
"           \ 'else | '.
"           \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base1.' ctermfg='.g:sol.cterm.base1.' | '.
"           \ 'endif'
"           elseif color == 'emphasize'
"               exec 'autocmd FileType nerdtree,startify if &background == ''dark'' | '.
"                   \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base1.' ctermfg='.g:sol.cterm.base1.' | '.
"                   \ 'else | '.
"                   \ 'highlight devicons_'.color.' guifg='.g:sol.gui.base01.' ctermfg='.g:sol.cterm.base01.' | '.
"                   \ 'endif'
"           else
"               exec 'autocmd FileType nerdtree,startify highlight devicons_'.color.' guifg='.g:sol.gui[color].' ctermfg='.g:sol.cterm[color]
"           endif
"           exec 'autocmd FileType nerdtree,startify syntax match devicons_'.color.' /\v'.join(a:config[color], '|').'/ containedin=ALL'
"       endfor
"   augroup END
" endfunction
" let g:devicons_colors = {
" 	\'normal': ['', ''],
" 	\'emphasize': ['', '', '', '', '', '', '', ''],
" 	\'yellow': ['', '', '', '', ''],
"     \'wheat': [''],
" 	\'orange': ['', '', '', 'λ', '', ''],
" 	\'red': ['', '', '', '', '', '', '', '', ''],
" 	\'magenta': [''],
" 	\'violet': ['', '', '', ''],
" 	\'blue': ['', '', '', '', '', '', '', '', '', '', '', ''],
" 	\'cyan': ['', '', '', ''],
" 	\'green': ['', '', '', ''],
"     \'cream': ['', '', ''],
"     \'dark_blue': ['',''],
"     \'dark_green': [''],
"     \'dark_violet': ['']
" \}
" call DeviconsColors(g:devicons_colors)

" }


" coc() {

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    silent execute 'h '.expand('<cword>')
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

"autocmd! CompleteDone * if pumvisible() == 0 | pclose | endif
"autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')

let g:coc_global_extensions = [
  \ 'coc-lists',
  \ 'coc-json',
  \ 'coc-cmake',
  \ 'coc-snippets',
  \ 'coc-sh'
  \ ]

" }


" Leaderf() {

" let g:Lf_PreviewResult = {
"   \ 'line': 1
" \}
" let g:Lf_HideHelp=1
" let g:Lf_UseCache=0
" let g:Lf_UseVersionControlTool=0
" let g:Lf_IgnoreCurrentBufferName=0
" let g:Lf_ReverseOrder = 0
" let g:Lf_CommandMap = {'<C-K>': ['<Up>'], '<C-J>': ['<Down>']}
" let g:Lf_WindowHeight = 0.2
" let g:Lf_PreviewHorizontalPosition = 'right'
" let g:Lf_DefaultMode = 'Fuzzy'
" let g:Lf_PreviewInPopup = 1
" let g:Lf_PreviewResult = { 'rg': 1 }
" function! Find_current()
"   execute 'Leaderf rg --current-buffer --bottom --regexMode'
" endfunction
" function! Find_file()
"   execute 'Leaderf rg --bottom'
" endfunction
" let g:Lf_NormalMap = {
"     \ "_": [ 
"     \   ["<C-p>", "p"]
"     \ ]
" \}

" }


" fzf.vim() {

" This is the default extra key bindings
" let g:fzf_action = {
"   \ 'ctrl-t': 'tab split',
"   \ 'ctrl-x': 'split',
"   \ 'ctrl-v': 'vsplit' }

" layout setting.
" see: https://github.com/junegunn/fzf/blob/master/README-VIM.md
let g:fzf_layout = { 'window': { 'width': 0.9, 'height': 0.7 } }

" Customize fzf colors to match your color scheme
" - fzf#wrap translates this to a set of `--color` options
" let g:fzf_colors =
" \ { 'fg':      ['fg', 'Normal'],
"   \ 'bg':      ['bg', 'Normal'],
"   \ 'hl':      ['fg', 'Comment'],
"   \ 'fg+':     ['fg', 'CursorLine', 'CursorColumn', 'Normal'],
"   \ 'bg+':     ['bg', 'CursorLine', 'CursorColumn'],
"   \ 'hl+':     ['fg', 'Statement'],
"   \ 'info':    ['fg', 'PreProc'],
"   \ 'border':  ['fg', 'Ignore'],
"   \ 'prompt':  ['fg', 'Conditional'],
"   \ 'pointer': ['fg', 'Exception'],
"   \ 'marker':  ['fg', 'Keyword'],
"   \ 'spinner': ['fg', 'Label'],
"   \ 'header':  ['fg', 'Comment'] }

" When fzf starts in a terminal buffer, the file type of the buffer is set to fzf. 
" So you can set up FileType fzf autocmd to customize the settings of the window.
" For example, if you use a non-popup layout (e.g. {'down': '40%'}) on Neovim, you might want to temporarily disable the statusline for a cleaner look.
if has('nvim') && !exists('g:fzf_layout')
  autocmd! FileType fzf
  autocmd  FileType fzf set laststatus=0 noshowmode noruler
    \| autocmd BufLeave <buffer> set laststatus=2 showmode ruler
endif

"   - Preview window on the right with 50% width
"   - CTRL-/ will toggle preview window.
" - Note that this array is passed as arguments to fzf#vim#with_preview function.
" - To learn more about preview window options, see `--preview-window` section of `man fzf`.
let g:fzf_preview_window = ['right:50%', 'ctrl-p']

" }

" vimspector() {

" let g:vimspector_enable_mappings = 'VISUAL_STUDIO'
" function! s:PrintVariable(_val)
"   silent execute 'VimspectorEval '. a:_val
    "call feedkeys("G")
" endfunction
" command! -nargs=1 C call s:PrintVariable(<f-args>)
" function! s:WatchVariable(_val)
"   silent execute 'VimspectorWatch '. a:_val
" endfunction
" command! -nargs=1 W call s:WatchVariable(<f-args>)
" 
" command! Debug :call vimspector#Continue()
" command! Exit :call vimspector#Reset()
" command! Restart :call vimspector#Restart()
" 
" sign define vimspectorBP text=● texthl=dbg_break_point
" sign define vimspectorBPDisabled text=◌ texthl=Normal
" sign define vimspectorPC text=➤ texthl=dbg_current_pos
" 
" highlight dbg_break_point guibg=#none guifg=red
" highlight dbg_current_pos guibg=#none guifg=#ffc56b
" 
" let g:vimspector_install_gadgets = [ 'vscode-cpptools' ]
" 
" let g:vimspector_code_minwidth = 90
" let g:vimspector_terminal_maxwidth = 75
" let g:vimspector_terminal_minwidth = 20

" }


" gitgutter() {

"set foldtext=gitgutter#fold#foldtext()
highlight GitGutterAdd    guifg=#009900 ctermfg=2
highlight GitGutterChange guifg=#c4c421 ctermfg=3
highlight GitGutterChangeDelete guifg=#c4c421 ctermfg=4
highlight GitGutterDelete guifg=#ff2222 ctermfg=1
let g:gitgutter_close_preview_on_escape=1
let g:gitgutter_preview_win_floating = 0
let g:gitgutter_sign_allow_clobber = 1
let g:gitgutter_highlight_linenrs = 0
let g:gitgutter_use_location_list = 1
let g:gitgutter_sign_added = '▌'
let g:gitgutter_sign_modified = '▌'
let g:gitgutter_sign_removed = '▸ '
let g:gitgutter_sign_modified_removed = '▌'

" https://github.com/airblade/vim-gitgutter/issues/772
nmap hp <Plug>(GitGutterPreviewHunk):wincmd P<CR>

"let g:gitgutter_sign_removed_first_line = '^^'
"nnoremap <silent> <Esc> :pclose<CR>

" }


" compile() {

function! s:open_coc_quickfix()
  silent execute 'CocList --normal --no-quit quickfix'
endfunction
autocmd User AsyncRunStop call s:open_coc_quickfix()
let g:asyncrun_bell = 1

nnoremap <silent> <C-S-b> :AsyncRun gcc -Wall -g -O0 -static-libgcc -std=c11 -pthread -D_DEFAULT_SOURCE -Wno-unused-variable -Wunused-result "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" <CR>

function! Quick_run_c_program()
  silent execute "AsyncRun gcc -Wall -O0 -static-libgcc -std=c11 -pthread -D_DEFAULT_SOURCE -Wno-unused-variable -Wunused-result \"$(VIM_FILEPATH)\" -o \"$(VIM_FILEDIR)/$(VIM_FILENOEXT)\" && echo -e \"-------------------------------------------------------------------result-------------------------------------------------------------------\n\" && ./$(VIM_FILENOEXT) && rm ./$(VIM_FILENOEXT)"
endfunction
autocmd Filetype c command! Run :call Quick_run_c_program()


"nnoremap <C-m> :call asyncrun#quickfix_toggle(6)<cr>
"nnoremap <silent> <F7> :AsyncRun -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" <cr>

" }


" nerd_commenter() {

let g:NERDSpaceDelims = 1
let g:NERDCompactSexyComs = 1
let g:NERDDefaultAlign = 'both'
let g:NERDCustomDelimiters = { 'c': { 'left': '/*','right': '*/' } }
let g:NERDCommentEmptyLines = 0
let g:NERDTrimTrailingWhitespace = 1
let g:NERDToggleCheckAllLines = 1
let g:NERDUsePlaceHolders = 0

" }


" indentLine() {

let g:indentLine_char = '¦'
autocmd Filetype json let g:indentLine_setConceal = 0

" }


" raninbow_backet() {

let g:rainbow_active = 1
let g:rainbow_conf = {
	\	'guifgs': ['yellow', 'MediumOrchid2', 'SkyBlue2'],
	\	'operators': '_,_',
	\	'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold'],
	\}

" }


" vim-smootie() {

let g:smoothie_no_default_mappings = v:true

" }


" vim-go() {

let g:go_highlight_types = 1
let g:go_highlight_fields = 1
let g:go_highlight_functions = 1
let g:go_highlight_function_calls = 1
let g:go_highlight_operators = 1
let g:go_highlight_extra_types = 1

let g:go_fmt_autosave = 0
let g:go_imports_autosave = 0
let g:go_mod_fmt_autosave = 0
let g:go_metalinter_autosave = 0
let g:go_asmfmt_autosave = 0
let g:go_fmt_command = "gopls"
" let g:go_debug=["lsp"]

" }


" vim-visual-multi() {
  
" Ugly mapping, disable by default.
let g:VM_default_mappings=0
let g:VM_mouse_mappings=0
let g:VM_maps = {}

" customization key-bind mapping
let g:VM_maps['Find Under'] = '<C-d>'
let g:VM_maps['Find Subword Under'] = '<C-d>'

" }

"--------------------------------------------------------------------------------



"------------------------------BY_KEYS-------------------------------------------

inoremap <silent><expr> <Esc> (col('.') == 1) ? '<Esc>' : '<Esc><Right>'
nnoremap <silent><expr> <Home> (char2nr(matchstr(getline('.'), '\%' . (col('.') == 1 ? 1 : col('.') - 1) . 'c.'))) != 32 ? '^' : '0'
vnoremap <silent><expr> <Home> (char2nr(matchstr(getline('.'), '\%' . (col('.') == 1 ? 1 : col('.') - 1) . 'c.'))) != 32 ? '^' : '0'
inoremap <silent><expr> <Home> (char2nr(matchstr(getline('.'), '\%' . (col('.') == 1 ? 1 : col('.') - 1) . 'c.'))) != 32 ? '<Esc>^i' : '<Esc>0i'
vnoremap <End> $h
nnoremap <End> $l
"nnoremap <BS> "_X
"vnoremap <BS> "_X
"nnoremap <Space> i<Space><Esc>l
nnoremap x "_x
nnoremap X "_X
vnoremap x "_x
vnoremap X "_X
nnoremap p P
vnoremap p pgvy
nmap a i
vmap a I
vmap q b
" 这种映射方式可以直接选中一个单词，但是会出现前后不定的情况
" vnoremap w iw 
vnoremap w e
nnoremap q b
nnoremap <silent> <C-Left> :bp<Esc>
nnoremap <silent> <C-Right> :bn<Esc>
" setl bufhidden=delete<bar>bprevious<Esc>
nnoremap <silent> <C-Del> :BW<CR>
nnoremap <silent> <C-S-Left> <C-w><Left>
nnoremap <silent> <C-S-Right> <C-w><Right>
nnoremap <silent> <C-S-Up> <C-w><Up>
nnoremap <silent> <C-S-Down> <C-w><Down>
nnoremap <silent> <C-S-Del> <C-w>q
noremap <silent><F12> :<C-u>call CocActionAsync('jumpDefinition')<CR>
noremap <silent>sf :<C-u>call CocActionAsync('jumpReferences')<CR>
nnoremap <silent><C-F12> <C-o>
noremap <silent><C-k><C-d> :<C-u>call CocActionAsync('formatSelected',visualmode())<CR>
nnoremap <C-a> gg<S-v>G
inoremap <silent><C-s> <Esc>:w<CR>
nnoremap <silent><C-s> :w<CR>
"nnoremap <C-S-p> :

" Leaderf key-bind, disabled for now.
" nnoremap <silent>bl :Leaderf buffer --bottom<CR>
" noremap <silent><C-f> :call Find_current()<CR>
" noremap <silent><C-g> :call Find_file()<CR>

nnoremap <F36> <C-o>
nnoremap <silent><C-n> :CocList --normal diagnostics<CR>
nnoremap <silent><C-j> :CocList --normal quickfix<CR>
"nnoremap <silent><C-b> :call vimspector#ToggleBreakpoint()<CR>
vmap <C-k><C-s> <plug>NERDCommenterToggle
map <F1> <Esc>
imap <F1> <Esc>
nnoremap <S-Up> <C-y>
nnoremap <S-Down> <C-e>
vnoremap <S-Up> <C-y>
vnoremap <S-Down> <C-e>
" nnoremap <C-Up> <C-u>
map <silent> <C-Up> <cmd>call smoothie#upwards()<CR>
" nnoremap <C-Down> <C-d>
map <silent> <C-Down> <cmd>call smoothie#downwards()<CR>
map <silent> <PageDown> <cmd>call smoothie#forwards()<CR>
map <silent> <PageUp> <cmd>call smoothie#backwards()<CR>
inoremap <silent><c-z> <Esc>:u<CR>i
nnoremap <silent><c-z> u
map <S-Insert> <C-r>"
map! <S-Insert> <C-r>"
inoremap <C-Space> <Nop>
nnoremap <C-Space> <Nop>
nnoremap <C-f> /
" tnoremap <Esc> <C-\><C-n> " this key-bind make strange with fzf closing behavior.

"---------------------------------------------------------------------------------
