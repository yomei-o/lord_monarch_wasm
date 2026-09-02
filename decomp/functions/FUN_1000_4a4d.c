/* 1000:4a4d */

undefined4 __cdecl16near FUN_1000_4a4d(void)

{
  undefined2 in_AX;
  uint uVar1;
  undefined2 in_DX;
  int unaff_SI;
  int iVar2;
  undefined2 unaff_DS;
  
  uVar1 = *(uint *)(unaff_SI + 2);
  iVar2 = unaff_SI + 4;
  FUN_1000_4b61();
  uVar1 = uVar1 & 0xff;
  do {
    iVar2 = iVar2 + 2;
    FUN_1000_759b(iVar2);
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}


