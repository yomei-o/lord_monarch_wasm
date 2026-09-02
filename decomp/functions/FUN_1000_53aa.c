/* 1000:53aa */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000153ee) overlaps instruction at (ram,0x000153ec)
    */

ulong FUN_1000_53aa(byte *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                   undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  byte *pbVar1;
  uint *puVar2;
  code *pcVar3;
  ulong uVar4;
  ulong uVar5;
  uint in_AX;
  byte bVar7;
  uint uVar6;
  byte bVar8;
  undefined2 in_CX;
  uint uVar9;
  char cVar10;
  char extraout_DL;
  undefined2 in_DX;
  char cVar12;
  byte bVar13;
  undefined2 uVar11;
  char extraout_DH;
  int in_BX;
  uint *unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  uint *puVar14;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  undefined1 uVar15;
  byte bVar16;
  char cVar17;
  undefined1 uVar18;
  char in_SF;
  char in_OF;
  bool bVar19;
  ulong uVar20;
  
  cVar10 = (char)in_DX;
  if (in_OF != in_SF) {
    *(char *)0x107b = cVar10;
    *(undefined1 *)(unaff_BP + 5) = 1;
    return CONCAT22(param_5,param_7);
  }
  cVar17 = (char)((uint)in_DX >> 8);
  unaff_DI[in_BX + -0x60] = unaff_DI[in_BX + -0x60] + cVar17;
  cVar12 = cVar17 + unaff_DI[in_BX];
  bVar13 = (byte)in_AX;
  if (!SCARRY1(cVar17,unaff_DI[in_BX])) {
    in_AX = (uint)(bVar13 | unaff_SI[in_BX + 1]);
    goto code_r0x000153f0;
  }
  cVar17 = (char)((uint)in_CX >> 8);
  uVar9 = CONCAT11(cVar17 + *(byte *)((int)unaff_BP + (int)unaff_SI),(char)in_CX);
  if (SCARRY1(cVar17,*(byte *)((int)unaff_BP + (int)unaff_SI))) {
    *unaff_DI = bVar13;
    unaff_DI[1] = bVar13;
    pbVar1 = unaff_SI;
    bVar7 = (byte)(in_AX >> 8);
    uVar15 = CARRY1(bVar7,*pbVar1);
    in_AX = CONCAT11(bVar7 + *pbVar1,bVar13);
    cVar17 = (byte)(bVar7 + *pbVar1) == '\0';
    bVar19 = false;
    if (SCARRY1(bVar7,*pbVar1)) {
      *unaff_SI = *unaff_SI + (char)((uint)in_BX >> 8) + uVar15;
      uVar15 = in_AX < 100;
      bVar19 = SBORROW2(in_AX,100);
      in_AX = in_AX - 100;
      cVar17 = in_AX == 0;
      unaff_SI = param_1;
      if (!(bool)uVar15) {
        if (!(bool)cVar17) {
          out(*param_1,CONCAT11(cVar12,cVar10 + *(byte *)((int)unaff_BP + (int)param_1)));
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        in_AX = 0x348d;
        goto code_r0x000153ec;
      }
    }
    if (bVar19 == (int)in_AX < 0) {
      if ((bool)uVar15 || (bool)cVar17) {
        if (bVar19 != (int)in_AX < 0) {
          unaff_SI[in_BX + 0x64fe] = 0x74;
          *(byte *)((int)unaff_BP + (int)unaff_SI) =
               *(byte *)((int)unaff_BP + (int)unaff_SI) + (char)in_CX;
          pcVar3 = (code *)swi(3);
          uVar20 = (*pcVar3)();
          return uVar20;
        }
        uVar6 = in_AX ^ 0x75;
        unaff_BP = (uint *)((uint)unaff_BP | uVar6);
        in_BX = (int)*(undefined4 *)(unaff_DI + -0x53);
      }
      else {
        while( true ) {
          FUN_1000_58a1();
          uVar20 = FUN_1000_5641();
          uVar11 = (undefined2)(uVar20 >> 0x10);
          if (!(bool)uVar15) break;
          uVar20 = FUN_1000_5917();
          if (!(bool)cVar17) {
            puVar2 = (uint *)(unaff_DI + 2);
            uVar15 = false;
            *puVar2 = *puVar2 & (uint)uVar20;
            uVar18 = *puVar2 == 0;
            do {
              if (!(bool)uVar15) {
                return uVar20;
              }
              do {
                bVar16 = 1;
                uVar20 = FUN_1000_5948();
                if (!(bool)uVar18) {
                  return uVar20;
                }
code_r0x00015459:
                uVar6 = uVar9 - *(uint *)((byte *)((int)unaff_BP + (int)unaff_SI) + 0x431);
                uVar15 = uVar9 < *(uint *)((byte *)((int)unaff_BP + (int)unaff_SI) + 0x431) ||
                         uVar6 < bVar16;
                uVar9 = uVar6 - bVar16;
                uVar18 = uVar9 == 0;
                FUN_1000_562f();
              } while ((bool)uVar15);
              unaff_SI = (byte *)0x32f6;
              uVar20 = FUN_1000_5988();
            } while( true );
          }
          puVar2 = unaff_BP + 0x1a;
          bVar13 = (byte)(uVar20 >> 0x18);
          uVar15 = (byte)*puVar2 < bVar13;
          *(byte *)puVar2 = (byte)*puVar2 - bVar13;
          cVar17 = (byte)*puVar2 == 0;
        }
        puVar14 = (uint *)0xc562;
        uVar9 = uVar9 - 1;
        if (uVar9 == 0 || cVar17 != '\0') {
          uVar4 = uVar20 & 0xff0000;
          uVar5 = uVar20 & 0xff0000;
          in(0x10);
          pbVar1 = unaff_SI;
          unaff_SI = unaff_SI + 2;
          uVar20 = CONCAT22(uVar11,*(undefined2 *)pbVar1) & 0xffffff;
          do {
          } while (uVar4 == 0);
          puVar14 = unaff_BP;
          param_2 = unaff_DS;
          if (uVar5 != 0) {
            return CONCAT22(uVar11,*(undefined2 *)pbVar1) & 0xffffff;
          }
        }
        if (*(int *)(unaff_SI + 3) != 0x2053) {
          return uVar20;
        }
        if (*(int *)(unaff_SI + 6) != 0x4843) {
          return uVar20;
        }
        if (unaff_SI[8] != 0x34) {
          return uVar20;
        }
        uVar6 = func_0x0001b202();
        *puVar14 = uVar6;
        unaff_DS = param_2;
        cVar10 = extraout_DL;
        cVar12 = extraout_DH;
      }
      if ((char)(cVar12 + '\x01') != 'd') {
        return CONCAT22(CONCAT11(cVar12 + '\x01',cVar10),uVar6);
      }
      pbVar1 = unaff_SI + in_BX + -0x7cea;
      bVar13 = *pbVar1;
      bVar8 = (byte)uVar9;
      *pbVar1 = *pbVar1 + bVar8;
      pbVar1 = unaff_SI + 0x50;
      bVar16 = (byte)(uVar9 >> 8);
      bVar7 = *pbVar1 + bVar16;
      bVar16 = CARRY1(*pbVar1,bVar16) || CARRY1(bVar7,CARRY1(bVar13,bVar8));
      *pbVar1 = bVar7 + CARRY1(bVar13,bVar8);
      goto code_r0x00015459;
    }
  }
  else {
code_r0x000153ec:
    *(undefined1 *)0x107d = (char)(in_AX >> 8);
  }
code_r0x000153f0:
  *(undefined1 *)0x107b = (char)in_AX;
  *(undefined1 *)(unaff_BP + 5) = 0;
  return CONCAT22(param_5,param_7);
}


