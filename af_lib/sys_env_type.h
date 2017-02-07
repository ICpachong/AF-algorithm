/* ===========================================================================
* @path $(IPNCPATH)\include
*
* @desc
* .
* Copyright (c) Appro Photoelectron Inc.  2008
*
* Use of this software is controlled by the terms and conditions found
* in the license agreement under which this software has been supplied
*
* =========================================================================== */
/**
* @file sys_env_type.h
* @brief System evironment structure and Global definition.
*/
#ifndef __SYS_ENV_TYPE_H__
#define __SYS_ENV_TYPE_H__

#include <asm/types.h>
#include <netinet/in.h>
#include <time.h>


#define MAGIC_NUM			0x9A9B000D 
#define REL_UNIQUE_ID 		(026000)		//�˽��Ʊ�ʾ
#define REL_UNIQUE_ID_1 	(0x3ff)
#define REL_UNIQUE_ID_2 	(0x400)


#define SYS_ENV_SIZE			sizeof(SysInfo)
#define SYS_ENV_SIZE0			sizeof(SysInfo_0)
#define SYS_ENV_SIZE1			sizeof(SysInfo_1)
#define SYS_ENV_SIZE2			sizeof(SysInfo_2)
#define SYS_ENV_SIZE_RES		32 * 1024
#define MAX_LOG_PAGE_NUM		40 
#define NUM_LOG_PER_PAGE		10
#define LOG_ENTRY_SIZE			sizeof(LogEntry_t)


#define MAX_DOMAIN_NAME			40 		///< Maximum length of domain name. Ex: www.xxx.com
#define MAX_LANCAM_TITLE_LEN	11 		///< Maximum length of LANCAM title.
#define OSDTEXTLEN				256
#define MAX_NAME_LENGTH			200 	///< Maximum length of normal string.
#define MAX_OSD_STREAMS			3 		///< Maximum length of normal string.
#define MAX_CODEC_STREAMS		3 		///< Maximum length of normal string.
#define MAX_STREAM_NAME			75  	///< Maximum length of normal string.
#define MAC_LENGTH				6 		///< Length of MAC address.
#define MAX_FILE_NAME			128		///< Maximum length of file name.

#define ACOUNT_NUM				16 		///< How many acounts which are stored in system.
#define USER_LEN				32 		///< Maximum of acount username length.
#define PASSWORD_LEN			32 		///< Maximum of acount password length. //old is 16 may short
#define SMTP_USER_LEN			64
#define SMTP_PASSWD_LEN		64
#define IP_STR_LEN				20		///< IP string length

#define MOTION_BLK_LEN			(8) 		///< Motion block size
#define MOTION_BLK_LEN_EX		(32) 	///< Motion block size

#define MAX_PRIVACYMASK_NUMS	12

/**
* @brief Infomation of network status and user settings.
*/
typedef struct
{
	struct in_addr		ip; 							///< IP address in static IP mode
	struct in_addr		netmask; 					///< netmask in static IP mode
	struct in_addr		gateway; 					///< gateway in static IP mode
	struct in_addr		dns; 						///< DNS IP in static IP mode
	__u16 			http_port; 					///< HTTP port in web site.
	__u16			rtsp_port; 					///< HTTP port in web site.
	int				dhcp_enable; 				///< current DHCP status.
	__u8 			ntp_enable;		
	char				ntp_server[MAX_DOMAIN_NAME+1]; 	///< NTP server FQDN
	__u8			ntp_timezone; 				///< current time zone
	__u8			time_format; 				///< time display format
	__u8			MAC[MAC_LENGTH]; 			///< hardware MAC address
	__u16       		mobileport;  					///< mobile port
	__u8        		ucOnvif_Enable;   		
	__u8 			Authentication;
	__u8 			NvrModifyTimeEnable;
	__u8 			wifi_dhcp_enable;
	struct in_addr		wifi_ip; 						///< IP address in static IP mode
	struct in_addr		wifi_netmask; 				///< netmask in static IP mode
	struct in_addr		wifi_gateway; 				///< gateway in static IP mode
	struct in_addr 	wifi_dns;					///< DNS IP in static IP mode			
	__u8			wifi_mac[MAC_LENGTH]; 		///< hardware MAC address
	__u8   			Wifi_ConnectStatus;			///0:disconnect 1:connect
	__u8 			ucRes1[1];
	__u16 			usHttps_Port;
	__u16 			usOnvif_Port;
	__u16 			usHkPrivate_Port;
	__u8			ucHkPrivate_Enable;
	__u8 			ucRes3[1];
	__u16 			usXmPrivate_Port;
	__u8			ucXmPrivate_Enable;
	__u8 			ucRes4[1];	
	
	char 			reserve[90]; 				
} Network_Config_Data;


/**
* @brief Infomation about ftp configuration.
*/
typedef struct
{
	__u8       bFtpEnable;						///< FTP enable
	char		servier_ip[MAX_DOMAIN_NAME+1]; 	///< FTP server address
	char		username[USER_LEN]; 				///< FTP login username
	char		password[PASSWORD_LEN]; 		///< FTP login password
	char		foldername[MAX_FILE_NAME];		///< FTP upload folder
	__u8	ucAnonymousEnable;				///< FTP Anonymous enable,0:not enable 1:enable 
	__u8      ucAutoCoverEnable;			      ///< FTP AutoCover enable,0:not enable 1:enable 
	__u8      ucFtptestStatus;				      /// 0:success 1:fail			
	__u8 	ucFtpUploadStatus;
	//int	image_acount; 				      ///< Image count
	int		pid; 							      ///< PID
	__u16	port; 						      ///< FTP port
	__u8       ftpfileformat; 				      ///< file format
} Ftp_Config_Data;


