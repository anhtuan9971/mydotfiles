local impatient_ok, impatient = pcall(require, "impatient")
if impatient_ok then
  impatient.enable_profile()
end

local utils = require "core.utils"

utils.disabled_builtins()

utils.bootstrap()

local sources = {
  "core.options",
  "core.autocmds",
  "core.plugins",
  "core.mappings",
}

for _, source in ipairs(sources) do
  local status_ok, fault = pcall(require, source)
  if not status_ok then
    error("Failed to load " .. source .. "\n\n" .. fault)
  end
end

utils.compiled()

local polish = utils.user_plugin_opts "polish"
if type(polish) == "function" then
  polish()
end

local Plug = vim.fn['plug#']

vim.call('plug#begin', '~/.config/nvim/plugged')

-- List of plugins goes here
-- ....
-- PLug 'xianzhon/vim-code-runner'
--code runner
Plug 'xianzhon/vim-code-runner'
Plug ('neoclide/coc.nvim', {branch = 'release'})
Plug 'mfussenegger/nvim-jdtls'
vim.call('plug#end')
vim.cmd [[
let g:code_runner_save_before_execute = 1
]]
