
/**
 * @if (CGA)
 *  @CGA_INCLUDE{ITidlManagerService.h}
 * @endif
 */
// FileName - ITidlManagerService.h
/**
 * @attention Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved.
 *   This program or software including the accompanying associated documentation ("Software") is
 *   the proprietary software of LG Electronics Inc.  and or its licensors, and may only be used,
 *   duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement
 *   between you and LG Electronics Inc. ("Authorized License").
 *   Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use,
 *   or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in
 *   and to the Software and all intellectual property therein.
 *   If you have no Authorized License, then you have no rights to use the Software in any ways,
 *   and should immediately notify LG Electronics Inc. and discontinue all use of the Software.
 *
 * @author  LGE_worker@lge.com
 * @date    2020.12.11
 * @version 3.0.00
 */

/** @defgroup TIDLMGR_API TIDLMGR TIDL API
 *  @ingroup TIDLMGR
 *
 *  Thease are the TIDL APIs
 */

/** @defgroup TIDLMGR_CB TIDLMGR Callback
 *  @ingroup TIDLMGR
 *
 *  This is the TIDL Manager Receiver list.
 */ 

/** @defgroup TIDL_RECEIVER_TEST_API TIDL receiver Test API list
 *  @ingroup TIDLMGR
 *
 *  This is the TIDL Test API list for receiver.
 */ 

#ifndef _ITIDLNOSTIC_MANAGER_SERVICE_H_
#define _ITIDLNOSTIC_MANAGER_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include "Typedef.h"

#include "TidlCommand.h"
#include "ITidlManagerServiceType.h"
#include "ITidlSignalReceiver.h"
#include "ITidlStatusReceiver.h"

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
    /*
     * Write your own additional code
     * add your #include
     * add your global declare the function and variables
     * add your function
     */

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

/**
 * @brief If Apps or other services need to control TIDL, It could be obatined by these API.
 * To use these API, APP or Service, You Should get ITidlManaerService
 *
 * @note
 *  tidlManagerService service name is @b Tidl_SRV_NAME (="service_layer.tidlManagerService")
 */
class ITidlManagerService : public android::IInterface
{
public:
    DECLARE_META_INTERFACE(TidlManagerService);
    //< Interfaces for ITidlManagerService


    /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onReceive(..) is the function to register receiver for the BpTidlSignalReceiver .
     * 
     * @details desc onReceive with did
     * Managers created with TIDL can broadcast messages to other managers and apps.
     * When a specific event occurs in the Manager made with TIDL, if a manager wants to receive the event from the TIDL Manager,
     * manager can register events of interest to TIDL Manager with the registerreceiver function.
     * Then, when the event occurs, a specific event is delivered to the requested Manager through broadcast.
     * For example, if you want to know when the car has started, register the event through the registerreceiver function, and the car has started.
     * An event indicating that startup has occurred will be delivered to the manager who created the RegisterReceiver request.
     *
     * @param[in] receiver android::sp< TidlSignalReceiver > interface
     * @param[in] signalID ETidlDid : enum with related class
     * @retval   error_t   If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t registerReceiverTidlSignalReceiverOnReceive(
        const android::sp< ITidlSignalReceiver >& receiver
        , ETidlDid signalID
        ) = 0;

    /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onReceiveSecond(..) is the function to register receiver for the BpTidlSignalReceiver .
     * 
     * @details desc onReceiveB
     * Managers created with TIDL can broadcast messages to other managers and apps.
     * When a specific event occurs in the Manager made with TIDL, if a manager wants to receive the event from the TIDL Manager,
     * manager can register events of interest to TIDL Manager with the registerreceiver function.
     * Then, when the event occurs, a specific event is delivered to the requested Manager through broadcast.
     * For example, if you want to know when the car has started, register the event through the registerreceiver function, and the car has started.
     * An event indicating that startup has occurred will be delivered to the manager who created the RegisterReceiver request.
     *
     * @param[in] receiver android::sp< TidlSignalReceiver > interface
     * @param[in] p int32_t : integer
     * @retval   error_t   If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t registerReceiverTidlSignalReceiverOnReceiveSecond(
        const android::sp< ITidlSignalReceiver >& receiver
        , int32_t p
        ) = 0;

