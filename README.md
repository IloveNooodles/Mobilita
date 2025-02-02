# Mobilita

Tugas Besar Alstrukdat IF2110

With the COVID-19 pandemic, Mobita's parents' business has decreased income. After the PPKM was eased, Mobita wanted to help his parents
earn a living as a courier. Your job is to help Mobita
developed an app that would help him track orders, navigate maps, pick up
and unload goods.

Mobilita is CLI (Command Line Interface) Game that we made using c language. This game includes a lot of data structure and also Abstract Data Types that we made ourself. Some of them are Stack, Queue, Linked list, and many more. The purpose of the game is to deliver all of the item in TODO list and get the fastest time and also lot of money.

## Setup

- If you're in windows based, install GNU Compiler (GCC) and set the PATH (Because UNIX already have the gcc installed by the first place).
- If you're in UNIX based just follow the Usage instruction.

## Usage

1. Clone this repository
2. If you want to edit the configuration file, it is inside `config/config.txt`
3. Execute `run.bat` if you're in windows
4. If you're in UNIX based OS, Execute `run.sh`

## Features Done

- Main menu
- Time mechanism
- Ordered List
- To do list
- In progress list
- Bag
- Item
- Ability
- Gadget
- Inventory
- Peta
- Command includes (MOVE, PICK_UP, DROP_OFF, MAP, TO_DO, IN_PROGRESS, BUY, INVENTORY, HELP, RETURN)
- Game Flow
- All the bonus includes save game/load game, vip item, gadget and ability.

## Member List:

| Nama                           |   NIM    |                                                   Workload management                                                   |
| ------------------------------ | :------: | :---------------------------------------------------------------------------------------------------------------------: |
| Vionie Novencia Thanggestyo    | 13520006 |                                     All of gadget implementation & Inventory gadget                                     |
| Gagas Praharsa Bahar           | 13520016 |               Start menu and main menu, new game, exit, load/save, mesin kata & karakter, move, map, help               |
| Muhammad Garebaldhie Er Rahman | 13520029 | Start game, game flow, pickup, dropoff, map,bag, item, ability, VIP Item, Return to sender, TO DO list, inprogress list |
| Taufan Fajarama Putrawansyah R | 13520031 |                                       Daftar Pesanan, TO DO list, inprogress list                                       |
| Jeremy S.O.N. Simbolon         | 13520042 |                                     Bag, Normal item, Heavy item, Perishable item.                                      |
| Arik Rayi Arkananta            | 13520048 |                             Speed boost, increase capacity, map, dropoff, return to sender                              |

## Program Structure

```
│   .gitignore
│   main.c
│   main.exe
│   README.md
│   run.bat
│   run.sh
│   todo.md
│
├───.vscode
│       settings.json
│
├───config
│       1241.txt
│       a.txt
│       config.txt
│       config2.txt
│       end.txt
│       misalnyasave.txt
│       test.txt
│
├───Doc
│       IF2110_FormAsistensiTB.doc
│       IF2110_TB_01_01.pdf
│       IF2110_TemplateLaporanTB.doc
│       Pedoman Tubes 2021-2022.pdf
│       Spesifikasi Tugas Besar IF2110 .pdf
│       Spesifikasi Tugas Besar IF2110 rev 1.pdf
│
└───lib
    │   adt.h
    │   tempdriver.h
    │
    ├───ability
    │       ability.c
    │       ability.exe
    │       ability.h
    │       ability_driver.c
    │       run.bat
    │
    ├───gadget
    │       gadget.c
    │       gadget.h
    │       gadget_driver.c
    │
    ├───item
    │       item.c
    │       item.exe
    │       item.h
    │       item_driver.c
    │       run.bat
    │
    ├───listdin
    │       listdin.c
    │       listdin.exe
    │       listdin.h
    │       listdin_driver.c
    │       run.bat
    │
    ├───listpos
    │       listpos.c
    │       listpos.h
    │
    ├───list_linked
    │       list_linked.c
    │       list_linked.exe
    │       list_linked.h
    │       list_linked_driver.c
    │       node.c
    │       node.h
    │       run.bat
    │
    ├───lokasi
    │       lokasi.c
    │       lokasi.exe
    │       lokasi.h
    │       lokasi_driver.c
    │       run.bat
    │
    ├───matrix
    │       matrix.c
    │       matrix.exe
    │       matrix.h
    │       matrix_driver.c
    │       run.bat
    │
    ├───pcolor
    │       pcolor.c
    │       pcolor.h
    │       pcolor_driver.c
    │
    ├───point
    │       point.c
    │       point.exe
    │       point.h
    │       point_driver.c
    │       run.bat
    │
    ├───PrioQueue
    │       prioqueue.c
    │       prioqueue.exe
    │       prioqueue.h
    │       prioqueue_driver.c
    │       run.bat
    │
    ├───stack
    │       run.bat
    │       stack.c
    │       stack.h
    │       stack_driver.c
    │       stack_driver.exe
    │
    ├───utility
    │       boolean.h
    │       const.h
    │       game.c
    │       game.exe
    │       game.h
    │       game_driver.c
    │       run.bat
    │       utility.c
    │       utility.h
    │
    └───wordmachine
            charmachine.c
            charmachine.h
            wordmachine.c
            wordmachine.h
```
