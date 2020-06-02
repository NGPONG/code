"------------------------------BY_PLUGINS-------------------------------------------
call plug#begin('~/.local/share/nvim/plugged')
 " theme: one-darkd
 Plug 'tomasiser/vim-code-dark'
 " theme: dark-plus
 Plug 'joshdick/onedark.vim'
 " more syntax
 "Plug 'sheerun/vim-polyglot'
 " remove whitespace in world trailing
 Plug 'bronson/vim-trailing-whitespace'
 " airline
 "Plug 'vim-airline/vim-airline'
 "Plug 'vim-airline/vim-airline-themes'
 " tags
 "Plug 'ludovicchabant/vim-gutentags'
 "Plug 'universal-ctags/ctags'
 "Plug 'skywind3000/gutentags_plus'
 " syntax check
 "Plug 'dense-analysis/ale'
 " visual tree
 "Plug 'preservim/nerdtree'
 "Plug 'ryanoasis/vim-devicons'
 "Plug 'tiagofumo/vim-nerdtree-syntax-highlight'

 Plug 'neoclide/coc.nvim', {'branch': 'release'}

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
"let g:airline_powerline_fonts = 1
"let g:airline#extensions#whitespace#enabled = 0
"let g:airline#extensions#whitespace#symbol = '!'
"let g:airline#extensions#hunks#enabled=0
"let g:airline#extensions#branch#enabled=1
"let g:airline#extensions#tabline#enabled = 1
"let g:airline#extensions#tabline#formatter = 'unique_tail'
"let g:airline#extensions#tabline#tab_nr_type = 1
"let g:airline#extensions#tabline#show_tab_nr = 1
"let g:airline#extensions#tabline#buffer_nr_show = 0
"let g:airline#extensions#tabline#fnametruncate = 16
"let g:airline#extensions#tabline#fnamecollapse = 2
"let g:airline#extensions#tabline#buffer_idx_mode = 1
"if !exists('g:airline_symbols')
"  let g:airline_symbols = {}
"endif
"let g:airline_section_x=''
"let g:airline_skip_empty_sections = 1

" ALE
"let g:ale_sign_column_always = 1
"let g:ale_set_highlights = 0
"let g:ale_sign_error = '✗'
"let g:ale_sign_warning = '⚡'
"let g:ale_statusline_format = ['✗ %d', '⚡ %d', '✔ OK']
"let g:ale_completion_delay = 500
"let g:ale_echo_delay = 20
"let g:ale_lint_delay = 500
"let g:ale_lint_on_text_changed = 'normal'
"let g:ale_lint_on_insert_leave = 1
"let g:airline#extensions#ale#enabled = 1
"let g:ale_c_gcc_options = '-Wall -O2 -std=c99'
"let g:ale_cpp_gcc_options = '-Wall -O2 -std=c++14'
"let g:ale_c_cppcheck_options = ''
"let g:ale_cpp_cppcheck_options = ''

" set tags
"set tags=./.tags;,.tags
"let $GTAGSLABEL = 'native-pygments'
"let $GTAGSCONF = '/usr/local/share/gtags/gtags.conf'
"let g:gutentags_project_root = ['.root', '.svn', '.git', '.hg', '.project']
"let g:gutentags_ctags_tagfile = '.tags'
"let g:gutentags_modules = []
"if executable('ctags')
"	let g:gutentags_modules += ['ctags']
"endif
"if executable('gtags-cscope') && executable('gtags')
"	let g:gutentags_modules += ['gtags_cscope']
"endif
"let g:gutentags_cache_dir = expand('~/.cache/tags')
"let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
"let g:gutentags_ctags_extra_args += ['--c++-kinds=+px']
"let g:gutentags_ctags_extra_args += ['--c-kinds=+px']
"let g:gutentags_ctags_extra_args += ['--output-format=e-ctags']
"let g:gutentags_auto_add_gtags_cscope = 0
"let g:gutentags_define_advanced_commands = 1

