
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

#ifndef _SERVICELAYER_XXENUM_ETIDLDID_H_
#define _SERVICELAYER_XXENUM_ETIDLDID_H_

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
 * @brief Enum class : ETidlDid
 * @details example of Enum (DIDA)
 */
class ETidlDid 
{ 
  public:
    /**
     * @brief Enum class : ETidlDid
     */
    enum Enum   {
        DID1 ,
        /**< Initaial */
        DID02 ,
        DID10 = 10 ,
        /**< set by OEM */
        DID_ANY ,
        /**< end */
    };

    std::unordered_map<int32_t,std::string> enumToString = {
        { ETidlDid::DID1 , "ETidlDid::DID1" } ,
        { ETidlDid::DID02 , "ETidlDid::DID02" } ,
        { ETidlDid::DID10 , "ETidlDid::DID10" } ,
        { ETidlDid::DID_ANY , "ETidlDid::DID_ANY" } ,
    };

    std::unordered_map<std::string,int32_t> stringToEnum = {
        { "ETidlDid::DID1" , ETidlDid::DID1 } ,
        { "DID1" , ETidlDid::DID1 } ,
        { "ETidlDid::DID02" , ETidlDid::DID02 } ,
        { "DID02" , ETidlDid::DID02 } ,
        { "ETidlDid::DID10" , ETidlDid::DID10 } ,
        { "DID10" , ETidlDid::DID10 } ,
        { "ETidlDid::DID_ANY" , ETidlDid::DID_ANY } ,
        { "DID_ANY" , ETidlDid::DID_ANY } ,
    };

    /**
     * @brief It is a function for the constructor of the ETidlDid data class.
     *
     */
    ETidlDid() {}
    /**
     * @brief It is a function for the destructor of the ETidlDid data class.
     *
     */
    ~ETidlDid() {}
    /**
     * @brief It is a function for the copy operator of the ETidlDid data class.
     *
     * @param[in] v ETidlDid
     */
    ETidlDid(const Enum& v) : value(v) {}
    /**
     * @brief Enum() operator of the ETidlDid data class.
     *
     * @retval   ETidlDid.value
     *
     */
    operator Enum() const { return value; }
    /**
     * @brief = operator of the ETidlDid data class.
     *
     * @param[in] v ETidlDid
     * @retval   ETidlDid
     *
     */
    Enum& operator=(Enum v) { value = v; return value;}
    /**
     * @brief == operator of the ETidlDid data class.
     *
     * @param[in] v ETidlDid
     * @retval   bool
     *
     */
    bool operator==(const Enum v) const { return value == v; }
    /**
     * @brief != operator of the ETidlDid data class.
     *
     * @param[in] v ETidlDid
     * @retval   bool
     *
     */
    bool operator!=(const Enum v) const { return value != v; }

    /**
     * @brief getStringEnum (): get std::string in related to value in enum class ETidlDid
     *
     * @retval   std::string   If success, return std::string, otherwise, return "E_ERROR".
     */
    std::string getStringEnum();

    /**
     * @brief getStringEnum (): get std::string in related to value in enum class ETidlDid
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
     * @brief This function is for writing parcel of the ETidlDid enum class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);

    /**
     * @brief This function is for reading from parcel of the ETidlDid enum class.
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


#endif /** _SERVICELAYER_XXENUM_ETIDLDID_H_ */
