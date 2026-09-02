/* 1000:78c3 */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_1000_78c3(void)

{
  uint *puVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int iVar7;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  
  bVar8 = false;
  iVar4 = FUN_1000_7aec();
  if (bVar8) {
    uVar5 = iVar4 + 2;
    puVar1 = (uint *)(unaff_SI + 6);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 - uVar5;
    if (uVar6 < uVar5 || *puVar1 == 0) {
      uVar6 = FUN_1000_1845();
      return uVar6;
    }
    return uVar5;
  }
  *(undefined2 *)(unaff_SI + 6) = 0;
  *(undefined1 *)(unaff_SI + 0xb) = 0xff;
  if ((*(byte *)(unaff_SI + 10) & 0x20) == 0) {
    iVar7 = unaff_SI + *(int *)(unaff_BP + unaff_SI + -0x41) + (uint)(unaff_SI < *(uint *)0x32bf);
    bVar3 = *(byte *)(in_BX + iVar7);
    pcVar2 = (char *)(in_BX + iVar7 + 0x5b);
    *pcVar2 = *pcVar2 + (char)in_BX;
    return (uint)(byte)((char)iVar4 + 0x80U ^ bVar3);
  }
  *(undefined1 *)(unaff_SI + 0xe) = 3;
  LOCK();
  *(int *)(unaff_DI + -0x5cee) = unaff_BP;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