" nerd tree
"map <F1> :NERDTreeToggle<CR>
"let g:NERDTreeChDirMode = 2
"let g:NERDTreeHidden=0
"let NERDTreeShowBookmarks=1
"autocmd BufEnter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) |cd %:p:h |endif
"autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
"let NERDTreeMinimalUI = 1
"let NERDTreeDirArrows = 1
"let g:NERDTreeDirArrowExpandable = '▸'
"let g:NERDTreeDirArrowCollapsible = '▾'
"let g:NERDTreeIndicatorMapCustom = {
"        \ "Modified"  : "✹",
"        \ "Staged"    : "✚",
"        \ "Untracked" : "✭",
"        \ "Renamed"   : "➜",
"        \ "Unmerged"  : "═",
"        \ "Deleted"   : "✖",
"        \ "Dirty"     : "✗",
"        \ "Clean"     : "✔︎",
"        \ 'Ignored'   : '☒',
"        \ "Unknown"   : "?"
"\}



" TextEdit might fail if hidden is not set.
set hidden

" Some servers have issues with backup files, see #649.
set nobackup
set nowritebackup

" Give more space for displaying messages.
set cmdheight=2

" Having longer updatetime (default is 4000 ms = 4 s) leads to noticeable
" delays and poor user experience.
set updatetime=300

" Don't pass messages to |ins-completion-menu|.
set shortmess+=c

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved.
if has("patch-8.1.1564")
  " Recently vim can merge signcolumn and number column into one
  set signcolumn=number
else
  set signcolumn=yes
endif

" Use tab for trigger completion with characters ahead and navigate.
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config.
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" Use <c-space> to trigger completion.
inoremap <silent><expr> <c-space> coc#refresh()

" Use <cr> to confirm completion, `<C-g>u` means break undo chain at current
" position. Coc only does snippet and additional edit on confirm.
" <cr> could be remapped by other vim plugin, try `:verbose imap <CR>`.
if exists('*complete_info')
  inoremap <expr> <cr> complete_info()["selected"] != "-1" ? "\<C-y>" : "\<C-g>u\<CR>"
else
  inoremap <expr> <cr> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"
endif

" Use `[g` and `]g` to navigate diagnostics
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" GoTo code navigation.
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

" Use K to show documentation in preview window.
nnoremap <silent> K :call <SID>show_documentation()<CR>

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

" Highlight the symbol and its references when holding the cursor.
autocmd CursorHold * silent call CocActionAsync('highlight')

" Symbol renaming.
nmap <leader>rn <Plug>(coc-rename)

" Formatting selected code.
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)

augroup mygroup
  autocmd!
  " Setup formatexpr specified filetype(s).
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  " Update signature help on jump placeholder.
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" Applying codeAction to the selected region.
" Example: `<leader>aap` for current paragraph
xmap <leader>a  <Plug>(coc-codeaction-selected)
nmap <leader>a  <Plug>(coc-codeaction-selected)

" Remap keys for applying codeAction to the current buffer.
nmap <leader>ac  <Plug>(coc-codeaction)
" Apply AutoFix to problem on the current line.
nmap <leader>qf  <Plug>(coc-fix-current)

" Map function and class text objects
" NOTE: Requires 'textDocument.documentSymbol' support from the language server.
xmap if <Plug>(coc-funcobj-i)
omap if <Plug>(coc-funcobj-i)
xmap af <Plug>(coc-funcobj-a)
omap af <Plug>(coc-funcobj-a)
xmap ic <Plug>(coc-classobj-i)
omap ic <Plug>(coc-classobj-i)
xmap ac <Plug>(coc-classobj-a)
omap ac <Plug>(coc-classobj-a)

" Use CTRL-S for selections ranges.
" Requires 'textDocument/selectionRange' support of LS, ex: coc-tsserver
nmap <silent> <C-s> <Plug>(coc-range-select)
xmap <silent> <C-s> <Plug>(coc-range-select)

" Add `:Format` command to format current buffer.
command! -nargs=0 Format :call CocAction('format')

" Add `:Fold` command to fold current buffer.
command! -nargs=? Fold :call     CocAction('fold', <f-args>)

" Add `:OR` command for organize imports of the current buffer.
command! -nargs=0 OR  :call     CocAction('runCommand', 'editor.action.organizeImport')

" Add (Neo)Vim's native statusline support.
" NOTE: Please see `:h coc-status` for integrations with external plugins that
" provide custom statusline: lightline.vim, vim-airline.
set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}



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

