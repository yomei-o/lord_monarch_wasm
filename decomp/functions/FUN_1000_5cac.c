/* 1000:5cac */

void FUN_1000_5cac(void)

{
  int iVar1;
  uint in_AX;
  uint in_CX;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = *(int *)0xc4e6 + in_CX < 0x134;
  uVar2 = (*(int *)0xc4e6 + in_CX) - 0x134;
  if ((bVar3 || uVar2 == 0) || (bVar3 = in_CX < uVar2, uVar2 < in_CX)) {
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_DL + bVar3;
    out(0xc4,(char)(in_AX & 0xff01));
    iVar1 = uVar2 * 2;
    *(uint *)(iVar1 + -0x4252) = in_AX & 0xff01;
    *(undefined2 *)(iVar1 + -0x3d82) = 0;
    *(undefined2 *)(iVar1 + 0x1212) = 0x8348;
    *(undefined2 *)(unaff_BP + unaff_SI) = 0xc480;
    func_0x0001b63b();
  }
  return;
}


