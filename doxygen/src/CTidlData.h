
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

#ifndef _SERVICELAYER_XXCLASS_CTIDLDATA_H_
#define _SERVICELAYER_XXCLASS_CTIDLDATA_H_

#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Log.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>
#include "CTidlData.h"

#include "ETidlDid.h"
#include "ETidlSignal.h"


// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
/// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}


#pragma pack(1)

typedef struct {
    size_t strAutoLenUseLen;
    uint8_t strAutoLenUse[BUFSIZ];
} CTidlDataDataFormat;

#pragma pack()


/**
 * @brief data class : CTidlData
 * @details CTidlData class - This is argument class in related to  {Module}Command.h & I{Module}Data.cpp
 */
class CTidlData : public android::RefBase {
public:
    /**
     * @brief constructor of the CTidlData data class.
     *
     */
    CTidlData();
    /**
     * @brief copy operator of the CTidlData data class.
     *
     * @param[in] other CTidlData
     *
     */
    CTidlData(const CTidlData& other);
    /**
     * @brief destructor of the CTidlData data class.
     *
     */
    virtual ~CTidlData();
    /**
     * @brief = operator of the CTidlData data class.
     *
     * @param[in] other CTidlData
     * @retval   CTidlData
     *
     */
    CTidlData& operator=(const CTidlData& other);
    /**
     * @brief It is for setting to CTidlData of the CTidlData data class.
     *
     * @param[in] other CTidlData
     * @retval   void
     *
     */
    void setTo(const CTidlData& other);
    /**
     * @brief This function is for writing parcel of the CTidlData data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);
    /**
     * @brief This function is for reading from parcel of the CTidlData data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t readFromParcel(const android::Parcel& parcel);
    /**
     * @brief This is a function that displays data in the CTidlData data class.
     *
     * @retval void
     *
     */
    void toString();
    /**
     * @brief This is a function that displays data by a specific name in the CTidlData data class.
     *
     * @param[in] from  printing data
     * @retval void
     *
     */
    void toString(const char* from);
    /**
     * @brief This function is for getting StrAutoLenUseLen of the CTidlData data class.
     *
     * @retval  size_t
     *
     */
    size_t  getStrAutoLenUseLen();
    uint8_t*  getStrAutoLenUse();

    /**
     * @brief function for setting data into CTidlDataDataFormat structure
     *
     * @param[in] df  CTidlDataDataFormat structure
     * @param[in] mstrAutoLenUseLen Length of mstrAutoLenUse
     * @param[in] mstrAutoLenUse desc str auto length use
     * @retval   void
     *
     */
    void setDataFormat(
        CTidlDataDataFormat& df
        , size_t mstrAutoLenUseLen
        , uint8_t* mstrAutoLenUse
    );

    /**
     * @brief It is function for setting data of the CTidlData data class.
     *
     * @param[in] mstrAutoLenUseLen Length of mstrAutoLenUse
     * @param[in] mstrAutoLenUse desc str auto length use
     * @retval   void
     *
     */
    void setData(
            size_t mstrAutoLenUseLen
            , uint8_t* mstrAutoLenUse
    );

private:
    void init();
    size_t  strAutoLenUseLen;
    uint8_t*  strAutoLenUse;
};


#endif /** _SERVICELAYER_XXCLASS_CTIDLDATA_H_ */
