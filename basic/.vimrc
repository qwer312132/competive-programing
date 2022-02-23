set nu
set cindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set autowrite
set mouse=a
autocmd filetype cpp nnoremap <F5> :w<CR> :!g++ % && ./a.out<CR>