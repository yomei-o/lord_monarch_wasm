/* 1000:2796 */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_2796(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte extraout_AL;
  byte extraout_AL_00;
  byte extraout_AL_01;
  byte extraout_AL_02;
  byte extraout_AL_03;
  byte extraout_AL_04;
  byte bVar4;
  byte bVar5;
  undefined2 in_AX;
  char extraout_AH;
  char extraout_AH_00;
  char extraout_AH_01;
  char extraout_AH_02;
  char extraout_AH_03;
  char extraout_AH_04;
  char cVar6;
  undefined2 in_CX;
  int in_BX;
  int iVar7;
  int *piVar8;
  int *unaff_BP;
  int iVar9;
  byte *unaff_SI;
  byte *pbVar10;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar11;
  byte in_AF;
  
  iVar9 = *unaff_BP;
  bVar4 = *unaff_SI;
  cVar6 = (char)((uint)in_AX >> 8);
  if ((bVar4 < 0x30) || (0x5f < bVar4)) {
    if ((bVar4 < 0x60) || (0x6f < bVar4)) {
      if ((bVar4 < 0x20) || (0x2f < bVar4)) {
        if ((bVar4 == 0) || (4 < bVar4)) {
          if ((bVar4 < 0x14) || (0x17 < bVar4)) {
            piVar8 = unaff_BP + 1;
            if ((7 < bVar4) && (piVar8 = unaff_BP + 1, bVar4 < 0xc)) {
              *unaff_BP = 0x27e5;
              FUN_1000_2983();
              piVar8 = unaff_BP;
              bVar4 = extraout_AL_04;
              cVar6 = extraout_AH_04;
            }
          }
          else {
            *unaff_BP = 0x27d8;
            func_0x0001294d();
            piVar8 = unaff_BP;
            bVar4 = extraout_AL_03;
            cVar6 = extraout_AH_03;
          }
        }
        else {
          *unaff_BP = 0x27cb;
          FUN_1000_2923();
          piVar8 = unaff_BP;
          bVar4 = extraout_AL_02;
          cVar6 = extraout_AH_02;
        }
      }
      else {
        *unaff_BP = 0x27be;
        FUN_1000_2895();
        piVar8 = unaff_BP;
        bVar4 = extraout_AL_01;
        cVar6 = extraout_AH_01;
      }
    }
    else {
      *unaff_BP = 0x27b1;
      FUN_1000_28dc();
      piVar8 = unaff_BP;
      bVar4 = extraout_AL_00;
      cVar6 = extraout_AH_00;
    }
  }
  else {
    *unaff_BP = 0x27a4;
    FUN_1000_282e();
    piVar8 = unaff_BP;
    bVar4 = extraout_AL;
    cVar6 = extraout_AH;
  }
  pbVar10 = unaff_SI + 2;
  bVar2 = 9 < (bVar4 & 0xf) | in_AF;
  bVar5 = bVar4 + bVar2 * -6 & 0xf;
  *(undefined2 *)((int)piVar8 + -2) = unaff_SS;
  *(undefined2 *)((int)piVar8 + -4) = unaff_ES;
  uVar3 = *(undefined4 *)(in_BX + unaff_DI + 0x16);
  uVar11 = (undefined2)((ulong)uVar3 >> 0x10);
  iVar7 = CONCAT11((char)((uint)in_BX >> 8),(char)in_BX + *(char *)(in_BX + -0x5f99));
  bVar4 = pbVar10[iVar7];
  if (bVar5 < 0x60) {
    bVar5 = 0x30;
  }
  else {
    if ((bVar5 < 0x60) || (0x6f < bVar5)) goto LAB_1000_2810;
    bVar5 = 0x60;
  }
  *pbVar10 = bVar5;
LAB_1000_2810:
  bVar1 = 9 < (bVar5 & 0xf) | bVar2;
  bVar5 = bVar5 + bVar1 * '\x06';
  cVar6 = (cVar6 - bVar2) + bVar1;
  *(uint *)((int)piVar8 + -6) = CONCAT11(cVar6,bVar5) & 0xff0f;
  *(undefined2 *)((int)piVar8 + -8) = CONCAT11((char)((uint)in_CX >> 8),(char)in_CX + 1U ^ bVar4);
  *(undefined2 *)((int)piVar8 + -10) = (int)uVar3;
  *(int *)((int)piVar8 + -0xc) = iVar7;
  *(undefined1 **)(undefined1 *)((int)piVar8 + -0xe) = (undefined1 *)((int)piVar8 + -4);
  *(int *)((int)piVar8 + -0x10) = iVar9;
  *(undefined2 *)((int)piVar8 + -0x12) = pbVar10;
  *(int *)((int)piVar8 + -0x14) = unaff_DI;
  pbVar10[iVar9] = pbVar10[iVar9] ^ cVar6 + (9 < (bVar5 & 0xf) | bVar1);
  return;
}


