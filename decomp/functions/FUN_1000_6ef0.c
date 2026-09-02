/* 1000:6ef0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016f08) overlaps instruction at (ram,0x00016f07)
    */
/* WARNING: Removing unreachable block (ram,0x00016efc) */

uint FUN_1000_6ef0(void)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  uint in_AX;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int extraout_DX;
  int iVar9;
  char cVar10;
  int in_BX;
  int unaff_BP;
  uint uVar11;
  uint *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  bool bVar12;
  undefined1 uVar13;
  longdouble in_ST0;
  ulong uVar14;
  undefined2 *in_stack_00000000;
  
  *unaff_DI = *unaff_DI & in_AX;
  swi(4);
  uVar6 = (uint)(byte)((char)in_AX + (char)(in_AX >> 8) * 'V') & *unaff_SI;
  bVar12 = (uVar6 & 1) != 0;
  uVar7 = uVar6 >> 1 | (uint)bVar12 << 0xf;
  uVar6 = 0x128;
  do {
    pcVar1 = (char *)0x58ed;
    cVar10 = *pcVar1;
    cVar5 = (char)uVar7;
    cVar2 = *pcVar1;
    *pcVar1 = cVar2 + cVar5 + bVar12;
    LOCK();
    uVar11 = *(uint *)(in_BX + uVar6);
    *(uint *)(in_BX + uVar6) = uVar6;
    UNLOCK();
    if (SCARRY1(cVar10,cVar5) == SCARRY1(cVar2 + cVar5,bVar12)) goto code_r0x00016f0c;
    while( true ) {
      *(uint *)0xa20 = uVar7;
      bVar12 = 0xfffd < uVar11;
      uVar11 = uVar11 + 2;
      iVar8 = (int)in_stack_00000000 + -1;
      if (iVar8 == 0) break;
      in_stack_00000000 = (undefined2 *)&DAT_0000_3e80;
      *(char *)(unaff_BP + uVar11) = *(char *)(unaff_BP + uVar11) + cVar5 + bVar12;
    }
    uVar7 = uVar7 + 1;
    uVar6 = uVar11;
    in_stack_00000000 = unaff_DS;
  } while (uVar7 != 0);
  FUN_1000_4b21();
  uVar6 = 0xaaaa;
  iVar9 = extraout_DX * -2 + 0x50;
  while( true ) {
    bVar12 = (uVar6 & 1) != 0;
    uVar7 = uVar6 >> 1;
    uVar6 = uVar7 | (uint)bVar12 << 0xf;
    if (iVar8 == 1) break;
    *(double *)((int)unaff_DI + iVar9 * 2 + -0x43) = (double)in_ST0;
  }
  cVar10 = ((char)((uint)iVar9 >> 8) - *(char *)(extraout_DX * -2 + -0x1382)) -
           (0x99 < (byte)uVar7 || bVar12);
  in_BX = CONCAT11(cVar10,(char)iVar9);
  uVar13 = cVar10 < '\0';
  iVar8 = 4;
  do {
    uVar14 = FUN_1000_6efe();
    bVar12 = (uVar14 & 1) != 0;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if ((bool)uVar13) {
    bVar4 = (byte)((uint)uVar14 >> 1);
    bVar3 = bVar4 + *(byte *)(in_BX + 0x3075);
    *(int *)0x3e86 =
         (*(int *)0x3e86 - (int)(uVar14 >> 0x10)) -
         (uint)(CARRY1(bVar4,*(byte *)(in_BX + 0x3075)) || CARRY1(bVar3,bVar12));
    uVar6 = CONCAT11((byte)(uVar14 >> 8) >> 1 | (byte)(((uint)bVar12 << 0xf) >> 8),bVar3 + bVar12) +
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


