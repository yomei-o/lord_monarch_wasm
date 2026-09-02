/* 1000:6bd2 */

uint FUN_1000_6bd2(uint param_1,undefined2 param_2,char *param_3,byte *param_4,int param_5,
                  undefined2 param_6,int param_7,undefined2 param_8,undefined2 param_9,int param_10)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  code *pcVar5;
  byte bVar6;
  int in_AX;
  uint uVar7;
  int in_CX;
  int iVar8;
  undefined2 in_DX;
  int extraout_DX;
  int in_BX;
  byte *unaff_SI;
  char *unaff_DI;
  undefined1 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  byte in_AF;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar10;
  
  while ((iVar8 = CONCAT11((char)((uint)in_DX >> 8),(byte)in_DX & (byte)in_CX), in_CX == 0 ||
         (in_CX == 0))) {
    bVar6 = (byte)in_AX;
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    pbVar2 = (byte *)(unaff_DI + 1);
    *unaff_DI = bVar6 + in_AF * -6 + (0x99 < bVar6) * -0x60;
    *(double *)(unaff_SI + in_BX) = (double)in_ST0;
    *pbVar2 = *unaff_SI;
    bVar6 = unaff_SI[1];
    for (; pbVar2 = pbVar2 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar2 = bVar6;
    }
    *pbVar2 = unaff_SI[2];
    unaff_CS = 0x1000;
    *(byte **)(unaff_SI + in_BX + -0x47ce) =
         unaff_SI +
         (uint)((byte *)0xffd2 < unaff_SI + 3) + *(int *)(unaff_SI + in_BX + -0x47ce) + 0x30;
    in_CX = CONCAT11(((char)((uint)param_9 >> 8) - param_3[param_5 + 0x1f]) - (0xffaf < param_1),
                     (char)param_9);
    in_AX = param_10;
    in_DX = param_8;
    in_BX = param_7;
    unaff_SI = param_4;
    unaff_DI = param_3;
    unaff_ES = param_2;
    in_ST0 = in_ST1;
    in_ST1 = in_ST2;
    in_ST2 = in_ST3;
    in_ST3 = in_ST4;
    in_ST4 = in_ST5;
    in_ST5 = in_ST6;
    in_ST6 = in_ST7;
  }
  if (in_CX != 0) {
    puVar9 = (undefined1 *)((int)(unaff_DI + in_AX) * 2 + 0x50d);
    uVar10 = func_0x000e3580(unaff_CS);
    uVar7 = (0x27 - ((int)((ulong)uVar10 >> 0x10) + -1)) * 2;
    if ((POPCOUNT(uVar7 & 0xff) & 1U) != 0) {
      return (uint)uVar10 | 0x8b05;
    }
    unaff_SI[in_CX + 0x10f] = unaff_SI[in_CX + 0x10f] - (char)((uint)in_CX >> 8);
    func_0x00014c23();
    do {
      puVar3 = (undefined2 *)(puVar9 + 1);
      *puVar9 = 0xff;
      for (iVar8 = extraout_DX; iVar8 != 0; iVar8 = iVar8 + -1) {
        puVar4 = puVar3;
        puVar3 = puVar3 + 1;
        *puVar4 = 0xffff;
      }
      *(undefined1 *)puVar3 = 0xff;
      puVar9 = (undefined1 *)((int)puVar3 + uVar7 + 1);
      in_CX = in_CX + -1;
    } while (in_CX != 0);
    *(undefined1 *)0xf566 = 0xff;
    pbVar1 = unaff_SI;
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 - 0x25;
    return CONCAT11(0xf5,(0x24 < bVar6) + -0x18);
  }
  pcVar5 = (code *)swi(3);
  uVar7 = (*pcVar5)();
  return uVar7;
}


