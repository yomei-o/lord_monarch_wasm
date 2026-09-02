/* 1000:5c72 */

/* WARNING: Instruction at (ram,0x00015cda) overlaps instruction at (ram,0x00015cd9)
    */
/* WARNING: Removing unreachable block (ram,0x00015cc7) */

uint FUN_1000_5c72(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  uint in_AX;
  uint uVar6;
  undefined1 *in_CX;
  int iVar7;
  int iVar8;
  char in_DL;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  undefined1 *unaff_DI;
  undefined1 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  
  unaff_SI[in_BX + -0x5714] = unaff_SI[in_BX + -0x5714] + (char)in_AX;
  if (&stack0x0000 + in_AX == (undefined1 *)0x0) {
    *unaff_DI = 0;
    *unaff_SI = *unaff_SI + CARRY2(in_AX,(uint)&stack0x0000);
    puVar9 = unaff_DI + 3;
    uVar2 = in(0x8e1);
    *(undefined2 *)(unaff_DI + 1) = uVar2;
    *unaff_SI = '\0';
    iVar8 = 0x40;
    cVar4 = '\0';
    do {
      do {
        cVar5 = cVar4;
        iVar7 = iVar8;
        FUN_1000_5cac();
        iVar8 = iVar7 + -1;
        cVar4 = cVar5 + '\x01';
      } while (iVar8 != 0);
      if (SCARRY1(cVar5,'\x01')) {
        return CONCAT11(0xc0,cVar5 + '\x01') ^ 0xad;
      }
      puVar9 = puVar9 + 2;
      iVar8 = iVar7 + -2;
      if (iVar8 == 0) {
        return 0x1e;
      }
      piVar1 = (int *)(puVar9 + in_BX + -0x517b);
      iVar7 = *piVar1;
      *piVar1 = *piVar1 + -1;
      unaff_BP = -0x7a39;
      cVar4 = cVar5;
    } while (*piVar1 == 0 || SBORROW2(iVar7,1) != *piVar1 < 0);
    unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  }
  else {
    uVar3 = *(undefined4 *)(unaff_DI + unaff_BP);
    bVar10 = unaff_DI < (undefined1 *)0x134;
    puVar9 = unaff_DI + -0x134;
    if ((!bVar10 && puVar9 != (undefined1 *)0x0) && (bVar10 = in_CX < puVar9, in_CX <= puVar9)) {
      return (uint)uVar3;
    }
    unaff_SI[in_BX] = unaff_SI[in_BX] + in_DL + bVar10;
    uVar6 = (uint)uVar3 & 0xff01;
    out(0xc4,(char)uVar6);
    puVar9 = (undefined1 *)((int)puVar9 * 2);
    *(uint *)(puVar9 + -0x4252) = uVar6;
    *(undefined2 *)(puVar9 + -0x3d82) = 0;
  }
  *(undefined2 *)(puVar9 + 0x1212) = 0x8348;
  (unaff_SI + unaff_BP)[0] = -0x80;
  (unaff_SI + unaff_BP)[1] = -0x3c;
  uVar6 = func_0x0001b63b();
  return uVar6;
}


