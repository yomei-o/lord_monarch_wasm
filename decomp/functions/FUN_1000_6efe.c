/* 1000:6efe */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016f08) overlaps instruction at (ram,0x00016f07)
    */

uint FUN_1000_6efe(void)

{
  char *pcVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char in_AL;
  uint uVar5;
  int iVar6;
  int extraout_DX;
  undefined2 in_DX;
  int iVar7;
  char cVar8;
  int in_BX;
  undefined2 *puVar9;
  undefined2 *unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 *unaff_DS;
  bool bVar10;
  undefined1 uVar11;
  bool bVar12;
  longdouble in_ST0;
  ulong uVar13;
  int iStack_106c;
  undefined2 *in_stack_0000ef96;
  
  bVar12 = SCARRY1(in_AL,-0x2f);
  puVar9 = (undefined2 *)&stack0xfffe;
  cVar8 = '\x05';
  do {
    unaff_BP = unaff_BP + -1;
    puVar9 = puVar9 + -1;
    *puVar9 = *unaff_BP;
    cVar8 = cVar8 + -1;
  } while ('\0' < cVar8);
  in(in_DX);
  while( true ) {
    LOCK();
    uVar5 = *(uint *)(in_BX + unaff_SI);
    *(uint *)(in_BX + unaff_SI) = unaff_SI;
    UNLOCK();
    if (!bVar12) goto code_r0x00016f0c;
    while( true ) {
      *(int *)0xa20 = iStack_106c;
      bVar10 = 0xfffd < uVar5;
      unaff_SI = uVar5 + 2;
      iVar6 = (int)in_stack_0000ef96 + -1;
      if (iVar6 == 0) break;
      in_stack_0000ef96 = (undefined2 *)&DAT_0000_3e80;
      (&stack0x0000)[uVar5] = (&stack0x0000)[uVar5] + (char)iStack_106c + bVar10;
      uVar5 = unaff_SI;
    }
    iStack_106c = iStack_106c + 1;
    if (iStack_106c == 0) break;
    pcVar1 = (char *)0x58ed;
    cVar8 = *pcVar1 + (char)iStack_106c;
    bVar12 = SCARRY1(*pcVar1,(char)iStack_106c) != SCARRY1(cVar8,bVar10);
    *pcVar1 = cVar8 + bVar10;
    in_stack_0000ef96 = unaff_DS;
  }
  FUN_1000_4b21();
  uVar5 = 0xaaaa;
  iVar7 = extraout_DX * -2 + 0x50;
  while( true ) {
    bVar12 = (uVar5 & 1) != 0;
    uVar3 = uVar5 >> 1;
    uVar5 = uVar3 | (uint)bVar12 << 0xf;
    if (iVar6 == 1) break;
    *(double *)(unaff_DI + iVar7 * 2 + -0x43) = (double)in_ST0;
  }
  cVar8 = ((char)((uint)iVar7 >> 8) - *(char *)(extraout_DX * -2 + -0x1382)) -
          (0x99 < (byte)uVar3 || bVar12);
  in_BX = CONCAT11(cVar8,(char)iVar7);
  uVar11 = cVar8 < '\0';
  iVar6 = 4;
  do {
    uVar13 = FUN_1000_6efe();
    bVar12 = (uVar13 & 1) != 0;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if ((bool)uVar11) {
    bVar4 = (byte)((uint)uVar13 >> 1);
    bVar2 = bVar4 + *(byte *)(in_BX + 0x3075);
    *(int *)0x3e86 =
         (*(int *)0x3e86 - (int)(uVar13 >> 0x10)) -
         (uint)(CARRY1(bVar4,*(byte *)(in_BX + 0x3075)) || CARRY1(bVar2,bVar12));
    uVar5 = CONCAT11((byte)(uVar13 >> 8) >> 1 | (byte)(((uint)bVar12 << 0xf) >> 8),bVar2 + bVar12) +
            0x2415;
    *(byte *)0x3e86 = *(byte *)0x3e86 ^ (byte)uVar5;
    return uVar5 & 0xff20;
  }
  *(byte *)0x8e70 = *(byte *)0x8e70 ^ (byte)in_BX;
code_r0x00016f0c:
  *(char *)(in_BX + -0x8000) = *(char *)(in_BX + -0x8000) >> 0xb;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


