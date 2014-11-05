static const CLS1_ParseCommandCallback CmdParserTable[] = {
  CLS1_ParseCommand, /* Processor Expert Shell component, is first in list */
  SHELL_ParseCommand, /* our own module parser */
  #if FRTOS1_PARSE_COMMAND_ENABLED
    FRTOS1_ParseCommand, /* FreeRTOS shell parser */
  #endif
  #if BT1_PARSE_COMMAND_ENABLED
    BT1_ParseCommand,
  #endif
  NULL /* Sentinel */};