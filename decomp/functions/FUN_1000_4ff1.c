/* 1000:4ff1 */

/* WARNING: Instruction at (ram,0x00015002) overlaps instruction at (ram,0x00015000)
    */
/* WARNING: Unable to track spacebase fully for stack */

undefined2 FUN_1000_4ff1(void)

{
  char *pcVar1;
  byte bVar2;
  byte in_AL;
  undefined2 uVar3;
  char cVar4;
  int in_CX;
  undefined2 in_DX;
  byte *in_BX;
  undefined1 *puVar5;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int unaff_BP;
  uint unaff_SI;
  char *unaff_DI;
  char *pcVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  char cVar11;
  char cVar12;
  bool bVar13;
  longdouble in_ST0;
  undefined2 *puVar6;
  
  LOCK();
  puVar5 = *(undefined1 **)(in_BX + (int)unaff_DI + -0x18);
  *(undefined1 **)(in_BX + (int)unaff_DI + -0x18) = &stack0xfffe;
  UNLOCK();
  bVar2 = in_AL - *in_BX;
  cVar11 = in_AL < *in_BX || bVar2 < in_CF;
  if ((bool)cVar11) {
    in_CX = in_CX + -1;
    pcVar10 = unaff_DI;
    if (in_CX != 0 && bVar2 == in_CF) goto code_r0x0001500d;
    *(undefined2 *)(puVar5 + -2) = unaff_ES;
    *(undefined2 *)(puVar5 + -4) = 0x5026;
    uVar3 = FUN_1000_502f();
    cVar4 = (char)((uint)uVar3 >> 8);
    uVar3 = CONCAT11(cVar4,((char)uVar3 + -0x12) - cVar11 | unaff_DI[unaff_BP]);
    (in_BX + (int)unaff_DI)[-7] = (in_BX + (int)unaff_DI)[-7] + cVar4;
  }
  else {
    *(undefined2 *)(puVar5 + -2) = 0x1012;
    pcVar10 = unaff_DI + 2;
    uVar3 = in(in_DX);
    *(undefined2 *)unaff_DI = uVar3;
    bVar13 = (char)((uint)in_DX >> 8) == '\0' && *(char *)(unaff_BP + unaff_SI + 5) == '\0';
    puVar6 = (undefined2 *)(puVar5 + -4);
    puVar5 = puVar5 + -4;
    *puVar6 = 0x5003;
    uVar3 = FUN_1000_59b2();
    if (bVar13) {
      while( true ) {
        in_BX[unaff_SI] = in_BX[unaff_SI] & (byte)in_CX;
        bVar13 = (byte)uVar3 == 6;
        if (5 < (byte)uVar3) {
          if (!bVar13) {
            return uVar3;
          }
code_r0x0001500d:
          cVar12 = CARRY1((byte)in_CX,in_BX[(int)pcVar10]);
          cVar4 = (char)((uint)in_CX >> 8);
          puVar7 = (undefined2 *)(puVar5 + -2);
          puVar5 = puVar5 + -2;
          *puVar7 = 0x5014;
          cVar11 = FUN_1000_567c();
          if ((bool)cVar12) goto LAB_1000_501b;
          puVar9 = (undefined2 *)(puVar5 + -2);
          puVar5 = puVar5 + -2;
          *puVar9 = 0x5019;
          uVar3 = FUN_1000_2fef();
          pcVar1 = (char *)(unaff_BP + unaff_SI + 0x12aa);
          *pcVar1 = *pcVar1 + cVar4 + cVar12;
          bVar13 = *pcVar1 == '\0';
        }
        unaff_ES = (undefined2)((ulong)*(undefined4 *)(in_BX + (int)pcVar10) >> 0x10);
        in_CX = (int)*(undefined4 *)(in_BX + (int)pcVar10);
        if (!bVar13) break;
        *(uint *)(pcVar10 + 0xd) = *(uint *)(pcVar10 + 0xd) | unaff_SI;
      }
    }
    else {
      puVar8 = (undefined2 *)(puVar5 + -2);
      puVar5 = puVar5 + -2;
      *puVar8 = 0x7206;
      cVar11 = (char)uVar3 + -0x18;
      *(int *)(in_BX + unaff_SI) = (int)ROUND(in_ST0);
      pcVar1 = pcVar10;
      pcVar10 = unaff_DI + 3;
      *pcVar1 = cVar11;
LAB_1000_501b:
      *pcVar10 = cVar11;
      *(uint *)(unaff_SI - 0x1f) = *(uint *)(unaff_SI - 0x1f) | unaff_SI;
    }
    uVar3 = *(undefined2 *)(puVar5 + 0xe);
  }
  return uVar3;
}


