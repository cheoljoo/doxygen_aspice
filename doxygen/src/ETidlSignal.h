
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

#ifndef _SERVICELAYER_XXENUM_ETIDLSIGNAL_H_
#define _SERVICELAYER_XXENUM_ETIDLSIGNAL_H_

#include <limits>
#include <unordered_map>
#include <iostream>
#include "Log.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>


// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}



/**
 * @brief Enum class : ETidlSignal
 * @details example of Enum (DIDB)
 */
class ETidlSignal 
{ 
  public:
    /**
     * @brief Enum class : ETidlSignal
     */
    enum Enum   {
        DID1234 ,
        DID02 ,
        /**< last element */
    };

    std::unordered_map<int32_t,std::string> enumToString = {
        { ETidlSignal::DID1234 , "ETidlSignal::DID1234" } ,
        { ETidlSignal::DID02 , "ETidlSignal::DID02" } ,
    };

    std::unordered_map<std::string,int32_t> stringToEnum = {
        { "ETidlSignal::DID1234" , ETidlSignal::DID1234 } ,
        { "DID1234" , ETidlSignal::DID1234 } ,
        { "ETidlSignal::DID02" , ETidlSignal::DID02 } ,
        { "DID02" , ETidlSignal::DID02 } ,
    };

    /**
     * @brief It is a function for the constructor of the ETidlSignal data class.
     *
     */
    ETidlSignal() {}
    /**
     * @brief It is a function for the destructor of the ETidlSignal data class.
     *
     */
    ~ETidlSignal() {}
    /**
     * @brief It is a function for the copy operator of the ETidlSignal data class.
     *
     * @param[in] v ETidlSignal
     */
    ETidlSignal(const Enum& v) : value(v) {}
    /**
     * @brief Enum() operator of the ETidlSignal data class.
     *
     * @retval   ETidlSignal.value
     *
     */
    operator Enum() const { return value; }
    /**
     * @brief = operator of the ETidlSignal data class.
     *
     * @param[in] v ETidlSignal
     * @retval   ETidlSignal
     *
     */
    Enum& operator=(Enum v) { value = v; return value;}
    /**
     * @brief == operator of the ETidlSignal data class.
     *
     * @param[in] v ETidlSignal
     * @retval   bool
     *
     */
    bool operator==(const Enum v) const { return value == v; }
    /**
     * @brief != operator of the ETidlSignal data class.
     *
     * @param[in] v ETidlSignal
     * @retval   bool
     *
     */
    bool operator!=(const Enum v) const { return value != v; }

    /**
     * @brief getStringEnum (): get std::string in related to value in enum class ETidlSignal
     *
     * @retval   std::string   If success, return std::string, otherwise, return "E_ERROR".
     */
    std::string getStringEnum();

    /**
     * @brief getStringEnum (): get std::string in related to value in enum class ETidlSignal
     *
     * @param[in] v enum value
     * @retval   std::string   If success, return std::string, otherwise, return "E_ERROR".
     */
    std::string getStringFromEnum(int32_t v);

    /**
     * @brief getEnumFromString (): get int32_t in related to enum string
     *
     * @param[in] s enum string
     * @retval   int32_t  If success, return enum value, otherwise, return std::numeric_limits<int32_t>::min()
     */
    int32_t getEnumFromString(std::string s);

    /**
     * @brief This function is for writing parcel of the ETidlSignal enum class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);

    /**
     * @brief This function is for reading from parcel of the ETidlSignal enum class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t readFromParcel(const android::Parcel& parcel);

    /**
     * @brief getValue (): return value with type 
     *
     * @retval   int32_t 
     */
    int32_t getValue();

    /**
     * @brief getValueAsInt32 (): return value with type int32_t
     *
     * @retval   int32_t   Enum value
     */
    int32_t getValueAsInt32();

  private:
    Enum value;
}; 


#endif /** _SERVICELAYER_XXENUM_ETIDLSIGNAL_H_ */
