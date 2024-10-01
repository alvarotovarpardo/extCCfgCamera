#include "config_base.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

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
	enum EnumConfigConnectionMode { CONFIG_CAM_CMODE_ARAVIS, CONFIG_CAM_CMODE_CCTV, CONFIG_CAM_CMODE_DMK, CONFIG_CAM_CMODE_EYECGAS, CONFIG_CAM_CMODE_FLIR_ATLAS, CONFIG_CAM_CMODE_FLIR_SPINNAKER, CONFIG_CAM_CMODE_GST, CONFIG_CAM_CMODE_NONE, CONFIG_CAM_CMODE_OPENCV, CONFIG_CAM_CMODE_PCO, CONFIG_CAM_CMODE_PLEORA, CONFIG_CAM_CMODE_SIMULATE, CONFIG_CAM_CMODE_SIMULATE_EYECGAS, CONFIG_CAM_CMODE_SIMULATE_FLIR, CONFIG_CAM_CMODE_SMART, CONFIG_CAM_CMODE_VIDEOINPUT };
	enum EnumConfigCameraType { CONFIG_CAM_TYPE_NONE, CONFIG_CAM_TYPE_THERMAL, CONFIG_CAM_TYPE_VISIBLE };
	enum EnumConfigSensorType { CONFIG_SENSOR_ATTO640, CONFIG_SENSOR_FASTPELICAN, CONFIG_SENSOR_FREJA, CONFIG_SENSOR_GUIDE, CONFIG_SENSOR_HOTPELICAN, CONFIG_SENSOR_KINGLET, CONFIG_SENSOR_NONE, CONFIG_SENSOR_PELICAN, CONFIG_SENSOR_PICO, CONFIG_SENSOR_PICO384, CONFIG_SENSOR_PICO384V2, CONFIG_SENSOR_PICO640, CONFIG_SENSOR_VOXI };
	enum EnumConfigLaserType { CONFIG_LASER_A, CONFIG_LASER_B, CONFIG_LASER_NONE };
	enum EnumFocus { FOCUS_AUTO, FOCUS_DECREMENT, FOCUS_INCREMENT };
	enum EnumConfigCameraMode { CONFIG_MODE_ETHERNET, CONFIG_MODE_OTHER, CONFIG_MODE_USB };
	CCfgCamGeneral();
	virtual ~CCfgCamGeneral();
	void initDefault();
	void display();
	void matchField(std::string &sAtributo, Jzon::Node &nodoValor);
	void serializeFields(Jzon::Node &node);
	char *getDescription() { return m_szDescription; }
	EnumConfigConnectionMode getConnectionMode() { return m_eConfigConnectionMode; }
	void setConnectionMode(EnumConfigConnectionMode eConfigConnectionMode) { m_eConfigConnectionMode = eConfigConnectionMode; }
	char *getConnectionChain() { return m_szConnectionChain; }
	void setConnectionChain(QString sConnectionChain) { strcpy_s(m_szConnectionChain,sConnectionChain.toLatin1().toStdString().c_str()); }
	char *getSerialNumber() { return m_szSerialNumber; }
	void setSerialNumber(QString sSerialNumber) { strcpy_s(m_szSerialNumber,sSerialNumber.toStdString().c_str()); }
	char *getLicense() { return m_szLicense; }
	void setLicense(QString sLicense) { strcpy_s(m_szLicense, sLicense.toStdString().c_str()); }
	int getFps() { return m_iFps; }
	int getTimeSendFps() { return m_iTimeSendFps; }
	int getFpsShow() { return m_iFpsShow; }
	int getMatWidth() { return m_iMatWidth; }
	int getMatHeight() { return m_iMatHeight; }
	int getMatType() { return m_iMatType; }
	int getBuffMaxLengh() { return m_iBuffMaxLengh; }
	int getLeftCutout() { return m_iLeftCutout; }
	int getRightCutout() { return m_iRightCutout; }
	int getTopCutout() { return m_iTopCutout; }
	int getBottomCutout() { return m_iBottomCutout; }
	double getFocalLength() { return m_dFocalLength; }
	double getPixelPitch() { return m_dPixelPitch; }
	double getIFOV() { return m_dIFOV; }
	double getOffsetIfov_x() { return m_dOffsetIfov_x; }
	double getOffsetIfov_y() { return m_dOffsetIfov_y; }
	double getDistParameterK1() { return m_dDistParameterK1; }
	double getDistParameterK2() { return m_dDistParameterK2; }
	double getDistParameterK3() { return m_dDistParameterK3; }
	void setDescription(char *szDescription) { strcpy_s(m_szDescription, szDescription); }
	void setFps(int iFps) { m_iFps = iFps; }
	void setTimeSendFps(int iTimeSendFps) { m_iTimeSendFps = iTimeSendFps; }
	void setFpsShow(int iFpsShow) { m_iFpsShow = iFpsShow; }
	void setMatWidth(int iMatWidth) { m_iMatWidth = iMatWidth; }
	void setMatHeight(int iMatHeight) { m_iMatHeight = iMatHeight; }
	void setMatType(int iMatType) { m_iMatType = iMatType; }
	void setBuffMaxLengh(int iBuffMaxLengh) { m_iBuffMaxLengh = iBuffMaxLengh; }
	void setLeftCutout(int iLeftCutout) { m_iLeftCutout = iLeftCutout; }
	void setRightCutout(int iRightCutout) { m_iRightCutout = iRightCutout; }
	void setTopCutout(int iTopCutout) { m_iTopCutout = iTopCutout; }
	void setBottomCutout(int iBottomCutout) { m_iBottomCutout = iBottomCutout; }
	void setFocalLength(double dFocalLength) { m_dFocalLength = dFocalLength; }
	void setPixelPitch(double dPixelPitch) { m_dPixelPitch = dPixelPitch; }
	void setIFOV(double dIFOV) {m_dIFOV = dIFOV; }
	void setOffsetIfov_x(double dOffsetIfov_x) {m_dOffsetIfov_x = dOffsetIfov_x; }
	void setOffsetIfov_y(double dOffsetIfov_y) {m_dOffsetIfov_y = dOffsetIfov_y; }
	void setDistParameterK1(double dDistParameterK1) {m_dDistParameterK1 = dDistParameterK1; }
	void setDistParameterK2(double dDistParameterK2) {m_dDistParameterK2 = dDistParameterK2; }
	void setDistParameterK3(double dDistParameterK3) {m_dDistParameterK3 = dDistParameterK3; }
	bool getCCTVAccessControl() { return m_bCCTVAccessControl; }
	void setCCTVAccesControl(bool bCCTVAccesControl) { m_bCCTVAccessControl = bCCTVAccesControl; }
	void setCCTVUsername(char *szCCTVUsername) { strcpy_s(m_szCCTVUsername, szCCTVUsername); }
	char *getCCTVUsername() { return m_szCCTVUsername; }
	void setCCTVPassword(char *szCCTVPassword) { strcpy_s(m_szCCTVPassword, szCCTVPassword); }
	char *getCCTVPassword() { return m_szCCTVPassword;}
	EnumConfigCameraType getConfigCameraType() { return m_eConfigCameraType; }
	void setConfigCameraType(EnumConfigCameraType eConfigCamera) { m_eConfigCameraType = eConfigCamera; }
	EnumConfigSensorType getConfigSensorType() { return m_eConfigSensorType; }
	void setConfigSensorType(EnumConfigSensorType eConfigSensor) { m_eConfigSensorType = eConfigSensor; }
	char *getCameraModelName() { return m_szCameraModelName; }
	void setCameraModelName(char *sCameraModelName) { strcpy_s(m_szCameraModelName,sCameraModelName); }
	char *getCameraHierarchy() { return m_szCameraHierarchy; }
	void setCameraHierarchy(char *sCameraHierarchy) { strcpy_s(m_szCameraHierarchy, sCameraHierarchy); }
	QByteArray getPartNumber() { return m_baPartNumber; }
	void setPartNumber(QByteArray baPartNumber) { m_baPartNumber = baPartNumber; }
	int getMatMetaDataLeft() { return m_iMatMetaDataLeft; }
	void setMatMetaDataLeft(int iMatMetaDataLeft) { m_iMatMetaDataLeft = iMatMetaDataLeft; }
	int getMatMetaDataRigh() { return m_iMatMetaDataRight; }
	void setMatMetaDataRigh(int iMatMetaDataRight) { m_iMatMetaDataRight = iMatMetaDataRight; }
	void setReconnectionWait(int iReconnectionWait) { m_iReconnectionWait = iReconnectionWait; }
	int getReconnectionWait() { return m_iReconnectionWait; }
	void setReconnectionAttemps(int iReconnectionAttemps) { m_iReconnectionAttemps = iReconnectionAttemps; }
	int getReconnectionAttemps() { return m_iReconnectionAttemps; }
	unsigned char getDataBits() { return m_ucDataBits; }
	void setDataBits(unsigned char ucDataBits) { m_ucDataBits = ucDataBits; }
	unsigned char getModeConvert2_8To16() { return m_ucModeConvert2_8To16; }
	void setModeConvert2_8To16(unsigned char ucModeConvert2_8To16) { m_ucModeConvert2_8To16 = ucModeConvert2_8To16; }
	unsigned short getDivConvert2_8To16() { if (m_usDivConvert2_8To16 == 0) return 1; else return m_usDivConvert2_8To16; }
	void setDivConvert2_8To16(unsigned short usDivConvert2_8To16) { m_usDivConvert2_8To16 = usDivConvert2_8To16; }
	unsigned short getAndConvert2_8To16() { return m_usAndConvert2_8To16; }
	void setAndConvert2_8To16(unsigned short usAndConvert2_8To16) { m_usAndConvert2_8To16 = usAndConvert2_8To16; }
	int getInvertValues() { return m_iInvertValues; }
	void setInvertValues(int iInvertValues) { m_iInvertValues = iInvertValues; }
	void setAutomaticGain(bool bAutomaticGain) { m_bAutomaticGain = bAutomaticGain; }
	void setMaxPixSaturated(int iMaxPixSaturated) { m_iMaxPixSaturated = iMaxPixSaturated; }
	void setAutoGainInterval(int iAutoGainInterval) { m_iAutoGainInterval = iAutoGainInterval; }
	void setGain(int iGain) { m_iGain = iGain; }
	void setDiodeBias(int iDiodeBias) { m_iDiodeBias= iDiodeBias; }
	void setIntegrationTime(int iIntegrationTime) { m_iIntegrationTime = iIntegrationTime; }
	void setIntegrationData(int iIntegrationData) { m_iIntegrationData = iIntegrationData; }
	bool getAutomaticGain() { return m_bAutomaticGain; }
	int getMaxPixSaturated() { return  m_iMaxPixSaturated; }
	int getAutoGainInterval() { return  m_iAutoGainInterval; }
	int getGain() { return m_iGain; }
	int getDiodeBias() { return m_iDiodeBias; }
	int getIntegrationTime() { return m_iIntegrationTime; }
	int getIntegrationData() { return m_iIntegrationData; }
	void setParamGFID(int iParamGFID) { m_iParamGFID = iParamGFID; }
	void setParamGSK(int iParamGSK) { m_iParamGSK = iParamGSK; }
	void setParamVSK(int iParamVSK) { m_iParamVSK = iParamVSK; }
	void setParamVBUS(int iParamVBUS) { m_iParamVBUS = iParamVBUS; }
	void setParamGain(int iParamGain) { m_iParamGain = iParamGain; }
	void setParamTInt(int iParamTInt) { m_iParamTInt = iParamTInt; }
	int getParamGFID() { return m_iParamGFID; }
	int getParamGSK() { return m_iParamGSK; }
	int getParamVSK() { return m_iParamVSK; }
	int getParamVBUS() { return m_iParamVBUS; }
	int getParamGain() { return m_iParamGain; }
	int getParamTInt() { return m_iParamTInt; }
	bool getHasLaser() { return m_bHasLaser; }
	void setHasLaser(bool bHasLaser) { m_bHasLaser = bHasLaser; }
	int getLaserCOM() { return m_iLaserCOM; }
	void setLaserCOM(int iLaserCOM) { m_iLaserCOM = iLaserCOM; }
	EnumConfigLaserType getConfigLaserType() { return m_eConfigLaserType; }
	void setConfigLaserType(EnumConfigLaserType eConfigLaserType) { m_eConfigLaserType = eConfigLaserType; }
	int getPortThirdPartyOnvif() { return m_iPortThirdPartyOnvif; }
	void setPortThirdPartyOnvif(int iPortThirdPartyOnvif) { m_iPortThirdPartyOnvif = iPortThirdPartyOnvif; }
	int getPortThirdPartyHttp() { return m_iPortThirdPartyHttp; }
	void setPortThirdPartyHttp(int iPortThirdPartyHttp) { m_iPortThirdPartyHttp = iPortThirdPartyHttp; }
	int getPortThirdPartyRtsp() { return m_iPortThirdPartyRtsp; }
	void setPortThirdPartyRtsp(int iPortThirdPartyRtsp) { m_iPortThirdPartyRtsp = iPortThirdPartyRtsp; }
	int getFramesSecondRtsp() { return m_iFramesSecondRtsp; }
	void setFramesSecondRtsp(int iFramesSecondRtsp) { m_iFramesSecondRtsp = iFramesSecondRtsp; }
	bool getRTSPAccessControl() { return m_bRTSPAccessControl; }
	void setRTSPAccesControl(bool bRTSPAccesControl) { m_bRTSPAccessControl = bRTSPAccesControl; }
	void setRTSPUsername(char *szRTSPUsername) { strcpy_s(m_szRTSPUsername, szRTSPUsername); }
	char *getRTSPUsername() { return m_szRTSPUsername; }
	void setRTSPPassword(char *szRTSPPassword) { strcpy_s(m_szRTSPPassword, szRTSPPassword); }
	const char * getRTSPPassword() { return m_szRTSPPassword; }
	bool getPaletteRtsp() { return m_bPaletteRtsp; }
	void setPaletteRtsp(bool bPaletteRtsp) { m_bPaletteRtsp = bPaletteRtsp; }
	bool getValuesRtsp() { return m_bValuesRtsp; }
	void setValuesRtsp(bool bValuesRtsp) { m_bValuesRtsp = bValuesRtsp; }
	void setVerticalFlip(bool bVerticalFlip) { m_bVerticalFlip = bVerticalFlip; }
	void setHorizontalFlip(bool bHorizontalFlip) { m_bHorizontalFlip = bHorizontalFlip; }
	void setImageRotate(bool bImageRotate) { m_bImageRotate = bImageRotate; }
	void setPaletteBar(bool bPaletteBar) { mtxChangeHotConfig.lock(); m_bPaletteBar = bPaletteBar; mtxChangeHotConfig.unlock();}
	void setStretching(bool bStretching) { m_bStretching = bStretching; }
	void setAutoStretching(bool bAutoStretching) { m_bAutoStretching = bAutoStretching; }
	void setCameraRepeatedFrames(bool bCameraRepeatedFrames) { m_bCameraRepeatedFrames = bCameraRepeatedFrames; }
	void setShowROI(bool bShowROI) { m_bShowROI = bShowROI; }
	void setShowNOROI(bool bShowNOROI) { m_bShowNOROI = bShowNOROI; }
	void setCamEmissivity(double dCamEmissivity) { m_dCamEmissivity = dCamEmissivity; }
	void setEnableAll(bool bStatus) {m_bEnableAll = bStatus;}
	void setShowDigitalLevels(bool bShowDigitalLevels) { m_bShowDigitalLevels = bShowDigitalLevels;}
	void setShowSaturatedPixels(bool bShowSaturatedPixels){ m_bShowSaturatedPixels = bShowSaturatedPixels; }
	void setAutomaticRaw(bool bAutomaticRaw) { m_bAutomaticRaw = bAutomaticRaw; }
	void setAutomaticRLK(bool bAutomaticRLK) { m_bAutomaticRLK = bAutomaticRLK; }
	void setAutomaticMP4(bool bAutomaticMP4) { m_bAutomaticMP4 = bAutomaticMP4; }
	void setCamGain(double dCamGain) {m_dCamGain = dCamGain; }
	void setCamOffset(double dCamOffset) {m_dCamOffset = dCamOffset;}
	void setFPSWarnings(bool bState) { m_bFPSWarnings = bState; }
	void setSensiaNUC(bool bSensiaNUC) { m_bSensiaNUC = bSensiaNUC; }
	void setShowWindowTest(bool bShowWindowTest) { m_bShowWindowTest = bShowWindowTest; }
	void setSkip(int iSkip) { m_iSkip = iSkip; }
	void setMean(int iMean) { m_iMean = iMean; }
	void setWeightingFactors(bool bWeightingFactors){ m_bWeightingFactors = bWeightingFactors; }
	void setShowCurrentFrame(bool bShowCurrentFrame) { m_bShowCurrentFrame = bShowCurrentFrame; }
	void setShowSimulateName(bool bShowSimulateName) { m_bShowSimulateName = bShowSimulateName; }
	void setDummy(bool bDummy){ m_bIsDummy = bDummy;}
	bool getVerticalFlip() { return m_bVerticalFlip; }
	bool getHorizontalFlip() { return m_bHorizontalFlip; }
	bool getImageRotate() { return m_bImageRotate; }
	bool getPaletteBar() { return m_bPaletteBar; }
	bool getStretching() { return m_bStretching; }
	bool getAutoStretching() { return m_bAutoStretching; }
	bool getCameraRepeatedFrames() { return m_bCameraRepeatedFrames; }
	bool getShowROI() { return m_bShowROI; }
	bool getShowNOROI() { return m_bShowNOROI; }
	double getCamEmissivity() { return m_dCamEmissivity; }
	bool getEnableAll() {return m_bEnableAll;}
	bool getShowDititalLevels() {return m_bShowDigitalLevels;}
	bool getShowSaturatedPixels() { return m_bShowSaturatedPixels; }
	bool getAutomaticRaw() { return m_bAutomaticRaw; }
	bool getAutomaticRLK() { return m_bAutomaticRLK; }
	bool getAutomaticMP4() { return m_bAutomaticMP4; }
	double getCamGain() { return m_dCamGain; }
	double getCamOffset() { return m_dCamOffset; }
	bool getFPSWarnings() { return m_bFPSWarnings; }
	bool getSensiaNUC() { return m_bSensiaNUC; }
	bool getShowWindowTest() { return m_bShowWindowTest; }
	int getSkip() { return m_iSkip; }
	int getMean() {return m_iMean; }
	bool getWeightingFactors(){ return m_bWeightingFactors; }
	bool getShowCurrentFrame(){ return m_bShowCurrentFrame; }
	bool getShowSimulateName(){ return m_bShowSimulateName; }
	bool getDummy(){ return m_bIsDummy; }
	void setEmailAlert(bool bEmailAlert) { m_bEmailAlert = bEmailAlert; }
	bool getEmailAlert() { return m_bEmailAlert; }
	char *getConnectionPhidget() { return m_szConnectionPhidget; }
	void setConnectionPhidget(QString sConnectionPhidget) { strcpy_s(m_szConnectionPhidget,sConnectionPhidget.toStdString().c_str()); }
	int getRelayPort() { return m_iRelayPort; }
	void setRelayPort(int iRelayPort) { m_iRelayPort = iRelayPort; }
	int getStepperPort() { return m_iStepperPort; }
	void setStepperPort(int iStepperPort) { m_iStepperPort = iStepperPort; }
	int getSensorPort() { return m_iSensorPort; }
	void setSensorPort(int iSensorPort) { m_iSensorPort = iSensorPort; }
	int getShutterMaxPos() { return m_iShutterMaxPos; }
	void setShutterMaxPos(int iShutterMaxPos) { m_iShutterMaxPos = iShutterMaxPos; }
	int getShutterMinPos() { return m_iShutterMinPos; }
	void setShutterMinPos(int iShutterMinPos) { m_iShutterMinPos = iShutterMinPos; }
	bool getHasShutter() { return m_bHasShutter; }
	void setHasShutter(bool bHasShutter) { m_bHasShutter = bHasShutter; }
	int getNucSecondsBetweenAutomatic() { return m_iNucSecondsBetweenAutomatic; }
	void setNucSecondsBetweenAutomatic(int iNucSecondsBetweenAutomatic) { m_iNucSecondsBetweenAutomatic = iNucSecondsBetweenAutomatic; }
	int getSecondsDelayClosedshutterImgnuc() { return m_iSecondsDelayClosedshutterImgnuc; }
	void setSecondsDelayClosedshutterImgnuc(int iSecondsDelayClosedshutterImgnuc) { m_iSecondsDelayClosedshutterImgnuc = iSecondsDelayClosedshutterImgnuc; }
	bool getCloseShutter() { return m_bCloseShutter; }
	void setCloseShutter(bool bCloseShutter) { m_bCloseShutter = bCloseShutter; }
	bool getPanAndTilt() { return m_bPanAndTilt; }
	void setPanAndTilt(bool bPanAndTilt) { m_bPanAndTilt = bPanAndTilt; }
	int getPanAndTiltCom() { return m_iPanAndTiltCom; }
	void setPanAndTiltCom(int iPanAndTiltCom) { m_iPanAndTiltCom = iPanAndTiltCom; }
	bool getPanAndTiltPelcoD() { return m_bPanAndTiltPelcoD; }
	void setPanAndTiltPelcoD(bool bPanAndTiltPelcoD) { m_bPanAndTiltPelcoD = bPanAndTiltPelcoD; }
	int getPanAndTiltID() { return m_iPanAndTiltID; }
	void setPanAndTiltID(int iPanAndTiltID) { m_iPanAndTiltID = iPanAndTiltID; }
	int getPanAndTiltSpeed() { return m_iPanAndTiltSpeed; }
	void setPanAndTiltSpeed(int iPanAndTiltSpeed) { m_iPanAndTiltSpeed = iPanAndTiltSpeed; }
	bool getPanInverted() { return m_bPanInverted; }
	void setPanInverted(bool bPanInverted) { m_bPanInverted = bPanInverted; }
	bool getTiltInverted() { return m_bTiltInverted; }
	void setTiltInverted(bool bTiltInverted) { m_bTiltInverted = bTiltInverted; }
	char *getTourActiveAutomatic() { return m_szTourActiveAutomatic; }
	void setTourActiveAutomatic(char * szTour) { strncpy_s(m_szTourActiveAutomatic, szTour,  CFG_MAX_SMALL_ID); }
	char *getPresetActiveAutomatic() { return m_szPresetActiveAutomatic; }
	void setPresetActiveAutomatic(char * szPreset) { strncpy_s(m_szPresetActiveAutomatic, szPreset,  CFG_MAX_SMALL_ID); }
	bool getHasSensorLens() { return m_bHasSensorLens; }
	void setHasSensorLens(bool bHasSensorLens) { m_bHasSensorLens = bHasSensorLens; }
	bool getHasPleoraExpansor() { return m_bHasPleoraExpansor; }
	void setHasPleoraExpansor(bool bHasPleoraExpansor) { m_bHasPleoraExpansor = bHasPleoraExpansor; }
	bool getHasMemorySPI() { return m_bHasMemorySPI; }
	void setHasMemorySPI(bool bHasMemorySPI) { m_bHasMemorySPI = bHasMemorySPI; }
	bool getHasCompass() { return m_bHasCompass; }
	void setHasCompass(bool bHasCompass) { m_bHasCompass = bHasCompass; }
	bool getAdamRelay() { return m_bAdamRelay; }
	void setAdamRelay(bool bAdamRelay) { m_bAdamRelay = bAdamRelay; }
	char *getAdamRelayIP() { return m_szAdamRelayIP; }
	void setAdamRelayIP(QString sAdamRelayIP) { strcpy_s(m_szAdamRelayIP,sAdamRelayIP.toStdString().c_str()); }
	int getAdamRelayPort() { return m_iAdamRelayPort; }
	void setAdamRelayPort(int iAdamRelayPort) { m_iAdamRelayPort = iAdamRelayPort; }
	int getMaxOperationTemperature() { return m_iMaxOperationTemperature; }
	void setMaxOperationTemperature(int iMaxOperationTemperature) { m_iMaxOperationTemperature = iMaxOperationTemperature; }
	void setPulseRelay(bool bPulseRelay) { m_bPulseRelay = bPulseRelay; }
	bool getPulseRelay() { return m_bPulseRelay; }
	void setPulseRelaySeconds(int iPulseRelaySeconds) { m_iPulseRelaySeconds = iPulseRelaySeconds; }
	int getPulseRelaySeconds() { return m_iPulseRelaySeconds; }
	bool getSwitchPOE() { return m_bSwitchPOE; }
	void setSwitchPOE(bool bSwitchPOE) { m_bSwitchPOE = bSwitchPOE; }
	char *getSwitchIP() { return m_szSwitchIP; }
	void setSwitchIP(QString sSwitchIP) { strcpy_s(m_szSwitchIP,sSwitchIP.toStdString().c_str()); }
	int getSwitchInterface() { return m_iSwitchInterface; }
	void setSwitchInterface(int iSwitchInterface) { m_iSwitchInterface = iSwitchInterface; }
	void setMaintenanceMode(bool bMaintenanceMode) { m_bMaintenanceMode = bMaintenanceMode; }
	bool getMaintenanceMode() { return m_bMaintenanceMode; }
	bool getAutoResetEnabled() { return m_bAutoResetEnabled; }
	void setAutoResetEnabled(bool bStatus) { m_bAutoResetEnabled = bStatus; }
	bool getResetPeriodicEnabled() { return m_bResetPeriodicEnabled; }
	void setResetPeriodicEnabled(bool bStatus) { m_bResetPeriodicEnabled = bStatus; }
	bool getResetPunctualEnabled() { return m_bResetPunctualEnabled; }
	void setResetPunctualEnabled(bool bStatus) { m_bResetPunctualEnabled = bStatus; }
	char *getResetUnits() { return m_szResetUnits; }
	void setResetUnits(char *szResetUnits) { strcpy_s(m_szResetUnits, szResetUnits); }
	int getResetUnitsValue() { return m_iResetUnitsValue; }
	void setResetUnitsValue(int iResetUnitsValue) { m_iResetUnitsValue = iResetUnitsValue; }
	char *getResetDateTime() { return m_szResetDateTime; }
	void setResetDateTime(char *szResetDateTime) { strcpy_s(m_szResetDateTime, szResetDateTime); }
	char *getResetPeriodicDateTime() { return m_szResetPeriodicDateTime; }
	void setResetPeriodicDateTime(char *szResetPeriodicDateTime) { strcpy_s(m_szResetPeriodicDateTime, szResetPeriodicDateTime); }
	void setCurrentPreset(int iCurrentPreset) { m_iCurrentPreset = iCurrentPreset; }
	int getCurrentPreset() { return m_iCurrentPreset; }
	void setCurrentTour(int iCurrentTour) { m_iCurrentTour = iCurrentTour; }
	int getCurrentTour() { return m_iCurrentTour; }
	double getGlobalTemp() { return m_dMediaTemp; }
	void setGlobalTemp(double dTempFever, int numberSamples, int idRoi);
	void setGeolocation(char *sGeolocation) { strcpy_s(m_sGeolocation, sGeolocation); }
	char *getGeolocation() { return m_sGeolocation; }
	void setCameraBand(char *sCameraBand) { strcpy_s(m_szCameraBand, sCameraBand); }
	char *getCameraBand() { return m_szCameraBand; }
	/* Smart camera periodic cleaner */
	void setPeriodicUnitsValue(int iPeriodicUnitsValue) { m_iPeriodicUnitsValue = iPeriodicUnitsValue; }
	int getPeriodicUnitsValue() { return m_iPeriodicUnitsValue; }
	void setPeriodicUnits(char *sPeriodicUnits) { strcpy_s(m_szPeriodicUnits, sPeriodicUnits); }
	char *getPeriodicUnits() { return m_szPeriodicUnits; }
	void setPeriodicPunctual(bool bPeriodicPunctual) { m_bPeriodicPunctual = bPeriodicPunctual; }
	bool getPeriodicPunctual() { return m_bPeriodicPunctual; }
	void setPeriodicRepeat(bool bPeriodicRepeat) { m_bPeriodicRepeat = bPeriodicRepeat; }
	bool getPeriodicRepeat() { return m_bPeriodicRepeat; }
	void setPeriodicDeleteAt(bool bPeriodicDeleteAt) { m_bPeriodicDeleteAt = bPeriodicDeleteAt; }
	bool getPeriodicDeleteAt() { return m_bPeriodicDeleteAt; }
	void setPeriodicDeleteAtActive(bool bPeriodicDeleteAtActive) { m_bPeriodicDeleteAtActive = bPeriodicDeleteAtActive; }
	bool getPeriodicDeleteAtActive() { return m_bPeriodicDeleteAtActive; }
	void setPeriodicDeleteAtTime(char *sPeriodicDeleteAtTime) { strcpy_s(m_szPeriodicDeleteAtTime, sPeriodicDeleteAtTime); }
	char *getPeriodicDeleteAtTime() { return m_szPeriodicDeleteAtTime; }
	void setPeriodicNextCheckTime(char *sNextCheckTime) { strcpy_s(m_szNextCheckTime, sNextCheckTime); }
	char *getPeriodicNextCheckTime() { return m_szNextCheckTime; }

	##################################################
	################## Distributed ###################
	##################################################

	int getFocalLength() { return m_iFocalLength; }
	int getPixelPitch() { return m_iPixelPitch; }
	void setFocalLength(int iFocalLength) { m_iFocalLength = iFocalLength; }
	void setPixelPitch(int iPixelPitch) { m_iPixelPitch = iPixelPitch; }
	void setStretchingRegion(bool bStretchingRegion) { m_bStretchingRegion = bStretchingRegion; }
	void setRegionSize(int iRegionSize) { m_iRegionSize = iRegionSize; }
	bool getStretchingRegion() { return m_bStretchingRegion; }
	int getRegionSize() { return m_iRegionSize; }
	void setTourActiveAutomatic(char * szTour) { STRNCPY(m_szTourActiveAutomatic, szTour,  CFG_MAX_SMALL_ID); }
	void setPresetActiveAutomatic(char * szPreset) { STRNCPY(m_szPresetActiveAutomatic, szPreset,  CFG_MAX_SMALL_ID); }
	/* PRESET LIMITS */
	void setPTLimitTiltUp(int iPTLimitTiltTop) { m_iPTLimitTiltTop = iPTLimitTiltTop; }
	int getPTLimitTiltUp() { return m_iPTLimitTiltTop; }
	void setPTLimitTiltBottom(int iPTLimitTiltBottom) { m_iPTLimitTiltBottom = iPTLimitTiltBottom; }
	int getPTLimitTiltBottom() { return m_iPTLimitTiltBottom; }
	void setPTLimitPanLeft(int iPTLimitPanLeft) { m_iPTLimitPanLeft = iPTLimitPanLeft; }
	int getPTLimitPanLeft() { return m_iPTLimitPanLeft; }
	void setPTLimitPanRight(int iPTLimitPanRight) { m_iPTLimitPanRight = iPTLimitPanRight; }
	int getPTLimitPanRight() { return m_iPTLimitPanRight; }
	bool copyBakToCam(std::string sPathCam);
	bool copyCamToBak(std::string sPathCam);

	##################################################
	#################### Analytics ###################
	##################################################

	EnumConfigCameraMode getConfigCameraMode() { return m_eConfigCameraMode; }
	void setConfigCameramode(EnumConfigCameraMode eConfigCameraMode) { m_eConfigCameraMode = eConfigCameraMode; }
	void setConnectionChain(QString sConnectionChain) { strcpy_s(m_szConnectionChain,sConnectionChain.toStdString().c_str()); }
	bool getElectronicOld() { return m_bElectronicOld; }
	void setElectronicOld(bool bElectronicOld) { m_bElectronicOld=bElectronicOld; }
	char *getFuel() { return m_sFuel; }
	void setFuel(char *sFuel) { strcpy_s(m_sFuel, sFuel); }
	void setPlaybackSpeed(char *sPlaybackSpeed) { strcpy_s(m_szPlaybackSpeed, sPlaybackSpeed); }
	char *getPlaybackSpeed() { return m_szPlaybackSpeed; }
	void setCCTVAccessControl(bool bCCTVAccesControl) { m_bCCTVAccessControl = bCCTVAccesControl; }
	void setPaletteBar(bool bPaletteBar) { m_bPaletteBar = bPaletteBar; }
	void setShowDigitalLevels(bool bShowDigitalLevels) { m_bShowDigitalLevels = bShowDigitalLevels; }
	void setShowSaturatedPixels(bool bShowSaturatedPixels) { m_bShowSaturatedPixels = bShowSaturatedPixels; }
	void setEmail(char *szEmail) { strcpy_s(m_szEmail, szEmail); }
	void setEmailCC(char *szEmailCC) { strcpy_s(m_szEmailCC, szEmailCC); }
	void setEmailSendAll(bool bEmailSendAll) { m_bEmailSendAll = bEmailSendAll; }
	char *getEmail() { return m_szEmail; }
	char *getEmailCC() { return m_szEmailCC; }
	bool getEmailSendAll() { return m_bEmailSendAll; }
	bool getHasSensorTemperature() { return m_bHasSensorTemperature; }
	void setHasSensorTemperature(bool bHasSensorTemperature) { m_bHasSensorTemperature = bHasSensorTemperature; }
	void setThresholdCO(double dThresholdCO) { m_dThresholdCO = dThresholdCO; }
	double getThresholdCO() { return m_dThresholdCO; }
	void setThresholdNOx(double dThresholdNOx) { m_dThresholdNOx = dThresholdNOx; }
	double getThresholdNOx() { return m_dThresholdNOx; }
	void setThresholdHC(double dThresholdHC) { m_dThresholdHC = dThresholdHC; }
	double getThresholdHC() { return m_dThresholdHC; }
	void setThresholdOpacity(double dThresholdOpacity) { m_dThresholdOpacity = dThresholdOpacity; }
	double getThresholdOpacity() { return m_dThresholdOpacity; }
	void setDumpCO2(bool bDumpCO2) { m_bDumpCO2 = bDumpCO2; }
	bool getDumpCO2() { return m_bDumpCO2; }
	void setDumpCO(bool bDumpCO) { m_bDumpCO = bDumpCO; }
	bool getDumpCO() { return m_bDumpCO; }
	void setDumpNOx(bool bDumpNOx) { m_bDumpNOx = bDumpNOx; }
	bool getDumpNOx() { return m_bDumpNOx; }
	void setDumpHC(bool bDumpHC) { m_bDumpHC = bDumpHC; }
	bool getDumpHC() { return m_bDumpHC; }
	void setDumpOpacity(bool bDumpOpacity) { m_bDumpOpacity = bDumpOpacity; }
	bool getDumpOpacity() { return m_bDumpOpacity; }
	double getTHLocalMinCO2() { return m_dTHLocalMinCO2; }
	double getTHLocalMinCO() { return m_dTHLocalMinCO; }
	double getTHLocalMinHC() { return m_dTHLocalMinHC; }
	double getTHLocalMinNOx() { return m_dTHLocalMinNOx; }
	double getTHLocalMinOpacity() { return m_dTHLocalMinOpacity; }
	void setTHLocalMinCO2(double dTHLocalMinCO2) { m_dTHLocalMinCO2 = dTHLocalMinCO2; }
	void setTHLocalMinCO(double dTHLocalMinCO) { m_dTHLocalMinCO = dTHLocalMinCO; }
	void setTHLocalMinHC(double dTHLocalMinHC) { m_dTHLocalMinHC = dTHLocalMinHC; }
	void setTHLocalMinNOx(double dTHLocalMinNOx) { m_dTHLocalMinNOx = dTHLocalMinNOx; }
	void setTHLocalMinOpacity(double dTHLocalMinOpacity) { m_dTHLocalMinOpacity = dTHLocalMinOpacity; }
	double getWaitTime() { return m_dWaitTime; }
	void setWaitTime(double dWaitTime) { m_dWaitTime = dWaitTime; }
	int getVariationThreshold() { return m_iVariationThreshold; }
	void setVariationThreshold(int iVariationThreshold) { m_iVariationThreshold = iVariationThreshold; }
	int getKernelCO2() { return m_iKernelCO2; }
	void setKernelCO2(int iKernelCO2) { m_iKernelCO2 = iKernelCO2; }
	int getKernelCO() { return m_iKernelCO; }
	void setKernelCO(int iKernelCO) { m_iKernelCO = iKernelCO; }
	int getKernelHC() { return m_iKernelHC; }
	void setKernelHC(int iKernelHC) { m_iKernelHC = iKernelHC; }
	int getKernelNOx() { return m_iKernelNOx; }
	void setKernelNOx(int iKernelNOx) { m_iKernelNOx = iKernelNOx; }
	int getKernelOpacity() { return m_iKernelOpacity; }
	void setKernelOpacity(int iKernelOpacity) { m_iKernelOpacity = iKernelOpacity; }
	double getAbsorbanceCO2() { return m_dAbsorbanceCO2; }
	void setAbsorbanceCO2(double dAbsorbanceCO2) { m_dAbsorbanceCO2 = dAbsorbanceCO2; }
	double getAbsorbanceCO() { return m_dAbsorbanceCO; }
	void setAbsorbanceCO(double dAbsorbanceCO) { m_dAbsorbanceCO = dAbsorbanceCO; }
	double getAbsorbanceHC() { return m_dAbsorbanceHC; }
	void setAbsorbanceHC(double dAbsorbanceHC) { m_dAbsorbanceHC = dAbsorbanceHC; }
	double getAbsorbanceNOx() { return m_dAbsorbanceNOx; }
	void setAbsorbanceNOx(double dAbsorbanceNOx) { m_dAbsorbanceNOx = dAbsorbanceNOx; }
	double getAbsorbanceOpacity() { return m_dAbsorbanceOpacity; }
	void setAbsorbanceOpacity(double dAbsorbanceOpacity) { m_dAbsorbanceOpacity = dAbsorbanceOpacity; }
	int getOffset() { return m_iOffset; }
	void setOffset(int iOffset) { m_iOffset = iOffset; }
	int getOCRPort() { return m_iOCRPort; }
	void setOCRPort(int iOCRPort) { m_iOCRPort = iOCRPort; }
	bool getOCR() { return m_bOCR; }
	void setOCR(bool bOCR) { m_bOCR = bOCR; }
	void setUnits(char *szUnits) { strcpy_s(m_szUnits, szUnits); }
	char *getUnits() { return m_szUnits; }
	void setTarjetGas(char *szTarjetGas) { strcpy_s(m_szTarjetGas, szTarjetGas); }
	char *getTarjetGas() { return m_szTarjetGas; }
	void setCorrectionFactor(double dCorrectionFactor) { m_dCorrectionFactor = dCorrectionFactor; }
	double getCorrectionFactor() { return m_dCorrectionFactor; }
	void setOpticalSize(char *szOpticalSize) { strcpy_s(m_szOpticalSize, szOpticalSize); }
	char *getOpticalSize() { return m_szOpticalSize; }
	void setSensitivity(char *szSensitivity) { strcpy_s(m_szSensitivity, szSensitivity); }
	char *getSensitivity() { return m_szSensitivity; }
	void setLambda1(double dLambda1) { m_dLambda1 = dLambda1; }
	double getLambda1() { return m_dLambda1; }
	void setLambda2(double dLambda2) { m_dLambda2 = dLambda2; }
	double getLambda2() { return m_dLambda2; }
	void setGasAbsorption(bool bGasAbsorption) { m_bGasAbsorption = bGasAbsorption; }
	bool getGasAbsorption() { return m_bGasAbsorption; }
	void setGasEmission(bool bGasEmission) { m_bGasEmission = bGasEmission; }
	bool getGasEmission() { return m_bGasEmission; }
	void setEdgeRemove(bool bEdgeRemove) { m_bEdgeRemove = bEdgeRemove; }
	bool getEdgeRemove() { return m_bEdgeRemove; }

	##################################################
	###################### Lite ######################
	##################################################

	int getTamVectorData() { return m_iTamVectorData; }
	void setTamVectorData(int iTamVectorData) { m_iTamVectorData = iTamVectorData; }
	int getTFrame() { return m_iTFrame; }
	void setTFrame(int iTFrame) { m_iTFrame = iTFrame; }
	bool getImageRotate(){ return m_bImageRotate;}
	void setImageRotate(bool bImageRotate) {m_bImageRotate = bImageRotate;}
	int getMean() { return m_iMean; }
	int getWindowSize() { return m_iWindowSize; }
	void setWindowSize(int iWindowSize) { m_iWindowSize = iWindowSize; }
	int getSizeClaheSkip() { return m_iSizeClaheSkip; }
	void setSizeClaheSkip(int iSizeClaheSkip) { m_iSizeClaheSkip = iSizeClaheSkip; }
	int getSizeClaheEnhanced() { return m_iSizeClaheEnhanced; }
	void setSizeClaheEnhanced(int iSizeClaheEnhanced) { m_iSizeClaheEnhanced = iSizeClaheEnhanced; }
	int getSizeClahe() { return m_iSizeClahe; }
	void setSizeClahe(int iSizeClahe) { m_iSizeClahe = iSizeClahe; }
	double getClipClaheSkip() { return m_dClipClaheSkip; }
	void setClipClaheSkip(double dClipClaheSkip) { m_dClipClaheSkip = dClipClaheSkip; }
	double getClipClaheEnhanced() { return m_dClipClaheEnhanced; }
	void setClipClaheEnhanced(double dClipClaheEnhanced) { m_dClipClaheEnhanced = dClipClaheEnhanced; }
	double getClipClahe() { return m_dClipClahe; }
	void setClipClahe(double dClipClahe) { m_dClipClahe = dClipClahe; }
	char *getDeviceSerialNumber() {return m_sDeviceSerialNumber;}
	void setDeviceSerialNumber(char *sDeviceSerialNumber) {strcpy_s(m_sDeviceSerialNumber, sDeviceSerialNumber);}
	float getFactorMeanPond() { return m_fFactorMeanPond; }
	void setFactorMeanPond(float fFactorMeanPond) { m_fFactorMeanPond = fFactorMeanPond; }
	void setDistanceUnits(char *szDistanceUnits) { strcpy_s(m_szDistanceUnits, szDistanceUnits); }
	char *getDistanceUnits() { return m_szDistanceUnits; }
	void setLeakDistance(double iLeakDistance) { m_iLeakDistance = iLeakDistance; }
	double getLeakDistance() { return m_iLeakDistance; }
	void setMinFlowRate(double dMinFlowRate) { m_dMinFlowRateLimit = dMinFlowRate; }
	double getMinFlowRate() {return m_dMinFlowRateLimit; }
	void setMaxFlowRate(double dMaxFlowRate) { m_dMaxFlowRateLimit = dMaxFlowRate; }
	double getMaxFlowRate() {return m_dMaxFlowRateLimit; }
	void setTemperatureUnits(char *szTemperatureUnits) { strcpy_s(m_szTemperatureUnits, szTemperatureUnits); }
	char *getTemperatureUnits() { return m_szTemperatureUnits; }
	void setAmbientTemperature(double dAmbientTemperature) { m_dAmbientTemperature = dAmbientTemperature; }
	double getAmbientTemperature() { return m_dAmbientTemperature; }
	void setHR(int iHR) { m_iHR = iHR; }
	int getHR() { return m_iHR; }
	void setGasTemperature(double dGasTemperature) { m_dGasTemperature = dGasTemperature; }
	double getGasTemperature() { return m_dGasTemperature; }
	void setDensityUnits(char *szDensityUnits) { strcpy_s(m_szDensityUnits, szDensityUnits); }
	char *getDensityUnits() { return m_szDensityUnits; }
	void setGasDensity(double dGasDensity) { m_dGasDensity = dGasDensity; }
	double getGasDensity() { return m_dGasDensity; }
	void setQSensitivity(char *szSensitivity) { strcpy_s(m_szSensitivity, szSensitivity); }
	char *getQSensitivity() { return m_szSensitivity; }

};