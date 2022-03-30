#ifndef CSTATEMACHINE_H_
#define CSTATEMACHINE_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//Call back functions -> enter and exit
typedef std::function<void(string)> EnterCallBack;
typedef std::function<void()> ExitCallBack;

class CState {

public:

	CState(string stateName, EnterCallBack enterCb, ExitCallBack exitCb) {
	 mStateName = stateName;
	 mEntryCallback = enterCb;
	 mExitCallback = exitCb;
	}
    void invokeEntryCallback(string msg) {mEntryCallback(msg);}
    void invokeExitCallback() { mExitCallback(); }
    string getStateName() { return mStateName; }

private:

string mStateName;
EnterCallBack mEntryCallback;
ExitCallBack mExitCallback;

};

template <class T>
class CStateMachine {

public:
CStateMachine(T* smHolder, vector<CState> stateArray) 
                        : mCurrentState(stateArray[0]) 
{
 cout << " State Machine Constructor" << endl;
 mStateMachineHolder = smHolder;
 addStates(stateArray);
}

~CStateMachine() {
	 cout << " State Machine Destructor" << endl;
}
void addStates(vector<CState> stateArray) {
 
 for_each(stateArray.begin(), stateArray.end(),
        [this](const CState& state)
        {            
            mStateArray.push_back(state);
        });
}

void transitionTo(string stateId, string message) {
  bool found = false;
  for_each(mStateArray.begin(), mStateArray.end(),
       [this, stateId, message, &found](CState& state)
       {
         if(stateId == state.getStateName()) {         
           found = true;
	       mCurrentState.invokeExitCallback();
	       mCurrentState = state;
	       mCurrentState.invokeEntryCallback(message);	      
	      }      
        });
  if(!found) cout << "Something Went Wrong..Exit Program !!" << endl;     
}

string getCurrentState() {
 return mCurrentState.getStateName();
}


private:
	T* mStateMachineHolder;
	CState& mCurrentState;
	vector<CState> mStateArray;
};

#endif /* CSTATEMACHINE_H_ */
