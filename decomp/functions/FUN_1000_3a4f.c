/* 1000:3a4f */

/* WARNING: Instruction at (ram,0x00013ade) overlaps instruction at (ram,0x00013add)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x00013ace) */
/* WARNING: Removing unreachable block (ram,0x00013ada) */
/* WARNING: Removing unreachable block (ram,0x00013ad5) */
/* WARNING: Removing unreachable block (ram,0x00013add) */

undefined2 FUN_1000_3a4f(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  char in_AL;
  byte bVar5;
  undefined2 uVar6;
  uint in_CX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  unaff_SI[in_BX] = unaff_SI[in_BX] - 0x15;
  puVar1 = (uint *)(unaff_BP + unaff_DI + 0x645);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - in_CX;
  bVar5 = (in_AL + -0x10) - (uVar2 < in_CX) | 2;
  iVar3 = *(int *)(unaff_DI + 0x55);
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar5;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & (byte)in_CX;
  *(int *)0xf029 = unaff_BP;
  if (iVar3 != *(int *)0x32bb) {
    *(undefined2 *)0xf027 = 0x3ac4;
    func_0x0001afc1();
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] | bVar5;
    pcVar4 = (code *)swi(1);
    uVar6 = (*pcVar4)();
    return uVar6;
  }
  if ((((*unaff_SI & 0x80) == 0) && (unaff_SI[0xb] == 0xff)) &&
     ((unaff_SI[10] == 0 || ((*(byte *)0x3c00 != unaff_SI[0xc] && (unaff_SI[10] == 2)))))) {
    unaff_SI[10] = 1;
  }
  return *(undefined2 *)0xf037;
}