/**
* @brief Infomation about SMTP configuration.
*/
typedef struct
{
	__u8		bSmtpEnable;				///< SMTP enable
	char		servier_ip[MAX_DOMAIN_NAME+1]; 	///< SMTP server address
	__u16		server_port; 					///< SMTP server port
	char		username[SMTP_USER_LEN]; 		///< SMTP username
	char		password[SMTP_PASSWD_LEN]; 		///< SMTP password
	__u8		authentication; 				///< SMTP authentication
	char		sender_email[MAX_NAME_LENGTH]; 	///< sender E-mail address
	char		receiver_email[MAX_NAME_LENGTH]; ///< receiver E-mail address
	char		receiver_email1[100];				///< receiver E-mail address
	char		receiver_email2[100]; 				///< receiver E-mail address
	char		CC[MAX_NAME_LENGTH]; 			///< CC E-mail address
	char		subject[MAX_NAME_LENGTH]; 		///< mail subject
	char		text[MAX_NAME_LENGTH]; 			///< mail text
	__u8 	ucSmtpTestEnable;				/// 0:not enable 1:enable	
	__u8 	ucSmtpTestStatus;				/// 0:success 1:fail					
	//__u8		attachments; 					///< mail attachment
	//__u8		view; 						///< smtp view
	__u8		asmtpattach; 				///< attatched file numbers
	__u8       	attfileformat; 				///< attachment file format
} Smtp_Config_Data;


/**
* @brief Infomation about Cloud Storage configuration.
*/
typedef struct
{
	__u8       bCloudStorageEnable;			///< Cloud Storage enable
	__u8       CloudStorageFileFormat; 		///< file format
	__u8 	CloudStorageType;
	__u8 	ucRes[29];
	
} CloudStorage_Config_Data;


/**
* @brief IPCAM configuration data.
*/
typedef struct
{
	__u8		nBrightness;					///< brightness value
	__u8		nContrast;						///< contrast value
	__u8		nSaturation;					///< saturation value
	__u8		nSharpness;						///< sharpness value

	__u8		ircutswitchtime;
	__u8		agc;
	__u8		noisefilter;
	__u8		nWhiteBalance;					///< white balance mode, 0�Զ� 1�ֶ� 2:������ƽ�� 3:�չ�� 4:�׳�� 5:ů��� 6:��Ȼ�� 
	__u8		nMwbRgain;						///< manual white balance r gain
	__u8		nMwbGgain;						///< manual white balance g gain
	__u8		nMwbBgain;						///< manual white balance b gain

	__u8		nBacklightControl;				///< backlight control setting
	__u8		nBackLight;						///< backlight value
	__u8		imagesource; 					///< image source (NTSC/PAL)
	__u8 		irismode;
	__u8 		irisopen;
	__u8		ircutmode;
	__u8		night2day;
	__u8		irled;
	__u8		nElectronicShutter;
	__u8 		nExposureCtl;
	__u8		maxexposure;
	__u8		nWideDynamicEable;
	__u8		nWideDynamicLevel;
	__u8 		nDNRModel;
	__u8 		nDNR2DStrength;
	__u8		nDNR3DStrength;
	__u8		nDefogEnable;
	__u8        	nDefogMode;
	__u8        	nDefogStrength;
	__u8		nRotateAngle;
	__u8 		nSLInhibition;				 	 
	__u8		nSLInhibitionStreangth;			 
 
	__u8 		nStreamType;
	__u8		nVideocodecmode;				///< selected codec mode
	__u8		nEncodingType1;					///< selected encoding type, 0:jpeg 1:MPEG4 2:h264 3:h265 4:MJPEG
	__u8 		nEncodingType2; 
	__u8 		nEncodingType3;
	int			nFrameRate1;					///< MPEG4_1 frame rate
	int			nFrameRate2;					///< MPEG4_2 frame rate
	int			nFrameRate3;					///< JPEG frame rate
	unsigned long			nBitrate1;						///< MPEG4_1 bitrate
	unsigned long			nBitrate2;						///< MPEG4_2 bitrate
	unsigned long			nBitrate3;						///< MPEG4_3 bitrate
	__u8		nRateControl1;					///< stream1 bitrate control setting
	__u8		nRateControl2;					///< stream2 bitrate control setting
	__u8		nRateControl3;					///< stream3 bitrate control setting

	__u8		mirror; 						///< mirroring	0,off,  1,H  2,V 3both
	__u8		premirror; 						///< mirroring	0,off,  1,H  2,V 3both
	
	__u8		nImageQuality1;					///<	 image quality
	__u8		nImageQuality2;					///<	 image quality
	__u8		nImageQuality3;					///<	 image quality

	__u8 		nProfile1;						///0:baseline profile 1:main profile 2:high profile
	__u8 		nProfile2;
	__u8 		nProfile3;
	
	//__u8		Supportstream1;					///< support stream1 (JPEG)
	//__u8		Supportstream2;					///< support stream2 (MPEG4_1)
	//__u8		Supportstream3;					///< support stream3 (MPEG4_2)
	
	__u8		Supportstream4;					///< support stream4
	__u8		Supportstream5;					///< support stream5 (AVC_1)
	__u8		Supportstream6;					///< support stream6 (AVC_2)

	/*IO*/
	__u8		gioinenable;						///< GIO input enable
	__u8		giointype;						///< GIO input type,  0�͵�ƽ 1�ߵ�ƽ
	__u8		giooutenable;					///< GIO output enable
	__u8		gioouttype;						///< GIO output type, 0�͵�ƽ 1�ߵ�ƽ

    	__u8		ucElectronicAntiShakeEnable;  		//���ӷ���: 0:�ر� 1:ʹ��
    	
	//__u8		bSdaEnable;						///< alarm save into SD card
	__u8        	aviduration;						///< avi record duration
	__u8		aviformat;						///< avirecord format.
	__u8		chipConfig;
	__u8		nAlarmAudioFile; 			    		///< alarm audio file
	
	__u8		nDayNight;						///< Daynight mode
	__u8		nBinning;						///< binning/skipping setting
	__u8		linearwdr;
	__u8		nRateControl;					///< bitrate control setting

	__u8		nAEWswitch;						///< 2A engine selection
	__u8		AdvanceMode; 					///< video stabilization (ON/OFF)
	__u8		nAEWtype;						///< 2A engine selection

	__u8		maxgain;
	__u8        	dateposition;
	__u8        	timeposition;
	__u8		nAlarmAudioPlay; 			    ///< alarm audio play enable/disable
	__u8		daylight_time; 					///< daylight saving time mode
	__u8		imageformat; 					///< image format
	__u8		nPreRotateAngle; 				//add 20150303 
	__u8 		nHdrEnable;
	__u8 		reserve[510];
} Lancam_Config_Data;


