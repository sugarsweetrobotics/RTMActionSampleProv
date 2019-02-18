// -*- C++ -*-
/*!
 * @file  ActionProv.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ActionProv.h"

// Module specification
// <rtc-template block="module_spec">
static const char* actionprov_spec[] =
  {
    "implementation_id", "ActionProv",
    "type_name",         "ActionProv",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ActionProv::ActionProv(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sv_namePort("sv_name")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ActionProv::~ActionProv()
{
}



RTC::ReturnCode_t ActionProv::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_sv_namePort.registerProvider("ssr_RTMActionSample", "ssr::RTMActionSample", m_service);
  
  // Set service consumers to Ports
  m_sv_namePort.registerConsumer("ssr_RTMActionSampleCallback", "ssr::RTMActionSampleCallback", m_callback);
  
  // Set CORBA Service Ports
  addPort(m_sv_namePort);

  m_service.setRTC(this);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ActionProv::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ActionProv::onExecute(RTC::UniqueId ec_id)
{
	if (m_goal >= 0) {
		long temp = m_previous;
		m_previous = m_current;
		m_current = temp + m_previous;
		std::cout << "ActionProv: " << m_current << std::endl;
		if (m_current < m_goal) {
			ssr::RTMActionSampleFeedback_var feedback(new ssr::RTMActionSampleFeedback());
			feedback->current = m_current;
			m_callback->setFeedback(feedback);
		}
		else {
			ssr::RTMActionSampleResult_var result(new ssr::RTMActionSampleResult());
			result->current = m_current;
			m_callback->setResult(result);
			m_goal = -1;
		}
	}
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t ActionProv::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ActionProv::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ActionProvInit(RTC::Manager* manager)
  {
    coil::Properties profile(actionprov_spec);
    manager->registerFactory(profile,
                             RTC::Create<ActionProv>,
                             RTC::Delete<ActionProv>);
  }
  
};


