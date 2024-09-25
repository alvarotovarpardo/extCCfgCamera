void CCfgCamGeneral::initDefault()
{
    STRCPY(m_szDescription, "");
    m_szDescription[49] = '\0';
    m_eConfigConnectionMode = CONFIG_CAM_CMODE_NONE;
    STRCPY (m_szConnectionChain, "");
    m_szConnectionChain[CONFIG_MAX_PATH] = '\0';
    m_iFps = 25;
    m_iTimeSendFps = 5;
    m_iFpsShow = 20;
    m_iMatWidth = 640;
    m_iMatHeight = 480;
    m_iMatType = 3;
    m_iBuffMaxLengh = 25;

    m_eConfigCameraType = CONFIG_CAM_TYPE_NONE;
    m_eConfigSensorType = CONFIG_SENSOR_NONE;
    m_iMatMetaDataLeft = 0;
    m_iMatMetaDataRight = 0;
    STRCPY(m_szCameraModelName, "");
    m_szCameraModelName[19] = '\0';

    m_ucDataBits = 0;
    m_ucModeConvert2_8To16 = 3;
    m_usDivConvert2_8To16 = 1;
    m_usAndConvert2_8To16 = 0;
    m_iInvertValues = 16384;
    m_iTamVectorData = 25;

    m_iGain = 0;
    m_iDiodeBias = 2;
    m_iTFrame = 60;
    m_iIntegrationTime = 4000;

    m_iPortThirdPartyHttp = 0;
    m_iPortThirdPartyRtsp = 0;
    m_iFramesSecondRtsp = 5;
    m_bPaletteRtsp = false;
    m_bValuesRtsp = false;

    m_bVerticalFlip = false;
    m_bHorizontalFlip = false;
    m_bPaletteBar = true;
    m_bStretching = true;
    m_bAutoStretching = true;
    m_bStretchingRegion = false;
    m_iRegionSize = 50;
    m_bShowROI = true;
    m_bShowNOROI = false;
    m_dCamEmissivity = 1.0;
    m_bShowDigitalLevels = false;
    m_iSkip = 4;
    m_iMean = 5;
    m_iWindowSize = 5;
    m_iSizeClahe = 8;
    m_iSizeClaheEnhanced = 5;
    m_iSizeClaheSkip = 8;
    m_dClipClahe = 40;
    m_dClipClaheEnhanced = 12;
    m_dClipClaheSkip = 40;
    m_fFactorMeanPond = 0.0;

    m_iReconnectionWait = 3000;
    m_iReconnectionAttemps = 10;

    m_bPanAndTilt = false;
    m_bHasShutter = false;
    m_iNucSecondsBetweenAutomatic = -1;
    m_iSecondsDelayClosedshutterImgnuc = 1;
    STRCPY (m_szTourActiveAutomatic, "");
    STRCPY (m_szPresetActiveAutomatic, "");
    m_szTourActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_bAutomaticRaw = false;

    STRCPY(m_szUnits, "");
    m_szUnits[49] = '\0';
    STRCPY(m_szDistanceUnits, "m");
    m_iLeakDistance = 0;
    m_dMaxFlowRateLimit = -1; //(382 L/min --- 15 kg/h)
    m_dMinFlowRateLimit = -1; //(102 L/min --- 4 kg/h)
    STRCPY(m_szTarjetGas, "");
    m_szTarjetGas[49] = '\0';
    m_dCorrectionFactor = 0.0;
    STRCPY(m_szTemperatureUnits, "ºC");
    m_dAmbientTemperature = 0.0;
    m_iHR = 0;
    m_dGasTemperature = 0.0;
    STRCPY(m_szOpticalSize, "20 mm");
    m_szOpticalSize[49] = '\0';
    STRCPY(m_szSensitivity, "High");
    m_szSensitivity[49] = '\0';
    STRCPY(m_szDensityUnits, "g/m3");
    m_dGasDensity = 0.0;
    m_bImageRotate = false;
}