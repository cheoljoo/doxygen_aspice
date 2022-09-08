
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

#ifndef _SERVICELAYER_XXCLASS_CTIDLITALY_H_
#define _SERVICELAYER_XXCLASS_CTIDLITALY_H_

#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Log.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>
#include "CTidlItaly.h"

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
    uint16_t italyDid;
    ETidlDid italyAtt;
    size_t italyStrAutoLenUseLen;
    uint8_t italyStrAutoLenUse[BUFSIZ];
    int32_t italyLen;
    double italyD5;
    size_t italyStrNoLenUseLen;
    uint8_t italyStrNoLenUse[BUFSIZ];
    float italyFloat;
    uint8_t strNoLenUse[BUFSIZ];
} CTidlItalyDataFormat;

#pragma pack()


/**
 * @brief data class : CTidlItaly
 * @details CTidlItaly class - I wanna go to Italy again. Example (Italy)
 */
class CTidlItaly : public android::RefBase {
public:
    /**
     * @brief constructor of the CTidlItaly data class.
     *
     */
    CTidlItaly();
    /**
     * @brief copy operator of the CTidlItaly data class.
     *
     * @param[in] other CTidlItaly
     *
     */
    CTidlItaly(const CTidlItaly& other);
    /**
     * @brief destructor of the CTidlItaly data class.
     *
     */
    virtual ~CTidlItaly();
    /**
     * @brief = operator of the CTidlItaly data class.
     *
     * @param[in] other CTidlItaly
     * @retval   CTidlItaly
     *
     */
    CTidlItaly& operator=(const CTidlItaly& other);
    /**
     * @brief It is for setting to CTidlItaly of the CTidlItaly data class.
     *
     * @param[in] other CTidlItaly
     * @retval   void
     *
     */
    void setTo(const CTidlItaly& other);
    /**
     * @brief This function is for writing parcel of the CTidlItaly data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);
    /**
     * @brief This function is for reading from parcel of the CTidlItaly data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t readFromParcel(const android::Parcel& parcel);
    /**
     * @brief This is a function that displays data in the CTidlItaly data class.
     *
     * @retval void
     *
     */
    void toString();
    /**
     * @brief This is a function that displays data by a specific name in the CTidlItaly data class.
     *
     * @param[in] from  printing data
     * @retval void
     *
     */
    void toString(const char* from);
    /**
     * @brief This function is for getting ItalyDid of the CTidlItaly data class.
     *
     * @retval  uint16_t
     *
     */
    uint16_t  getItalyDid();
    /**
     * @brief This function is for getting ItalyAtt of the CTidlItaly data class.
     *
     * @retval  ETidlDid
     *
     */
    ETidlDid  getItalyAtt();
    /**
     * @brief This function is for getting ItalyStrAutoLenUseLen of the CTidlItaly data class.
     *
     * @retval  size_t
     *
     */
    size_t  getItalyStrAutoLenUseLen();
    uint8_t*  getItalyStrAutoLenUse();
    /**
     * @brief This function is for getting ItalyLen of the CTidlItaly data class.
     *
     * @retval  int32_t
     *
     */
    int32_t  getItalyLen();
    /**
     * @brief This function is for getting ItalyD5 of the CTidlItaly data class.
     *
     * @retval  double
     *
     */
    double  getItalyD5();
    /**
     * @brief This function is for getting ItalyStrNoLenUseLen of the CTidlItaly data class.
     *
     * @retval  size_t
     *
     */
    size_t  getItalyStrNoLenUseLen();
    uint8_t*  getItalyStrNoLenUse();
    /**
     * @brief This function is for getting ItalyFloat of the CTidlItaly data class.
     *
     * @retval  float
     *
     */
    float  getItalyFloat();
    uint8_t*  getStrNoLenUse();

    /**
     * @brief function for setting data into CTidlItalyDataFormat structure
     *
     * @param[in] df  CTidlItalyDataFormat structure
     * @param[in] mitalyDid  desc did
     * @param[in] mitalyAtt  desc ENUM test in Class
     * @param[in] mitalyStrAutoLenUseLen Length of mitalyStrAutoLenUse
     * @param[in] mitalyStrAutoLenUse desc str auto length use
     * @param[in] mitalyLen  data length
     * @param[in] mitalyD5  
     * @param[in] mitalyStrNoLenUseLen Length of mitalyStrNoLenUse
     * @param[in] mitalyStrNoLenUse desc str auto length use
     * @param[in] mitalyFloat  
     * @param[in] mstrNoLenUse desc str not used auto length
     * @retval   void
     *
     */
    void setDataFormat(
        CTidlItalyDataFormat& df
        , uint16_t mitalyDid
        , ETidlDid mitalyAtt
        , size_t mitalyStrAutoLenUseLen
        , uint8_t* mitalyStrAutoLenUse
        , int32_t mitalyLen
        , double mitalyD5
        , size_t mitalyStrNoLenUseLen
        , uint8_t* mitalyStrNoLenUse
        , float mitalyFloat
        , uint8_t* mstrNoLenUse
    );

    /**
     * @brief It is function for setting data of the CTidlItaly data class.
     *
     * @param[in] mitalyDid  desc did
     * @param[in] mitalyAtt  desc ENUM test in Class
     * @param[in] mitalyStrAutoLenUseLen Length of mitalyStrAutoLenUse
     * @param[in] mitalyStrAutoLenUse desc str auto length use
     * @param[in] mitalyLen  data length
     * @param[in] mitalyD5  
     * @param[in] mitalyStrNoLenUseLen Length of mitalyStrNoLenUse
     * @param[in] mitalyStrNoLenUse desc str auto length use
     * @param[in] mitalyFloat  
     * @param[in] mstrNoLenUse desc str not used auto length
     * @retval   void
     *
     */
    void setData(
            uint16_t mitalyDid
            , ETidlDid mitalyAtt
            , size_t mitalyStrAutoLenUseLen
            , uint8_t* mitalyStrAutoLenUse
            , int32_t mitalyLen
            , double mitalyD5
            , size_t mitalyStrNoLenUseLen
            , uint8_t* mitalyStrNoLenUse
            , float mitalyFloat
            , uint8_t* mstrNoLenUse
    );

private:
    void init();
    uint16_t  italyDid;
    ETidlDid  italyAtt;
    size_t  italyStrAutoLenUseLen;
    uint8_t*  italyStrAutoLenUse;
    int32_t  italyLen;
    double  italyD5;
    size_t  italyStrNoLenUseLen;
    uint8_t*  italyStrNoLenUse;
    float  italyFloat;
    uint8_t*  strNoLenUse;
};


#endif /** _SERVICELAYER_XXCLASS_CTIDLITALY_H_ */
