uint8_t CLS1_IterateTable(const uint8_t *cmd, bool *handled, CLS1_ConstStdIOType *io, CLS1_ConstParseCommandCallback *parserTable)
{
  uint8_t res = ERR_OK;

  if (parserTable==NULL) { /* no table??? */
    return ERR_FAILED;
  }
  /* iterate through all parser functions in table */
  while(*parserTable!=NULL) {
    if ((*parserTable)(cmd, handled, io)!=ERR_OK) {
      res = ERR_FAILED;
    }
    parserTable++;
  }
  return res;
}