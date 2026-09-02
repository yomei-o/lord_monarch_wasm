/* 1000:6baa */

uint FUN_1000_6baa(undefined2 param_1,uint param_2,undefined2 param_3,char *param_4,byte *param_5,
                  int param_6,undefined2 param_7,int param_8,undefined2 param_9,undefined2 param_10,
                  byte *param_11)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  code *pcVar5;
  byte bVar6;
  byte *in_AX;
  uint uVar7;
  int iVar8;
  int in_DX;
  int extraout_DX;
  int in_BX;
  int iVar9;
  byte *unaff_SI;
  char *unaff_DI;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_CF;
  byte in_AF;
  longdouble in_ST0;
  longdouble in_ST1;
  longdouble in_ST2;
  longdouble in_ST3;
  longdouble in_ST4;
  longdouble in_ST5;
  longdouble in_ST6;
  longdouble in_ST7;
  undefined4 uVar11;
  
  do {
    while( true ) {
      bVar6 = (byte)in_AX;
      in_AF = 9 < (bVar6 & 0xf) | in_AF;
      pbVar2 = (byte *)(unaff_DI + 1);
      *unaff_DI = bVar6 + in_AF * -6 + (0x99 < bVar6 | in_CF) * -0x60;
      *(double *)(unaff_SI + in_BX) = (double)in_ST0;
      *pbVar2 = *unaff_SI;
      bVar6 = unaff_SI[1];
      for (; pbVar2 = pbVar2 + 1, in_DX != 0; in_DX = in_DX + -1) {
        *pbVar2 = bVar6;
      }
      *pbVar2 = unaff_SI[2];
      *(byte **)(unaff_SI + in_BX + -0x47ce) =
           unaff_SI +
           (uint)((byte *)0xffd2 < unaff_SI + 3) + *(int *)(unaff_SI + in_BX + -0x47ce) + 0x30;
      iVar9 = CONCAT11(((char)((uint)param_10 >> 8) - param_4[param_6 + 0x1f]) - (0xffaf < param_2),
                       (byte)param_10);
      in_CF = 0;
      in_DX = CONCAT11((char)((uint)param_9 >> 8),(byte)param_9 & (byte)param_10);
      in_AX = param_11;
      in_BX = param_8;
      unaff_SI = param_5;
      unaff_DI = param_4;
      unaff_ES = param_3;
      in_ST0 = in_ST1;
      in_ST1 = in_ST2;
      in_ST2 = in_ST3;
      in_ST3 = in_ST4;
      in_ST4 = in_ST5;
      in_ST5 = in_ST6;
      in_ST6 = in_ST7;
      if (iVar9 != 0) break;
      param_11 = param_5;
      param_10 = 0;
    }
  } while (iVar9 == 0);
  if (iVar9 != 0) {
    puVar10 = (undefined1 *)((int)(param_4 + (int)param_11) * 2 + 0x50d);
    uVar11 = func_0x000e3580();
    uVar7 = (0x27 - ((int)((ulong)uVar11 >> 0x10) + -1)) * 2;
    if ((POPCOUNT(uVar7 & 0xff) & 1U) != 0) {
      return (uint)uVar11 | 0x8b05;
    }
    param_5[iVar9 + 0x10f] = param_5[iVar9 + 0x10f] - (char)((uint)iVar9 >> 8);
    func_0x00014c23();
    do {
      puVar3 = (undefined2 *)(puVar10 + 1);
      *puVar10 = 0xff;
      for (iVar8 = extraout_DX; iVar8 != 0; iVar8 = iVar8 + -1) {
        puVar4 = puVar3;
        puVar3 = puVar3 + 1;
        *puVar4 = 0xffff;
      }
      *(undefined1 *)puVar3 = 0xff;
      puVar10 = (undefined1 *)((int)puVar3 + uVar7 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(undefined1 *)0xf566 = 0xff;
    pbVar1 = param_5;
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 - 0x25;
    return CONCAT11(0xf5,(0x24 < bVar6) + -0x18);
  }
  pcVar5 = (code *)swi(3);
  uVar7 = (*pcVar5)();
  return uVar7;
}


