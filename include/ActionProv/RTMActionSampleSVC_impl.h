// -*-C++-*-
/*!
 * @file  RTMActionSampleSVC_impl.h
 * @brief Service implementation header of RTMActionSample.idl
 *
 */

#include "RTMActionSampleSkel.h"

#ifndef RTMACTIONSAMPLESVC_IMPL_H
#define RTMACTIONSAMPLESVC_IMPL_H
 
class ActionProv;
/*!
 * @class RTMActionSampleSVC_impl
 * Example class implementing IDL interface ssr::RTMActionSample
 */
class ssr_RTMActionSampleSVC_impl
 : public virtual POA_ssr::RTMActionSample,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~RTMActionSampleSVC_impl();
	 ActionProv* m_pRTC;
public:
	void setRTC(ActionProv* pRTC) { m_pRTC = pRTC; }
 public:
  /*!
   * @brief standard constructor
   */
	 ssr_RTMActionSampleSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ssr_RTMActionSampleSVC_impl();

   // attributes and operations
   void setGoal(const ssr::RTMActionSampleGoal& goal);

};

/*!
 * @class RTMActionSampleCallbackSVC_impl
 * Example class implementing IDL interface ssr::RTMActionSampleCallback
 */
class ssr_RTMActionSampleCallbackSVC_impl
 : public virtual POA_ssr::RTMActionSampleCallback,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~RTMActionSampleCallbackSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
	 ssr_RTMActionSampleCallbackSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ssr_RTMActionSampleCallbackSVC_impl();

   // attributes and operations
   void setFeedback(const ssr::RTMActionSampleFeedback& feedback);
   void setResult(const ssr::RTMActionSampleResult& result);

};



#endif // RTMACTIONSAMPLESVC_IMPL_H


