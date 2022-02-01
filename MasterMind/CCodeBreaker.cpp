/*
 * CCodeBreaker.cpp
 *
 * This contains the functions done by CodeBreaker
 * who predicts the code and inform CodeMaker
 *
 *  Created on: 31-Jan-2022
 *      Author: Neethu
 */

#include "CCodeBreaker.h"

CCodeBreaker::CCodeBreaker() {
	cout << "CodeBreaker Constructor" << endl;
	mStateList = {"Start", "Processing", "Waiting" };
	CState Start(mStateList[0],
	  	[](string message)
		{
		  cout << "Code Breaker Enter Start State" << message << endl;
		} ,
		[]() {cout <<"Code Breaker Exit Start State" << endl;});
    CState Processing(mStateList[1],
    	std::bind(&CCodeBreaker::predictCode, this, _1),
		[]() {cout <<"Code Breaker Exit Processing State" << endl;});
	CState Waiting(mStateList[2],
		[](string message)
		{
		  cout << "Code Breaker Enter Waiting State" << endl;
		} ,
		[]() {cout <<"Code Breaker Exit Waiting State" << endl;});

	vector<CState> stateList;
	stateList.push_back(Start);
	stateList.push_back(Processing);
	stateList.push_back(Waiting);

	mStateMachine = new CStateMachine<CCodeBreaker>(this, stateList);
}

/*
 * Function - predictCode()  -
 * Description
 * This function predicts the the Code
 * If the CodeBreaker is Human, it asks to guess the code
 * If the CodeBreaker is System, System will guess the logic
 * Once guessing is done, CodeBreaker will notify the CodeMaker and go to Waiting
 * state and waits for the feedback from CodeMaker
 */
void CCodeBreaker::predictCode(string message) {
	cout << "Code Breaker Enter Processing state predictCode" << endl;
	string msg;
	if(CConfiguration::getInstance()->getCodeBreakerRole() == Human) {
		cout << "Guess the 4 digit Code";
		cin >> msg;
	}
	else {
		//TODO Logic of guess
		cout << "Guess from system " << endl;
		msg = "RGBY";
	}
	mStateMachine->transitionTo(mStateList[2], "Waiting");
	mNotifyCodeMaker(msg);
}

/*
 * notify() - Notify the CodeMaker and set the CodeBreaker to next state
 */
void CCodeBreaker::notify(string message) {
	cout << "Notification from Code Maker " << message << endl;
	mStateMachine->transitionTo(mStateList[1], message);
}

/*
 * attachObserver() - Notify the CodeMaker and goes to Waiting state
 */
void CCodeBreaker::attachObserver(CCodeMaker *codemaker) {
	mNotifyCodeMaker = bind(&CCodeMaker::notify, codemaker, _1);
	mStateMachine->transitionTo(mStateList[2], "To Waiting state");
}
