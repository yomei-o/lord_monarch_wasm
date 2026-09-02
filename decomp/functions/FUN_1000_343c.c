/* 1000:343c */

void FUN_1000_343c(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  byte *pbVar4;
  byte bVar5;
  uint in_CX;
  uint in_DX;
  uint uVar6;
  int in_BX;
  byte bVar7;
  int unaff_BP;
  undefined1 *puVar8;
  undefined1 *in_ESI;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  
  puVar8 = (undefined1 *)in_ESI + 1;
  out(*in_ESI,in_DX);
  uVar6 = *(uint *)(puVar8 + in_BX + 0x33);
  pcVar1 = puVar8 + in_BX + 100;
  bVar5 = (byte)in_CX & 0x1f;
  cVar3 = *pcVar1;
  *pcVar1 = *pcVar1 >> bVar5;
  bVar9 = (in_CX & 0x1f) == 0;
  bVar9 = (bool)(bVar9 * (uVar6 < in_DX) | !bVar9 * ((cVar3 >> bVar5 - 1 & 1U) != 0));
  FUN_1000_a120();
  if (!bVar9) {
    uVar6 = *(uint *)(puVar8 + 6);
    if (200 < uVar6) {
      uVar6 = 200;
    }
    bVar5 = ((byte)uVar6 >> 1) + 1;
    pbVar4 = *(byte **)(puVar8 + -0x53);
    bVar7 = (byte)((uint)pbVar4 >> 8);
    in_BX = CONCAT11(bVar7 - *pbVar4,(char)pbVar4);
    *(uint *)(puVar8 + unaff_BP) = *(int *)(puVar8 + unaff_BP) + in_CX + (uint)(bVar7 < *pbVar4);
    unaff_BP = unaff_BP + CONCAT11(bVar5,(char)param_1);
    puVar8[in_BX] = puVar8[in_BX] + '\x04';
    param_1 = (uint)bVar5 << 8;
    *(undefined1 **)(puVar8 + in_BX) = &stack0x0004;
  }
  unaff_DI[in_BX] = unaff_DI[in_BX] + -1;
  puVar8[unaff_BP + 0x30] = puVar8[unaff_BP + 0x30] ^ (byte)((uint)param_1 >> 8);
  *unaff_DI = -*unaff_DI;
  bVar5 = (byte)(*(uint *)(puVar8 + 6) >> 1);
  if ((byte)(*(uint *)(puVar8 + 6) >> 9) == 0) {
    pbVar2 = (byte *)(unaff_DI + -0x2d81);
    bVar7 = *pbVar2;
    *pbVar2 = *pbVar2 - bVar5;
    if (bVar5 <= bVar7 && *pbVar2 != 0) {
      return;
    }
  }
  *unaff_DI = '2';
  return;
}


