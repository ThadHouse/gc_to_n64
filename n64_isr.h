


#define N64_RX_BUF_SIZE 33
#define N64_TX_BUF_SIZE	32

#ifndef __ASSEMBLER__

extern volatile unsigned char n64_rx_buf[32];

// doublebuffered to prevent glitches in analog stick.
// see int_r8_use_buf1
extern volatile unsigned char n64_tx_buf0[32];
extern volatile unsigned char n64_tx_buf1[32];

// usually constant, therefore not doublebuffered. Reply to 0x00 (id) and 0xff (reset)
extern volatile unsigned char n64_tx_id_reply[3]; // { 0x05, 0x00, 0x02 };

// dedicated registers for communicating with interrupt
extern volatile unsigned char n64_got_command;

extern volatile unsigned char n64_use_buf1;

#endif

