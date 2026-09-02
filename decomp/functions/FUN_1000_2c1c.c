/* 1000:2c1c */

/* WARNING: Instruction at (ram,0x00012cda) overlaps instruction at (ram,0x00012cd8)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00012d06) */

ulong FUN_1000_2c1c(void)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  char cVar4;
  int in_AX;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char extraout_AH;
  uint uVar10;
  int in_DX;
  byte extraout_DH;
  byte *in_BX;
  byte *pbVar11;
  int unaff_BP;
  uint *unaff_SI;
  uint *puVar12;
  int unaff_DI;
  uint uVar13;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar14;
  bool bVar15;
  undefined1 uVar16;
  undefined4 uVar17;
  ulong uVar18;
  undefined1 in_stack_00000000;
  undefined1 in_stack_00000001;
  undefined1 uStack0003;
  undefined1 uStack0005;
  undefined2 uStack0007;
  undefined2 uStack0009;
  uint in_stack_00000012;
  byte bVar9;
  
  uVar13 = unaff_DI - 0x62;
  do {
    uVar8 = uVar13;
    bVar9 = (byte)((uint)in_AX >> 8);
    if (bVar9 == *(byte *)(uVar8 + 0xd27e)) {
      *(uint *)(in_BX + (int)unaff_SI) =
           (*(int *)(in_BX + (int)unaff_SI) - in_DX) - (uint)(bVar9 < *(byte *)(uVar8 + 0xd27e));
      in(in_DX);
      unaff_SS = 3;
    }
    in_AX = (uint)bVar9 << 8;
    bVar14 = 0xffa5 < uVar8;
    uVar13 = uVar8 + 0x5a;
    uVar10 = CONCAT11(in_stack_00000001,in_stack_00000000) - 1;
  } while (uVar10 != 0);
  uVar17 = func_0x0001a4ee();
  bVar15 = true;
  puVar12 = unaff_SI;
  if (bVar14) goto LAB_1000_2c9b_2;
  uVar10 = CONCAT11((char)(uVar10 >> 8),(byte)uVar10 | *in_BX);
  *(byte *)(unaff_SI + 6) = 4;
  unaff_SI[3] = 200;
  *(byte *)((int)unaff_SI + 0xb) = 0xff;
  uVar5 = in(0x20);
  uStack0003 = (undefined1)unaff_ES;
  puVar12 = (uint *)((int)unaff_SI + -1);
  in_BX[(int)puVar12] = in_BX[(int)puVar12] + (char)in_BX;
  puVar2 = (uint *)(in_BX + (int)puVar12);
  *puVar2 = *puVar2 ^ uVar10;
  if (*puVar2 == 0) {
    bVar9 = (byte)uVar5;
    uVar16 = 0x17 < bVar9;
    uVar8 = CONCAT11((char)((uint)uVar5 >> 8),bVar9 - 0x18);
    uVar18 = (ulong)uVar8;
    if ((byte)(bVar9 - 0x18) != '\0' && '\x17' < (char)bVar9) {
      if (!(bool)uVar16) {
        return (ulong)uVar8;
      }
      cVar4 = CARRY2((uint)in_BX,uVar8);
      pbVar11 = in_BX + uVar8;
      FUN_1000_91b2();
      uStack0003 = 0x90;
      uVar17 = func_0x0001a45f();
      if ((bool)cVar4) {
        return (ulong)CONCAT11((char)((ulong)uVar17 >> 8),
                               (char)uVar17 + *(byte *)(unaff_BP + (int)puVar12) + '\x01');
      }
      uStack0005 = 0x95;
      FUN_1000_9213();
      *(byte *)(unaff_BP + (int)puVar12) =
           (*(byte *)(unaff_BP + (int)puVar12) - extraout_AH) - cVar4;
      pbVar1 = (byte *)(unaff_BP + uVar13 + 0x2f);
      bVar14 = false;
      *pbVar1 = *pbVar1 ^ extraout_DH;
      uStack0007 = 0x2e9e;
      uVar18 = FUN_1000_343c();
      if (!bVar14) {
        return uVar18;
      }
      uStack0009 = 0x2ea4;
      uVar18 = func_0x000134ff();
      if (bVar14) {
        uVar13 = *(uint *)(pbVar11 + 0x1287);
        puVar2 = (uint *)((int)puVar12 + unaff_BP + 1);
        *puVar2 = *puVar2 | (uint)puVar12;
        return (ulong)CONCAT11((char)(uVar18 >> 8),((char)uVar18 + '\x18') - (uVar13 < 0x5c));
      }
      return uVar18;
    }
  }
  else {
    while( true ) {
      bVar14 = (byte)uVar5 < 0x14;
      bVar9 = (byte)((uint)uVar5 >> 8);
      bVar3 = -bVar14;
      uVar5 = CONCAT11(bVar9,bVar3);
      pbVar1 = (byte *)(unaff_BP + (int)puVar12);
      *pbVar1 = *pbVar1 + (char)((uint)in_BX >> 8) + bVar14;
      if (*pbVar1 == 0) break;
      *(byte *)((int)unaff_SI + 0x7b) =
           *(byte *)((int)unaff_SI + 0x7b) | (byte)((ulong)uVar17 >> 0x18);
    }
    uVar16 = false;
    bVar14 = false;
    bVar9 = bVar9 | in_BX[(int)puVar12];
    uVar6 = CONCAT11(bVar9,bVar3);
    cVar4 = '\0';
    if (bVar9 != 0) {
      bVar9 = *(char *)(uVar8 + 0xd2dc) - 8;
      bVar14 = bVar9 < 8;
      do {
        if (bVar14) {
          uVar6 = CONCAT11(bVar9,bVar3) & 0x3ff;
          bVar3 = (byte)(uVar6 >> 8);
          bVar9 = (byte)uVar6;
          uVar16 = bVar9 < bVar3;
          bVar14 = SBORROW1(bVar9,bVar3);
          cVar4 = bVar9 - bVar3;
          if (bVar9 != bVar3) break;
        }
        uStack0003 = 0x2c;
        uVar17 = func_0x0001a4c2();
        iVar7 = (int)uVar17;
        if (-1 < (char)in_BX[uVar8 + 4]) {
          out((int)((ulong)uVar17 >> 0x10),iVar7);
          *(undefined1 *)(iVar7 + uVar13 + 599) = (char)uVar10;
          cVar4 = func_0x0001b538();
          if (((char)*(uint *)0xd27e == (char)(cVar4 + '\b')) && (uRam00020000 < 0x4000)) {
            uVar13 = (uint)in_BX[0x12] * (*(uint *)0xd27e >> 8);
            if ((char)(uVar13 >> 8) != '\0') {
              puVar2 = (uint *)(in_BX + 0xe);
              uVar8 = *puVar2;
              *puVar2 = *puVar2 + uVar13;
              *(uint *)(in_BX + 0x10) = *(int *)(in_BX + 0x10) + (uint)CARRY2(uVar8,uVar13);
              *(char *)0xd280 = *(char *)0xd280 - (char)uVar13;
              *(char *)(iVar7 + 0x7e86) = *(char *)(iVar7 + 0x7e86) + -1;
              *(char *)(iVar7 + 3) = *(char *)(iVar7 + 3) >> 0x1f;
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
          }
          return (ulong)in_stack_00000012;
        }
        *(byte *)puVar12 = (byte)*puVar12 | (byte)uVar17;
        uVar17 = CONCAT22(CONCAT11((byte)((ulong)uVar17 >> 0x18) |
                                   *(byte *)((int)puVar12 + unaff_BP + 6),
                                   (char)((ulong)uVar17 >> 0x10)),iVar7);
        puVar2 = puVar12;
        bVar15 = CARRY2(*puVar2,(uint)in_BX);
        *puVar2 = (uint)(in_BX + *puVar2);
LAB_1000_2c9b_2:
        bVar9 = (byte)((ulong)uVar17 >> 8);
        bVar3 = in(CONCAT11((char)((ulong)uVar17 >> 0x18),
                            (char)((ulong)uVar17 >> 0x10) + -0x80 + bVar15));
        bVar14 = false;
        (in_BX + (int)puVar12)[0x8fc] = (in_BX + (int)puVar12)[0x8fc] | bVar3;
      } while( true );
    }
    if (bVar14 != cVar4 < '\0') {
      in_BX = in_BX + uVar6;
      goto code_r0x00012d12;
    }
    uStack0003 = 0x2d;
    uVar18 = FUN_1000_a08e();
  }
  if ((bool)uVar16) {
    return uVar18;
  }
code_r0x00012d12:
  uStack0003 = 0x2d;
  FUN_1000_38b6();
  bVar9 = *(byte *)((int)puVar12 + 0xb);
  uStack0005 = (undefined1)((uint)unaff_BP >> 8);
  uStack0003 = (undefined1)((uint)unaff_DS >> 8);
  bVar14 = bVar9 < in_BX[uVar13] || (byte)(bVar9 - in_BX[uVar13]) < (bVar9 != 0xff);
  uVar18 = FUN_1000_342c();
  if (bVar14) {
    return (ulong)CONCAT11((char)(uVar18 >> 8),*(undefined1 *)0x42e);
  }
  return uVar18;
}


