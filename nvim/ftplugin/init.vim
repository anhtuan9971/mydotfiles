augroup jdtls_lsp
    autocmd!
    autocmd FileType java lua require'jdtls_setup'.setup()
augroup end
