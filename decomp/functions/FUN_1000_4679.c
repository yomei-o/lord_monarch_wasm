/* 1000:4679 */

/* WARNING: Instruction at (ram,0x00014727) overlaps instruction at (ram,0x00014726)
    */

void FUN_1000_4679(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  undefined2 in_AX;
  uint uVar9;
  byte bVar10;
  int in_CX;
  byte bVar11;
  int in_DX;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int *in_BX;
  undefined1 uVar12;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  int iVar13;
  undefined1 *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar15;
  undefined4 uVar16;
  byte *pbStackY_e;
  int iStackY_c;
  undefined2 uStackY_8;
  
  do {
    uVar8 = CONCAT11((char)((uint)in_AX >> 8) + '\x01',(char)in_AX);
    iVar13 = unaff_DI;
    do {
      unaff_DI = iVar13 + 2;
      if (in_DX == 1) {
        unaff_DI = iVar13 + 0x4da;
      }
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        out(0xff,uVar8);
        *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + (char)uVar8;
        uVar3 = *(undefined2 *)(unaff_SI + unaff_BP);
        pbVar2 = (byte *)(unaff_BP + unaff_DI + -0x1730);
        *pbVar2 = *pbVar2 >> 6 | *pbVar2 << 2;
        puVar14 = (undefined1 *)(unaff_DI + (uVar8 ^ 0xc2) + 0x2d0e);
        if (puVar14 != (undefined1 *)*(int *)0x32a2) {
          FUN_1000_46ef(uVar3);
          uVar12 = (undefined1)((uint)in_BX >> 8);
          *(undefined2 *)0x32a2 = puVar14;
          uVar4 = FUN_1000_86c1();
          *puVar14 = uVar4;
          in_BX = (int *)CONCAT11(uVar12,unaff_SI[unaff_BP]);
        }
        do {
          func_0x00017617();
          FUN_1000_6159();
          uVar9 = func_0x00017617();
          puVar14 = (undefined1 *)*(undefined2 *)0x36a2;
          puVar1 = (uint *)(unaff_SI + unaff_BP);
          uVar8 = *puVar1;
          *puVar1 = *puVar1 - uVar9;
          bVar15 = 0xefdb < uVar9 || CARRY2(uVar9 + 0x1024,(uint)(uVar8 < uVar9));
          bVar5 = (char)(uVar9 + 0x1024) + (uVar8 < uVar9);
          bVar7 = bVar5 + 0xa8;
          bVar6 = bVar7 - bVar15;
          bVar11 = (byte)((uint)in_CX >> 8);
          bVar10 = (byte)in_CX;
          iVar13 = *in_BX;
          FUN_1000_6153();
          func_0x00017611();
          *(undefined2 *)0x89a2 = 0x132;
          pbVar2 = unaff_SI;
          *pbVar2 = *pbVar2 >> (bVar10 & 7) | *pbVar2 << 8 - (bVar10 & 7);
          FUN_1000_4693();
          func_0x0001b778();
          uVar4 = in(extraout_DX);
          *puVar14 = uVar4;
          *(uint *)((byte *)((int)in_BX + (int)unaff_SI) + 0x7440) =
               *(int *)((byte *)((int)in_BX + (int)unaff_SI) + 0x7440) -
               (unaff_BP + iVar13 +
               (uint)(bVar11 < bVar6 || (byte)(bVar11 - bVar6) < (bVar5 < 0x58 || bVar7 < bVar15)));
          unaff_ES = *(undefined2 *)(byte *)((int)in_BX + (int)unaff_SI);
          in_CX = 0x46e6;
          in_BX = (int *)CONCAT11((char)((uint)uStackY_8 >> 8),(char)uStackY_8 + 'F');
          do {
            thunk_FUN_1000_47c8();
            bVar7 = func_0x0001b68c();
          } while ((bVar7 & 0xf) != 0);
          *(undefined2 *)0x3bdc = extraout_DX_00;
          *(undefined1 *)0x3289 = 0x2f;
          unaff_BP = iStackY_c;
          unaff_SI = pbStackY_e;
        } while( true );
      }
      FUN_1000_7676(uVar8);
      FUN_1000_61bd();
      uVar16 = FUN_1000_6845();
      in_DX = (int)((ulong)uVar16 >> 0x10);
      uVar4 = (undefined1)((ulong)uVar16 >> 8);
      bVar7 = (char)uVar16 + 1;
      uVar8 = CONCAT11(uVar4,bVar7);
      iVar13 = unaff_DI;
    } while (bVar7 < 0x7f);
    in_AX = CONCAT11(uVar4,0x21);
  } while( true );
}


