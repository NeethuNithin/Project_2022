/*
 * CConfiguration.h
 *
 *  Created on: 31-Jan-2022
 *      Author: Neethu
 */

#ifndef CCONFIGURATION_H_
#define CCONFIGURATION_H_

enum {
    System,
    Human
};

class CConfiguration {

public:
	static CConfiguration* getInstance();
    int getNumberOfAttempts() const;
    int getCodeMakerRole() const;
    int getCodeBreakerRole() const;
    int getNumberOfColors() const;
	int getNumberOfSlots() const;
    void setConfig(int NumberofAttempts, int cm, int cb);
private:
    CConfiguration();
    CConfiguration(CConfiguration &other) = delete;
    void operator=(const CConfiguration &) = delete;
	static CConfiguration* sInstance;
	int mNumberOfAttempts;
	int mCodeMakerRole;
	int mCodeBreakerRole;
	int mNumberOfColors;
	int mNumberOfSlots;
};

#endif /* CCONFIGURATION_H_ */
