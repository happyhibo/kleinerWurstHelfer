#ifndef DEFINITION
#define DEFINITION

// comment this line for release build
//#define DEBUG true

//Datenbankvorlage
#define DB_VORLAGE		"kwh_db_vorlage.s3db"
#define DATEN_VORLAGE	"kwh_daten_vorlage.sql"

//Userdatenbankname
#ifdef DEBUG
#define DB_NAME	"kwh_daten_test.s3db"
#else
#define DB_NAME	"kwh_daten.s3db"
#endif

#define DB_VERSION		1
#define APP_VERSION 	"0.99.0"
#define APP_NAME		"kleinerWurstHelfer"
#define APP_KURZNAME	"KWH"


//Fehlermeldungen
#define TYPE_INFO 1
#define TYPE_WARNUNG 2
#define TYPE_KRITISCH 3

#define CANCEL_NO 10
#define CANCEL_AKTION 11
#define CANCEL_PROGRAM 12

#define ERR_SQL_DB_OPEN 100
#define ERR_SQL_DB_VERSION 101
#define ERR_SQL_DB_USER_KOPIE 102
#define ERR_SQL_DB_VORLAGE 103
#define ERR_SQL_DB_PFAD 104
#define ERR_SQL_DB_ABFRAGE 105
#define ERR_SQL_DB_CREATE 106
#define ERR_DB_KOPIE_NEU_ORT 109
#define ERR_DB_PFAD_NIO 129

#define ERR_DEBUG_INFO 200


#endif // !DEFINITION