    /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onNoArguReceive(..) is the function to register receiver for the BpTidlStatusReceiver .
     * 
     * @details no aruments
     * Managers created with TIDL can broadcast messages to other managers and apps.
     * When a specific event occurs in the Manager made with TIDL, if a manager wants to receive the event from the TIDL Manager,
     * manager can register events of interest to TIDL Manager with the registerreceiver function.
     * Then, when the event occurs, a specific event is delivered to the requested Manager through broadcast.
     * For example, if you want to know when the car has started, register the event through the registerreceiver function, and the car has started.
     * An event indicating that startup has occurred will be delivered to the manager who created the RegisterReceiver request.
     *
     * @param[in] receiver android::sp< TidlStatusReceiver > interface
     * @retval   error_t   If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t registerReceiverTidlStatusReceiverOnNoArguReceive(
        const android::sp< ITidlStatusReceiver >& receiver
        ) = 0;

    /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onStatusReceive(..) is the function to register receiver for the BpTidlStatusReceiver .
     * 
     * @details desc onStatusReceive
     * Managers created with TIDL can broadcast messages to other managers and apps.
     * When a specific event occurs in the Manager made with TIDL, if a manager wants to receive the event from the TIDL Manager,
     * manager can register events of interest to TIDL Manager with the registerreceiver function.
     * Then, when the event occurs, a specific event is delivered to the requested Manager through broadcast.
     * For example, if you want to know when the car has started, register the event through the registerreceiver function, and the car has started.
     * An event indicating that startup has occurred will be delivered to the manager who created the RegisterReceiver request.
     *
     * @param[in] receiver android::sp< TidlStatusReceiver > interface
     * @param[in] p ETidlSignal : first integer
     * @param[in] q int32_t : second integer
     * @retval   error_t   If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t registerReceiverTidlStatusReceiverOnStatusReceive(
        const android::sp< ITidlStatusReceiver >& receiver
        , ETidlSignal p
        , int32_t q
        ) = 0;


     /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onReceive(..) is the function to unregister receiver for the BpTidlSignalReceiver .
     * 
     * @details desc onReceive with did
     *
     * @param[in] receiver android::sp< TidlSignalReceiver > interface
     * @param[in] signalID ETidlDid : enum with related class
     * @retval   error_t   If the receiver is unregistered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t unregisterReceiverTidlSignalReceiverOnReceive( 
        const android::sp< ITidlSignalReceiver >& receiver
        , ETidlDid signalID
        ) = 0;

     /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onReceiveSecond(..) is the function to unregister receiver for the BpTidlSignalReceiver .
     * 
     * @details desc onReceiveB
     *
     * @param[in] receiver android::sp< TidlSignalReceiver > interface
     * @param[in] p int32_t : integer
     * @retval   error_t   If the receiver is unregistered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t unregisterReceiverTidlSignalReceiverOnReceiveSecond( 
        const android::sp< ITidlSignalReceiver >& receiver
        , int32_t p
        ) = 0;

     /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onNoArguReceive(..) is the function to unregister receiver for the BpTidlStatusReceiver .
     * 
     * @details no aruments
     *
     * @param[in] receiver android::sp< TidlStatusReceiver > interface
     * @retval   error_t   If the receiver is unregistered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t unregisterReceiverTidlStatusReceiverOnNoArguReceive( 
        const android::sp< ITidlStatusReceiver >& receiver
        ) = 0;

