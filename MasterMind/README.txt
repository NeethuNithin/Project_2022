About the game:

This is a Mastermind game program. There are two players - CodeMaker and CodeBreaker. 
CodeMaker sets an initial code and CodeBreaker needs to predict the correct code within particular number of attempts.
If CodeBreaker guess the code correctly, CodeBreaker wins the game else, CodeMaker wins the game.

About the code :

The codes contains CodeMaker and CodeBreaker logic for MasterMind game. Here the logic is in such a way that the CodeMaker is System and it generates a random 4 colour code and sends feedback to the guess of CodeBreaker. The CodeBreaker is the Human – needs to guess the correct code  from the feedback got from CodeMaker within maximum number of attempts.

Statemachine design pattern is used to create the states for CodeMaker and CodeBreaker. At the start, the CodeBreaker will be in waiting state, CodeMaker will notify the CodeBreaker once Initial code is set and goes to waiting state. When the initial code is received, the CodeBreaker will go to processing state and guess the code and goes to waiting state. The CodeMaker is then notified that the guess is done by the CodeBreaker and CodeMaker goes to Processing state and send feedback to the CodeBreaker and goes to waiting state again. This cycle continues until the CodeBreaker guess the code correctly or the maximum number of attempts have been reached. 

The design pattern used for Mastermind code : 

1. State machine design pattern
2. Singleton design pattern

Most of the C++ OOPs concepts are also used in this code.

The sequence diagram and Flow diagram are also attached along with the code.
