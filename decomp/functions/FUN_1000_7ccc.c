/* 1000:7ccc */

/* WARNING: Instruction at (ram,0x00015da1) overlaps instruction at (ram,0x00015d9f)
    */

undefined4 FUN_1000_7ccc(undefined2 param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  undefined2 in_AX;
  int iVar4;
  int in_CX;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 in_DX;
  undefined1 uVar8;
  byte bVar9;
  int in_BX;
  uint unaff_BP;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined2 uVar13;
  byte *in_ESI;
  byte *unaff_DI;
  uint uVar14;
  byte *pbVar15;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar16;
  byte in_AF;
  byte *in_stack_00000000;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  bVar2 = (byte)((uint)in_AX >> 8);
  pbVar11 = (byte *)in_ESI;
  if ((byte)in_DX != bVar2) {
    bVar3 = unaff_DI[0x1820];
    uVar8 = (undefined1)((uint)in_DX >> 8);
    pbVar15 = (byte *)CONCAT11(uVar8,bVar3);
    pbVar11[in_BX] = pbVar11[in_BX] + bVar3 + ((byte)in_DX < bVar2);
    in_BX = in_BX + 1;
    if (bVar3 == bVar2) {
      bVar2 = bVar2 ^ 0xad;
      goto code_r0x00017d21;
    }
    bVar5 = unaff_DI[0x247c];
    pbVar11[in_BX] = pbVar11[in_BX] + bVar5 + (bVar3 < bVar2);
    bVar3 = 9 < ((byte)in_AX & 0xf) | in_AF;
    if (bVar5 != (byte)(bVar2 + bVar3)) {
      pbVar11[in_BX] = pbVar11[in_BX] + unaff_DI[0x3080] + (bVar5 < (byte)(bVar2 + bVar3));
      uVar14 = (int)unaff_DI - *(int *)(pbVar11 + unaff_BP);
      bVar2 = ((byte)in_AX + bVar3 * '\x06' & 0xf) % 0x74;
      bVar16 = 0x99 < bVar2 || unaff_DI < *(byte **)(pbVar11 + unaff_BP);
      bVar2 = bVar2 + (9 < (bVar2 & 0xf) | bVar3) * '\x06' + bVar16 * '`';
      uVar7 = (uint)bVar2;
      cVar1 = *(char *)(uVar14 + 0x3cdc);
      pbVar11[in_BX] = pbVar11[in_BX] + cVar1 + bVar16;
      uVar6 = CONCAT11(uVar8,cVar1);
      if (cVar1 != '\0') {
        bVar5 = *(byte *)(uVar14 + 0x48de);
        uVar6 = CONCAT11(uVar8,bVar5);
        pbVar12 = pbVar11 + in_BX;
        bVar3 = *pbVar12;
        *pbVar12 = *pbVar12 + bVar5;
        uVar7 = uVar14 + *(uint *)(pbVar11 + unaff_BP);
        bVar16 = CARRY2(uVar14,*(uint *)(pbVar11 + unaff_BP)) ||
                 CARRY2(uVar7,(uint)CARRY1(bVar3,bVar5));
        pbVar15 = (byte *)(uVar7 + CARRY1(bVar3,bVar5));
        bVar3 = bVar2 % 0x74;
        uVar7 = CONCAT11(bVar2 / 0x74,bVar3);
        if ((POPCOUNT((uint)bVar3) & 1U) == 0) {
          *(char *)0xe6ac = *(char *)0xe6ac + bVar3 + bVar16;
          bVar16 = false;
          do {
            pbVar10 = (byte *)in_ESI;
            pbVar11 = pbVar10 + 1;
            uVar13 = (undefined2)((ulong)in_ESI >> 0x10);
            bVar2 = *pbVar10;
            out(0xa9,bVar2);
            bVar3 = (byte)((uint)uVar6 >> 8);
            uVar6 = CONCAT11(bVar3,(char)uVar6 + '\x01');
            in_CX = in_CX + -1;
            if (in_CX == 0) {
              LOCK();
              bVar2 = pbVar11[unaff_BP];
              pbVar11[unaff_BP] = bVar3;
              UNLOCK();
              pbVar12 = pbVar15 + 0x2b;
              *pbVar12 = *pbVar12 + bVar2;
              in_ESI = (byte *)0x3e20;
              break;
            }
            if (bVar16) {
              while( true ) {
                pbVar11[in_BX + 2] = pbVar11[in_BX + 2] | bVar2;
                bVar2 = *pbVar11;
                pbVar11[in_BX + 0x1f] = pbVar11[in_BX + 0x1f] + bVar2;
                *pbVar15 = bVar2;
                in_BX = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + '\x01');
                in_CX = in_CX + -1;
                if (in_CX == 0) break;
                pbVar11 = (byte *)0x2e10;
                *(byte *)(in_BX + 0x2e10) = *(byte *)(in_BX + 0x2e10) & (byte)in_CX;
                *(uint *)(in_stack_00000000 + unaff_BP + 0x8aa) =
                     *(uint *)(in_stack_00000000 + unaff_BP + 0x8aa) & unaff_BP;
                bVar2 = bVar2 - 0x18 & 0xf;
                out(0xae,bVar2);
                pbVar15 = in_stack_00000000;
              }
              return CONCAT22(in_stack_0000000a,in_stack_0000000e);
            }
            pbVar12 = (byte *)CONCAT22(uVar13,pbVar10 + 3);
            out(*(undefined2 *)pbVar11,uVar6);
            bVar16 = CARRY1(*pbVar12,bVar2 + 1);
            *pbVar12 = *pbVar12 + bVar2 + 1;
            in_ESI = (byte *)CONCAT22(uVar13,pbVar10 + 4);
            out(0xa9,pbVar10[3]);
          } while (-1 < (char)*pbVar12);
          bVar2 = 0;
          do {
            out(0xa8,bVar2);
            uVar7 = 0xae;
            iVar4 = 3;
            do {
              pbVar11 = (byte *)in_ESI;
              in_ESI = (byte *)ZEXT24(pbVar11 + 1);
              bVar3 = (byte)((uint)(byte)((*pbVar11 & 0xf) + 1) * (uint)*(byte *)0x34d6 >> 8);
              out(uVar7,bVar3);
              uVar7 = uVar7 - 2;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            bVar2 = bVar2 + 1;
          } while (bVar2 < 0x10);
          bVar2 = (byte)uVar7;
          *(char *)0xe432 = *(char *)0xe432 + bVar2 + CARRY1(bVar3,bVar2);
          bVar2 = ~(byte)((uint)(byte)(bVar3 + bVar2) / (uVar7 & 0xff));
          return CONCAT22(uVar7,CONCAT11(bVar2,bVar2));
        }
        pbVar11[in_BX] = pbVar11[in_BX] + bVar2 / 0x74 + bVar16;
        uVar6 = param_1;
      }
      return CONCAT22(uVar6,uVar7);
    }
    in(0x8a);
  }
  in_ESI = (byte *)ZEXT24(pbVar11 + 2);
  bVar2 = (byte)((uint)*(undefined2 *)pbVar11 >> 8);
  pbVar15 = in_stack_00000000;
code_r0x00017d21:
  unaff_DI[unaff_BP] = unaff_DI[unaff_BP] + (char)((uint)in_CX >> 8);
  iVar4 = CONCAT11((char)((uint)in_BX >> 8),(byte)in_BX | *unaff_DI);
  bVar5 = (byte)pbVar15;
  bVar16 = CARRY1(bVar5,unaff_DI[iVar4]);
  bVar9 = (byte)((uint)pbVar15 >> 8);
  bVar3 = bVar9 - ((byte *)in_ESI)[iVar4];
  return CONCAT22(CONCAT11(bVar3 - bVar16,
                           bVar5 + unaff_DI[iVar4] + *(char *)(unaff_BP + 0x22) +
                           (bVar9 < ((byte *)in_ESI)[iVar4] || bVar3 < bVar16)),
                  CONCAT11(bVar2 + 1,unaff_DI[0x4616]));
}