/**
* @brief SD card configuration data.
*/
typedef struct
{
	__u8			sdfileformat;	///< file format saved into SD card
	__u8			sdrenable;		///< enable SD card recording
	__u8			sdinsert;		///< SD card inserted
	__u8			sdstrategy;   	///< SD strategy      
	__u8			sdmaxsize;  	///< SD  avi file  maxsize
}Sdcard_Config_Data;


/**
* @brief IPCAM user account data.
*/
typedef struct
{
	char		user[USER_LEN];				///< username
	char		password[PASSWORD_LEN];		///< password
	int	authority;							///< user authority
}Acount_t;


/**
* @brief motion detection configuration data.
*/
typedef struct
{
	__u8      		motionenable;				///< motion detection enable
	__u8      		motioncenable;				///< customized sensitivity enable
	__u8      		motionlevel;					///< predefined sensitivity level
	__u8      		motioncvalue;				///< customized sensitivity value
	__u8		motionblock[MOTION_BLK_LEN];	///< motion detection block data
	unsigned long motionblockEx[MOTION_BLK_LEN_EX];
	//char 		reserve[128];
}Motion_Config_Data;


typedef struct
{
	__u8	maskenable;
	unsigned long 	x1[MAX_PRIVACYMASK_NUMS];
	unsigned long		y1[MAX_PRIVACYMASK_NUMS];
	unsigned long		x2[MAX_PRIVACYMASK_NUMS];
	unsigned long		y2[MAX_PRIVACYMASK_NUMS];
}PrivacyMask_Config_Data;

typedef struct
{
	__u8 x;
	__u8 y;
}POINT_T;

typedef struct
{
	POINT_T pos[4];
}REGION_T;

typedef struct
{
	__u8      		audioenable;									
	__u8		codectype;
	__u8      		samplerate;						
	__u8      		bitrate;						
	__u32     	bitrateValue;					
	__u8		audioinvolume;
	__u8		audiooutvolume;
	__u8 		audioInputMode;
	__u8      		audiorecvenable;    			
	__u8      		audioServerIp[MAX_NAME_LENGTH];  
}Audio_Config_Data;

typedef struct
{
	__u8		dateformat;
	__u8		nTimeEnable;				///< time  enable (ON/OFF)
	__u8		nTimePosition;   				///< time position
	__u8		nTextEnable;					///< text enable (ON/OFF)
	__u8		nTextPosition;   				///< text position
	__u8		overlaytext[OSDTEXTLEN];		///< osd text name
}OSD_config;

typedef struct
{
	__u32 		ipRatio;
	__u8 		fIframe;
	__u8 		qpInit;
	__u8 		qpMin;
	__u8 		qpMax;
	__u8 		meConfig;
	__u8 		packetSize;
	__u8 		unkown1;
	__u8 		unkown2;
}CodecAdvParam;


typedef struct
{
  __u16     	width;
  __u16     	height;
  __u16			portnum;
  __u8			name[MAX_STREAM_NAME];
  __u8 			portname[MAX_STREAM_NAME];
  __u8 			iEnable;
}StreamParam;


/*ptz ��������*/
typedef struct 
{
	unsigned char ucAddr;                	/*��ַλ*/
	unsigned char ucDataBit;            	/*����λ*/
	unsigned char ucStopBit;            	/*ֹͣλ*/
	unsigned char ucCheckType;       	/*��������*/
	unsigned char ucProtocol;          	/*Э��*/
	unsigned char ucRes1[2];       		/*����1*/
	unsigned long ulBaudRate;			/*������*/
}Ptz_Serial_Config;


/**
* @brief PTZ configuration data.
*/
typedef struct
{
  	__u8 		ucFocusMode;     
	__u8 		ucZoomPos; 
   	__u8  		ucApertureMode;   	/*��Ȧģʽ  0�Զ�  1����*/
   	__u8  		ucApertureVal;    		/*��Ȧ���� 0-100 (�ڹ�ȦģʽΪ���Ƶ��������Ч)*/
      __u8 		ucStep;				/*�ٶ�*/
	__u8 		reserve[3];
	__u32       	uiZoomPosReal;
	__u8 		reserve1[4];
	Ptz_Serial_Config ptz_serial;
	__u8 		ucRes[36];
}Ptz_Config_Data;   //64


/*
@ weblanguage
*/
typedef struct
{
	char		language[32];	///< zoom-in
}Ipnc_web_language;


/**
* @brief event log data structure.
*/
typedef struct LogEntry_t{
	char 			event[100];	///< event description
	struct tm 	time;		///< event log time
}LogEntry_t;


/**
* @brief user settings structure.
*/
typedef struct{
	char 		id[USER_LEN];
	char 		password[PASSWORD_LEN];
	char 		remote_ip[IP_STR_LEN];
}login_data_t;


#if 1
typedef struct{
	char 		user_id[USER_LEN];
	int  		authority;
}get_user_authority_t;


