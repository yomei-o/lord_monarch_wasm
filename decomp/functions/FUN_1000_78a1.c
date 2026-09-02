/* 1000:78a1 */

/* WARNING: Control flow encountered bad instruction data */

uint FUN_1000_78a1(void)

{
  uint *puVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  char cVar10;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte in_CL;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  uint unaff_SI;
  int iVar11;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  
  cVar3 = *(char *)0xd089;
  cVar10 = (char)((uint)in_DX >> 8);
  cVar6 = (char)in_DX;
  *(undefined2 *)(in_BX + unaff_SI + -0x56) = CONCAT11(cVar10,cVar6 + *unaff_DI);
  *unaff_DI = cVar6;
  cVar4 = *(char *)(in_BX + unaff_SI + -0x77);
  *(byte *)(unaff_BP + -0x76) = *(byte *)(unaff_BP + -0x76) ^ in_CL;
  if (((byte)(cVar6 - 0x14U) < 4) ||
     (iVar7 = CONCAT11(cVar10 + cVar3 + cVar4,cVar6 + -8),
     (char)(cVar6 + -8) == *(char *)(unaff_SI + 0xc))) {
    bVar12 = false;
    iVar7 = FUN_1000_7aec();
    if (!bVar12) {
      *(undefined2 *)(unaff_SI + 6) = 0;
      *(undefined1 *)(unaff_SI + 0xb) = 0xff;
      if ((*(byte *)(unaff_SI + 10) & 0x20) == 0) {
        iVar11 = unaff_SI + *(int *)(unaff_BP + unaff_SI + -0x41) +
                 (uint)(unaff_SI < *(uint *)0x32bf);
        bVar5 = *(byte *)(in_BX + iVar11);
        pcVar2 = (char *)(in_BX + iVar11 + 0x5b);
        *pcVar2 = *pcVar2 + (char)in_BX;
        return (uint)(byte)((char)iVar7 + 0x80U ^ bVar5);
      }
      *(undefined1 *)(unaff_SI + 0xe) = 3;
      LOCK();
      *(int *)(unaff_DI + -0x5ced) = unaff_BP;
      UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  uVar8 = iVar7 + 2;
  puVar1 = (uint *)(unaff_SI + 6);
  uVar9 = *puVar1;
  *puVar1 = *puVar1 - uVar8;
  if (uVar9 < uVar8 || *puVar1 == 0) {
    uVar9 = FUN_1000_1845();
    return uVar9;
  }
  return uVar8;
}


