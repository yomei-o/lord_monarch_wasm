/* 1000:342c */

void FUN_1000_342c(void)

{
  byte *pbVar1;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  byte in_AL;
  byte bVar5;
  byte bVar6;
  uint in_CX;
  int in_DX;
  uint uVar7;
  int in_BX;
  int unaff_BP;
  int *piVar8;
  int *in_ESI;
  char *pcVar9;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  char cVar10;
  bool bVar11;
  byte in_AF;
  int in_stack_00000000;
  
  bVar6 = 0x99 < in_AL | in_CF;
  bVar5 = in_AL + (9 < (in_AL & 0xf) | in_AF) * -6 + bVar6 * -0x60;
  piVar8 = (int *)in_ESI;
  uVar7 = (in_DX - *piVar8) - (uint)bVar6;
  cVar10 = '\0';
  if (bVar5 != 0) {
    bVar5 = bVar5 - 0xc;
    cVar10 = '\x01';
    if (3 < bVar5) goto LAB_1000_3482;
  }
  pcVar9 = (char *)CONCAT22((int)((ulong)in_ESI >> 0x10),(char *)((int)piVar8 + 1));
  out((char)*piVar8,uVar7);
  pcVar2 = (char *)((int)piVar8 + 1);
  *pcVar2 = (*pcVar2 - bVar5) - cVar10;
  in_ESI = (int *)(pcVar9 + 1);
  out(*pcVar9,uVar7);
  uVar3 = *(uint *)((int)(int *)in_ESI + in_BX + 0x33);
  pcVar2 = (char *)((int)(int *)in_ESI + in_BX + 100);
  bVar6 = (byte)in_CX & 0x1f;
  cVar10 = *pcVar2;
  *pcVar2 = *pcVar2 >> bVar6;
  bVar11 = (in_CX & 0x1f) == 0;
  bVar11 = (bool)(bVar11 * (uVar3 < uVar7) | !bVar11 * ((cVar10 >> bVar6 - 1 & 1U) != 0));
  FUN_1000_a120();
  piVar8 = (int *)in_ESI;
  if (!bVar11) {
    uVar7 = piVar8[3];
    if (200 < uVar7) {
      uVar7 = 200;
    }
    bVar6 = ((byte)uVar7 >> 1) + 1;
    pbVar4 = *(byte **)(char *)((int)piVar8 + -0x53);
    bVar5 = (byte)((uint)pbVar4 >> 8);
    in_BX = CONCAT11(bVar5 - *pbVar4,(char)pbVar4);
    *(int *)(unaff_BP + (int)piVar8) =
         *(int *)(unaff_BP + (int)piVar8) + in_CX + (uint)(bVar5 < *pbVar4);
    unaff_BP = unaff_BP + CONCAT11(bVar6,(char)in_stack_00000000);
    *(char *)(in_BX + (int)piVar8) = *(char *)(in_BX + (int)piVar8) + '\x04';
    in_stack_00000000 = (uint)bVar6 << 8;
    *(BADSPACEBASE **)(char *)(in_BX + (int)piVar8) = register0x00000010;
  }
  unaff_DI[in_BX] = unaff_DI[in_BX] + -1;
  pbVar1 = (byte *)((int)piVar8 + unaff_BP + 0x30);
  *pbVar1 = *pbVar1 ^ (byte)((uint)in_stack_00000000 >> 8);
  *unaff_DI = -*unaff_DI;
LAB_1000_3482:
  bVar6 = (byte)((uint)((int *)in_ESI)[3] >> 1);
  if ((byte)((uint)((int *)in_ESI)[3] >> 9) == 0) {
    pbVar1 = (byte *)(unaff_DI + -0x2d81);
    bVar5 = *pbVar1;
    *pbVar1 = *pbVar1 - bVar6;
    if (bVar6 <= bVar5 && *pbVar1 != 0) {
      return;
    }
  }
  *unaff_DI = '2';
  return;
}


