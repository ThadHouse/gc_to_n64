#ifndef _eeprom_h__
#define _eeprom_h__

#define EEPROM_MAGIC_SIZE		8
#define EEPROM_APPDATA_SIZE		256

// Atmega8 : 512 byte eeprom
//
// 28 bytes per mapping

struct eeprom_data_struct {
	unsigned char magic[EEPROM_MAGIC_SIZE];
	unsigned char defmap;
	unsigned char deadzone_enabled;
	unsigned char old_v1_5_conversion;
	unsigned char wide_conversion;
	unsigned char appdata[EEPROM_APPDATA_SIZE];
};

extern struct eeprom_data_struct g_eeprom_data;
void eeprom_commit(void);
void eeprom_writeDefaults(void);

/** \return 0 if init ok, 1 if corrupted (and fixed)
 */
int eeprom_init(void);

// These make a change and commit
void toggle_old_v1_5_conversion(void);
void toggleDeadzone(void);
void setDefaultMapping(int id);

#endif // _eeprom_h__

