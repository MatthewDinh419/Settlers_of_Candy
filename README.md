# Settlers of Candy

Based off the game "Settlers of Catan" that is candy themed along with new features.


## How to Run:
    1. QTCREATOR 
    2. OPEN FILE/PROJECT 
    3. SETTLERS_OF_CANDY.PRO
    4. BUILD
    5. RUN 
    
## Design:
    * Hexagon Object Factory Implementation
    * Building subclasses: Candy Road, Chocolate House, Chocolate Mansion
    * Randomly generated hexagon generation
    * Records mechanics awarding players with points for achieving certain records
    * Analytics Display
    
## To-Do:
     * AI players
     * AI needs to roll die
     * Check Player AI logic
    
## Known Bugs:
    * AI: adding a building to a point which already has a building
    * AI: Sometimes does not add a house to a road when there is nothing at the end of the road
    * AI: Automating the turns with timer does not go through each AI's turn and does it not bulk
        - Player 1 and Player 2's turn may happen simultaneously at once
    * AI: resource not correct (too many turns at once?)

## Possible Features:
    * Development Cards
    * Theif
    * Restart
    * Make Dice Useful