typedef struct{
	char		user_id[USER_LEN];
	char		password[PASSWORD_LEN];
	__u8		authority;
}add_user_t;
#endif

/*DDNS*/
typedef struct{
	unsigned long 	enable;
	unsigned long 	type;	//ddns service type
	char 			user[32];
	char 			pwd[32];
	char 			site[32];	
}Ddns_Config_Data;


/*HTTP*/
typedef struct{
	int 		cmd;
	int 		internalport;
	int 		externalport;
}Http_Config_Data;


typedef struct 
{
	__u32 	update_interval;
	char 	device_id[16];
	char 	update_server[IP_STR_LEN];
	__u16 	update_port;

	__u8 	pppoe_enable;
	char 	pppoe_account[32];
	char 	pppoe_password[32];
	__u8 	pppoe_status;
	__u8 	pppoe_ip[32];
}HY_Config_Data;


typedef struct
{
	__u8 	freeptopenable;
	__u32  	maxwaitmsfreep2p;	
	char 	freeptopserverip[32];
	char 	freeptopsn[32];
	char 	freeptopiosapp[128];
	char 	freeptopandroidapp[128];

	__u8 	ucFreeIpRegion;			
	__u8 	ucRes[295];	
}P2P_Config_Data;


/**
* @brief custom data structure for time.
*/
typedef struct{
	__u8		nHour;	///< Hour from 0 to 23.
	__u8		nMin;	///< Minute from 0 to 59.
	__u8		nSec;	///< Second from 0 to 59.
} Time_t;


//�Զ�ά��
typedef struct
{
	__u8	AutoRebootEnable;
	__u8	Day;
	Time_t	Time;	
}AutoMainTain_Config_Data;


typedef struct 
{
	unsigned char ucEnable;                 	/*�Ƿ�����ʱ����, 0�ر�, 1����*/
  	unsigned char ucRebootModel;	    	/*����ģʽ, 0ÿ��, 1ÿ��, 2ÿ��*/
	unsigned char ucDay;			    	/*����ʱ��, ��λ��*/ 
	unsigned char ucHour;                   	/*����ʱ��, ��λʱ*/
	unsigned char ucMinute;		    	/*����ʱ��, ��λ��*/
	unsigned char ucSecond;                  /*����ʱ��, ��λ��*/
	unsigned char ucWeekData;             /*0-6 �ֱ�Ϊ�����쵽������*/
	unsigned char ucRes[25];			/*����*/
}AutoReboot_Config_Data;


//��������
typedef struct 
{
	__u8   	nAlarmEnable;                   	///< alarm enable/disable setting
	__u16	alarmstatus;					///< Current alarm status.
	__u8	nAlarmDuration;				///< alarm duration
	__u8   	lostalarm;					///< ethernet lost alarm
	__u8	nExtAlarm; 			            	///< external trigger alarm
	char		SnapshotPath[MAX_FILE_NAME]; 	///< recordpath path
	char		recordpath[MAX_FILE_NAME]; 		///< record path
	__u8 	nAlarmType;					///0:none 1:IO 2:motion
}Alarm_Config_Data;


//���Ҳ���
typedef struct
{
    	char		strDevName[32];            	//�豸����
	char		strFactoryName[32];		   	//��������
	char		strHardVer[64];			   	//�̼��汾��
	char		strSoftVer[64];			   	//����汾��
}Factory_config_Data;


/*���νṹ��*/
typedef struct {
    unsigned long x1;                 /*���Ͻ�x����*/
    unsigned long y1;                 /*���Ͻ�y����*/
    unsigned long x2;                 /*���½�x����*/
    unsigned long y2;                 /*���½�y����*/
}ROI_RECT;

typedef struct {
	ROI_RECT      area;               /*�ٷֱ�����*/
	unsigned char ucQpType;       /*QP����: ��д ROI_QP_TYPE*/
	char cQpVal;             		/*QP��ֵ: ���ģʽ����[-51,51] ����ģʽ����[0,51]*/
	unsigned char ucEnbale;           /*ʹ��: 0�ر� 1��*/
	unsigned char ucRes[1];         /*����*/
}ROI_Region;

typedef struct {
    unsigned char ucCh;                 /*ͨ��*/
    unsigned char ucEnable;           /*0�ر�RIO, 1����ROI*/
    unsigned char ucBgFrameRate;      /*����֡��: 0�رձ���֡��, 1-255��ֵΪ����֡��.����������֡��*/
    ROI_Region    region[8];
    unsigned char ucRes2[16];         /*����2*/
}ROI_Config_data;


typedef struct {
	unsigned char  ucViewType;    /*�����������: 0�ü� 1ȫģʽ*/
	long  	lCenterXOffset;		    /*�������ĵ����ͼ�����ĵ�ˮƽƫ��: -75��75*/
	long  	lCenterYOffset;		    /*�������ĵ����ͼ�����ĵ㴹ֱƫ��: -75��75*/
	unsigned long  ulRatio;           /*����̶�: 0-511*/
}LDC_Config_data;


typedef struct {
	unsigned char  ucMonth;                /*��*/
	unsigned char  ucDay;                  /*��*/
	unsigned char  ucHour;                 /*ʱ*/
	unsigned char  ucweekDay;                  /*��*/
	unsigned char  ucWeekNumber;          /*�����*/
	unsigned char  ucRes[16];               /*����*/
 
}DST_Property;


typedef struct {    
	unsigned char  ucEnDST;                /*DST����, 1���� 0�ر�*/	
	unsigned char  ucDSTType;                /*DSTģʽ, 0����  1��*/
	DST_Property ucDSTStart;              /*��ʼʱ��*/	
	DST_Property ucDSTEnd;              /*����ʱ��*/	
	unsigned char  offsetTime;          /*ƫ��ʱ�䣬Ĭ��Ϊһ��Сʱ*/
	unsigned char  ucRes[16];               /*����*/
}DST_Config_Data;


