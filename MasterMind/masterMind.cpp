/*
 * MasterMind  - This is a program to run a Master mind Board game
 * There are 2 players - CodeMaker and a CodeBreaker.
 * The CodeMaker sets an initial code or 4 color and the CodeBreaker needs to
 * guess the code and set a 4 color code within a number of attempts,
 * The CodeMaker provides the feedback to CodeBreaker's predicted code using some
 * colors such as white and black
 * If the CodeBreaker couldn't guess the code right, the CodeMaker wins the game.
 *
 */

#include <iostream>
#include "CCodeMaker.h"
#include "CCodeBreaker.h"
#include "CConfiguration.h"

using namespace std;

int main(int argc, char **argv) {
	CConfiguration::getInstance()->setConfig(10, System, Human);
	CCodeMaker cm;
	CCodeBreaker cb;
	cb.attachObserver(&cm);
	cm.attachObserver(&cb);
	return 0;
}
