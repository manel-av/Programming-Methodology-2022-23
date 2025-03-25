# Programming Methodology - Candy Crush Project
## About This Course
This hands-on course in programming methodology focused on developing a simplified version of the popular Candy Crush game. Through this project, we learned essential programming concepts, object-oriented design principles, and game development techniques.

## Project Overview
### Game Features Implemented
- #### Core Gameplay Mechanics:
  - Candy swapping and matching
  - Detection of horizontal/vertical alignments (3+ same-color candies)
  - Special striped candies (appear with 4+ matches)
  - Cascade effects for chain reactions
  - Score tracking and move counting

- #### Technical Implementation:
  - File-based level initialization
  - Game state serialization
  - Graphical interface (in second phase)
  - Interactive mouse controls

## Development Phases
### Phase 1: Core Game Engine (Weeks 1-4)
#### Key Components:
- Implemented core classes:
  - Partida (Game): Manages overall game state
  - Tauler (Board): Handles candy grid operations
  - Candy: Represents individual candies with type/color
  - Posicio: Manages grid positions

#### Main Functionality:
- File-based level loading
- Valid move verification
- Match detection and removal
- Board refill mechanics
- Special candy generation (striped)
- Game state saving

### Phase 2: Graphical Interface (Weeks 5-8)
#### Enhancements:
- Added Joc (Play) class for visual management
- Implemented graphical rendering:
  - Candy sprites
  - Animated swaps
  - Visual effects for matches
- Interactive mouse controls
- Game state visualization:
  - Score display
  - Move counter
  - Objective tracking
- Smooth animations for:
  - Candy swaps
  - Match removal
  - Board refill


### Key Algorithms
1. #### Match Detection:
  - Grid traversal for horizontal/vertical alignments
  - Special handling for striped candies
2. #### Board Refill:
  - Gravity-based candy dropping
  - Cyclic new candy generation (R→O→Y→B→G→P)
3. #### Special Candies:
  - Generation rules (4+ matches)
  - Destruction effects (row/column clearing)

## Development Environment
- #### Programming Language: C++
- #### Graphics Library: Custom graphics framework provided
- #### Tools: Visual Studio Community 2019

## Learning Outcomes
Through this project, we gained:
1. Solid understanding of object-oriented design
2. Experience with game state management
3. Skills in algorithm design (particularly for grid-based games)
4. Practice with file I/O operations
5. Experience implementing graphical interfaces
6. Improved debugging and problem-solving skills

The progressive development approach (core engine first, then graphics) helped us build complex functionality systematically while maintaining code quality.
