/*
 * CNotify.h
 *
 *  Created on: 31-Jan-2022
 *      Author: Neethu
 */

#ifndef CNOTIFY_H_
#define CNOTIFY_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CNotify {

public:
	virtual void notify(string message) = 0;
	virtual ~CNotify() { };
};


#endif /* CNOTIFY_H_ */
