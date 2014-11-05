static portTASK_FUNCTION(ShellTask, pvParameters) {
#if PL_HAS_USB_CDC
  static unsigned char cdc_buf[48];
#endif
#if PL_HAS_BLUETOOTH
  static unsigned char bluetooth_buf[48];
#endif
  static unsigned char localConsole_buf[48];
#if CLS1_DEFAULT_SERIAL
  CLS1_ConstStdIOTypePtr ioLocal = CLS1_GetStdio();  
#endif
  
  (void)pvParameters; /* not used */
#if PL_HAS_USB_CDC
  cdc_buf[0] = '\0';
#endif
#if PL_HAS_BLUETOOTH
  bluetooth_buf[0] = '\0';
#endif
  localConsole_buf[0] = '\0';
#if CLS1_DEFAULT_SERIAL
  (void)CLS1_ParseWithCommandTable((unsigned char*)CLS1_CMD_HELP, ioLocal, CmdParserTable);
#endif