#ifndef GLOBAL_VAR
#define GLOBAL_VAR

///��̬��������
volatile char global_device_name[20];
volatile u8 g_bt_conn_status;

///��̬��������

static const char lcd_bt_error[] = {"Blue-ERROR"};
static const char lcd_bt_emit_connected[] = {"BlueEmit-Connected"};
static const char lcd_bt_emit_waiting[] = {"BlueEmit-Wait"};
static const char lcd_bt_scan[]={"KEY2-Scanning"};
static const char lcd_bt_receonnect[]={"KEY3-Reconnect"};
static const char lcd_bt_disceonnect[]={"KEY3-DisConnect"};

#endif // GLOBAL_VAR
