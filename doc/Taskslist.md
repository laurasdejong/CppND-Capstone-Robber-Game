# Options to implement

## Game play

- Make some sort of finis or consequence to the game. Either create game.Alive() or inside game.Play()

### Controller
- Make controller robust. Bug: when an arrow is pressed in the terminal, the demand is permanently set to 0, skipping the input 'wait'

### Render

- Screens for 'robber-mode'
- Pretty puppets
- Start screen
- End screen, showing reason of termination, gold and time

### Robber
- Make robber.payRobbersGuild
    - add consequences to game (kill game if no gold)

### Targets

- Make targets move
- Spawn multiple targets
- STransferring update to robber -> Usefull for future moving targets or new function desired?
- Is alive used & future prove?

### World
- Create obstacles
- Adjust controller to not walk along obstacle

### Misc

- Magic numbers watch -> read from yaml?
