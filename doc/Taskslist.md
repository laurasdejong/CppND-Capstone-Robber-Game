# Options to implement


## Instructions

- Fill rubric criteria

## Game play

### Controller
- Make controller robust. Bug: when an arrow is pressed in the terminal, the demand is permanently set to 0, skipping the input 'wait'

### Render

- Screens for 'robber-mode'
- Pretty puppets
- Leaving 'kills' on the screen
- Start screen
- End screen, showing reason of termination, gold and time
- MakePuppet function

### Robber
- Make robber.payRobbersGuild
    - substract on timer
    - add consequences to game (kill game if no gold)

### Targets

- Make targets instead of point/food/whatever
- Vary targets gold
- Make targets move
- Spawn multiple targets

### World
- Create obstacles
- Adjust controller to not walk along obstacle

### Misc

- Town income (throught targets.townsize)
- Stripping unused functions
