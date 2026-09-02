/* 1000:3607 */

void FUN_1000_3607(void)

{
  byte *pbVar1;
  byte bVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  code *pcVar7;
  uint uVar8;
  byte in_CL;
  undefined2 in_DX;
  byte in_BL;
  undefined2 *puVar9;
  undefined2 *unaff_BP;
  uint *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  
  *(char *)unaff_SI = (char)*unaff_SI + (char)((uint)in_DX >> 8);
  puVar3 = unaff_SI + 1;
  uVar4 = *unaff_SI;
  uVar8 = uVar4 | 8;
  if (in_CL < 4) {
    *(byte *)((int)unaff_BP + unaff_DI) = *(byte *)((int)unaff_BP + unaff_DI) | in_BL;
    *(byte *)(unaff_DI + 0x3a64) = *(byte *)(unaff_DI + 0x3a64) ^ (byte)(uVar4 >> 8);
    puVar9 = (undefined2 *)&stack0xfff6;
    cVar6 = '\x19';
    do {
      unaff_BP = unaff_BP + -1;
      puVar9 = puVar9 + -1;
      *puVar9 = *unaff_BP;
      cVar6 = cVar6 + -1;
    } while ('\0' < cVar6);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  bVar10 = CARRY1(in_CL,(byte)*puVar3);
  pbVar1 = (byte *)((int)unaff_BP + (int)puVar3);
  bVar2 = *pbVar1;
  bVar5 = *pbVar1 + (byte)uVar8;
  *pbVar1 = bVar5 + bVar10;
  *(char *)((int)unaff_BP + (int)puVar3) =
       *(char *)((int)unaff_BP + (int)puVar3) + (char)unaff_SS +
       (uVar8 < *(uint *)((int)unaff_BP + (int)puVar3) ||
       uVar8 - *(uint *)((int)unaff_BP + (int)puVar3) <
       (uint)(CARRY1(bVar2,(byte)uVar8) || CARRY1(bVar5,bVar10)));
  pcVar7 = (code *)swi(3);
  (*pcVar7)(&stack0xfff6);
  return;
}