     /**
     * @ingroup TIDLMGR_API
	 *
     * @brief onStatusReceive(..) is the function to unregister receiver for the BpTidlStatusReceiver .
     * 
     * @details desc onStatusReceive
     *
     * @param[in] receiver android::sp< TidlStatusReceiver > interface
     * @param[in] p ETidlSignal : first integer
     * @param[in] q int32_t : second integer
     * @retval   error_t   If the receiver is unregistered successfully, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t unregisterReceiverTidlStatusReceiverOnStatusReceive( 
        const android::sp< ITidlStatusReceiver >& receiver
        , ETidlSignal p
        , int32_t q
        ) = 0;


    /**
     * @brief setLogLevel sets the log level for tidl module separately.
     *
     * @details dynamic log level - each module can set log level separately.
     *
     * @param[in] lvl int32_t : set log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     */
    virtual error_t setLogLevel(int32_t lvl)=0;
    /**
     * @brief setLogLevelAsDefault sets the log level according to perf and debug mode.
     *
     * @details dynamic log level - set log level as default log level according to perf and debug mode
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t setLogLevelAsDefault()=0;
    /**
     * @brief getLogLevel gets the log level for tidl module separately.
     *
     * @details dynamic log level - get log level of each module separately.
     *
     * @param[out] lvl int32_t& : get log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     */
    virtual error_t getLogLevel(int32_t& lvl)=0;

