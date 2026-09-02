/* 1000:6e9a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016eb9) overlaps instruction at (ram,0x00016eb8)
    */

uint FUN_1000_6e9a(void)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  byte bVar5;
  int in_AX;
  uint uVar6;
  undefined2 *in_CX;
  int iVar7;
  int extraout_DX;
  int in_BX;
  int iVar8;
  char cVar9;
  int unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  bool bVar10;
  undefined1 uVar11;
  longdouble in_ST0;
  ulong uVar12;
  
  while( true ) {
    while( true ) {
      *(int *)0xa20 = in_AX;
      bVar10 = 0xfffd < unaff_SI;
      unaff_SI = unaff_SI + 2;
      iVar7 = (int)in_CX + -1;
      if (iVar7 == 0) break;
      in_CX = (undefined2 *)&DAT_0000_3e80;
      *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + (char)in_AX + bVar10;
    }
    in_AX = in_AX + 1;
    if (in_AX == 0) break;
    pcVar1 = (char *)0x58ed;
    cVar9 = *pcVar1;
    cVar3 = *pcVar1 + (char)in_AX;
    *pcVar1 = cVar3 + bVar10;
    LOCK();
    uVar6 = *(uint *)(in_BX + unaff_SI);
    *(uint *)(in_BX + unaff_SI) = unaff_SI;
    UNLOCK();
    in_CX = unaff_DS;
    unaff_SI = uVar6;
    if (SCARRY1(cVar9,(char)in_AX) == SCARRY1(cVar3,bVar10)) goto code_r0x00016f0c;
  }
  FUN_1000_4b21();
  uVar6 = 0xaaaa;
  iVar8 = extraout_DX * -2 + 0x50;
  while( true ) {
    bVar10 = (uVar6 & 1) != 0;
    uVar4 = uVar6 >> 1;
    uVar6 = uVar4 | (uint)bVar10 << 0xf;
    if (iVar7 == 1) break;
    *(double *)(unaff_DI + iVar8 * 2 + -0x43) = (double)in_ST0;
  }
  cVar9 = ((char)((uint)iVar8 >> 8) - *(char *)(extraout_DX * -2 + -0x1382)) -
          (0x99 < (byte)uVar4 || bVar10);
  in_BX = CONCAT11(cVar9,(char)iVar8);
  uVar11 = cVar9 < '\0';
  iVar7 = 4;
  do {
    uVar12 = FUN_1000_6efe();
    bVar10 = (uVar12 & 1) != 0;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if ((bool)uVar11) {
    bVar5 = (byte)((uint)uVar12 >> 1);
    bVar2 = bVar5 + *(byte *)(in_BX + 0x3075);
    *(int *)0x3e86 =
         (*(int *)0x3e86 - (int)(uVar12 >> 0x10)) -
         (uint)(CARRY1(bVar5,*(byte *)(in_BX + 0x3075)) || CARRY1(bVar2,bVar10));
    uVar6 = CONCAT11((byte)(uVar12 >> 8) >> 1 | (byte)(((uint)bVar10 << 0xf) >> 8),bVar2 + bVar10) +
            0x2415;
    *(byte *)0x3e86 = *(byte *)0x3e86 ^ (byte)uVar6;
    return uVar6 & 0xff20;
  }
  *(byte *)0x8e70 = *(byte *)0x8e70 ^ (byte)in_BX;
code_r0x00016f0c:
  *(char *)(in_BX + -0x8000) = *(char *)(in_BX + -0x8000) >> 0xb;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