typedef enum 
{
	SCOPE_NULL       = 0,                  /*��ʱ���*/
	SCOPE_ALL,                             /*ȫ��ʱ���*/
	SCOPE_SAME,                            /*����һ��ʱ���*/
	SCOPE_DIFF,                            /*��ÿ������ʱ���*/
}Scope_Mode;

typedef struct 
{
	unsigned char   ucHour;               /*ʱ: 0-23*/
	unsigned char   ucMinute;             /*��: 0-59*/
	unsigned char   ucSecond;             /*��: 0-59*/
	unsigned char   ucRes[1];             /*����*/
}Hour_Info;

typedef struct 
{
	Hour_Info  beginHour;
	Hour_Info  endHour;
}Hour_Scope;


/*��Сʱ��Χ*/
typedef struct
{
    unsigned char         ucSocpeMode;          /*ʱ��ģʽ*/
    unsigned char         ucRes1[3];            	   /*����*/
    Hour_Scope            hourScope[6];         /*һ�������6��ʱ��*/
}Day_Hour_Scope;


/*��ʱ���*/
typedef struct
{
	Day_Hour_Scope   dayScope[7];          /*һ��7��. 0��6 ��ʾ�����쵽������*/
}Week_Scope;


/*¼��洢*/
typedef struct 
{
	unsigned char     	ucEnable;               	 	/*�Ƿ�����¼��: 0�ر� 1����*/
	unsigned char     	ucStorageType;          	/*�洢ģʽ: ��д ARG_STORAGE_TYPE*/
	unsigned char		ucPackingModel;    	 	/*���ģʽ 0��ʱ�� 1����С 2��*/
	unsigned char 	ucPackingTime;     		/*���ʱ�� 0-255 ��λ����(��ʱ����ģʽ����Ч)*/

	unsigned char 	ucPackingSize;     		/*�����С 0-125M, 1-256M, 2-512M, 3-1G, 4-2G, 5-4G (����С���ģʽ����Ч)*/
	unsigned char 	ucLackSpaceModel; 	 	/*0 Ϊ������1Ϊ����*/
	unsigned char     	ucRes1[10];            	 	/*����*/
	Week_Scope       	weekScope;       	 		/*��ʱ��*/
}Record_Config_Data;


//////////////////////////////��Ƶ�����������//////////////////////////
#define	MAX_CODEC_CHANNEL	5
#define   MAX_CODEC_MODE		4

typedef struct 
{
	int width;
	int height;
}Resolution_Param;


typedef struct 
{
	int sizeResolutions;
	Resolution_Param Resolutions[5];
}Resoulution_Available_Param;


/*��Ƶ��������*/
typedef struct 
{
	unsigned char  ucEncodingType;      /*��Ƶ���� ��д (ARG_ENCODING_TYPE)����Ƶ����*/
	unsigned char  ucPicQuality;        /*ͼ������ 0-��� 1-�κ� 2-�Ϻ� 3-һ�� 4-�ϲ� 5-��*/
	unsigned char  ucStreamType;	/*��������: 0:������,1:������*/
	unsigned char  ucProfile;		/*���븴�Ӷ� 0-�� 1-�� 3-��*/

	unsigned short usWidth;             /*���*/
	unsigned short usHeight;            /*�߶�*/
	unsigned short ucFrameRate;     	/*֡��*/
	unsigned short ucBitRate;           /*���� ��λk byte(��B)*/

	unsigned char  ucKeyFrameInterval;  /* I֡���,(ucEncodingTypeΪh264ʱ��Ч)*/
	unsigned char  ucBitrateType;       /*�������� 0:�����ʣ�1:������*/

	unsigned char  ucVideoType;		/*��Ƶ����: 0:��Ƶ�� 1:������*/

	unsigned char  ucRes1[21];

	Resoulution_Available_Param ReSolution; /*�ֱ�����Чֵ*/
	
}Video_Encoding_Property;


typedef struct 
{
	unsigned char  ucCh;              /*ͨ���� ARG_CHANNEL_TYPE*/

	unsigned char  ucChStreamMode;    /*ͨ������ģʽ 0:������,1:˫����,2:������*/
	unsigned char  ucMaxFrameRate;
	unsigned char  ucMinFrameRate;
	unsigned char  ucEncodingScope;   /*��Ƶ����֧������,��д ARG_ENCODING_SCOPE_TYPE*/	 

	unsigned char  ucRes[11];

	Video_Encoding_Property  Video[3];	

}Encoding_Config_Data;


//////////////////////////////���۲�������//////////////////////////
typedef enum 
{
	STREAM_MODE_ONE = 0,          /*ģʽ1: ����+ȫ��+3*PTZ*/
	STREAM_MODE_TWO,     	      /*ģʽ2: ���ۻ���4*PTZ*/
	STREAM_MODE_THREE,     	      /*ģʽ3: ����������+����������+3PTZ*/
	STREAM_MODE_FOUR,   	      /*ģʽ4: ȫ��������+ȫ��������*/
}STREAM_MODE_TYPE;


typedef struct 
{
	unsigned char ucCh;

	unsigned char ucStreamMode;     	/*����ģʽ ��д ARG_STREAM_MODE_TYPE*/
	unsigned char ucInstallMode;		/*��װ��ʽ 0:ǽ�� 1:���� 2:����*/

	unsigned char ucRes[61];
}FishEye_Config_Data;


/////////////////////////////Ѳ����������//////////////////////////
#define	MAX_CHANNEL					4			/*���ͨ��*/
#define 	MAX_CRUISE_ROUTE 				32			/*���Ѳ��·��*/
#define 	MAX_CRUISE_ROUTE_PRESENT	16			/*ÿ��Ѳ��·�����Ԥ�õ���*/

