//***********************************************
OOP2_Project
//***********************************************

//***********************************************
Author: Dima Nikonov
//***********************************************

//***********************************************
Overview:
//***********************************************

Auto chess like small game.
players in the buying state can buy units from the shop
and place them on the board. the placamenet is on the first
3 columns from the left. after the player has made it choises
press the ready button to compete against 7 other PC players.
the last player standing wins.

//***********************************************
Main Files:
//***********************************************
GameEngine- the main class that runs the game
and processes the programm states.

GameController- the controller class that handles
the whole game logic and it game states

BuyingStateUnit- units that are placed in the buying state
and can be bought by the player

ArenaUnit- units that are placed in the arena state
the units are created from the buying state units
using the attributes.

HeroFactory- factory class that creates the units and projectiles
the units are created from the UnitAttributes class

UnitAttributes- class that holds the attributes of the units
every new unit inherits from this class and registers itself in the factory

Projectile- class that holds the projectiles inherits from GameObject
each new projectile inherits from this class and registers itself in the factory

Player- class that holds the player attributes
HumanPlayer- player controlled class
ComputerPlayer- computer controlled class

UIElement- abstract class that holds the UI elements
each new UI element inherits from this class
each element has a method of draw and checks if the mouse is over it
also returns containers positions

UnitState- abstract class that holds the unit states
each new unit state inherits from this class
the Units are using the MoveState, AttackState using strategy pattern
every unit has a unique state that injected from the attributes class

Resource- class that holds the resources of the game using singleton pattern
the resources has a static factory like methods for Animation registration.

Menu- a menu state class, the button inside uses the command pattern
used as a MainMenu.

ArenaState - the state where the players get matched against other players
and maintains the round loop.

BattleState - the state where the battle is taking place between 2 players.

//***********************************************
Data Structures:
//***********************************************
GameData- holds all the information about the current game
the players, the board and players status.

Inventory- class that holds the units that the player has bought
it has a container for units that are placed on the board in the buying state
and units that are in the players backpack

//***********************************************
Algorithms:
//***********************************************
Nothing complicated.
//***********************************************
DESIGN:
//***********************************************
the project uses:
State pattern,
Strategy State pattern,
Singleton pattern,
Command pattern,
Composite pattern,
Factory pattern
//***********************************************
Known bugs:
//***********************************************
