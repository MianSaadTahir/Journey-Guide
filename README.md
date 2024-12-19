# Journey Guide

**Journey Guide** is a C++ project designed to simplify airline ticketing and travel planning. It employs graph theory and algorithms like Bellman-Ford to calculate the shortest paths between destinations. The system also manages user credentials and ticket history for a seamless user experience.

## Table of Contents
- [Features](#features)
- [Screenshots](#screenshots)
- [Usage](#usage)
- [Documentation](#documentation)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)

## Features
- **Card Setup**: Implements the standard Klondike card layout with 7 tableau columns and 4 foundation piles.
- **Game Logic**: Card movement between tableau columns, foundation piles, and stockpile, adhering to Klondike rules.
- **Data Structures**: Stack (LIFO) for tableau columns and foundation piles <br>
Queue (FIFO) for the stockpile <br>
Array/List for storing and shuffling the deck <br>
Linked List for tableau piles for card manipulation <br>
Dictionary for tracking card positions and states <br>
- **User Interface**:  Built with Pygame, providing an interactive GUI where players can select and drop cards.
- **Win Condition**:  The game ends when all cards are moved to the foundation piles in the correct order.

## Screenshot
<img src="assets/wireframe/screenshot.png" alt="Screenshot" width="75%">

## Usage
1. Clone the repository:
   `git clone https://github.com/miansaadtahir/solitaire.git`
2. Install pygame dependencies by running command `pip install pygame` in terminal.
3. Navigate to the project directory:
   `cd Solitaire/src/`
4. Open terminal in this directory and run command `python game.py` to launch the game.

## Documentation
For a detailed overview of the project and its features, visit the [Documentation](./documentation/) in the repository.

## Technologies Used
- Python
- Pygame

## Contributing
Contributions, issues, and feature requests are welcome!  
Feel free to check out the [issues page](https://github.com/miansaadtahir/solitaire/issues) for more information.

## License
Distributed under the MIT License. See [LICENSE](./LICENSE) for more details.
