void CCfgCamGeneral::initDefault()
{
    //Clase de cifrado
    crypto = new SimpleCrypt(Q_UINT64_C(0x0c2ad4a4acb9f023));

    STRCPY(m_szDescription, "");
    m_szDescription[19] = '\0';
    m_eConfigConnectionMode = CONFIG_CAM_CMODE_NONE;
    m_eConfigCameraMode = CONFIG_MODE_OTHER;
    STRCPY (m_szConnectionChain, "");
    m_szConnectionChain[CONFIG_MAX_PATH] = '\0';
    m_bElectronicOld = false;
    m_iFps = 5;
    STRCPY(m_sFuel, "");
    m_sFuel[19] = '\0';
    m_iTimeSendFps = 5;
    m_iFpsShow = 5;
    m_iMatWidth = 640;
    m_iMatHeight = 480;
    m_iMatType = 3;
    m_iBuffMaxLengh = 125;

    m_bCCTVAccessControl = false;
    strcpy_s(m_szCCTVUsername, "");
    strcpy_s(m_szCCTVPassword, "");

    m_eConfigCameraType = CONFIG_CAM_TYPE_NONE;
    m_eConfigSensorType = CONFIG_SENSOR_NONE;
    m_iMatMetaDataLeft = 0;
    m_iMatMetaDataRight = 0;
    STRCPY(m_szCameraModelName, "");
    m_szCameraModelName[19] = '\0';
    m_baPartNumber = QByteArray::fromHex("");
    STRCPY(m_szPlaybackSpeed, "");
    m_szPlaybackSpeed[19] = '\0';

    m_ucDataBits = 14;
    m_ucModeConvert2_8To16 = 1;
    m_usDivConvert2_8To16 = 4;
    m_usAndConvert2_8To16 = 0;
    m_iInvertValues = 16384;

    /*Mileva parameters*/
    m_iGain = 0;
    m_iDiodeBias = 2;
    m_iIntegrationTime = 4000;

    /*Pico & ATTO parameters*/
    m_iParamGFID = -1;
    m_iParamGSK = -1;
    m_iParamVSK = -1;
    m_iParamVBUS = -1;
    m_iParamGain = -1;
    m_iParamTInt = -1;

    m_iPortThirdPartyOnvif = 0;
    m_iPortThirdPartyHttp = 0;
    m_iPortThirdPartyRtsp = 0;
    m_iFramesSecondRtsp = 5;
    m_bPaletteRtsp = false;
    m_bValuesRtsp = false;

    m_bVerticalFlip = false;
    m_bHorizontalFlip = false;
    m_bImageRotate = false;
    m_bPaletteBar = true;
    m_bStretching = true;
    m_bAutoStretching = true;
    m_bShowROI = true;
    m_bShowNOROI = false;
    m_bEnableAll = true;
    m_dCamEmissivity = 1.0;
    m_bShowDigitalLevels = false;
    m_bShowSaturatedPixels = true;

    m_bEmailAlert = false;
    STRCPY(m_szEmail, "");
    STRCPY(m_szEmailCC, "");
    m_bEmailSendAll = false;

    m_iReconnectionWait = 3000;
    m_iReconnectionAttemps = 10;

    m_bHasShutter = false;
    m_iNucSecondsBetweenAutomatic = -1;
    m_iSecondsDelayClosedshutterImgnuc = 2;
    m_bCloseShutter = false;

    m_bPanAndTilt = false;
    STRCPY (m_szTourActiveAutomatic, "");
    STRCPY (m_szPresetActiveAutomatic, "");
    m_szTourActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_bAutomaticRaw = false;
    m_bHasSensorTemperature = false;
    m_bHasPleoraExpansor = false;
    m_bHasMemorySPI = false;
    m_bHasCompass = false;

    /* Variables para el reset automático de cámaras */
    m_bAutoResetEnabled = false;
    m_bResetPeriodicEnabled = false;
    m_bResetPunctualEnabled = false;
    STRCPY(m_szResetUnits, "");
    m_szResetUnits[9] = '\0';
    m_iResetUnitsValue = -1;
    STRCPY(m_szResetDateTime, "");
    m_szResetDateTime[49] = '\0';
    STRCPY(m_szResetPeriodicDateTime, "");
    m_szResetPeriodicDateTime[49] = '\0';

    /* ------- RIO Gases  */
    //umbrales para vehiclos de tipología M1
    m_dThresholdCO = 0.208;
    m_dThresholdNOx = 0.01464;
    m_dThresholdHC = 0.0072;
    m_dThresholdOpacity = 1.1;
    m_bDumpCO2 = false;
    m_bDumpCO = false;
    m_bDumpNOx = false;
    m_bDumpHC = false;
    m_bDumpOpacity = false;

    m_dTHLocalMinCO2 = 2000;
    m_dTHLocalMinCO = 2000;
    m_dTHLocalMinHC = 2000;
    m_dTHLocalMinNOx = 2000;
    m_dTHLocalMinOpacity = 2000;
    m_dWaitTime = 1.8;
    m_iVariationThreshold = 15000;
    m_iKernelCO2 = 3;
    m_iKernelCO = 3;
    m_iKernelHC = 3;
    m_iKernelNOx = 3;
    m_iKernelOpacity = 3;
    m_dAbsorbanceCO2 = 1.0;
    m_dAbsorbanceCO = 1.0;
    m_dAbsorbanceHC = 1.0;
    m_dAbsorbanceNOx = 1.0;
    m_dAbsorbanceOpacity = 1.0;
    m_iOffset = 0;

    strcpy_s(m_szUnits, "ppm·m");
    m_szUnits[49] = '\0';
    strcpy_s(m_szTarjetGas, "CO2");
    m_szTarjetGas[49] = '\0';
    m_dCorrectionFactor = 1.0;
    strcpy_s(m_szOpticalSize, "35 mm");
    m_szOpticalSize[49] = '\0';
    strcpy_s(m_szSensitivity, "High");
    m_szSensitivity[49] = '\0';
    m_dLambda1 = 4.3;
    m_dLambda2 = 4.6;
    m_bGasAbsorption = false;
    m_bGasEmission = true;
    m_bEdgeRemove = false;

    m_bOCR = false;
    m_iOCRPort = 0;
}