     // auto API start : wishtoUseAPI
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : 
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     ==  ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_0(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_0, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_0, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_0(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_0()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_0()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_0(
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api 1 desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in,out] switchOff  desc it is switch off <br> when you want to power off.
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api 1 desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_1(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_1, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_1, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_1(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_1()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_1()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_1(
         int32_t& switchOff
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] getN  desc
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_2_get_int(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_2_GET_INT, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_2_GET_INT, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_2_get_int(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_2_get_int()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_2_get_int()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_2_get_int(
         int32_t& getN
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] strLen Length of str
     * @param[out] str  desc : this is another example <p> add line
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_2_get_str(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_2_GET_STR, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_2_GET_STR, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_2_get_str(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_2_get_str()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_2_get_str()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_2_get_str(
         size_t& strLen
        , uint8_t* str
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] CTidlDidxx  desc
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_3_class(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_3_CLASS, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_3_CLASS, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_3_class(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_3_class()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_3_class()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_3_class(
         android::sp< CTidlDid >& CTidlDidxx
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] Edidxx  desc string data
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_3_enum(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_3_ENUM, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_3_ENUM, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_3_enum(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_3_enum()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_3_enum()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_3_enum(
         ETidlDid& Edidxx
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] sDTC  desc
     * @param[out] CTiIxx  desc
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_4_two(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_4_TWO, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_4_TWO, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_4_two(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_4_two()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_4_two()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_4_two(
         uint32_t& sDTC
        , android::sp< CTidlItaly >& CTiIxx
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] dd  desc
     * @param[out] strLen Length of str
     * @param[out] str  desc : this is another example <p> add line
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_5(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_5, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_5, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_5(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_5()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_5()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_5(
         double& dd
        , size_t& strLen
        , uint8_t* str
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api desc
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] CTiDataxx  desc
     * @param[in,out] ft  7 float (first argument)
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_6(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_6, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_6, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_6(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_6()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_6()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_6(
         android::sp< CTidlData >& CTiDataxx
        , float& ft
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : api with multiple argument including float
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in,out] fTest1  7 float (first argument)
     * @param[in] xx7  7 CTidlDid
     * @param[out] st7  7 string
     * @param[in] fTest4  7 float (4th argument)
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api with multiple argument including float ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_7(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_7, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_7, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_7(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_7()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_7()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_7(
         float& fTest1
        , android::sp< CTidlData >& xx7
        , android::sp< CTidlItaly >& st7
        , ETidlSignal& fTest4
        )=0;
     /**
     * @ingroup TIDLMGR_API
     *
     * @brief API : receiver arguments test
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] rcv  8 receiver
     * @param[in] nn  8 nn int32_
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == receiver arguments test ==
     *     App -> BpTidlManagerService : TIDL_COMMON_API_8(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_TIDL_COMMON_API_8, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_TIDL_COMMON_API_8, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : TIDL_COMMON_API_8(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_8()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::TIDL_COMMON_API_8()_SRS"}
     * @endcond
     */     
    virtual error_t TIDL_COMMON_API_8(
         android::sp< ITidlStatusReceiver >& rcv
        , int32_t& nn
        )=0;
    // RECEIVER API start
    /**
     * @ingroup TIDL_RECEIVER_TEST_API
     *
     * @brief API : desc onReceive with did
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] signalID  enum with related class
     * @param[in,out] bufLen Length of buf
     * @param[in,out] buf  enum with related class
     *
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == desc onReceive with did ==
     *     App -> BpTidlManagerService : onReceive(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_ONRECEIVE, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_ONRECEIVE, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : onReceive(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::onReceive()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::onReceive()_SRS"}
     * @endcond
     */
    virtual error_t testOnReceive(         //  Parm:0
         ETidlDid& signalID    //  Parm:1
        , size_t& bufLen     //  Parm:2
        , uint8_t* buf
        )=0;
    /**
     * @ingroup TIDL_RECEIVER_TEST_API
     *
     * @brief API : desc onReceiveB
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] q  integer
     *
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == desc onReceiveB ==
     *     App -> BpTidlManagerService : onReceiveSecond(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_ONRECEIVESECOND, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_ONRECEIVESECOND, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : onReceiveSecond(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::onReceiveSecond()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::onReceiveSecond()_SRS"}
     * @endcond
     */
    virtual error_t testOnReceiveSecond(         //  Parm:0
         int32_t& q    //  Parm:1
        )=0;
    /**
     * @ingroup TIDL_RECEIVER_TEST_API
     *
     * @brief API : no aruments
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     *
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == no aruments ==
     *     App -> BpTidlManagerService : onNoArguReceive(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_ONNOARGURECEIVE, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_ONNOARGURECEIVE, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : onNoArguReceive(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::onNoArguReceive()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::onNoArguReceive()_SRS"}
     * @endcond
     */
    virtual error_t testOnNoArguReceive(         //  Parm:0
        )=0;
    /**
     * @ingroup TIDL_RECEIVER_TEST_API
     *
     * @brief API : desc onStatusReceive
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in,out] p  first integer
     * @param[in,out] ctd  third integer (no class)
     *
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpTidlManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnTidlManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == desc onStatusReceive ==
     *     App -> BpTidlManagerService : onStatusReceive(arguments)
     *     BpTidlManagerService -> Binder : TidlData >> remote()->onTransact(OP_REGISTER_ONSTATUSRECEIVE, Parcel)
     *     Binder -> BnTidlManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_ONSTATUSRECEIVE, Parcel >> arguments
     *     BnTidlManagerService -> ServiceStub : onStatusReceive(arguments)
     *     activate ServiceStub
     *     BnTidlManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnTidlManagerService : reply->writeInt32
     *     BpTidlManagerService <- Binder : reply.readInt32()
     *     App <- BpTidlManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:TidlManagerService::onStatusReceive()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:TidlManagerService::onStatusReceive()_SRS"}
     * @endcond
     */
    virtual error_t testOnStatusReceive(         //  Parm:0
         ETidlSignal& p    //  Parm:1
        , android::sp< CTidlItaly >& ctd         //  Parm:2
        )=0;
    // auto RECEIVER API end for test : receiver_function

    // @CGA_VARIANT_START{"ITidlManagerService:ITidlManagerService()"}
    /*
     * Write your own code
     */
    // @CGA_VARIANT___END{"ITidlManagerService:ITidlManagerService()"}

};

class BnTidlManagerService : public android::BnInterface<ITidlManagerService>
{

public:
    /**
     * @brief onTransact function for the BnTidlManagerService.
     *
     * @param[in] code operation code in binder
     * @param[in] data data parcel in binder
     * @param[in,out] reply reply packet in binder
     * @param[in] flags flags
     * @retval   status_t It returns the status of onTransact function.
     *
     */
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags);
};

#endif /**ITIDL_MANAGER_SERVICE_H*/
