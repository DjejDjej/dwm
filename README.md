# DWM config + more

## How to install

`sudo pacman -S base-devel libx11 libxft libxinerama freetype2 fontconfig ttf-dejavu ttf-dejavu-nerd `
`cd dwm'
`sudo make clean install `

## Screenshots
 ![Screenshot](https://raw.githubusercontent.com/DjejDjej/dotfiles/refs/heads/main/images/terminals.png)
 ![Screenshot](https://raw.githubusercontent.com/DjejDjej/dotfiles/refs/heads/main/images/vim.png)
 ![Screenshot](https://raw.githubusercontent.com/DjejDjej/dotfiles/refs/heads/main/images/vimopen.png)

## Application rules

- **Chromium**: Tag 1
- **Kitty**: Tag 2
- **KeePassXC**: Tag 3
- **Zoom**: Tag 4
- **Discord**: Tag 3
- **Pavucontrol**: Tag 5 


## Keybindings

- **Modkey ** = alt

- **MODKEY + r**: Launch **Chromium** in dark mode (web browser).
- **MODKEY + t**: Launch **kitty** (default terminal).
- **MODKEY + Shift + t**: Launch **termclone** (an additional instance of the kitty terminal).
- **MODKEY + y**: Run **togglelayout** (changes keyboard layout).
- **MODKEY + q**: **Close the focused window** (kills the currently active application).
- **MODKEY + End**: **Quit the window manager session** (ends the session or logs out).
- **MODKEY + l**: **Lock the screen** (using the `slock` tool to secure the session).
- **MODKEY + x**: Open **KeePassXC** (a password manager).
- **MODKEY + d**: Open **Discord** (messaging app).
- **MODKEY + Print**: Take a **screenshot** (using the specified screenshot tool).
- **MODKEY + e**: **Cycle through windows** in the current stack in reverse order.
- **MODKEY + i**: **Add a window to the master area** (increases the number of master windows in the layout).
- **MODKEY + u**: **Remove a window from the master area** (decreases the number of master windows).
- **MODKEY + j**: **Shrink the size of the current window** (decreases the master window size).
- **MODKEY + k**: **Expand the size of the current window** (increases the master window size).
- **MODKEY + o**: **Zoom the selected window** (brings it into the master area or swaps it).
- **MODKEY + Tab**: **Move to the next window** in the view.
- **MODKEY + Shift + Tab**: **Move to the previous window** in the view.
- **MODKEY + g**: **Toggle gaps** (adjusts the gaps around windows for aesthetics or spacing).
