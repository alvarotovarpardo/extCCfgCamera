#include 'config_base.h'


class extendedCCfgCamGeneral : public CCfgClass // Change name!!
{
private:

	/**************************************/
	/*******   COMMON PROPERTIES   *******/
	/**************************************/


	/*******   fix & distributed & analytics & lite   *******/

	EnumConfigCameraType m_eConfigCameraType;
	EnumConfigConnectionMode m_eConfigConnectionMode;
	EnumConfigSensorType m_eConfigSensorType;
	bool m_bAutoStretching;
	bool m_bAutomaticRaw;
	bool m_bHasShutter;
	bool m_bHorizontalFlip;
	bool m_bImageRotate;
	bool m_bPaletteBar;
	bool m_bPaletteRtsp;
	bool m_bPanAndTilt;
	bool m_bShowDigitalLevels;
	bool m_bShowNOROI;
	bool m_bShowROI;
	bool m_bStretching;
	bool m_bValuesRtsp;
	bool m_bVerticalFlip;
	char m_szCameraModelName[20];
	char m_szConnectionChain[CONFIG_MAX_PATH + 1];
	char m_szDescription[50];
	char m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID + 1];
	char m_szTourActiveAutomatic[CFG_MAX_SMALL_ID + 1];
	double m_dCamEmissivity;
	int m_iBuffMaxLengh;
	int m_iDiodeBias;
	int m_iFps;
	int m_iFpsShow;
	int m_iFramesSecondRtsp;
	int m_iGain;
	int m_iIntegrationTime;
	int m_iInvertValues;
	int m_iMatHeight;
	int m_iMatMetaDataLeft;
	int m_iMatMetaDataRight;
	int m_iMatType;
	int m_iMatWidth;
	int m_iNucSecondsBetweenAutomatic;
	int m_iPortThirdPartyHttp;
	int m_iPortThirdPartyRtsp;
	int m_iReconnectionAttemps;
	int m_iReconnectionWait;
	int m_iSecondsDelayClosedshutterImgnuc;
	int m_iTimeSendFps;
	nan
	unsigned char m_ucDataBits;
	unsigned char m_ucModeConvert2_8To16;
	unsigned short m_usAndConvert2_8To16;
	unsigned short m_usDivConvert2_8To16;

	/*******   fix & distributed & analytics   *******/

	QByteArray m_baPartNumber;
	SimpleCrypt *crypto;
	bool m_bAutoResetEnabled;
	bool m_bCCTVAccessControl;
	bool m_bCloseShutter;
	bool m_bEmailAlert;
	bool m_bEnableAll;
	bool m_bHasCompass;
	bool m_bHasMemorySPI;
	bool m_bHasPleoraExpansor;
	bool m_bResetPeriodicEnabled;
	bool m_bResetPunctualEnabled;
	bool m_bShowSaturatedPixels;
	char m_szCCTVPassword[50];
	char m_szCCTVUsername[50];
	char m_szResetDateTime[50];
	char m_szResetPeriodicDateTime[50];
	int m_iParamGFID;
	int m_iParamGSK;
	int m_iParamGain;
	int m_iParamTInt;
	int m_iParamVBUS;
	int m_iParamVSK;
	int m_iPortThirdPartyOnvif;
	int m_iResetUnitsValue;

	/*******   fix & distributed & lite   *******/

	int m_iMean;
	int m_iSkip;

	/*******   fix & analytics & lite   *******/


	/*******   distributed & analytics & lite   *******/


	/*******   fix & distributed   *******/

	EnumConfigLaserType m_eConfigLaserType;
	bool m_bAdamRelay;
	bool m_bAutomaticGain;
	bool m_bAutomaticMP4;
	bool m_bCameraRepeatedFrames;
	bool m_bFPSWarnings;
	bool m_bHasSensorLens;
	bool m_bMaintenanceMode;
	bool m_bPanAndTiltPelcoD;
	bool m_bPanInverted;
	bool m_bPeriodicDeleteAt;
	bool m_bPeriodicDeleteAtActive;
	bool m_bPeriodicPunctual;
	bool m_bPeriodicRepeat;
	bool m_bRTSPAccessControl;
	bool m_bSensiaNUC;
	bool m_bShowCurrentFrame;
	bool m_bShowSimulateName;
	bool m_bShowWindowTest;
	bool m_bSwitchPOE;
	bool m_bTiltInverted;
	bool m_bWeightingFactors;
	char m_sGeolocation[100];
	char m_szAdamRelayIP[CONFIG_MAX_PATH + 1];
	char m_szConnectionPhidget[CONFIG_MAX_IP + 1];
	char m_szLicense[CONFIG_MAX_PATH + 1];
	char m_szNextCheckTime[50];
	char m_szPeriodicDeleteAtTime[50];
	char m_szPeriodicUnits[50];
	char m_szRTSPPassword[50];
	char m_szRTSPUsername[50];
	char m_szResetUnits[20];
	char m_szSerialNumber[CONFIG_MAX_PATH + 1];
	char m_szSwitchIP[CONFIG_MAX_PATH + 1];
	double m_dCamGain;
	double m_dCamOffset;
	double m_dIFOV;
	double m_dMediaTemp;
	double m_dOffsetIfov_x;
	double m_dOffsetIfov_y;
	int m_iAdamRelayPort;
	int m_iAutoGainInterval;
	int m_iBottomCutout;
	int m_iCurrentPreset;
	int m_iCurrentTour;
	int m_iLaserCOM;
	int m_iLeftCutout;
	int m_iMaxOperationTemperature;
	int m_iMaxPixSaturated;
	int m_iPanAndTiltCom;
	int m_iPanAndTiltID;
	int m_iPanAndTiltSpeed;
	int m_iPeriodicUnitsValue;
	int m_iRelayPort;
	int m_iRightCutout;
	int m_iSensorPort;
	int m_iShutterMaxPos;
	int m_iShutterMinPos;
	int m_iStepperPort;
	int m_iSwitchInterface;
	int m_iTopCutout;
	std::vector<double> vGlobalTemp;

	/*******   fix & analytics   *******/


	/*******   fix & lite   *******/


	/*******   distributed & analytics   *******/


	/*******   distributed & lite   *******/

	bool m_bStretchingRegion;
	int m_iRegionSize;

	/*******   analytics & lite   *******/

	char m_szOpticalSize[50];
	char m_szSensitivity[50];
	char m_szTarjetGas[50];
	char m_szUnits[50];
	double m_dCorrectionFactor;

	/**************************************/
	/******   SPECIFIC PROPERTIES   ******/
	/**************************************/


	/*******   fix   *******/

	bool m_bAutomaticRLK;
	bool m_bHasLaser;
	bool m_bIsDummy;
	bool m_bPulseRelay;
	char m_szCameraBand[CONFIG_MAX_PATH + 1];
	char m_szCameraHierarchy[20];
	double m_dDistParameterK1;
	double m_dDistParameterK2;
	double m_dDistParameterK3;
	double m_dFocalLength;
	double m_dPixelPitch;
	int m_iIntegrationData;
	int m_iPulseRelaySeconds;

	/*******   distributed   *******/

	int m_iFocalLength;
	int m_iPTLimitPanLeft;
	int m_iPTLimitPanRight;
	int m_iPTLimitTiltBottom;
	int m_iPTLimitTiltTop;
	int m_iPixelPitch;

	/*******   analytics   *******/

	EnumConfigCameraMode m_eConfigCameraMode;
	bool m_bDumpCO2;
	bool m_bDumpCO;
	bool m_bDumpHC;
	bool m_bDumpNOx;
	bool m_bDumpOpacity;
	bool m_bEdgeRemove;
	bool m_bElectronicOld;
	bool m_bEmailSendAll;
	bool m_bGasAbsorption;
	bool m_bGasEmission;
	bool m_bHasSensorTemperature;
	bool m_bOCR;
	char m_sFuel[20];
	char m_szEmailCC[640];
	char m_szEmail[50];
	char m_szPlaybackSpeed[20];
	char m_szResetUnits[10];
	double m_dAbsorbanceCO2;
	double m_dAbsorbanceCO;
	double m_dAbsorbanceHC;
	double m_dAbsorbanceNOx;
	double m_dAbsorbanceOpacity;
	double m_dLambda1;
	double m_dLambda2;
	double m_dTHLocalMinCO2;
	double m_dTHLocalMinCO;
	double m_dTHLocalMinHC;
	double m_dTHLocalMinNOx;
	double m_dTHLocalMinOpacity;
	double m_dThresholdCO;
	double m_dThresholdHC;
	double m_dThresholdNOx;
	double m_dThresholdOpacity;
	double m_dWaitTime;
	int m_iKernelCO2;
	int m_iKernelCO;
	int m_iKernelHC;
	int m_iKernelNOx;
	int m_iKernelOpacity;
	int m_iOCRPort;
	int m_iOffset;
	int m_iVariationThreshold;

	/*******   lite   *******/

	char m_sDeviceSerialNumber[50];
	char m_szDensityUnits[50];
	char m_szDistanceUnits[50];
	char m_szTemperatureUnits[50];
	double m_dAmbientTemperature;
	double m_dClipClahe;
	double m_dClipClaheEnhanced;
	double m_dClipClaheSkip;
	double m_dGasDensity;
	double m_dGasTemperature;
	double m_dMaxFlowRateLimit;
	double m_dMinFlowRateLimit;
	double m_iLeakDistance;
	float m_fFactorMeanPond;
	int m_iHR;
	int m_iSizeClahe;
	int m_iSizeClaheEnhanced;
	int m_iSizeClaheSkip;
	int m_iTFrame;
	int m_iTamVectorData;
	int m_iWindowSize;


public:

};