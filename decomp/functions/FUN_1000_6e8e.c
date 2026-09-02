/* 1000:6e8e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00016eb9) overlaps instruction at (ram,0x00016eb8)
    */

uint FUN_1000_6e8e(void)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  int in_AX;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 *in_DX;
  int extraout_DX;
  int in_BX;
  int iVar8;
  char cVar9;
  int unaff_BP;
  uint uVar10;
  int unaff_DI;
  undefined2 unaff_SS;
  bool bVar11;
  undefined1 uVar12;
  longdouble in_ST0;
  ulong uVar13;
  
  bVar11 = false;
  uVar5 = 0;
  do {
    *(char *)(unaff_BP + uVar5) = *(char *)(unaff_BP + uVar5) + (char)in_AX + bVar11;
    puVar6 = (undefined2 *)&DAT_0000_3e80;
    while( true ) {
      *(int *)0xa20 = in_AX;
      bVar11 = 0xfffd < uVar5;
      uVar10 = uVar5 + 2;
      iVar7 = (int)puVar6 + -1;
      uVar5 = uVar10;
      if (iVar7 != 0) break;
      in_AX = in_AX + 1;
      if (in_AX == 0) {
        FUN_1000_4b21();
        uVar5 = 0xaaaa;
        iVar8 = extraout_DX * -2 + 0x50;
        while( true ) {
          bVar11 = (uVar5 & 1) != 0;
          uVar10 = uVar5 >> 1;
          uVar5 = uVar10 | (uint)bVar11 << 0xf;
          if (iVar7 == 1) break;
          *(double *)(unaff_DI + iVar8 * 2 + -0x43) = (double)in_ST0;
        }
        cVar9 = ((char)((uint)iVar8 >> 8) - *(char *)(extraout_DX * -2 + -0x1382)) -
                (0x99 < (byte)uVar10 || bVar11);
        in_BX = CONCAT11(cVar9,(char)iVar8);
        uVar12 = cVar9 < '\0';
        iVar7 = 4;
        do {
          uVar13 = FUN_1000_6efe();
          bVar11 = (uVar13 & 1) != 0;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        if ((bool)uVar12) {
          bVar4 = (byte)((uint)uVar13 >> 1);
          bVar2 = bVar4 + *(byte *)(in_BX + 0x3075);
          *(int *)0x3e86 =
               (*(int *)0x3e86 - (int)(uVar13 >> 0x10)) -
               (uint)(CARRY1(bVar4,*(byte *)(in_BX + 0x3075)) || CARRY1(bVar2,bVar11));
          uVar5 = CONCAT11((byte)(uVar13 >> 8) >> 1 | (byte)(((uint)bVar11 << 0xf) >> 8),
                           bVar2 + bVar11) + 0x2415;
          *(byte *)0x3e86 = *(byte *)0x3e86 ^ (byte)uVar5;
          return uVar5 & 0xff20;
        }
        *(byte *)0x8e70 = *(byte *)0x8e70 ^ (byte)in_BX;
code_r0x00016f0c:
        *(char *)(in_BX + -0x8000) = *(char *)(in_BX + -0x8000) >> 0xb;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      pcVar1 = (char *)0x58ed;
      cVar9 = *pcVar1;
      cVar3 = *pcVar1 + (char)in_AX;
      *pcVar1 = cVar3 + bVar11;
      LOCK();
      uVar5 = *(uint *)(in_BX + uVar10);
      *(uint *)(in_BX + uVar10) = uVar10;
      UNLOCK();
      puVar6 = in_DX;
      if (SCARRY1(cVar9,(char)in_AX) == SCARRY1(cVar3,bVar11)) goto code_r0x00016f0c;
    }
  } while( true );
}


