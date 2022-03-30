/*
 * CObserver.h
 *
 *  Created on: 31-Jan-2022
 *      Author: Neethu
 */

#ifndef COBSERVER_H_
#define COBSERVER_H_

template <class T>
class CObserver   {
   public:
      CObserver() {}
      virtual ~CObserver() {}
      virtual void update(T *subject)= 0;
};

#endif /* COBSERVER_H_ */
