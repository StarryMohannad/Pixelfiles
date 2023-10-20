return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'

  -- Telescope
  use { 'nvim-telescope/telescope.nvim',
        tag = '0.1.2',
        requires = { 'nvim-lua/plenary.nvim' }
  }

  -- Nvim Tree
  use { 'nvim-tree/nvim-tree.lua',
         requires = { 'nvim-tree/nvim-web-devicons' },
  }

  -- Discord RPC
  use 'andweeb/presence.nvim'

  -- Treesitter
  use { 'nvim-treesitter/nvim-treesitter' }

  -- COC
  use { 'neoclide/coc.nvim',
        branch = 'release'
  }

  -- LSP Config
  use {
    "williamboman/mason.nvim",
    "williamboman/mason-lspconfig.nvim",
    "neovim/nvim-lspconfig",
  }

  -- Lualine
  use {
    'nvim-lualine/lualine.nvim',
    requires = { 'nvim-tree/nvim-web-devicons', opt = true }
  }

  -- Dashboard
  use {
    'glepnir/dashboard-nvim',
    event = 'VimEnter',
    config = function()
      require('dashboard').setup {
              theme = 'hyper',
              config = {
                          week_header = {
                            enable = true,
                          },

                          shortcut = {
                                       { desc = '󰊳 Update', group = '@property', action = 'PackerSync', key = 'u' },

                                       {
                                          icon = ' ',
                                          icon_hl = '@variable',
                                          desc = 'Files',
                                          group = 'Label',
                                          action = 'Telescope find_files',
                                          key = 'f',
                                       },

                                       {
                                          icon = ' ',
                                          icon_hl = '@variable',
                                          desc = 'Terminal',
                                          group = 'Label',
                                          action = 'term',
                                          key = 't',
                                       },
                       },
              },
      }
    end,
    requires = {'nvim-tree/nvim-web-devicons'}
  }

  -- Kitty Theme :3
  use {'catppuccin/nvim', as = 'catppuccin'}
end)