#define 	MAX_CRUISE_POINT				256			/*���Ԥ�õ���*/


/*ptz ����*/
typedef struct 
{
	unsigned char ucCh;                 		/*ͨ��*/
	unsigned char ucOptType;            	/*��������: PTZ_OPTION_TYPE*/
	unsigned char ucRes1[2];           	 	/*����*/
	union{
		unsigned char ucPresetPointIndex;   /*Ԥ�õ����*/
		unsigned char ucCruiseLineIndex;    	/*Ѳ�������*/
	}opt;
}Ptz_Option;


//Ԥ�õ�����
typedef struct 
{
	unsigned char      ucEnable;            				/*�Ƿ�ʹ��,0:��ʹ�� 1:ʹ��*/
	unsigned char      ucRes[3];
	int      	            iPanPos;			
	int      	            iTiltPos;
	int 			     iZoomPos;
}Point_Param;


typedef struct 
{
	Point_Param 		point[MAX_CHANNEL][MAX_CRUISE_POINT];
}Preset_Point_Config_Data;


/*Ѳ�������*/
typedef struct 
{
	unsigned char      ucCh;                               /*ͨ����*/
	unsigned char      ucCruiseLineIndex;           /*Ѳ�������*/
	unsigned char      ucCruisePointIndex;         /*Ѳ�������*/
	unsigned char      ucRes1[1];                       /*����*/

	unsigned char      ucEnable;                         /*�Ƿ�ʹ��, 0��ʹ��, 1ʹ��*/
	unsigned char      ucPresetPointIndex;         /*Ԥ�õ����*/
	unsigned char      ucStep;                            /*�ٶȣ���Χ1~8��8����Ч��������,��������ƶ����¸�����ٶ�*/
	unsigned char      ucRes2[1];                        /*����*/
	unsigned long      ulDwelltime;                      /*ͣ��ʱ��: ��λ����, ���30����*/
	unsigned char      ucRes3[16];                       /*����*/
}Cruise_Point_Option;


/*Ѳ���߲���*/
typedef struct 
{
	unsigned char              ucCh;                                       					/*ͨ��*/
	unsigned char              ucIndex;                                    					/*Ѳ�������*/
	unsigned char              ucEnable;                                   					/*�Ƿ�����, 0����, 1������, ֻ��*/
	unsigned char              ucLineName[64];                		/*Ѳ��������*/
	Cruise_Point_Option      ucPoints[32];   	/*Ѳ�����±�, ��� 32 ��Ԥ�õ�*/
	unsigned char              ucRes1[16];                                 				/*����*/
}Cruise_Line_Option;


//Ѳ��������
typedef struct 
{
	int    		index; 				//Ԥ�õ����		
	unsigned char 	ucCruiseTime;
	unsigned char       	ucCruiseSpeed;
	unsigned char		ucEnable;
	unsigned char    	ucCruisePointIndex; 	//Ѳ�������	
}Cruise_Point_Param;


typedef struct 
{
	Cruise_Point_Param  cruise_point[MAX_CRUISE_ROUTE_PRESENT];
}Cruise_Route_Param;


typedef struct 
{
	Cruise_Route_Param   	cruise_route[MAX_CHANNEL][MAX_CRUISE_ROUTE];
}Cruise_Config_Data;


typedef struct
{
	unsigned char		ucCh;
	unsigned char		ucZoomPos;                      /*0-100 ����*/
	unsigned char 	ucRes[2];
	int				iPanpos;
	int 				iTiltPos;
	unsigned char		ucRes1[8];                          /*����*/
}Ptz_Info;


typedef struct 
{
	Ptz_Info			Info[MAX_CHANNEL];
}Ptz_Info_Config_Data;


typedef struct
{
	unsigned char 	ucCh;             /*ͨ��*/
	unsigned char 	ucRes[3];
	Ptz_Info_Config_Data 		Info_Config;
	Cruise_Config_Data		Cruise_Config;			//��̨Ѳ��·������
	Preset_Point_Config_Data	Preset_Point_Config;		//��̨Ԥ�õ�����
}Ptz_Config_Data_Ex;



typedef struct 
{
	unsigned char ucCh;
	unsigned char ucOsdNameVisiable;	/*��ʾ����:0:����ʾ 1:��ʾ*/
	unsigned char ucOsdDateVisiable;		/*��ʾ����:0:����ʾ 1:��ʾ*/
	unsigned char ucOsdWeekVisiable;	/*��ʾ����:0:����ʾ 1:��ʾ*/

	unsigned char ucOsdTimeFormat;		/*ʱ���ʽ:0:12Сʱ�� 1:24Сʱ��*/
	unsigned char ucOsdDateFormat;		/*���ڸ�ʽ:��д ARG_DATE_FORMAT_TYPE*/
	unsigned char ucOsdDisplayMode;		/*OSD����:��д ARG_DISPLAY_MODE_TYPE*/
	unsigned char ucOsdFontSizeMode;	/*OSD�����С:��дARG_FONTSIZE_MODE_TYPE*/

	unsigned char ucOsdFontSizeScope;	/*OSD�����С֧���б�: ��д ARG_FONTSIZE_MODE_TYPE*/

	unsigned char ucOsdTime_X_Coordinate;	/*OSDʱ��X����λ��: 0-100 �ٷֱ�*/
	unsigned char ucOsdTime_Y_Coordinate; 	/*OSDʱ��Y����λ��: 0-100 �ٷֱ�*/  	
	unsigned char ucOsdText_X_Coordinate;	/*OSD����X����λ��: 0-100 �ٷֱ�*/ 
	unsigned char ucOsdText_Y_Coordinate;	/*OSD����Y����λ��: 0-100 �ٷֱ�*/ 

	unsigned char ucRes[51];

	unsigned char ucOsdText[64];	/*OSD��ʾ�ı�*/

}OSD_Config_Ex;



