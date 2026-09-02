/* 1000:4bb9 */

/* WARNING: Instruction at (ram,0x00014cda) overlaps instruction at (ram,0x00014cd9)
    */
/* WARNING: Removing unreachable block (ram,0x00014c91) */

undefined4 FUN_1000_4bb9(void)

{
  uint *puVar1;
  ulong *puVar2;
  char *pcVar3;
  byte *pbVar4;
  int *piVar5;
  undefined2 *puVar6;
  uint uVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  undefined2 uVar13;
  int in_CX;
  byte bVar14;
  undefined2 in_DX;
  uint uVar15;
  byte bVar17;
  uint extraout_DX;
  int iVar16;
  int extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined2 in_BX;
  int *piVar18;
  int unaff_BP;
  undefined2 *puVar19;
  char *in_ESI;
  undefined2 *puVar20;
  int unaff_DI;
  undefined1 *puVar21;
  char *pcVar22;
  byte *pbVar23;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar24;
  undefined1 uVar25;
  bool bVar26;
  undefined8 in_MM1;
  undefined8 in_MM5;
  undefined4 uVar27;
  int *piVar28;
  undefined2 uVar29;
  
  puVar21 = (undefined1 *)(unaff_DI + 1);
  piVar28 = (int *)CONCAT11((byte)((uint)in_BX >> 8) | ((char *)in_ESI)[unaff_BP + 0x60],(char)in_BX
                           );
  bVar26 = (POPCOUNT((byte)((uint)in_DX >> 8) | ((char *)((int)piVar28 + (int)(char *)in_ESI))[0x11]
                    ) & 1U) == 0;
  iVar11 = FUN_1000_5685();
  piVar18 = piVar28;
  if (!bVar26) {
    puVar21[unaff_BP] = puVar21[unaff_BP] ^ 0x45;
    pcVar3 = (char *)in_ESI;
    *pcVar3 = *pcVar3 + (char)iVar11;
    piVar18 = (int *)CONCAT11((byte)((uint)iVar11 >> 8) | ((char *)in_ESI)[unaff_BP + 0x60],
                              (char)iVar11);
    iVar11 = (int)piVar28 + unaff_BP;
    puVar21 = (undefined1 *)(unaff_DI + 3);
    in_ESI = (char *)((ulong)in_ESI & 0xffff0000);
  }
  in_CX = in_CX + 1;
  *puVar21 = (char)iVar11;
  pcVar22 = puVar21 + 2;
  puVar21[1] = (char)iVar11;
  pcVar3 = pcVar22 + unaff_BP;
  cVar8 = (char)((uint)piVar18 >> 8);
  bVar26 = SBORROW1(*pcVar3,cVar8);
  *pcVar3 = *pcVar3 - cVar8;
  *(undefined1 *)0x33a6 = 0x42;
  puVar20 = (undefined2 *)CONCAT22((int)((ulong)in_ESI >> 0x10),(undefined2 *)0x339e);
  uVar29 = 0x4bea;
  uVar27 = func_0x0001c159();
  uVar15 = (uint)((ulong)uVar27 >> 0x10);
  uVar12 = (uint)uVar27;
  if (bVar26) {
    puVar19 = (undefined2 *)puVar20;
    uVar15 = uVar15 ^ *(uint *)((int)puVar19 + unaff_BP + 0x1b);
    pcVar3 = (char *)(unaff_BP + (int)puVar19);
    *pcVar3 = *pcVar3 + (char)uVar27;
    if (*pcVar3 != '\0') {
      pbVar4 = (byte *)((int)puVar19 + unaff_BP + 0x2aa);
      *pbVar4 = *pbVar4 & (byte)((uint)in_CX >> 8);
      puVar1 = (uint *)((int)piVar18 + (int)puVar19);
      iVar11 = (uVar15 + 1 & 3) - (*puVar1 & 3);
      *puVar1 = *puVar1 + (uint)(0 < iVar11) * iVar11;
      pbVar4 = (byte *)((int)puVar19 + unaff_BP + 0x720a);
      *pbVar4 = *pbVar4 | (byte)(uVar15 + 1 >> 8);
      bVar26 = true;
      FUN_1000_5644();
      uVar29 = unaff_DS;
      if (!bVar26) {
        FUN_1000_85e0();
      }
      goto LAB_1000_4c8c;
    }
    *(byte *)0xe811 = *(byte *)0xe811 | (byte)uVar15;
code_r0x00014c00:
    uVar29 = 0x2075;
    pcVar22 = puVar21 + 3;
    puVar20 = (undefined2 *)
              CONCAT22((int)((ulong)puVar20 >> 0x10),(undefined2 *)((int)(undefined2 *)puVar20 + 1))
    ;
  }
  else {
    *(uint *)((int)piVar18 + (int)pcVar22) = *(uint *)((int)piVar18 + (int)pcVar22) ^ uVar15;
    uVar27 = func_0x0001c174();
    uVar12 = (uint)uVar27;
    *(byte *)0x33a6 = *(byte *)0x33a6 & (byte)uVar27;
    iVar11 = (int)((ulong)uVar27 >> 0x10) - *(int *)((int)piVar18 + (int)(undefined2 *)puVar20);
    pbVar4 = (byte *)((int)(undefined2 *)puVar20 + 0x75);
    bVar17 = (byte)iVar11;
    uVar15 = CONCAT11((char)((uint)iVar11 >> 8),bVar17 + *pbVar4);
    if (!SCARRY1(bVar17,*pbVar4)) {
      uVar12 = uVar12 + unaff_BP + (uint)CARRY1(bVar17,*pbVar4);
      goto code_r0x00014c00;
    }
  }
  uVar7 = piVar18[0x1b];
  puVar19 = (undefined2 *)puVar20;
  cVar8 = (char)(uVar12 ^ uVar7);
  *(char *)(unaff_BP + (int)puVar19) = *(char *)(unaff_BP + (int)puVar19) + cVar8;
  cVar8 = cVar8 + (char)((uint)in_CX >> 8) + (*(undefined2 **)(pcVar22 + 0x70) < puVar19);
  bVar26 = false;
  bVar17 = (byte)(uVar15 >> 8) | *(byte *)((int)puVar19 + unaff_BP + -0x58);
  uVar27 = CONCAT22(CONCAT11(bVar17,(char)uVar15),CONCAT11((char)((uVar12 ^ uVar7) >> 8),cVar8));
  *pcVar22 = cVar8;
  uVar12 = in_CX - 1;
  if (uVar12 == 0 || bVar17 != 0) {
    *(undefined1 *)0x33b2 = 0x42;
    puVar20 = (undefined2 *)CONCAT22((int)((ulong)puVar20 >> 0x10),(undefined2 *)0x33aa);
    uVar27 = FUN_1000_563c();
    if (bVar26) {
      piVar28 = (int *)0x4ca3;
      uVar13 = FUN_1000_5644();
      bVar17 = (byte)(uVar12 >> 8);
      if (bVar26) {
LAB_1000_4c8c:
        return CONCAT22(uVar29,unaff_CS);
      }
      goto code_r0x00014ca5;
    }
  }
  uVar29 = in((int)((ulong)uVar27 >> 0x10));
  *(undefined2 *)(pcVar22 + 1) = uVar29;
  *(uint *)0xe880 = *(uint *)0xe880 & (uint)piVar18;
  cVar8 = *(char *)(ulong)((int)piVar18 + ((uint)uVar27 & 0xff));
  bVar17 = (byte)(uVar12 >> 8);
  puVar19 = (undefined2 *)puVar20;
  puVar1 = (uint *)(unaff_BP + -1 + (int)puVar19);
  uVar15 = *puVar1;
  *puVar1 = *puVar1 - uVar12;
  if (uVar12 <= uVar15) {
    FUN_1000_85f2();
    puVar19 = (undefined2 *)puVar20;
    *(uint *)((int)piVar18 + (int)puVar19) = *(uint *)((int)piVar18 + (int)puVar19) & extraout_DX;
    *(char *)((int)piVar18 + (int)puVar19) =
         *(char *)((int)piVar18 + (int)puVar19) + (char)uVar12 +
         CARRY1((byte)extraout_DX,*(byte *)((int)puVar19 + unaff_BP + 0x20));
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar13 = CONCAT11((char)((ulong)uVar27 >> 8),cVar8 + bVar17 * '\x02' + '\x01');
  puVar6 = puVar19 + 1;
  puVar20 = (undefined2 *)CONCAT22((int)((ulong)puVar20 >> 0x10),puVar6);
  *(undefined2 *)(pcVar22 + 3) = *puVar19;
  puVar1 = (uint *)((int)puVar6 + unaff_BP + -0x1a);
  *puVar1 = *puVar1 | (uint)puVar6;
  piVar28 = piVar18;
code_r0x00014ca5:
  *(char *)piVar18 = (char)((uint)piVar18 >> 8);
  pbVar4 = (byte *)(unaff_BP + -1 + (int)(undefined2 *)puVar20);
  *pbVar4 = *pbVar4 | (byte)uVar13;
  *(undefined2 *)(unaff_BP + -3) = uVar13;
  iVar11 = (uint)bVar17 << 8;
  bVar26 = false;
  do {
    do {
      bVar24 = bVar26;
      *(undefined1 *)((undefined2 *)puVar20 + 4) = 0x42;
      FUN_1000_5622(piVar28);
      bVar26 = true;
    } while (bVar24);
    uVar25 = 0;
    pbVar23 = (byte *)0x0;
    FUN_1000_5cef();
    piVar28 = (int *)0x4cc5;
    uVar27 = FUN_1000_5644();
    bVar26 = true;
  } while ((bool)uVar25);
  *piVar18 = (int)piVar18;
  do {
    puVar19 = (undefined2 *)puVar20;
    pbVar4 = (byte *)((int)puVar19 + unaff_BP + -0x19);
    *pbVar4 = *pbVar4 | (byte)((ulong)uVar27 >> 0x10);
    bVar26 = puVar19 < (undefined2 *)*(int *)((int)piVar18 + (int)puVar19);
    puVar20 = (undefined2 *)
              CONCAT22((int)((ulong)puVar20 >> 0x10),
                       (undefined2 *)((int)puVar19 - *(int *)((int)piVar18 + (int)puVar19)));
    bVar9 = (byte)uVar27;
    pbVar23[-1] = bVar9;
    pbVar4 = pbVar23;
    pbVar23 = pbVar23 + 1;
    *pbVar4 = bVar9;
    bVar14 = (byte)((uint)iVar11 >> 8);
    bVar17 = bVar9 + bVar14;
    bVar10 = bVar17 + bVar26;
    bVar26 = 0xef < bVar10 || CARRY1(bVar10 + 0x10,CARRY1(bVar9,bVar14) || CARRY1(bVar17,bVar26));
    uVar27 = FUN_1000_5641();
    iVar16 = (int)((ulong)uVar27 >> 0x10);
  } while (bVar26);
  while( true ) {
    piVar5 = (int *)((int)piVar18 + (int)(undefined2 *)puVar20 + 6);
    *piVar5 = *piVar5 - iVar16;
    cVar8 = FUN_1000_661b();
    in_MM1 = psubsb(in_MM1,*(undefined8 *)(pbVar23 + 10));
    if (0xfa < (byte)(cVar8 + 1U)) break;
    puVar2 = (ulong *)((int)(undefined2 *)puVar20 + unaff_BP + -0x15);
    *puVar2 = *puVar2 | (ulong)puVar20;
    iVar16 = extraout_DX_00;
    pbVar23 = pbVar23 + 1;
  }
  uVar12 = *(int *)(unaff_BP + -3) + 0x800;
  if (0xb800 < uVar12) {
    uVar12 = *(int *)(unaff_BP + -3) + 0x2800;
  }
  *(uint *)(unaff_BP + -3) = uVar12;
  *(undefined1 *)((undefined2 *)puVar20 + 4) = 0x45;
  FUN_1000_8b17();
  psubsb(in_MM5,*(undefined8 *)((int)piVar18 + (int)(undefined2 *)puVar20));
  uVar29 = in(0x61);
  return CONCAT22(CONCAT11((byte)((uint)extraout_DX_01 >> 8) | (byte)extraout_DX_01,
                           (byte)extraout_DX_01),uVar29);
}


