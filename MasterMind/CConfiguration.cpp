/*
 * CConfiguration.cpp
 *
 * This program contains a singleton design pattern which defines
 *  the number of attempts, role
 *
 *  Created on: 31-Jan-2022
 *      Author: Neethu
 */

#include "CConfiguration.h"

CConfiguration* CConfiguration::sInstance = nullptr;

CConfiguration::CConfiguration () {
	mCodeMakerRole = System;
	mCodeBreakerRole = Human;
	mNumberOfAttempts = 0;
	mNumberOfColors = 6;
	mNumberOfSlots = 4;
}
CConfiguration* CConfiguration::getInstance() {
	if(sInstance == nullptr)
		sInstance = new CConfiguration();
	return sInstance;
}
int CConfiguration::getNumberOfAttempts() const{
    return mNumberOfAttempts;
}
int CConfiguration::getCodeMakerRole() const {
   	return mCodeMakerRole;
}
int CConfiguration::getCodeBreakerRole() const {
   	return mCodeBreakerRole;
}
int CConfiguration::getNumberOfColors() const{
    return mNumberOfColors;
}
int CConfiguration::getNumberOfSlots() const{
    return mNumberOfSlots;
}

void CConfiguration::setConfig(int NumberofAttempts, int cm, int cb) {
   	mNumberOfAttempts = NumberofAttempts;
   	mCodeMakerRole = cm;
   	mCodeBreakerRole = cb;
}



