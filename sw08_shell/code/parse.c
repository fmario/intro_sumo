uint8_t CLS1_ParseWithCommandTable(const uint8_t *cmd, CLS1_ConstStdIOType *io, CLS1_ConstParseCommandCallback *parseCallback){
  uint8_t res = ERR_OK;
  bool handled, silent;

  if (*cmd=='\0') { /* empty command */
    return ERR_OK;
  }
  /* parse first shell commands */
  handled = FALSE;
  silent = (bool)(*cmd=='#');
  if (silent) {
    cmd++; /* skip '#' */
  }
  res = CLS1_IterateTable(cmd, &handled, io, parseCallback); /* iterate through all parser functions in table */
  if (!handled || res!=ERR_OK) { /* no handler has handled the command? */
    CLS1_PrintCommandFailed(cmd, io);
    res = ERR_FAILED;
  }
  if (!silent) {
    CLS1_PrintPrompt(io);
  }
  return res;
}