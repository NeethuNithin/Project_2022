/*
 * CCodeMaker.h
 *
 *  Created on: 30-Jan-2022
 *      Author: Neethu
 */

#ifndef CCODEMAKER_H_
#define CCODEMAKER_H_

#include <string>
#include <vector>
#include <functional>
#include "CStateMachine.h"
#include "CCodeBreaker.h"
#include "CNotify.h"
#include "CConfiguration.h"

using namespace std::placeholders;

typedef std::function<void(string)> NotifyCodeBreaker;

//Forward Declaration
class CCodeBreaker;

class CCodeMaker : public CNotify {
public:
CCodeMaker();
CCodeMaker(const CCodeMaker&) = default;
CCodeMaker& operator= ( const CCodeMaker& ) = default;
void makeCode(string message);
void feedback(string message);
void notify(string message);
void attachObserver(CCodeBreaker *codebreaker);
string getRandomCode();
string processMessage(string message);

private:
    string mCode;
    int mAttempts;
    vector<string> mStateList;
	CStateMachine<CCodeMaker>* mStateMachine;
	NotifyCodeBreaker mNotifyCodeBreaker;
};

#endif /* CCODEMAKER_H_ */
