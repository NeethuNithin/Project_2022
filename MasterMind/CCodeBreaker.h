/*
 * CCodeBreaker.h
 *
 *This is the header file for CodeBreaker who predicts
 *the code and inform Code maker
 *
 *  Created on: 30-Jan-2022
 *      Author: Neethu
 */

#ifndef CCODEBREAKER_H_
#define CCODEBREAKER_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "CStateMachine.h"
#include "CCodeMaker.h"
#include "CNotify.h"

using namespace std::placeholders;
typedef std::function<void(string)> NotifyCodeMaker;

//Forward Declaration
class CCodeMaker;
class CCodeBreaker : public CNotify {

public:
	CCodeBreaker();
	CCodeBreaker(const CCodeBreaker&) = default;
	CCodeBreaker& operator= ( const CCodeBreaker& ) = default;
	void predictCode(string message);
	void notify(string message);
	void attachObserver(CCodeMaker* codemaker);

private:
    vector<string> mStateList;
	CStateMachine<CCodeBreaker>* mStateMachine;
	NotifyCodeMaker mNotifyCodeMaker;
};



#endif /* CCODEBREAKER_H_ */
