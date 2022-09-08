
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

#ifndef _SERVICELAYER_XXCLASS_CTIDLDID_H_
#define _SERVICELAYER_XXCLASS_CTIDLDID_H_

#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Log.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>
#include "CTidlDid.h"

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
    uint16_t did;
    uint32_t att;
    size_t strAutoLenUseLen;
    uint8_t strAutoLenUse[BUFSIZ];
    int32_t len;
    double d5;
    uint8_t strNoLenUse[BUFSIZ];
} CTidlDidDataFormat;

#pragma pack()


/**
 * @brief data class : CTidlDid
 * @details CTidlDid 3rd class
 */
class CTidlDid : public android::RefBase {
public:
    /**
     * @brief constructor of the CTidlDid data class.
     *
     */
    CTidlDid();
    /**
     * @brief copy operator of the CTidlDid data class.
     *
     * @param[in] other CTidlDid
     *
     */
    CTidlDid(const CTidlDid& other);
    /**
     * @brief destructor of the CTidlDid data class.
     *
     */
    virtual ~CTidlDid();
    /**
     * @brief = operator of the CTidlDid data class.
     *
     * @param[in] other CTidlDid
     * @retval   CTidlDid
     *
     */
    CTidlDid& operator=(const CTidlDid& other);
    /**
     * @brief It is for setting to CTidlDid of the CTidlDid data class.
     *
     * @param[in] other CTidlDid
     * @retval   void
     *
     */
    void setTo(const CTidlDid& other);
    /**
     * @brief This function is for writing parcel of the CTidlDid data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);
    /**
     * @brief This function is for reading from parcel of the CTidlDid data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t readFromParcel(const android::Parcel& parcel);
    /**
     * @brief This is a function that displays data in the CTidlDid data class.
     *
     * @retval void
     *
     */
    void toString();
    /**
     * @brief This is a function that displays data by a specific name in the CTidlDid data class.
     *
     * @param[in] from  printing data
     * @retval void
     *
     */
    void toString(const char* from);
    /**
     * @brief This function is for getting Did of the CTidlDid data class.
     *
     * @retval  uint16_t
     *
     */
    uint16_t  getDid();
    /**
     * @brief This function is for getting Att of the CTidlDid data class.
     *
     * @retval  uint32_t
     *
     */
    uint32_t  getAtt();
    /**
     * @brief This function is for getting StrAutoLenUseLen of the CTidlDid data class.
     *
     * @retval  size_t
     *
     */
    size_t  getStrAutoLenUseLen();
    uint8_t*  getStrAutoLenUse();
    /**
     * @brief This function is for getting Len of the CTidlDid data class.
     *
     * @retval  int32_t
     *
     */
    int32_t  getLen();
    /**
     * @brief This function is for getting D5 of the CTidlDid data class.
     *
     * @retval  double
     *
     */
    double  getD5();
    uint8_t*  getStrNoLenUse();

    /**
     * @brief function for setting data into CTidlDidDataFormat structure
     *
     * @param[in] df  CTidlDidDataFormat structure
     * @param[in] mdid  desc did
     * @param[in] matt  desc att
     * @param[in] mstrAutoLenUseLen Length of mstrAutoLenUse
     * @param[in] mstrAutoLenUse desc str auto length use
     * @param[in] mlen  data length
     * @param[in] md5  
     * @param[in] mstrNoLenUse desc str not used auto length
     * @retval   void
     *
     */
    void setDataFormat(
        CTidlDidDataFormat& df
        , uint16_t mdid
        , uint32_t matt
        , size_t mstrAutoLenUseLen
        , uint8_t* mstrAutoLenUse
        , int32_t mlen
        , double md5
        , uint8_t* mstrNoLenUse
    );

    /**
     * @brief It is function for setting data of the CTidlDid data class.
     *
     * @param[in] mdid  desc did
     * @param[in] matt  desc att
     * @param[in] mstrAutoLenUseLen Length of mstrAutoLenUse
     * @param[in] mstrAutoLenUse desc str auto length use
     * @param[in] mlen  data length
     * @param[in] md5  
     * @param[in] mstrNoLenUse desc str not used auto length
     * @retval   void
     *
     */
    void setData(
            uint16_t mdid
            , uint32_t matt
            , size_t mstrAutoLenUseLen
            , uint8_t* mstrAutoLenUse
            , int32_t mlen
            , double md5
            , uint8_t* mstrNoLenUse
    );

private:
    void init();
    uint16_t  did;
    uint32_t  att;
    size_t  strAutoLenUseLen;
    uint8_t*  strAutoLenUse;
    int32_t  len;
    double  d5;
    uint8_t*  strNoLenUse;
};


#endif /** _SERVICELAYER_XXCLASS_CTIDLDID_H_ */