/********************************************************************************************/
/**********************************      ������������   **********************************/
/********************************************************************************************/
typedef struct 
{
	unsigned char 	ucAlarmSmtpEnable;		   /*SMTP����ʹ��*/
	unsigned char 	ucAlarmFtpEnable;		   /*FTP����ʹ��*/
	unsigned char 	ucAlarmCloudEnalbe;		   /*�ϴ���ʹ��*/
	unsigned char 	ucAlarmRecordEnable;	   /*¼��ʹ��*/
	unsigned char 	ucAlarmIOEnable;		   	   /*IO����ʹ��*/
	unsigned char 	ucRes[11];
}Alarm_Process;


typedef struct 
{
	unsigned char       ucCh;                   		/*ͨ��*/
	unsigned char       ucAlarmType;            		/*��������: ��д ARG_ALARM_TYPE*/
	unsigned char       ucAlarmLinkScope;		/*������������,��дARG_ALARM_LINK_TYPE*/
	unsigned char       ucRes1[29];             		/*����1*/
	Hour_Scope		timeSocpeTab[7][8];     	/*ʱ���: 7��ÿ��8��ʱ��*/
	Alarm_Process	    	process;	    				/*������������*/
	unsigned char       ucRes3[64];             		/*����3*/
}Alarm_Config_Data_Ex;


/********************************************************************************************/
/**********************************      �ڵ���������   *********************************/
/********************************************************************************************/
/*���νṹ��*/
typedef struct 
{
    unsigned char	x1;                         /*���Ͻ�x����ٷֱ�*/
    unsigned char 	y1;                         /*���Ͻ�y����ٷֱ�*/
    unsigned char 	x2;                         /*���½�x����ٷֱ�*/
    unsigned char 	y2;                         /*���½�y����ٷֱ�*/
}Arg_Rect;


typedef struct 
{
	unsigned char 	ucCH;               		/*ͨ��*/
	unsigned char 	ucEnable;           		/*0:�ر��ڸǱ���, 1:�����ڸǱ���*/
	unsigned char 	ucSensitivity;      		/*������ 0:�� 1:�� 2:��*/ 
	unsigned char   	ucAlarmLinkScope;   	/*������������,��дARG_ALARM_LINK_TYPE*/  
	unsigned char 	ucRes[4];           		/*����*/   
	Arg_Rect     		ucArea[6];          		/*6��ٷֱ�����*/
	Hour_Scope 		timeSocpeTab[7][8];   /*ʱ���: 7��ÿ��8��ʱ��*/
	Alarm_Process		process;	    			/*������������*/
	unsigned char 	ucRes1[16];          	/*����*/
}VideoCover_Alarm_Config_Data;


/********************************************************************************************/
/*******************************       TCP/IP����������չ   ******************************/
/********************************************************************************************/
/*TCP/IP����*/
typedef struct 
{
	unsigned char ucCh;                              		/*ͨ����*/
	unsigned char ucNetCardType;                     	/*��������,��дARG_NETCARD_TYPE*/
	unsigned char ucEnDHCP;                          	/*ʹ��dhcp, 0���� 1�ر�*/
	unsigned char ucIPAddrTestEnable;			/*ʹ��IP��ַ����, 0:�ر� 1:����*/
	unsigned char ucIPAddrStatus;				/*IP��ַ״̬,0:���� 1:������*/
	unsigned char ucRes1[11];                         	/*����*/
	unsigned char ucIPV4[16];          		/*IPV4��ַ*/
	unsigned char ucSubNetMaskV4[16];     	/*IPV4��������*/
	unsigned char ucGatewayV4[16];        	/*IPV4����*/
	unsigned char ucDNS1Ip[16];           		/*dns ������1*/
	unsigned char ucDNS2Ip[16];           		/*dns ������2*/
	unsigned char ucIPV6Mode;			     	/*IPV6ģʽ:��дARG_IPV6MODE_TYPE*/
	unsigned char ucRes2[3];
	int 	  		iMaxTransUnit;		     	/*MTU*/
	unsigned char ucIPV6[40];           		/*IPV6��ַ*/
	int		 	  iSubNetMaskV6;   		/*IPV6��������*/
	unsigned char ucGatewayV6[40];      		/*IPV6����*/
	unsigned char ucMulticast[40];      		/*�ಥ��ַ*/
	unsigned char ucMacIp[20];                     /*Mac��������ַ: ��д�ַ������� "A1:B2:C3:D4:E5:F6"*/
	unsigned char ucRes3[36];                       /*����*/
}Net_Config_Data_Ex;



/********************************************************************************************/
/***********************************      �쳣�¼�    **************************************/
/********************************************************************************************/
typedef struct 
{
    unsigned char 	ucCh;                      		/*ͨ����*/	
    unsigned char 	ucAbnormalType;			/*�쳣����,��дARG_ABNORMAL_TYPE*/
    unsigned char   	ucAlarmLinkScope;	   	/*������������,��дARG_ALARM_LINK_TYPE*/
    unsigned char 	ucRes[45];			       /*����*/
    Alarm_Process	process;		           		/*������������*/		
}Abnormal_Event_Config_Data;



