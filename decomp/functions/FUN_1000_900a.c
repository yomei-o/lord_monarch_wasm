/* 1000:900a */

undefined2 FUN_1000_900a(void)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  undefined2 in_AX;
  byte bVar5;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  undefined1 uStack_5;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) << 1;
  cVar4 = (char)((uint)in_DX >> 8);
  *(char *)(unaff_DI + -0x10) = *(char *)(unaff_DI + -0x10) + cVar4;
  *(undefined1 *)0x32d0 = 2;
  uStack_2 = (byte)unaff_BP;
  pcVar1 = (char *)(in_BX + unaff_SI + 0x10);
  uStack_3 = (byte)in_AX;
  *pcVar1 = *pcVar1 - uStack_3;
  out(in_DX,uStack_3);
  *(char *)(unaff_SI + 0x13) = *(char *)(unaff_SI + 0x13) + '\x01';
  bVar5 = (byte)((uint)in_AX >> 8);
  if (((byte)((uint)in_stack_00000000 >> 8) & uStack_3) == 0) {
    uStack_5 = *(undefined1 *)0x32ce;
    uStack_2 = bVar5;
  }
  else {
    pbVar2 = (byte *)(in_BX + unaff_SI);
    bVar3 = *pbVar2;
    *pbVar2 = *pbVar2 - bVar5;
    *(char *)(unaff_DI + 0x7402) = *(char *)(unaff_DI + 0x7402) + cVar4 + (bVar3 < bVar5);
    uStack_3 = (byte)((uint)unaff_ES >> 8);
  }
  do {
    cVar4 = FUN_1000_8f0d();
  } while (cVar4 != '\0');
  *(undefined1 *)0x32ce = uStack_5;
  return CONCAT11(uStack_2,uStack_3);
}


