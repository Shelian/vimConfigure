set sw = 4
set ts = 4
set et
set smarttab
set smartindent
set lbr
set fo += mB
set sm
set selection = inclusive
set wildmenu
set mousemodel = popup

au FileType php setlocal dict += ~/ .vim / dict / php_funclist.dict
au FileType css setlocal dict += ~/ .vim / dict / css.dict
au FileType c setlocal dict += ~/ .vim / dict / c.dict
au FileType cpp setlocal dict += ~/ .vim / dict / cpp.dict
au FileType scale setlocal dict += ~/ .vim / dict / scale.dict
au FileType javascript setlocal dict += ~/ .vim / dict / javascript.dict
au FileType html setlocal dict += ~/ .vim / dict / javascript.dict
au FileType html setlocal dict += ~/ .vim / dict / css.dict

"
"syntastic���
execute pathogen#infect()
let g : syntastic_python_checkers = ['pylint']
let g : syntastic_php_checkers = ['php', 'phpcs', 'phpmd']
"golang
"Processing... % (ctrl+c to stop)
let g : fencview_autodetect = 0
set rtp += $GOROOT / misc / vim
" ��ʾ���  

syntax on
set cul "�������������
set cuc
set shortmess = atI   " ������ʱ����ʾ�Ǹ�Ԯ���ڸɴ��ͯ����ʾ  
set go = " ��Ҫͼ�ΰ�ť  
"color desert     " ���ñ�������
color ron     " ���ñ�������  
"color torte     " ���ñ�������
"set guifont=Courier_New:h10:cANSI   " ��������
"autocmd InsertLeave * se nocul  " ��ǳɫ������ǰ��
autocmd InsertEnter * se cul    " ��ǳɫ������ǰ��  
set ruler           " ��ʾ���  
set showcmd         " �����������ʾ�������������Щ  
"set whichwrap+=<,>,h,l   " ����backspace�͹�����Խ�б߽�(������)
set scrolloff = 3     " ����ƶ���buffer�Ķ����͵ײ�ʱ����3�о���  
set statusline = %F%m%r%h%w\[FORMAT = %{ &ff }]\[TYPE = %Y]\[POS = %l, %v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "״̬����ʾ������
set laststatus = 2    " ������ʾ״̬��(1),������ʾ״̬��(2)  
"set foldenable      " �����۵�
""set foldmethod = manual   " �ֶ��۵�  
set nocompatible  "ȥ��������й�viһ����ģʽ��������ǰ�汾��һЩbug�;���  
" ��ʾ���İ���
if version >= 603
set helplang = cn
set encoding = utf - 8
endif
" �Զ�����
set autoindent
set cindent
" Tab���Ŀ��
set tabstop = 4
" ͳһ����Ϊ4
set softtabstop = 4
set shiftwidth = 4
" ʹ�ÿո�����Ʊ��
set expandtab
" ���кͶο�ʼ��ʹ���Ʊ��
set smarttab
" ��ʾ�к�
set number
" ��ʷ��¼��
set history = 1000
"�������ַ�����
set hlsearch
set incsearch
"��������
set langmenu = zh_CN.UTF - 8
set helplang = cn
" ������ʾ״̬��
set cmdheight = 2
" ����ļ�����
filetype on
" �����ļ����Ͳ��
filetype plugin on
" Ϊ�ض��ļ�����������������ļ�
filetype indent on
" ����ȫ�ֱ���
set viminfo += !
" �������·��ŵĵ��ʲ�Ҫ�����зָ�
set iskeyword += _, $, @, %, #, -
" �ַ���������������Ŀ

"markdown����
au BufRead, BufNewFile *.{md, mdown, mkd, mkdn, markdown, mdwn}   set filetype = mkd
au BufRead, BufNewFile *.{go}   set filetype = go
au BufRead, BufNewFile *.{js}   set filetype = javascript
"rkdown to HTML  
nmap md : !~/ .vim / markdown.pl % > %.html <CR><CR>
nmap fi : !firefox %.html & <CR><CR>
nmap \ \cc
vmap \ \cc

"��tab�滻Ϊ�ո�
nmap tt : %s / \t / / g<CR>




"""""���ļ�����

"�½�.c,.h,.sh,.java�ļ����Զ������ļ�ͷ 
autocmd BufNewFile *.cpp, *.[ch], *.sh, *.rb, *.java, *.py exec ":call SetTitle()"
""���庯��SetTitle���Զ������ļ�ͷ
func SetTitle()
"����ļ�����Ϊ.sh�ļ� 
if &filetype == 'sh'
call setline(1, "\#!/bin/bash")
call append(line("."), "")
elseif &filetype == 'python'
call setline(1, "#!/usr/bin/env python")
call append(line("."), "# coding=utf-8")
call append(line(".") + 1, "")

elseif &filetype == 'ruby'
call setline(1, "#!/usr/bin/env ruby")
call append(line("."), "# encoding: utf-8")
call append(line(".") + 1, "")

"    elseif &filetype == 'mkd'
"        call setline(1,"<head><meta charset = \"UTF-8\"></head>")
else
call setline(1, "/*************************************************************************")
call append(line("."), "	> File Name: ".expand("%"))
call append(line(".") + 1, "	> Author: ")
call append(line(".") + 2, "	> Mail: ")
call append(line(".") + 3, "	> Created Time: ".strftime("%c"))
call append(line(".") + 4, " ************************************************************************/")
call append(line(".") + 5, "")
endif
if expand("%:e") == 'cpp'
call append(line(".") + 6, "#include<iostream>")
call append(line(".") + 7, "using namespace std;")
call append(line(".") + 8, "")
endif
if &filetype == 'c'
call append(line(".") + 6, "#include<stdio.h>")
call append(line(".") + 7, "")
endif
if expand("%:e") == 'h'
call append(line(".") + 6, "#ifndef _".toupper(expand("%:r"))."_H")
call append(line(".") + 7, "#define _".toupper(expand("%:r"))."_H")
call append(line(".") + 8, "#endif")
endif
if &filetype == 'java'
call append(line(".") + 6, "public class ".expand("%:r"))
call append(line(".") + 7, "")
endif
"�½��ļ����Զ���λ���ļ�ĩβ
endfunc
autocmd BufNewFile * normal G



"��������

:nmap <silent> <F9> <ESC> : Tlist<RETURN>
" shift tab pages
map <S - Left> : tabp<CR>
map <S - Right> : tabn<CR>
map!<C - Z> <Esc>zzi
map!<C - O> <C - Y>,
map <C - A> ggVG$"+y
map <F12> gg = G
map <C - w> <C - w>w
imap <C - k> <C - y>,
imap <C - t> <C - q><TAB>
imap <C - j> <ESC>
" ѡ��״̬�� Ctrl+c ����
"map <C-v> "*pa
imap <C - v> <Esc>"*pa
imap <C - a> <Esc>^
imap <C - e> <Esc>$
vmap <C - c> "+y
set mouse = v
"set clipboard=unnamed
"ȥ����  
nnoremap <F2> :g / ^\s*$ / d<CR>
"�Ƚ��ļ�  
nnoremap <C - F2> :vert diffsplit
"nnoremap <Leader>fu :CtrlPFunky<Cr>
"nnoremap <C-n> :CtrlPFunky<Cr>
"�г���ǰĿ¼�ļ�  
map <F3> : NERDTreeToggle<CR>
imap <F3> <ESC> : NERDTreeToggle<CR>
"����״�ļ�Ŀ¼  
map <C - F3> \be
: autocmd BufRead, BufNewFile *.dot map <F5> : w<CR> : !dot - Tjpg - o %<.jpg % && eog %<.jpg  <CR><CR> && exec "redr!"
"C��C++ ��F5��������
map <F5> : call CompileRunGcc()<CR>
func!CompileRunGcc()
exec "w"
if &filetype == 'c'
exec "!g++ % -o %<"
exec "!time ./%<"
elseif &filetype == 'cpp'
exec "!g++ % -o %<"
exec "!time ./%<"
elseif &filetype == 'java'
exec "!javac %"
exec "!time java %<"
elseif &filetype == 'sh'
:!time bash %
elseif &filetype == 'python'
exec "!time python2.7 %"
elseif &filetype == 'html'
exec "!firefox % &"
elseif &filetype == 'go'
"        exec "!go build %<"
exec "!time go run %"
elseif &filetype == 'mkd'
exec "!~/.vim/markdown.pl % > %.html &"
exec "!firefox %.html &"
endif
endfunc
"C,C++�ĵ���
map <F8> :call Rungdb()<CR>
func!Rungdb()
exec "w"
exec "!g++ % -g -o %<"
exec "!gdb ./%<"
endfunc


"�����ʽ�Ż���

map <F6> :call FormartSrc()<CR><CR>

"����FormartSrc()
func FormartSrc()
exec "w"
if &filetype == 'c'
exec "!astyle --style=ansi -a --suffix=none %"
elseif &filetype == 'cpp' || &filetype == 'hpp'
exec "r !astyle --style=ansi --one-line=keep-statements -a --suffix=none %> /dev/null 2>&1"
elseif &filetype == 'perl'
exec "!astyle --style=gnu --suffix=none %"
elseif &filetype == 'py' || &filetype == 'python'
exec "r !autopep8 -i --aggressive %"
elseif &filetype == 'java'
exec "!astyle --style=java --suffix=none %"
elseif &filetype == 'jsp'
exec "!astyle --style=gnu --suffix=none %"
elseif &filetype == 'xml'
exec "!astyle --style=gnu --suffix=none %"
else
exec "normal gg=G"
return
endif
exec "e! %"
endfunc
"��������FormartSrc


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
""ʵ������
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if has("autocmd")
autocmd BufReadPost *
\ if line("'\"") > 0 && line("'\"") <= line("$") |
\   exe "normal g`\"" |
\ endif
endif
"����vim��û���ļ�ʱ�Զ���NERDTree
autocmd vimenter * if !argc() | NERDTree | endif
" ֻʣ NERDTreeʱ�Զ��ر�
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif

" ���õ��ļ����Ķ�ʱ�Զ�����
set autoread
" quickfixģʽ
autocmd FileType c, cpp map <buffer> <leader><space> :w<cr> : make<cr>
"���벹ȫ 
set completeopt = preview, menu
"������  
"filetype plugin on
"���������  
"set clipboard+=unnamed 
"�Զ�����
set autowrite
"set ruler                   " ��״̬�����
"set cursorline              " ͻ����ʾ��ǰ��
set magic                   " ����ħ��
set guioptions -= T           " ���ع�����
set guioptions -= m           " ���ز˵���
""set foldcolumn = 0
""set foldmethod = indent
""set foldlevel = 3
" ��Ҫʹ��vi�ļ���ģʽ������vim�Լ���
set nocompatible
" ȥ������������ʾ����
set noeb
" �ڴ���δ�����ֻ���ļ���ʱ�򣬵���ȷ��
set confirm
"��ֹ������ʱ�ļ�
set nobackup
set noswapfile
"�������Դ�Сд
set ignorecase




set linespace = 0
" ��ǿģʽ�е��������Զ���ɲ���
set wildmenu
" ʹ�ظ����backspace����������indent, eol, start��
set backspace = 2
" ����backspace�͹�����Խ�б߽�
set whichwrap += <, >, h, l
" ������buffer���κεط�ʹ����꣨����office���ڹ�����˫����궨λ��
set mouse = a
set selection = exclusive
set selectmode = mouse, key
" ͨ��ʹ��: commands������������ļ�����һ�б��ı��
set report = 0
" �ڱ��ָ�Ĵ��ڼ���ʾ�հף������Ķ�
set fillchars = vert:\, stl:\, stlnc:\
" ������ʾƥ�������
set showmatch
" ƥ�����Ÿ�����ʱ�䣨��λ��ʮ��֮һ�룩
set matchtime = 1
" ����ƶ���buffer�Ķ����͵ײ�ʱ����3�о���
set scrolloff = 3
" ΪC�����ṩ�Զ�����
"�Զ���ȫ
"":inoremap(()<ESC>i
"":inoremap) <c - r >= ClosePair(')')<CR>
":inoremap { {<CR>}<ESC>O
":inoremap } <c-r>=ClosePair('}')<CR>
"" : inoremap[[]<ESC>i
"":inoremap] <c - r >= ClosePair(']')<CR>
"" : inoremap " ""<ESC>i
"" : inoremap ' ''<ESC>i
""function!ClosePair(char)
""	if getline('.')[col('.') - 1] == a : char
""		return "\<Right>"
""	else
""		return a : char
""	endif
""endfunction
filetype plugin indent on
"���ļ����ͼ��, �������ſ��������ܲ�ȫ
set completeopt = longest, menu
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CTags���趨  
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let Tlist_Sort_Type = "name"    " ������������  
let Tlist_Use_Right_Window = 1  " ���Ҳ���ʾ����  
let Tlist_Compart_Format = 1    " ѹ����ʽ  
let Tlist_Exist_OnlyWindow = 1  " ���ֻ��һ��buffer��kill����Ҳkill��buffer  
""let Tlist_File_Fold_Auto_Close = 0  " ��Ҫ�ر������ļ���tags  
""let Tlist_Enable_Fold_Column = 0    " ��Ҫ��ʾ�۵���  
"let Tlist_Show_One_File=1            "��ͬʱ��ʾ����ļ���tag��ֻ��ʾ��ǰ�ļ���
"����tags  
set tags = tags;
set autochdir


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"��������
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"Ĭ�ϴ�Taglist 
let Tlist_Auto_Open = 0
""""""""""""""""""""""""""""""
" Tag list (ctags) 
""""""""""""""""""""""""""""""""
let Tlist_Ctags_Cmd = '/usr/local/bin/ctags'
let Tlist_Show_One_File = 1 "��ͬʱ��ʾ����ļ���tag��ֻ��ʾ��ǰ�ļ��� 
let Tlist_File_Fold_Auto_Close = 1
let Tlist_Exit_OnlyWindow = 1 "���taglist���������һ�����ڣ����˳�vim 
let Tlist_Use_Right_Window = 1 "���Ҳര������ʾtaglist����
" minibufexpl�����һ������
let g : miniBufExplMapWindowNavVim = 1
let g : miniBufExplMapWindowNavArrows = 1
let g : miniBufExplMapCTabSwitchBufs = 1
let g : miniBufExplModSelTarget = 1
nmap tl : Tlist<cr>

"python��ȫ
let g : pydiction_location = '~/.vim/after/complete-dict'
let g : pydiction_menu_height = 20
let Tlist_Ctags_Cmd = '/usr/local/bin/ctags'
let g : miniBufExplMapWindowNavVim = 1
let g : miniBufExplMapWindowNavArrows = 1
let g : miniBufExplMapCTabSwitchBufs = 1
let g : miniBufExplModSelTarget = 1


set iskeyword += .
set termencoding = utf - 8
set encoding = utf8
set fileencodings = utf8, ucs - bom, gbk, cp936, gb2312, gb18030

autocmd FileType python set omnifunc = pythoncomplete#Complete

"set nocompatible               " be iMproved
"filetype off                   " required!

set rtp += ~/ .vim / bundle / vundle /
call vundle#rc()

" let Vundle manage Vundle
" required! 
Bundle 'gmarik/vundle'

" My Bundles here:
"
" original repos on github
Bundle 'tpope/vim-fugitive'
Bundle 'rstacruz/sparkup', { 'rtp': 'vim/' }
Bundle 'Yggdroot/indentLine'
let g : indentLine_char = '��'
"ndle 'tpope/vim-rails.git'
" vim-scripts repos
Bundle 'L9'
Bundle 'FuzzyFinder'
" non github repos
Bundle 'https://github.com/wincent/command-t.git'
Bundle 'Auto-Pairs'
Bundle 'python-imports.vim'
Bundle 'CaptureClipboard'
Bundle 'ctrlp-modified.vim'
Bundle 'last_edit_marker.vim'
Bundle 'synmark.vim'
"Bundle 'Python-mode-klen'
Bundle 'SQLComplete.vim'
Bundle 'Javascript-OmniCompletion-with-YUI-and-j'
"Bundle 'JavaScript-Indent'
"Bundle 'Better-Javascript-Indentation'
Bundle 'jslint.vim'
Bundle "pangloss/vim-javascript"
Bundle 'Vim-Script-Updater'
Bundle 'ctrlp.vim'
Bundle 'tacahiroy/ctrlp-funky'
Bundle 'jsbeautify'
Bundle 'The-NERD-Commenter'
"django
Bundle 'django_templates.vim'
Bundle 'Django-Projects'

"Bundle 'FredKSchott/CoVim'
"Bundle 'djangojump'
" ...
let g : html_indent_inctags = "html,body,head,tbody"
let g : html_indent_script1 = "inc"
let g : html_indent_style1 = "inc"

filetype plugin indent on     " required!
"
"ctrlp����
"
set wildignore += */ tmp/*,*.so,*.swp,*.zip,*.pyc,*.png,*.jpg,*.gif     " MacOSX/Linux
						set wildignore+=*\\tmp\\*,*.swp,*.zip,*.exe,*.pyc,*.png,*.jpg,*.gif  " Windows

						let g:ctrlp_custom_ignore = '\v[\/]\.(git|hg|svn)$'
						let g:ctrlp_custom_ignore = '\v\.(exe|so|dll)$'
						let g:ctrlp_extensions = ['funky']

						let NERDTreeIgnore=['\.pyc']