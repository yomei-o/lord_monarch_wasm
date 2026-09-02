/* 1000:6bca */

uint FUN_1000_6bca(char *param_1,byte *param_2,int param_3,undefined2 param_4,int param_5,
                  undefined2 param_6,byte *param_7,int param_8,undefined2 param_9,uint param_10)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  code *pcVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int extraout_DX;
  int iVar9;
  uint unaff_DI;
  undefined1 *puVar10;
  undefined2 unaff_SS;
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
  undefined4 uVar11;
  undefined2 in_stack_00000000;
  
  while( true ) {
    iVar9 = CONCAT11(((char)((uint)param_7 >> 8) - param_1[param_3 + 0x1f]) - (0xffaf < unaff_DI),
                     (byte)param_7);
    iVar8 = CONCAT11((char)((uint)param_6 >> 8),(byte)param_6 & (byte)param_7);
    if ((iVar9 != 0) && (iVar9 != 0)) break;
    bVar6 = (byte)param_8;
    in_AF = 9 < (bVar6 & 0xf) | in_AF;
    param_7 = (byte *)(param_1 + 1);
    *param_1 = bVar6 + in_AF * -6 + (0x99 < bVar6) * -0x60;
    *(double *)(param_2 + param_5) = (double)in_ST0;
    *param_7 = *param_2;
    bVar6 = param_2[1];
    pbVar2 = param_7;
    for (; pbVar2 = pbVar2 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
      *pbVar2 = bVar6;
    }
    *pbVar2 = param_2[2];
    *(byte **)(param_2 + param_5 + -0x47ce) =
         param_2 + (uint)((byte *)0xffd2 < param_2 + 3) +
                   *(int *)(param_2 + param_5 + -0x47ce) + 0x30;
    unaff_SS = *(undefined2 *)(param_2 + param_5 + 0x30);
    param_8 = 0x1000;
    unaff_DI = param_10;
    in_ST0 = in_ST1;
    in_ST1 = in_ST2;
    in_ST2 = in_ST3;
    in_ST3 = in_ST4;
    in_ST4 = in_ST5;
    in_ST5 = in_ST6;
    in_ST6 = in_ST7;
  }
  if (iVar9 != 0) {
    puVar10 = (undefined1 *)((int)(param_1 + param_8) * 2 + 0x50d);
    uVar11 = func_0x000e3580();
    uVar7 = (0x27 - ((int)((ulong)uVar11 >> 0x10) + -1)) * 2;
    if ((POPCOUNT(uVar7 & 0xff) & 1U) != 0) {
      return (uint)uVar11 | 0x8b05;
    }
    param_2[iVar9 + 0x10f] = param_2[iVar9 + 0x10f] - (char)((uint)iVar9 >> 8);
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
    pbVar1 = param_2;
    bVar6 = *pbVar1;
    *pbVar1 = *pbVar1 - 0x25;
    return CONCAT11(0xf5,(0x24 < bVar6) + -0x18);
  }
  pcVar5 = (code *)swi(3);
  uVar7 = (*pcVar5)();
  return uVar7;
}


