/*
 * CCodeMaker.cpp
 *
 * Codemaker sets the code and provides feedback for the
 * guess made by Codebreaker
 *
 *  Created on: 30-Jan-2022
 *      Author: Neethu
 */

#include "CCodeMaker.h"


CCodeMaker::CCodeMaker() {
		cout << "CodeMaker Constructor" << endl;

		mStateList = {"Start", "Initialize", "Processing", "Waiting" };
        mAttempts = 0;
		CState Start(mStateList[0],
				[](string message) {cout << "Code Maker Enter Start State" << message << endl;} ,
				[]() {cout <<"Code Maker Exit Start State" << endl;});

		CState Init(mStateList[1],
				std::bind(&CCodeMaker::makeCode, this, _1),
				[]() {cout <<"Code Maker Exit Init State" << endl;});

		CState Processing(mStateList[2],
				std::bind(&CCodeMaker::feedback, this, _1),
				[]() {cout <<"Code Maker Exit Processing State" << endl;});

		CState Waiting(mStateList[3],
				[](string message) {cout << "Code Maker Enter Waiting State" << endl;} ,
				[]() {cout <<"Code Maker Exit Waiting State" << endl;});

		vector<CState> stateList;
		stateList.push_back(Start);
		stateList.push_back(Init);
		stateList.push_back(Processing);
		stateList.push_back(Waiting);

		mStateMachine = make_unique<CStateMachine<CCodeMaker>>(this, stateList);
}
/*
 * attachObserver() - Notify the CodeBreaker and Initialize the code
 */

void CCodeMaker::attachObserver(CCodeBreaker *codebreaker) {
	mNotifyCodeBreaker = bind(&CCodeBreaker::notify, codebreaker, _1);
	mStateMachine->transitionTo(mStateList[1], "Initialized");
}

/*
 * Function  makeCode()
 * Description -
 *
 * CodeMaker Set the initial code;
 * if CodeMaker is Human, then it asks us to set the initial 4 digit code
 * else set a random code and finally move to waiting state  after notifying
 * the CodeBreaker that the code is set
 */
void CCodeMaker::makeCode(string message) {
	cout << "Code Maker Enter Init State Make the code " << endl;
	if(CConfiguration::getInstance()->getCodeMakerRole() == Human) {
		cout << "Hey CodeMaker, Set an initial 4 digit Code : ";
		cin >> mCode;
	}
	else {
		mCode = getRandomCode();
		cout << "Random Code " << mCode << endl;
	}
	mStateMachine->transitionTo(mStateList[3], "Initial Code Set");
	mNotifyCodeBreaker("Code Set");
}

/* Function - feedback()
 * Description
 * CodeMaker checks if the guessed code from CodeBreaker is correct
 * or not
 * Also checks if the number of attempts are more than attempts set
 * Provides feedback to CodeBreaker based on the guess made by CodeBreaker
 */
void CCodeMaker::feedback(string message) {
	cout << "Code Maker Enter Processing State,  Provides Feedback " << endl;
	string data;
	if(message == mCode) {
		cout << "Hurray...Code Breaker, You are a genius!! You Win !" << endl;
		return;
	}
	else if (mAttempts > CConfiguration::getInstance()->getNumberOfAttempts()) {
		cout << "Oops.. Attempts over!! Code Breaker Better Luck Next Time!" << endl;
		return;
	}
	else {
	  //TODO Logic of Feedback
	  cout << "Feedback processing Logic" << endl;
	  data = processMessage(message);
	}
	mAttempts = mAttempts + 1;
	mStateMachine->transitionTo(mStateList[3], "Feedback provided");
	mNotifyCodeBreaker(data);
}

/*
 * notify() - Notify the CodeBreaker and set the CodeMaker to next state
 */
void CCodeMaker::notify(string message) {
	cout << "Notification from Code Breaker " << message << endl;
	mStateMachine->transitionTo(mStateList[2], message);
}

string CCodeMaker::getRandomCode()
{
    char code[] = { 'R', 'G', 'B', 'Y', 'O', 'P' };
    srand((unsigned int)time(NULL));
    string res = "";
    for (int i = 0; i < CConfiguration::getInstance()->getNumberOfSlots(); i++) {
        res = res + code[rand() % CConfiguration::getInstance()->getNumberOfColors()];
    }
    return res;
}
string CCodeMaker::processMessage(string message) {
  int blackCount = 0, whiteCount = 0;
  string restOfGuess, restOfCode;
  for(int i =0 ; i< message.length(); i++) {
	  if(message[i] == mCode[i]) blackCount++;
	  else {
		  restOfGuess = restOfGuess + message[i];
		  restOfCode = restOfCode + mCode[i];
	  }
  }
  sort(restOfGuess.begin(), restOfGuess.end());
  sort(restOfCode.begin(), restOfCode.end());
  for(int i =0 ; i< restOfGuess.length(); i++) {
	  if(restOfGuess[i] == restOfCode[i]) whiteCount++;
  }
  return "B" + to_string(blackCount) + "W" + to_string(whiteCount);
}
