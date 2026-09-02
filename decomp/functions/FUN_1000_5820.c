/* 1000:5820 */

undefined4
FUN_1000_5820(undefined2 param_1,uint param_2,undefined2 param_3,undefined2 param_4,int param_5)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  undefined2 in_AX;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_BP;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  bool bVar12;
  
  out(0xbe29,in_AX);
  *(undefined1 *)0x3bf2 = 1;
  FUN_1000_3532();
  FUN_1000_822d();
  pbVar1 = (byte *)(param_2 + param_5 + 4);
  *pbVar1 = *pbVar1 ^ (byte)((uint)param_4 >> 8);
  in(0x12);
  iVar8 = CONCAT11((char)((param_2 & 0xfff0) >> 8),(byte)(param_2 & 0xfff0) >> 3);
  FUN_1000_35cd();
  *(undefined1 *)0x3bfe = 0;
  FUN_1000_353b();
  FUN_1000_3769();
  bVar4 = FUN_1000_9f21();
  *(byte *)(unaff_BP + 0x3c6e) = *(byte *)(unaff_BP + 0x3c6e) ^ bVar4;
  iVar6 = 0x7360;
  *(byte *)(unaff_BP + 0x10d3) = *(byte *)(unaff_BP + 0x10d3) & bVar4;
  iVar8 = iVar8 + 1;
  pbVar1 = (byte *)(unaff_BP + 0x10d3);
  *pbVar1 = *pbVar1 >> 1 | *pbVar1 << 7;
  uVar5 = FUN_1000_9ab5();
  pbVar1 = (byte *)(unaff_BP + 0x12a5);
  bVar4 = *pbVar1;
  *pbVar1 = *pbVar1 + 0x91;
  *(char *)(iVar8 + 0x12a5) = *(char *)(iVar8 + 0x12a5) + (char)iVar6 + (0x6e < bVar4);
  out(*(undefined2 *)0x12a5,0xe8de);
  *(byte *)0x3c56 = *(byte *)0x3c56 | 0xdf;
  in_AF = 9 < ((byte)uVar5 & 0xf) | in_AF;
  *(byte *)(unaff_BP + -2) = *(byte *)(unaff_BP + -2) | 0xe8;
  pcVar11 = (char *)*(undefined2 *)0x2674;
  do {
    if (*pcVar11 == '\0') break;
    pcVar9 = (char *)*(undefined2 *)(unaff_BP + -2);
    iVar7 = 0xb;
    bVar12 = false;
    pcVar10 = pcVar11;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar3 = pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar2 = pcVar9;
      pcVar9 = pcVar9 + 1;
      bVar12 = *pcVar2 == *pcVar3;
    } while (bVar12);
    if (bVar12) {
      *(int *)(pcVar9 + iVar8 + 0x2627) = iVar8;
      goto code_r0x000158c9;
    }
    pcVar11 = pcVar11 + 0x20;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined1 *)0x3e92 = 0x80;
code_r0x000158c9:
  return CONCAT22(0xe8e0,CONCAT11((char)((uint)uVar5 >> 8) - in_AF,(byte)uVar5 + in_AF * -6) &
                         0xff0f);
}


