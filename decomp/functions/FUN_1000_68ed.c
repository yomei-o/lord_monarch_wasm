/* 1000:68ed */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_68ed(void)

{
  byte *pbVar1;
  byte bVar2;
  int in_AX;
  int in_BX;
  int iVar3;
  int unaff_BP;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  unkbyte10 in_ST0;
  
  *(int *)(in_BX + -0x769e) = *(int *)(in_BX + -0x769e) + in_AX;
  iVar3 = in_BX * 2;
  *(byte *)(unaff_BP + (int)unaff_DI) = *(byte *)(unaff_BP + (int)unaff_DI) ^ (byte)in_AX;
  *(unkbyte10 *)(iVar3 + unaff_SI + -1) = in_ST0;
  *(int *)(iVar3 + 0x648c) = in_AX;
  *(int *)(iVar3 + 0x648e) = in_AX;
  *(int *)(iVar3 + 0x64bc) = in_AX;
  *(int *)(iVar3 + 0x64be) = in_AX;
  pbVar1 = (byte *)(unaff_BP + 0x2757);
  *pbVar1 = *pbVar1 | (byte)((uint)iVar3 >> 8);
  if ((char)*pbVar1 < '\x01') {
    *unaff_DI = *(undefined2 *)0x270b;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_1000_69c7();
  bVar2 = FUN_1000_78c3();
  *(byte *)(unaff_BP + 0x36) = *(byte *)(unaff_BP + 0x36) ^ bVar2;
  *(char *)(iVar3 + 0x276a) = *(char *)(iVar3 + 0x276a) + (char)iVar3;
  return;
}


