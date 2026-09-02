/* 1000:72f8 */

/* WARNING: Instruction at (ram,0x0001731d) overlaps instruction at (ram,0x0001731c)
    */

void FUN_1000_72f8(void)

{
  uint *puVar1;
  byte *pbVar2;
  bool bVar3;
  int iVar4;
  byte bVar5;
  undefined2 in_AX;
  byte in_CL;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  char in_SF;
  char in_OF;
  
  out(0x80,(char)in_AX);
  if (in_OF == in_SF) {
    return;
  }
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_BX + in_CF;
  bVar5 = (char)in_AX - in_DL;
  if ('\x05' < (char)bVar5) {
    *(char *)0x80d3 = *(char *)0x80d3 + bVar5 + (bVar5 < 0x21);
    out(0xc4,bVar5);
    iVar4 = unaff_DI * 2;
    *(undefined2 *)(iVar4 + -0x4252) = CONCAT11((char)((uint)in_AX >> 8),bVar5);
    *(undefined2 *)(iVar4 + -0x3d82) = 0;
    *(undefined2 *)(iVar4 + 0x1212) = 0x8348;
    *(undefined2 *)(unaff_BP + unaff_SI) = 0xc480;
    func_0x0001b63b(0x1077);
    return;
  }
  puVar1 = (uint *)(in_BX + unaff_SI + 0x21ea);
  *puVar1 = *puVar1 << (in_CL & 0xf) | *puVar1 >> 0x10 - (in_CL & 0xf);
  bVar3 = (in_CL & 0x1f) == 0;
  *(char *)(unaff_BP + unaff_SI) =
       *(char *)(unaff_BP + unaff_SI) + in_DL +
       (bVar3 * (bVar5 < 6) | !bVar3 * ((*puVar1 & 1) != 0));
  pbVar2 = (byte *)(in_BX + unaff_DI + -0x1dea);
  *pbVar2 = *pbVar2 >> (in_CL & 7) | *pbVar2 << 8 - (in_CL & 7);
  return;
}


