/* 1000:7f80 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_7f80(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  uint *in_BX;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  char in_CF;
  bool in_ZF;
  
  if (in_ZF) {
    if ((*in_BX & CONCAT11(((char)((uint)in_AX >> 8) -
                           ((undefined1 *)((int)in_BX + (int)unaff_SI))[8]) - in_CF,(char)in_AX)) !=
        0) {
      in_DX = CONCAT11((char)((uint)in_DX >> 8) + (char)((uint)in_BX >> 8),
                       (char)in_DX - *(char *)((int)in_BX + (int)unaff_DI));
      *unaff_DI = (char)in_AX;
    }
    out(*unaff_SI,in_DX);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