/**
* @brief system info main data structure.
*/
typedef struct SysInfo_0{	
	unsigned int 				relUniqueId;						///< IPCAM device type
	Acount_t     				acounts[ACOUNT_NUM];				///< user account data
	Network_Config_Data		net;								///< network status and user settings
	Lancam_Config_Data 		lan_config;							///< IPCAM configuration data
	Factory_config_Data 		factory_config;
	Motion_Config_Data 		motion_config;						///< motion detection configuration data
	PrivacyMask_Config_Data	privacy_mask_config;
	Audio_Config_Data 		audio_config;
	OSD_config 				osd_config[MAX_OSD_STREAMS];
	CodecAdvParam 			codec_advconfig[MAX_CODEC_STREAMS];
	StreamParam 				stream_config[MAX_CODEC_STREAMS];
	Ftp_Config_Data 			ftp_config;							///< Ftp configuration data
	Smtp_Config_Data 			smtp_config;   						///< Smtp configuration data
	LogEntry_t				tCurLog;		    				///< event log
	AutoReboot_Config_Data     autoreboot_config;		    			
	Ddns_Config_Data 			ddns_config;  						//DDNS
	Http_Config_Data 			http_config;  						//http config
	P2P_Config_Data  			p2p_config;
	AutoMainTain_Config_Data	AutoMainTain_config;
	Alarm_Config_Data 		alarm_config;
	char 					reserve1[3];
	ROI_Config_data			Roi_config;
	LDC_Config_data			Ldc_config;
	Sdcard_Config_Data 		sdcard_config;
	CloudStorage_Config_Data	cloudstorage_config;
	Ptz_Config_Data			Ptz_config;
	Record_Config_Data            Record_config;
	DST_Config_Data			DST_config;
	
	//char 					reserve[548];
	char 					reserve[487];
}SysInfo_0;


/**
* @brief system info main data structure.
*/
typedef struct SysInfo_1{	
	unsigned int 					relUniqueId1;	
	Net_Config_Data_Ex			Net_Config_Ex;
	char 						reRes0[72];
	VideoCover_Alarm_Config_Data	VideoCoverAlarm_Config;
	char 						reRes1[152];		//1024
	Alarm_Config_Data_Ex			Alarm_Config_Ex[2];
	Abnormal_Event_Config_Data	Abnormal_Config[4]; 
	char 						reRes2[112];		//1024
	
	char 						reRes[14 * 1024];
}SysInfo_1;



/**
* @brief system info main data structure.
*/
typedef struct SysInfo_2{	
	unsigned int 			relUniqueId2;	

	Encoding_Config_Data     	Video_Encoding_Config[MAX_CODEC_MODE][MAX_CODEC_CHANNEL];  //5K
	OSD_Config_Ex			Osd_Config_Ex[MAX_CODEC_CHANNEL];
	FishEye_Config_Data		FishEye_Config;
	char 					reRes1[320];	
	char 					reRes2[4 * 1024];	

	char 					reRes3[768];
	Ptz_Config_Data_Ex		Ptz_Config_Ex;
	char 					reRes4[5 * 1024];
}SysInfo_2;


/**
* @brief system info main data structure.
*/
typedef struct SysInfo_3{	
	unsigned int 			relUniqueId2;	
	char 				reRes[32 * 1024];	
}SysInfo_3;


/**
* @brief system info main data structure.
*/
typedef struct SysInfo{	
	unsigned int 				relUniqueId;						///< IPCAM device type
	Acount_t     				acounts[ACOUNT_NUM];				///< user account data
	Network_Config_Data		net;								///< network status and user settings
	Lancam_Config_Data 		lan_config;							///< IPCAM configuration data
	Factory_config_Data 		factory_config;
	Motion_Config_Data 		motion_config;						///< motion detection configuration data
	PrivacyMask_Config_Data	privacy_mask_config;
	Audio_Config_Data 		audio_config;
	OSD_config 				osd_config[MAX_OSD_STREAMS];
	CodecAdvParam 			codec_advconfig[MAX_CODEC_STREAMS];
	StreamParam 				stream_config[MAX_CODEC_STREAMS];
	Ftp_Config_Data 			ftp_config;							///< Ftp configuration data
	Smtp_Config_Data 			smtp_config;   						///< Smtp configuration data
	LogEntry_t				tCurLog;		    				///< event log
	AutoReboot_Config_Data     autoreboot_config;		    			
	Ddns_Config_Data 			ddns_config;  						//DDNS
	Http_Config_Data 			http_config;  						//http config
	P2P_Config_Data  			p2p_config;
	AutoMainTain_Config_Data	AutoMainTain_config;
	Alarm_Config_Data 		alarm_config;
	char 					reserve0[3];
	ROI_Config_data			Roi_config;
	LDC_Config_data			Ldc_config;
	Sdcard_Config_Data 		sdcard_config;
	CloudStorage_Config_Data	cloudstorage_config;
	Ptz_Config_Data			Ptz_config;
	Record_Config_Data            Record_config;
	DST_Config_Data			DST_config;

	//char 					reserve[548];
	char 					reserve[487];

	unsigned int 					relUniqueId1;	
	Net_Config_Data_Ex			Net_Config_Ex;
	char 						reRes0[72];
	VideoCover_Alarm_Config_Data	VideoCoverAlarm_Config;
	char 						reRes1[152];		//1024
	Alarm_Config_Data_Ex			Alarm_Config_Ex[2];
	Abnormal_Event_Config_Data	Abnormal_Config[4]; 
	char 						reRes2[112];		//1024
	
	char 						reRes[14 * 1024];

	char 				reserver3[32 * 1024];

	///use for fish platform
	unsigned int 				relUniqueId2;	
	Encoding_Config_Data     	Video_Encoding_Config[MAX_CODEC_MODE][MAX_CODEC_CHANNEL];  //5K
	OSD_Config_Ex			Osd_Config_Ex[MAX_CODEC_CHANNEL];
	FishEye_Config_Data		FishEye_Config;
	char 					reRes11[320];	
	char 					reRes12[4 * 1024];	

	char 					reRes13[768];
	Ptz_Config_Data_Ex		Ptz_Config_Ex;
	char 					reRes14[5 * 1024];
}SysInfo;

#endif /* __SYS_ENV_TYPE_H__ */



