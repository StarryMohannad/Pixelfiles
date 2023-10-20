local augroup = vim.api.nvim_create_augroup
local autocmd = vim.api.nvim_create_autocmd

autocmd('BufNewFile', {
  pattern = '',
  command = 'Dashboard'
})

autocmd('VimEnter', {
  pattern = '',
  command = 'NvimTreeOpen'
})
