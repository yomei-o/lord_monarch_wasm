/* 1000:69fa */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_69fa(void)

{
  char *pcVar1;
  byte bVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (!in_ZF && in_OF == in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar2 = FUN_1000_78c3();
  *(byte *)(unaff_BP + 0x36) = *(byte *)(unaff_BP + 0x36) ^ bVar2;
  pcVar1 = (char *)(in_BX + unaff_SI + 0x5f);
  *pcVar1 = *pcVar1 + (char)in_BX;
  return;
}


